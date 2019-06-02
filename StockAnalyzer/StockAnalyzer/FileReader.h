#pragma once
#include "StockData.h"
using namespace System;
using namespace System::IO;
using namespace System::Windows::Forms;

ref class FileReader
{
public:
	FileReader();
	StockData^ getStockData();
	void readDailyData(String^);

private:
	String^ baseDir;
	StockData stockData;
	
	
};

