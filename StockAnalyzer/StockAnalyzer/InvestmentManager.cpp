#include "stdafx.h"
#include "InvestmentManager.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace std;


InvestmentManager::InvestmentManager()
{
	investments = gcnew List<Investment^>();
}

Investment ^ InvestmentManager::getInvestment(int index)
{
	return investments[index];
}

void InvestmentManager::showInvestment()
{
	throw gcnew System::NotImplementedException();
}

//Adds an investment object to the list
void InvestmentManager::addInvestment(Investment ^ toAdd)
{
	investments->Add(toAdd);
}

double InvestmentManager::getAvailableMoney()
{
	return availableMoney;
}

void InvestmentManager::setAvailableMoney(double newBalance)
{
	availableMoney = newBalance;
}

void InvestmentManager::setTotalPurchases(double balance)
{	//the introduced money divided by the openPrice of the stock
	totalPurchases = balance / manager->getInvestment(1)->getBuyPrice();
}
