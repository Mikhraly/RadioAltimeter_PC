#pragma once

#include <array>
#include <string>
#include "RadioAltimeter.h"
#include "Message.h"

namespace ComPort {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO::Ports;

	/// <summary>
	/// ?????? ??? MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void) {
			InitializeComponent();
		}
		
	protected:
		/// <summary>
		/// ?????????? ??? ???????????? ???????.
		/// </summary>
		~MyForm() {
			if (components) {
				delete components;
			}
		}

	private: Threading::Mutex mutex;
	private: SerialPort^ mySerialPort = gcnew SerialPort("COM1", 115200, Parity::None, 8, StopBits::One);

	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::StatusStrip^ statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^ portNameStatusLabel;
	private: System::Windows::Forms::ToolStripStatusLabel^ portSpeedStatusLabel;
	private: System::Windows::Forms::ToolStripStatusLabel^ isConnectStatusLabel;
	private: System::Windows::Forms::TextBox^ textBoxHightInput;
	private: System::Windows::Forms::Label^ labelHightInput;


	private: System::Windows::Forms::Button^ buttonHightSet;
	private: System::Windows::Forms::Label^ labelHightSet;




	private: System::Windows::Forms::GroupBox^ groupBoxHight;
	private: System::Windows::Forms::ToolStripMenuItem^ PortToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ speedToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ toConnectToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ com1ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ com2ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ com3ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ com4ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ com5ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem1200;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem2400;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem4800;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem9600;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem19200;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem38400;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem57600;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem115200;
	private: System::Windows::Forms::CheckBox^ checkBoxServiceability;
	private: System::Windows::Forms::CheckBox^ checkBoxPUI;
	private: System::Windows::Forms::GroupBox^ groupBoxAnalog;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::CheckBox^ checkBoxBanTest;

	private: System::Windows::Forms::CheckBox^ checkBoxControlRA;

	private: System::Windows::Forms::CheckBox^ checkBoxOffRadiation;







		/// <summary>
		/// ???????????? ?????????? ????????????.
		/// </summary>
		System::ComponentModel::IContainer^ components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// ????????? ????? ??? ????????? ???????????? ? ?? ????????? 
		/// ?????????? ????? ?????? ? ??????? ????????? ????.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->PortToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->com1ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->com2ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->com3ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->com4ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->com5ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->speedToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem1200 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem2400 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem4800 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem9600 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem19200 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem38400 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem57600 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem115200 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toConnectToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->portNameStatusLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->portSpeedStatusLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->isConnectStatusLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->textBoxHightInput = (gcnew System::Windows::Forms::TextBox());
			this->labelHightInput = (gcnew System::Windows::Forms::Label());
			this->buttonHightSet = (gcnew System::Windows::Forms::Button());
			this->labelHightSet = (gcnew System::Windows::Forms::Label());
			this->groupBoxHight = (gcnew System::Windows::Forms::GroupBox());
			this->checkBoxServiceability = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxPUI = (gcnew System::Windows::Forms::CheckBox());
			this->groupBoxAnalog = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->checkBoxOffRadiation = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxControlRA = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxBanTest = (gcnew System::Windows::Forms::CheckBox());
			this->menuStrip1->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->groupBoxHight->SuspendLayout();
			this->groupBoxAnalog->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->PortToolStripMenuItem,
					this->speedToolStripMenuItem, this->toConnectToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(484, 24);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// PortToolStripMenuItem
			// 
			this->PortToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->com1ToolStripMenuItem,
					this->com2ToolStripMenuItem, this->com3ToolStripMenuItem, this->com4ToolStripMenuItem, this->com5ToolStripMenuItem
			});
			this->PortToolStripMenuItem->Name = L"PortToolStripMenuItem";
			this->PortToolStripMenuItem->Size = System::Drawing::Size(47, 20);
			this->PortToolStripMenuItem->Text = L"????";
			// 
			// com1ToolStripMenuItem
			// 
			this->com1ToolStripMenuItem->Name = L"com1ToolStripMenuItem";
			this->com1ToolStripMenuItem->Size = System::Drawing::Size(108, 22);
			this->com1ToolStripMenuItem->Text = L"COM1";
			this->com1ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::com1ToolStripMenuItem_Click);
			// 
			// com2ToolStripMenuItem
			// 
			this->com2ToolStripMenuItem->Name = L"com2ToolStripMenuItem";
			this->com2ToolStripMenuItem->Size = System::Drawing::Size(108, 22);
			this->com2ToolStripMenuItem->Text = L"COM2";
			this->com2ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::com2ToolStripMenuItem_Click);
			// 
			// com3ToolStripMenuItem
			// 
			this->com3ToolStripMenuItem->Name = L"com3ToolStripMenuItem";
			this->com3ToolStripMenuItem->Size = System::Drawing::Size(108, 22);
			this->com3ToolStripMenuItem->Text = L"COM3";
			this->com3ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::com3ToolStripMenuItem_Click);
			// 
			// com4ToolStripMenuItem
			// 
			this->com4ToolStripMenuItem->Name = L"com4ToolStripMenuItem";
			this->com4ToolStripMenuItem->Size = System::Drawing::Size(108, 22);
			this->com4ToolStripMenuItem->Text = L"COM4";
			this->com4ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::com4ToolStripMenuItem_Click);
			// 
			// com5ToolStripMenuItem
			// 
			this->com5ToolStripMenuItem->Name = L"com5ToolStripMenuItem";
			this->com5ToolStripMenuItem->Size = System::Drawing::Size(108, 22);
			this->com5ToolStripMenuItem->Text = L"COM5";
			this->com5ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::com5ToolStripMenuItem_Click);
			// 
			// speedToolStripMenuItem
			// 
			this->speedToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {
				this->toolStripMenuItem1200,
					this->toolStripMenuItem2400, this->toolStripMenuItem4800, this->toolStripMenuItem9600, this->toolStripMenuItem19200, this->toolStripMenuItem38400,
					this->toolStripMenuItem57600, this->toolStripMenuItem115200
			});
			this->speedToolStripMenuItem->Name = L"speedToolStripMenuItem";
			this->speedToolStripMenuItem->Size = System::Drawing::Size(71, 20);
			this->speedToolStripMenuItem->Text = L"????????";
			// 
			// toolStripMenuItem1200
			// 
			this->toolStripMenuItem1200->Name = L"toolStripMenuItem1200";
			this->toolStripMenuItem1200->Size = System::Drawing::Size(110, 22);
			this->toolStripMenuItem1200->Text = L"1200";
			this->toolStripMenuItem1200->Click += gcnew System::EventHandler(this, &MyForm::toolStripMenuItem1200_Click);
			// 
			// toolStripMenuItem2400
			// 
			this->toolStripMenuItem2400->Name = L"toolStripMenuItem2400";
			this->toolStripMenuItem2400->Size = System::Drawing::Size(110, 22);
			this->toolStripMenuItem2400->Text = L"2400";
			this->toolStripMenuItem2400->Click += gcnew System::EventHandler(this, &MyForm::toolStripMenuItem2400_Click);
			// 
			// toolStripMenuItem4800
			// 
			this->toolStripMenuItem4800->Name = L"toolStripMenuItem4800";
			this->toolStripMenuItem4800->Size = System::Drawing::Size(110, 22);
			this->toolStripMenuItem4800->Text = L"4800";
			this->toolStripMenuItem4800->Click += gcnew System::EventHandler(this, &MyForm::toolStripMenuItem4800_Click);
			// 
			// toolStripMenuItem9600
			// 
			this->toolStripMenuItem9600->Name = L"toolStripMenuItem9600";
			this->toolStripMenuItem9600->Size = System::Drawing::Size(110, 22);
			this->toolStripMenuItem9600->Text = L"9600";
			this->toolStripMenuItem9600->Click += gcnew System::EventHandler(this, &MyForm::toolStripMenuItem9600_Click);
			// 
			// toolStripMenuItem19200
			// 
			this->toolStripMenuItem19200->Name = L"toolStripMenuItem19200";
			this->toolStripMenuItem19200->Size = System::Drawing::Size(110, 22);
			this->toolStripMenuItem19200->Text = L"19200";
			this->toolStripMenuItem19200->Click += gcnew System::EventHandler(this, &MyForm::toolStripMenuItem19200_Click);
			// 
			// toolStripMenuItem38400
			// 
			this->toolStripMenuItem38400->Name = L"toolStripMenuItem38400";
			this->toolStripMenuItem38400->Size = System::Drawing::Size(110, 22);
			this->toolStripMenuItem38400->Text = L"38400";
			this->toolStripMenuItem38400->Click += gcnew System::EventHandler(this, &MyForm::toolStripMenuItem38400_Click);
			// 
			// toolStripMenuItem57600
			// 
			this->toolStripMenuItem57600->Name = L"toolStripMenuItem57600";
			this->toolStripMenuItem57600->Size = System::Drawing::Size(110, 22);
			this->toolStripMenuItem57600->Text = L"57600";
			this->toolStripMenuItem57600->Click += gcnew System::EventHandler(this, &MyForm::toolStripMenuItem57600_Click);
			// 
			// toolStripMenuItem115200
			// 
			this->toolStripMenuItem115200->Name = L"toolStripMenuItem115200";
			this->toolStripMenuItem115200->Size = System::Drawing::Size(110, 22);
			this->toolStripMenuItem115200->Text = L"115200";
			this->toolStripMenuItem115200->Click += gcnew System::EventHandler(this, &MyForm::toolStripMenuItem115200_Click);
			// 
			// toConnectToolStripMenuItem
			// 
			this->toConnectToolStripMenuItem->Name = L"toConnectToolStripMenuItem";
			this->toConnectToolStripMenuItem->Size = System::Drawing::Size(156, 20);
			this->toConnectToolStripMenuItem->Text = L"??????????/?????????";
			this->toConnectToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::toConnectToolStripMenuItem_Click);
			// 
			// statusStrip1
			// 
			this->statusStrip1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(205)), static_cast<System::Int32>(static_cast<System::Byte>(215)),
				static_cast<System::Int32>(static_cast<System::Byte>(61)));
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->portNameStatusLabel,
					this->portSpeedStatusLabel, this->isConnectStatusLabel
			});
			this->statusStrip1->Location = System::Drawing::Point(0, 391);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(484, 22);
			this->statusStrip1->SizingGrip = false;
			this->statusStrip1->TabIndex = 3;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// portNameStatusLabel
			// 
			this->portNameStatusLabel->Name = L"portNameStatusLabel";
			this->portNameStatusLabel->Size = System::Drawing::Size(41, 17);
			this->portNameStatusLabel->Text = L"COM1";
			// 
			// portSpeedStatusLabel
			// 
			this->portSpeedStatusLabel->Name = L"portSpeedStatusLabel";
			this->portSpeedStatusLabel->Size = System::Drawing::Size(43, 17);
			this->portSpeedStatusLabel->Text = L"115200";
			// 
			// isConnectStatusLabel
			// 
			this->isConnectStatusLabel->Name = L"isConnectStatusLabel";
			this->isConnectStatusLabel->Size = System::Drawing::Size(98, 17);
			this->isConnectStatusLabel->Text = L"?? ??????????!";
			// 
			// textBoxHightInput
			// 
			this->textBoxHightInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxHightInput->Location = System::Drawing::Point(120, 40);
			this->textBoxHightInput->Name = L"textBoxHightInput";
			this->textBoxHightInput->Size = System::Drawing::Size(100, 26);
			this->textBoxHightInput->TabIndex = 4;
			this->textBoxHightInput->Text = L"1";
			this->textBoxHightInput->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBoxHightInput_KeyDown);
			this->textBoxHightInput->MouseWheel += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::textBoxHightInput_MouseWheel);
			// 
			// labelHightInput
			// 
			this->labelHightInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelHightInput->Location = System::Drawing::Point(20, 40);
			this->labelHightInput->Name = L"labelHightInput";
			this->labelHightInput->Size = System::Drawing::Size(100, 26);
			this->labelHightInput->TabIndex = 5;
			this->labelHightInput->Text = L"?????? >>";
			this->labelHightInput->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// buttonHightSet
			// 
			this->buttonHightSet->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonHightSet->Location = System::Drawing::Point(230, 40);
			this->buttonHightSet->Name = L"buttonHightSet";
			this->buttonHightSet->Size = System::Drawing::Size(145, 26);
			this->buttonHightSet->TabIndex = 6;
			this->buttonHightSet->Text = L">> ????????? >>";
			this->buttonHightSet->UseVisualStyleBackColor = true;
			this->buttonHightSet->Click += gcnew System::EventHandler(this, &MyForm::buttonHightSet_Click);
			// 
			// labelHightSet
			// 
			this->labelHightSet->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelHightSet->Location = System::Drawing::Point(385, 40);
			this->labelHightSet->Name = L"labelHightSet";
			this->labelHightSet->Size = System::Drawing::Size(100, 26);
			this->labelHightSet->TabIndex = 7;
			this->labelHightSet->Text = L"1";
			this->labelHightSet->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// groupBoxHight
			// 
			this->groupBoxHight->Controls->Add(this->labelHightInput);
			this->groupBoxHight->Controls->Add(this->labelHightSet);
			this->groupBoxHight->Controls->Add(this->textBoxHightInput);
			this->groupBoxHight->Controls->Add(this->buttonHightSet);
			this->groupBoxHight->Location = System::Drawing::Point(0, 36);
			this->groupBoxHight->Name = L"groupBoxHight";
			this->groupBoxHight->Size = System::Drawing::Size(484, 100);
			this->groupBoxHight->TabIndex = 8;
			this->groupBoxHight->TabStop = false;
			this->groupBoxHight->Text = L"?????? ? ??????";
			// 
			// checkBoxServiceability
			// 
			this->checkBoxServiceability->AutoSize = true;
			this->checkBoxServiceability->Checked = true;
			this->checkBoxServiceability->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBoxServiceability->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->checkBoxServiceability->Location = System::Drawing::Point(24, 29);
			this->checkBoxServiceability->Name = L"checkBoxServiceability";
			this->checkBoxServiceability->Size = System::Drawing::Size(158, 21);
			this->checkBoxServiceability->TabIndex = 9;
			this->checkBoxServiceability->Text = L"?????????????????";
			this->checkBoxServiceability->UseVisualStyleBackColor = true;
			this->checkBoxServiceability->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBoxServiceability_CheckedChanged);
			// 
			// checkBoxPUI
			// 
			this->checkBoxPUI->AutoSize = true;
			this->checkBoxPUI->Checked = true;
			this->checkBoxPUI->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBoxPUI->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBoxPUI->Location = System::Drawing::Point(24, 56);
			this->checkBoxPUI->Name = L"checkBoxPUI";
			this->checkBoxPUI->Size = System::Drawing::Size(302, 21);
			this->checkBoxPUI->TabIndex = 10;
			this->checkBoxPUI->Text = L"?????????? ????????????? ??????????";
			this->checkBoxPUI->UseVisualStyleBackColor = true;
			this->checkBoxPUI->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBoxPUI_CheckedChanged);
			// 
			// groupBoxAnalog
			// 
			this->groupBoxAnalog->Controls->Add(this->checkBoxServiceability);
			this->groupBoxAnalog->Controls->Add(this->checkBoxPUI);
			this->groupBoxAnalog->Location = System::Drawing::Point(0, 142);
			this->groupBoxAnalog->Name = L"groupBoxAnalog";
			this->groupBoxAnalog->Size = System::Drawing::Size(484, 100);
			this->groupBoxAnalog->TabIndex = 11;
			this->groupBoxAnalog->TabStop = false;
			this->groupBoxAnalog->Text = L"?????????? ??????";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->checkBoxBanTest);
			this->groupBox1->Controls->Add(this->checkBoxControlRA);
			this->groupBox1->Controls->Add(this->checkBoxOffRadiation);
			this->groupBox1->Location = System::Drawing::Point(0, 248);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(484, 127);
			this->groupBox1->TabIndex = 12;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"??????? ???????";
			// 
			// checkBoxOffRadiation
			// 
			this->checkBoxOffRadiation->AutoSize = true;
			this->checkBoxOffRadiation->Enabled = false;
			this->checkBoxOffRadiation->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->checkBoxOffRadiation->Location = System::Drawing::Point(24, 29);
			this->checkBoxOffRadiation->Name = L"checkBoxOffRadiation";
			this->checkBoxOffRadiation->Size = System::Drawing::Size(184, 21);
			this->checkBoxOffRadiation->TabIndex = 11;
			this->checkBoxOffRadiation->Text = L"?????????? ?????????";
			this->checkBoxOffRadiation->UseVisualStyleBackColor = true;
			// 
			// checkBoxControlRA
			// 
			this->checkBoxControlRA->AutoSize = true;
			this->checkBoxControlRA->Enabled = false;
			this->checkBoxControlRA->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBoxControlRA->Location = System::Drawing::Point(24, 56);
			this->checkBoxControlRA->Name = L"checkBoxControlRA";
			this->checkBoxControlRA->Size = System::Drawing::Size(112, 21);
			this->checkBoxControlRA->TabIndex = 12;
			this->checkBoxControlRA->Text = L"???????? ??";
			this->checkBoxControlRA->UseVisualStyleBackColor = true;
			// 
			// checkBoxBanTest
			// 
			this->checkBoxBanTest->AutoSize = true;
			this->checkBoxBanTest->Enabled = false;
			this->checkBoxBanTest->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBoxBanTest->Location = System::Drawing::Point(24, 83);
			this->checkBoxBanTest->Name = L"checkBoxBanTest";
			this->checkBoxBanTest->Size = System::Drawing::Size(116, 21);
			this->checkBoxBanTest->TabIndex = 13;
			this->checkBoxBanTest->Text = L"?????? ?????";
			this->checkBoxBanTest->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(484, 413);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->groupBoxAnalog);
			this->Controls->Add(this->groupBoxHight);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"???????? ??????????????? ?-053";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->groupBoxHight->ResumeLayout(false);
			this->groupBoxHight->PerformLayout();
			this->groupBoxAnalog->ResumeLayout(false);
			this->groupBoxAnalog->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		public: void outThread();
		public: void inThread();

		private: System::Void com1ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void com2ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void com3ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void com4ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void com5ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void toolStripMenuItem1200_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void toolStripMenuItem2400_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void toolStripMenuItem4800_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void toolStripMenuItem9600_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void toolStripMenuItem19200_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void toolStripMenuItem38400_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void toolStripMenuItem57600_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void toolStripMenuItem115200_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void toConnectToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

		private: System::Void buttonHightSet_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void buttonHightSet_Click();
		private: System::Void textBoxHightInput_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e);
		private: System::Void textBoxHightInput_MouseWheel(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
		private: System::Void checkBoxServiceability_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
		private: System::Void checkBoxPUI_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
		private: System::Void checkBoxes_CheckedChanged();
	};

}