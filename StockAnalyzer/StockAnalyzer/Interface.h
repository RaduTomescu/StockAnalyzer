#pragma once
#include"Controller.h"

namespace StockAnalyzer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Interface
	/// </summary>
	public ref class Interface : public System::Windows::Forms::Form
	{
	public:
		Interface(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			control.attachGuiElements(this->executeBtn,this->loadFilesBtn, this->outputBox,this->ssRadioBtn,
				this->ssDateBox,this->simulateRadioBtn, this->sStartDateBox,this->sEndDateBox,this->addBalanceTxtBox
				,this->addBalanceBtn,this->balanceBtn);

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Interface()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  executeBtn;
	private: System::Windows::Forms::Button^  balanceBtn;

	private: System::Windows::Forms::RadioButton^  simulateRadioBtn;
	
			 //the controller Object
	protected: Controller control;



	private: System::Windows::Forms::TextBox^  ssDateBox;
	protected:






	private: System::Windows::Forms::RadioButton^  ssRadioBtn;







	private: System::Windows::Forms::TextBox^  addBalanceTxtBox;
	private: System::Windows::Forms::Button^  addBalanceBtn;
	private: System::Windows::Forms::RichTextBox^  outputBox;
	private: System::Windows::Forms::TextBox^  sStartDateBox;
	private: System::Windows::Forms::TextBox^  sEndDateBox;








	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  loadFilesBtn;




	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->executeBtn = (gcnew System::Windows::Forms::Button());
			this->balanceBtn = (gcnew System::Windows::Forms::Button());
			this->simulateRadioBtn = (gcnew System::Windows::Forms::RadioButton());
			this->ssDateBox = (gcnew System::Windows::Forms::TextBox());
			this->ssRadioBtn = (gcnew System::Windows::Forms::RadioButton());
			this->addBalanceTxtBox = (gcnew System::Windows::Forms::TextBox());
			this->addBalanceBtn = (gcnew System::Windows::Forms::Button());
			this->outputBox = (gcnew System::Windows::Forms::RichTextBox());
			this->sStartDateBox = (gcnew System::Windows::Forms::TextBox());
			this->sEndDateBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->loadFilesBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// executeBtn
			// 
			this->executeBtn->Location = System::Drawing::Point(10, 284);
			this->executeBtn->Name = L"executeBtn";
			this->executeBtn->Size = System::Drawing::Size(108, 24);
			this->executeBtn->TabIndex = 0;
			this->executeBtn->Text = L"Execute";
			this->executeBtn->UseVisualStyleBackColor = true;
			// 
			// balanceBtn
			// 
			this->balanceBtn->Location = System::Drawing::Point(10, 314);
			this->balanceBtn->Name = L"balanceBtn";
			this->balanceBtn->Size = System::Drawing::Size(108, 24);
			this->balanceBtn->TabIndex = 1;
			this->balanceBtn->Text = L"View balance";
			this->balanceBtn->UseVisualStyleBackColor = true;
			// 
			// simulateRadioBtn
			// 
			this->simulateRadioBtn->AutoSize = true;
			this->simulateRadioBtn->Location = System::Drawing::Point(10, 197);
			this->simulateRadioBtn->Name = L"simulateRadioBtn";
			this->simulateRadioBtn->Size = System::Drawing::Size(65, 17);
			this->simulateRadioBtn->TabIndex = 4;
			this->simulateRadioBtn->TabStop = true;
			this->simulateRadioBtn->Text = L"Simulate";
			this->simulateRadioBtn->UseVisualStyleBackColor = true;
			// 
			// ssDateBox
			// 
			this->ssDateBox->Location = System::Drawing::Point(69, 161);
			this->ssDateBox->Name = L"ssDateBox";
			this->ssDateBox->ReadOnly = true;
			this->ssDateBox->Size = System::Drawing::Size(108, 20);
			this->ssDateBox->TabIndex = 5;
			// 
			// ssRadioBtn
			// 
			this->ssRadioBtn->AutoSize = true;
			this->ssRadioBtn->Location = System::Drawing::Point(10, 138);
			this->ssRadioBtn->Name = L"ssRadioBtn";
			this->ssRadioBtn->Size = System::Drawing::Size(106, 17);
			this->ssRadioBtn->TabIndex = 6;
			this->ssRadioBtn->TabStop = true;
			this->ssRadioBtn->Text = L"Suggest Strategy";
			this->ssRadioBtn->UseVisualStyleBackColor = true;
			// 
			// addBalanceTxtBox
			// 
			this->addBalanceTxtBox->Location = System::Drawing::Point(10, 54);
			this->addBalanceTxtBox->Name = L"addBalanceTxtBox";
			this->addBalanceTxtBox->Size = System::Drawing::Size(108, 20);
			this->addBalanceTxtBox->TabIndex = 7;
			// 
			// addBalanceBtn
			// 
			this->addBalanceBtn->Location = System::Drawing::Point(10, 80);
			this->addBalanceBtn->Name = L"addBalanceBtn";
			this->addBalanceBtn->Size = System::Drawing::Size(108, 23);
			this->addBalanceBtn->TabIndex = 8;
			this->addBalanceBtn->Text = L"Introduce Balance";
			this->addBalanceBtn->UseVisualStyleBackColor = true;
			// 
			// outputBox
			// 
			this->outputBox->Location = System::Drawing::Point(209, 12);
			this->outputBox->Name = L"outputBox";
			this->outputBox->ReadOnly = true;
			this->outputBox->Size = System::Drawing::Size(556, 326);
			this->outputBox->TabIndex = 9;
			this->outputBox->Text = L"";
			// 
			// sStartDateBox
			// 
			this->sStartDateBox->Location = System::Drawing::Point(69, 220);
			this->sStartDateBox->Name = L"sStartDateBox";
			this->sStartDateBox->ReadOnly = true;
			this->sStartDateBox->Size = System::Drawing::Size(108, 20);
			this->sStartDateBox->TabIndex = 10;
			// 
			// sEndDateBox
			// 
			this->sEndDateBox->Location = System::Drawing::Point(69, 248);
			this->sEndDateBox->Name = L"sEndDateBox";
			this->sEndDateBox->ReadOnly = true;
			this->sEndDateBox->Size = System::Drawing::Size(108, 20);
			this->sEndDateBox->TabIndex = 11;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(7, 223);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(59, 13);
			this->label1->TabIndex = 12;
			this->label1->Text = L"Start date :";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(7, 252);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(56, 13);
			this->label2->TabIndex = 13;
			this->label2->Text = L"End date :";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(30, 164);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(36, 13);
			this->label3->TabIndex = 14;
			this->label3->Text = L"Date :";
			// 
			// loadFilesBtn
			// 
			this->loadFilesBtn->Location = System::Drawing::Point(10, 12);
			this->loadFilesBtn->Name = L"loadFilesBtn";
			this->loadFilesBtn->Size = System::Drawing::Size(108, 23);
			this->loadFilesBtn->TabIndex = 15;
			this->loadFilesBtn->Text = L"Load Files";
			this->loadFilesBtn->UseVisualStyleBackColor = true;
			// 
			// Interface
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(772, 352);
			this->Controls->Add(this->loadFilesBtn);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->sEndDateBox);
			this->Controls->Add(this->sStartDateBox);
			this->Controls->Add(this->outputBox);
			this->Controls->Add(this->addBalanceBtn);
			this->Controls->Add(this->addBalanceTxtBox);
			this->Controls->Add(this->ssRadioBtn);
			this->Controls->Add(this->ssDateBox);
			this->Controls->Add(this->simulateRadioBtn);
			this->Controls->Add(this->balanceBtn);
			this->Controls->Add(this->executeBtn);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Interface";
			this->Text = L"Stock Analyzer";
			this->Load += gcnew System::EventHandler(this, &Interface::Interface_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void Interface_Load(System::Object^  sender, System::EventArgs^  e) {

	}



};
	


}
