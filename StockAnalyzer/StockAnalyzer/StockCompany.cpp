#include "stdafx.h"
#include "StockCompany.h"

//constrcutor
StockCompany::StockCompany()
{

	//List<StockDayDetails^> dailyList;
	//dailyDetails = %dailyList;
	dailyDetails = gcnew List<StockDayDetails^>();
}
//adds the StockDayDetails object pointer in the StockCompany list 
void StockCompany::addDayDetails(StockDayDetails^ newDay)
{
	dailyDetails->Add(newDay);
}
//returns the name of the company
String^ StockCompany::getEpic()
{
	return epic;
}
//sets the name of the company
void StockCompany::setEpic(String^ newEpic)
{
	epic = newEpic;
}

//returns the StockDayDetails object from the Company list with the specified index
StockDayDetails^ StockCompany::getDailyDetails(int index)
{
	return dailyDetails[index];
}
//returns the number of companies
int StockCompany::getDailyCompanySize()
{
	return dailyDetails->Count;
}