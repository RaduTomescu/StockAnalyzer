#pragma once
#include "StockData.h"

using namespace std;

ref class RollingMetric
{
public:
	RollingMetric();
	RollingMetric(StockData^);
	void perform();// override;

	bool compareDates();
	double bestCompanyPrice();

	//getter
	String^ getBestBuy();

private:
	StockData^ stockData;
	String^ bestBuy;
	cli::array<String^>^ dates;
};

