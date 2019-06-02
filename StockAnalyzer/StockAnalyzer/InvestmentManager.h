#pragma once
#include "Investment.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace std;

ref class InvestmentManager
{
public:
	InvestmentManager();
	Investment^ getInvestment(int index);
	void showInvestment();
	void addInvestment(Investment^);
	//getter
	double getAvailableMoney();
	
	//setter
	void setAvailableMoney(double);
	void setTotalPurchases(double);

private:
	InvestmentManager^ manager;
	List<Investment^>^ investments;
	double availableMoney;
	double totalSales;
	//number of stocks bought
	double totalPurchases;
	double totalLoss;

};

