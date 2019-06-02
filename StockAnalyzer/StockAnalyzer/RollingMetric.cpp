#include "stdafx.h"
#include "RollingMetric.h"
#include "StockData.h"
#include <map>
#include <string>
#include <iostream>
using namespace std;
using namespace System;

//define short name for multiple type
typedef multimap< double, string, less< double > > mmap;

//this function is purely to convert from a Microsoft String^ to a std::string. Do not worry what is happening.
void MarshalString(String ^ s, string& os) {
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}

RollingMetric::RollingMetric()
{
	throw gcnew System::NotImplementedException();
}

RollingMetric::RollingMetric(StockData^ stockData)
{
	this->stockData = stockData;
}


void RollingMetric::perform()
{
	String^ date;
	cli::array<wchar_t>^ delimiter = { '-' };
	
	mmap metricScores; //map to store our results in the format of <CompanyName, MetricResult>


	for (int i = 0; i < stockData->getStockCompanySize(); i++) // loop over each company
	{
		double cAvgOpen = 0.0;
		double cAvgOpenLong = 0.0;
		double different = 0.0;

		//if the dFound is true that means that the day was found
		bool dFound = false;

		for (int j = 0; j < stockData->getStockCompany(i)->getDailyCompanySize(); j++) // loop over each company's daily values
		{
			date = stockData->getStockCompany(i)->getDailyDetails(j)->getDate();

			//split the date 
			dates = date->Split(delimiter);
			//if its the same date
			if (compareDates()) {
				dFound = true;//true= the day has been found
				if (j + 200 < stockData->getStockCompany(i)->getDailyCompanySize()) {//if the specified date+200 are smaller than total dates
					for (int m = j; m < j + 15; m++) {
						cAvgOpen += stockData->getStockCompany(i)->getDailyDetails(m)->getOpen();
					}
					for (int n = j; n < j + 200; n++) {
						cAvgOpenLong += stockData->getStockCompany(i)->getDailyDetails(n)->getOpen();
					}
				}
				else {// there are not enough days to use this metric
					cAvgOpen = 0.0;
					cAvgOpenLong = 0.0;
				}

			}
			if (dFound) {// if the day has been found
				break;//breaks from the second for loop
			}
		}//if the specified date has been found
		if (dFound) {

			//divide them by the 15 and 200 days
			cAvgOpen = cAvgOpen / 15;
			cAvgOpenLong = cAvgOpenLong / 200; 
			different = cAvgOpen - cAvgOpenLong;

			//convert the String^ to a std:string for the multimap
			string epic = "";
			String ^ crlEpic = stockData->getStockCompany(i)->getEpic();
			MarshalString(crlEpic, epic);

			//add only the ones that can be bought
			if(different > 0 ){
		//	if (stockData->getStockCompany(i)->getDailyDetails(i)->getOpen() < different) {
				//add the result to the multimap
				metricScores.insert(mmap::value_type(different, epic));
			}
		}
	}

	//the multimap is stored ascending order. I.e those with the largest difference are located towards the end of the hashmap.
	//Therefore, the last one is the most profitable one. 
	 bestBuy = gcnew String(metricScores.rbegin()->second.c_str());

//	 Console::WriteLine(bestBuy);

}


/*The method compares the given date with the dates from the companies.
  If the given date is equal with the date from the company, it returns true, else false.
*/
bool RollingMetric::compareDates()
{
	String^ yyyy = "2014";
	String^ mm = "03";
	String^ dd = "18";
	for (int i = 0; i < dates->Length; i = i + 3) {
		if (Equals(dates[i], yyyy)) {

			if (Equals(dates[i + 1], mm)) {
				if (Equals(dates[i + 2], dd)) {
					return true;
				}
				else return false;
			}
			else return false;
		}
		else return false;
	}

}
//returns the openPrice of the best company from whom to buy in the specified date.
double RollingMetric::bestCompanyPrice()
{
	String^ date;
	//delimiter for the spliter used on the Strings that contain the dates
	cli::array<wchar_t>^ delimiter = { '-' };

	for (int i = 0; i < stockData->getStockCompanySize(); i++) // loop over each company 
	{	//if the name from the perform() with the name of the company
		if (Equals(bestBuy, stockData->getStockCompany(i)->getEpic())) {
			for (int j = 0; j < stockData->getStockCompany(i)->getDailyCompanySize(); j++) // loop over each company's daily values 
			{	//date is equal to the date from the company
				date = stockData->getStockCompany(i)->getDailyDetails(j)->getDate();

				//split the date 
				dates = date->Split(delimiter);
				//if its the same date
				if (compareDates()) {
					//returns the open price of the specific company, on the specificed date
					return stockData->getStockCompany(i)->getDailyDetails(j)->getOpen();
				}

			}
		}
	}
}

//Returns the name of the best stock company to buy
String ^ RollingMetric::getBestBuy()
{
	return bestBuy;
}
