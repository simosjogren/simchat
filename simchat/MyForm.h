#pragma once
#include<iostream>
#include<map>
#include<string>
#include<ctime>
#include<vector>
#include<msclr\marshal_cppstd.h>
#include "login.h"


namespace simchat {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	void sendMessageAction(TextBox^ msg, TextBox^ history);

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ sendBox;
	private: System::Windows::Forms::TextBox^ historyBox;


	private: System::Windows::Forms::Button^ LogOut;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->sendBox = (gcnew System::Windows::Forms::TextBox());
			this->historyBox = (gcnew System::Windows::Forms::TextBox());
			this->LogOut = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->button1->Location = System::Drawing::Point(617, 80);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(88, 48);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Send";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::sendMessage);
			// 
			// sendBox
			// 
			this->sendBox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sendBox->Location = System::Drawing::Point(32, 80);
			this->sendBox->Multiline = true;
			this->sendBox->Name = L"sendBox";
			this->sendBox->Size = System::Drawing::Size(572, 48);
			this->sendBox->TabIndex = 1;
			// 
			// historyBox
			// 
			this->historyBox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->historyBox->Location = System::Drawing::Point(32, 141);
			this->historyBox->Multiline = true;
			this->historyBox->Name = L"historyBox";
			this->historyBox->Size = System::Drawing::Size(572, 293);
			this->historyBox->TabIndex = 2;
			// 
			// LogOut
			// 
			this->LogOut->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LogOut->Location = System::Drawing::Point(617, 384);
			this->LogOut->Name = L"LogOut";
			this->LogOut->Size = System::Drawing::Size(88, 50);
			this->LogOut->TabIndex = 3;
			this->LogOut->Text = L"Log out";
			this->LogOut->UseVisualStyleBackColor = true;
			this->LogOut->Click += gcnew System::EventHandler(this, &MyForm::LogOut_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(548, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(157, 17);
			this->label1->TabIndex = 4;
			this->label1->Text = L"CLIENT VERSION 0.0.1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(26, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(120, 32);
			this->label2->TabIndex = 5;
			this->label2->Text = L"SimChat";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(719, 446);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->LogOut);
			this->Controls->Add(this->historyBox);
			this->Controls->Add(this->sendBox);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public: System::Void sendMessage(System::Object^ sender, System::EventArgs^ e) {

		// Lets move the current to the history box.
		sendMessageAction(sendBox, historyBox);
	}
	private: System::Void LogOut_Click(System::Object^ sender, System::EventArgs^ e) {

	}
};
}
