// FileReader.cpp : main project file.

#include "stdafx.h"
#include "Controller.h"
#include "Interface.h"
using namespace System;
using namespace System::IO;
using namespace StockAnalyzer;

int main(array<System::String ^> ^args)
{
	//creates an Interface Object named "stockAnalyzer"
	Interface stockAnalyzer;
	//initializes the interface
	stockAnalyzer.ShowDialog();
	
	system("pause");
	return 0;
}
