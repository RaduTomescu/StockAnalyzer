#pragma once

using namespace System;
ref class Investment
{
public:
	Investment();
	//set methods
	void setDate(String^);
	void setEpic(String^);
	void setBuyPrice(double);
	void setSellPrice(double);
	void setStopLoss(double);
	

	//get methods
	String^ getDate();
	String^ getEpic();
	double getBuyPrice();
	double getSellPrice();
	double getStopLoss();
//	double computeSellPrice();
//	double computereStopLoss();
	

private:
	double buyPrice ;
	double sellPrice;
	double stopLoss;
	String^ epic;
	String^ date;


};