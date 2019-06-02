#pragma once
using namespace System;
using namespace System::IO;

ref class StockDayDetails{

public:
	StockDayDetails();
	//set methods
	void setDate(String^);
	void setOpen(double);
	void setHigh(double);
	void setLow(double);
	void setClose(double);
	void setVolume(double);
	void setAdjClose(double);

	//get methods
	String^ getDate();
	double getOpen();
	double getHigh();
	double getLow();
	double getClose();
	double getVolume();
	double getAdjClose();

private:
	String^ date;
	double open;
	double high;
	double low;
	double close;
	double volume;
	double adj_close;
};

