#include "stdafx.h"
#include "FileReader.h"
#include "StockCompany.h"
#include "StockDayDetails.h"
#include "Interface.h"

using namespace System;
using namespace System::IO;
using namespace System::Collections;
using namespace std;

//using namespace StockAnalyzer; // test
//using namespace System::Windows::Forms;

FileReader::FileReader() 
{
}

void FileReader::readDailyData(String^ fileName)
{
	//first create a new StockData object for this file
	StockCompany newStock;
	cli::array<String^>^ path = fileName->Split('\\');
	newStock.setEpic(path[path->Length - 1]);		// pune numele
	StreamReader^ din = File::OpenText(fileName);
	String^ str;
	str = din->ReadLine(); //read first line to skip header
	while ((str = din->ReadLine()) != nullptr)		//pana nu e null
	{
		cli::array<String^>^ variables = str->Split(',');
		//create a new StockDayDetails object
		StockDayDetails stockDay;
		if (variables->Length >= 7) {
			stockDay.setDate(variables[0]);
			stockDay.setOpen(Double::Parse(variables[1]));
			stockDay.setHigh(Double::Parse(variables[2]));
			stockDay.setLow(Double::Parse(variables[3]));
			stockDay.setClose(Double::Parse(variables[4]));
			stockDay.setVolume(Double::Parse(variables[5]));
			stockDay.setAdjClose(Double::Parse(variables[6]));

			//add the object to the Stock object
			newStock.addDayDetails(%stockDay);
		}
	}
	//now add the stock object to the StockData
	stockData.addStock(%newStock);
}

StockData^ FileReader::getStockData()
{
	return %stockData;
}
