#include "stdafx.h"
#include "StockData.h"

//constructor
StockData::StockData()
{
	stockData = gcnew List<StockCompany^>();
}
//adds the StockCompany object pointer in the StockData list of StockCompany pointers
void StockData::addStock(StockCompany^ toAdd)
{
	stockData->Add(toAdd);
}
//returns the StockCompany object from the stockData list that was the specified index
StockCompany^ StockData::getStockCompany(int index)
{
	return stockData[index];
}
//returns the number of companies in the list 
int StockData::getStockCompanySize()
{
	return stockData->Count;
}