#pragma once
#include "StockDayDetails.h"
using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;

ref class StockCompany
{
public:
	//constructor
	StockCompany();
		
	void addDayDetails(StockDayDetails^); 

	void setEpic(String^);
	String^ getEpic();

	int getDailyCompanySize();
	StockDayDetails^ getDailyDetails(int index);
private:
	//list of StockDayDetails pointers 
	List<StockDayDetails^>^ dailyDetails;
	//name of the company
	String^ epic;
};


