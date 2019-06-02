#include "stdafx.h"
#include "Investment.h"



Investment::Investment()
{
}

void Investment::setDate(String ^ newDate)
{
	date = newDate;
}

void Investment::setEpic(String ^ newEpic)
{
	epic = newEpic;
}

void Investment::setBuyPrice(double newBuyPrice)
{
	buyPrice = newBuyPrice;
}


//Sets the sellPrice to be the openPrice + 20% of openPrice
void Investment::setSellPrice(double openStockPrice)
{
	sellPrice = openStockPrice + (openStockPrice*0.2);
}

//Sets the stopLoss to be the openPrice - 15% of openPrice
void Investment::setStopLoss(double newStopLoss)
{
	
	stopLoss = newStopLoss - (newStopLoss*0.15);
}

String ^ Investment::getDate()
{
	return date;
}

String ^ Investment::getEpic()
{
	return epic;
}

double Investment::getBuyPrice()
{
	return buyPrice;
}

double Investment::getSellPrice()
{
	return 0.0;
}

double Investment::getStopLoss()
{
	return 0.0;
}
