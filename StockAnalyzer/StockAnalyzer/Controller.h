#pragma once
#include "FileReader.h"
#include "StockCompany.h"
#include "StockDayDetails.h"
#include "InvestmentManager.h"
using namespace System::Windows::Forms;
ref class Controller
{
public:
	//constructor
	Controller();
	//loads the data in the 
	void loadInData(String^);
	void attachGuiElements(Button^, Button^, RichTextBox^,RadioButton^,TextBox^,RadioButton^, TextBox^, TextBox^
							, TextBox^, Button^, Button^);

	
	//The method that reads all the files from the directory using the "readDailyData"
	//	method from the FileReader class and printing in the RichTextBox.
	void readAllStockData();
	//set the directory
	void setBaseDir(String^);
	//get the directory
	String^ getBaseDir();
	RichTextBox^ getOutputBox();


	void performStrategySuggestion();
//	void performSimulation();

private:
	String^ baseDir;
	//GUI elements
	
	RadioButton^ ssRadioBtn;
	RadioButton^ simulateRadioBtn;
	Button^ executeBtn;
	Button^ loadFilesBtn;
	Button^ addBalanceBtn;
	Button^ balanceBtn;
	RichTextBox^ outputBox;
	TextBox^ ssDateBox;
	TextBox^ sStartDateBox;
	TextBox^ sEndDateBox;
	TextBox^ addBalanceTxtBox;

	//balance
	double balance;
	//bool variable used to check if the files have been loaded or not
	bool loadedFiles = false;
	//bool variables used to change the methods used when pressed the "Execute" button
	bool strategyChecked = false;
	bool simulateChecked = false;
	//date token from the strategy suggestion textbox
	String^ simulateDate;
	
	//GUI elements methods
	System::Void executeBtn_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void outputBox_TextChanged(System::Object^  sender, System::EventArgs^  e);
	System::Void loadFilesBtn_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void ssRadioBtn_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	System::Void ssDateBox_TextChanged(System::Object^  sender, System::EventArgs^  e);
	System::Void simulateRadioBtn_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	System::Void sStartDateBox_TextChanged(System::Object^  sender, System::EventArgs^  e);
	System::Void sEndDateBox_TextChanged(System::Object^  sender, System::EventArgs^  e);
	System::Void addBalanceTxtBox_TextChanged(System::Object^  sender, System::EventArgs^  e);
	System::Void addBalanceBtn_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void balanceBtn_Click(System::Object^  sender, System::EventArgs^  e);
	

	FileReader fReader;
	InvestmentManager manager;
};

