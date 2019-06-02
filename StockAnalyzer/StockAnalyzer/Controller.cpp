#include "stdafx.h"
#include "Controller.h"
#include "Interface.h"
#include "RollingMetric.h"


using namespace System;
using namespace System::IO;
using namespace System::Collections;
using namespace std;
using namespace StockAnalyzer;

Controller::Controller()
{
}

void Controller::loadInData(String^ director)
{
	//set the base directory
	setBaseDir(director);

	//read all stock data
	readAllStockData();
}

/*The method that reads all the files from the directory using the "readDailyData"
  method from the FileReader class and printing in the RichTextBox.
*/
void Controller::readAllStockData()
{
	//iterate over all files in the base directory
	cli::array<String^>^ files = Directory::GetFiles(baseDir);
	for (int i = 0; i < files->Length; i++)
	{
		fReader.readDailyData(files[i]);
		//	Console::Clear();
		cli::array<String^>^ path = files[i]->Split('\\');
		this->outputBox->AppendText("Finished " + path[path->Length - 1] + "\n");
	}
	this->outputBox->AppendText("All files have been uploaded.");
}
//Sets the Directory.
void Controller::setBaseDir(String ^ newDir)
{
	baseDir = newDir;
}
//Gets the Directory.
String ^ Controller::getBaseDir()
{
	return baseDir;
}

void Controller::performStrategySuggestion()
{
	RollingMetric metric(fReader.getStockData());
	metric.perform();


}











/* ****************************************GUI*************************************************/

/*The method that attaches all the GUI elements from the controller to the ones
  from the interface by passing parameters.
*/
void Controller::attachGuiElements(Button ^ newExecuteBtn, Button^ newLoadBtn, RichTextBox^ newOutputBox, RadioButton^ newSsRadioBtn,
									TextBox^ newSsDateBox, RadioButton^ newSimulateRadioBtn, TextBox^ newSStarDateBox,
									TextBox^ newSEndDateBox,TextBox^ newAddBalanceBox, Button^ newAddBalanceBtn,Button^ newBalanceBtn)
{
	this->executeBtn = newExecuteBtn;
	this->executeBtn->Click += gcnew System::EventHandler(this, &Controller::executeBtn_Click);

	this->loadFilesBtn = newLoadBtn;
	this->loadFilesBtn->Click += gcnew System::EventHandler(this, &Controller::loadFilesBtn_Click);

	this->outputBox = newOutputBox;
	this->outputBox->TextChanged += gcnew System::EventHandler(this, &Controller::outputBox_TextChanged);

	this->ssRadioBtn = newSsRadioBtn;
	this->ssRadioBtn->CheckedChanged += gcnew System::EventHandler(this, &Controller::ssRadioBtn_CheckedChanged);

	this->ssDateBox= newSsDateBox;
	this->ssDateBox->TextChanged += gcnew System::EventHandler(this, &Controller::ssDateBox_TextChanged);

	this->simulateRadioBtn = newSimulateRadioBtn;
	this->simulateRadioBtn->CheckedChanged += gcnew System::EventHandler(this, &Controller::simulateRadioBtn_CheckedChanged);

	this->sStartDateBox = newSStarDateBox;
	this->sStartDateBox->TextChanged += gcnew System::EventHandler(this, &Controller::sStartDateBox_TextChanged);

	this->sEndDateBox = newSEndDateBox;
	this->sEndDateBox->TextChanged += gcnew System::EventHandler(this, &Controller::sEndDateBox_TextChanged);

	this->addBalanceTxtBox = newAddBalanceBox;
	this->addBalanceTxtBox->TextChanged += gcnew System::EventHandler(this, &Controller::addBalanceTxtBox_TextChanged);

	this->addBalanceBtn = newAddBalanceBtn;
	this->addBalanceBtn->Click += gcnew System::EventHandler(this, &Controller::addBalanceBtn_Click);

	this->balanceBtn = newBalanceBtn;
	this->balanceBtn->Click += gcnew System::EventHandler(this, &Controller::balanceBtn_Click);

}

/*The method that controls the Execute Button action, when pressed, form the interface.
*/
System::Void Controller:: executeBtn_Click(System::Object^  sender, System::EventArgs^  e) {
	if (loadedFiles) {
		this->outputBox->AppendText(" simulateDate:"+ simulateDate + "\n");
	}else{
		MessageBox::Show("There are no files loaded.", "Info", MessageBoxButtons::OK, MessageBoxIcon::Exclamation); 
	}
	
}

/*The method that controls the loadFileButton's action, when pressed.
*/
System::Void Controller::loadFilesBtn_Click(System::Object^  sender, System::EventArgs^  e) {
	if (loadedFiles) {//if the files are already loaded show error message
		MessageBox::Show("The files have been already loaded.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
	}
	else {//if the files are not loaded
		String^ path = Directory::GetCurrentDirectory();
		path = path + "\\files";
		//call the load in data function passing the path where the stock datafiles are locates
		loadInData(path);
		loadedFiles = true;
	}
}

/*The method that controls the ssRadioButton's action, when checked.
*/
System::Void Controller::ssRadioBtn_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e)
{
	//Simulate
	sStartDateBox->Text = "";
	sEndDateBox->Text = "";
	sStartDateBox->ReadOnly = true;
	sEndDateBox->ReadOnly = true;
	simulateChecked = false;

	//Suggest Strategy 
	ssDateBox->ReadOnly = false;
	strategyChecked = true;//used in the button action method
	return System::Void();
}

System::Void Controller::ssDateBox_TextChanged(System::Object ^ sender, System::EventArgs ^ e)
{
	simulateDate=ssDateBox->Text;
	return System::Void();
}

/*The method that controls the simulateRadioButton's action, when checked.
*/
System::Void Controller::simulateRadioBtn_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e)
{	
	//Suggest Strategy
	ssDateBox->Text = "";	//deletes averything written in the ssDateBox
	ssDateBox->ReadOnly = true;	//makes the ssDateBox ReadOnly
	strategyChecked = false;

	//Simulate
	sStartDateBox->ReadOnly = false;
	sEndDateBox->ReadOnly = false;
	simulateChecked = true;//used in the button action method
	return System::Void();
}

/*The method that controls the sStartDateBox action.
*/
System::Void Controller::sStartDateBox_TextChanged(System::Object ^ sender, System::EventArgs ^ e)
{
	return System::Void();
}

/*The method that controls the sEndDateBox action.
*/
System::Void Controller::sEndDateBox_TextChanged(System::Object ^ sender, System::EventArgs ^ e)
{
	return System::Void();
}

/*The method that controls the AddBalanceTxtBox action.
*/
System::Void Controller::addBalanceTxtBox_TextChanged(System::Object ^ sender, System::EventArgs ^ e)
{
	return System::Void();
}

/*The method that controls the AddBalance's action, when pressed.
*/
System::Void Controller::addBalanceBtn_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (Double::Parse(addBalanceTxtBox->Text) < 0 ) {
		MessageBox::Show("You can not introduce negative balance.", "Negative Balance Error", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
	}else{
		balance = Double::Parse(addBalanceTxtBox->Text);
		manager.setAvailableMoney(balance);
	}
	addBalanceTxtBox->Text = "";
}

/*The method that shows the balance to the user when the balanceBtn("View Balance") button is pressed.
*/
System::Void Controller::balanceBtn_Click(System::Object ^ sender, System::EventArgs ^ e)
{	
	if (balance == NULL) {
		MessageBox::Show("You have not introduced a balance yet.", "No Balance Error", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
	}
	else {
		MessageBox::Show("Your current balance is: " + "£ " + balance, "Current Balance", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}

//The method  that controls the richTextBox
System::Void Controller::outputBox_TextChanged(System::Object ^ sender, System::EventArgs ^ e)
{	
	//calling the "ScrollToCaret" function to make the richtextBox scroll down when the text is printed
	outputBox->ScrollToCaret();
	return System::Void();
} 

//getter for the outputBox 
RichTextBox^ Controller::getOutputBox()
{
	return outputBox;
}


