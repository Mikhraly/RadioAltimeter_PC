#pragma once

#include <array>
#include <string>
#include "Port.h"

namespace ComPort {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO::Ports;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void) {
			InitializeComponent();
		}
		
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm() {
			if (components) {
				delete components;
			}
		}




	private: SerialPort^ mySerialPort = gcnew SerialPort("COM1", 115200, Parity::None, 8, StopBits::One);
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ portSettingsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ portNameToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ portSpeedToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ com1;
	private: System::Windows::Forms::ToolStripMenuItem^ com2;
	private: System::Windows::Forms::ToolStripMenuItem^ com3;
	private: System::Windows::Forms::ToolStripMenuItem^ com4;
	private: System::Windows::Forms::ToolStripMenuItem^ com5;
	private: System::Windows::Forms::ToolStripMenuItem^ speed1200;
	private: System::Windows::Forms::ToolStripMenuItem^ speed2400;
	private: System::Windows::Forms::ToolStripMenuItem^ speed4800;
	private: System::Windows::Forms::ToolStripMenuItem^ speed9600;
	private: System::Windows::Forms::ToolStripMenuItem^ speed19200;
	private: System::Windows::Forms::ToolStripMenuItem^ speed38400;
	private: System::Windows::Forms::ToolStripMenuItem^ speed57600;
	private: System::Windows::Forms::ToolStripMenuItem^ speed115200;








	private: System::Windows::Forms::ToolStripMenuItem^ portConnectToolStripMenuItem;
	private: System::Windows::Forms::StatusStrip^ statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^ portNameStatusLabel;
	private: System::Windows::Forms::ToolStripStatusLabel^ portSpeedStatusLabel;
	private: System::Windows::Forms::ToolStripStatusLabel^ isConnectStatusLabel;






		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::IContainer^ components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->portSettingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->portNameToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->com1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->com2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->com3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->com4 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->com5 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->portSpeedToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->speed1200 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->speed2400 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->speed4800 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->speed9600 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->speed19200 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->speed38400 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->speed57600 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->speed115200 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->portConnectToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->portNameStatusLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->portSpeedStatusLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->isConnectStatusLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->menuStrip1->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->portSettingsToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(500, 24);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// portSettingsToolStripMenuItem
			// 
			this->portSettingsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->portNameToolStripMenuItem,
					this->portSpeedToolStripMenuItem, this->portConnectToolStripMenuItem
			});
			this->portSettingsToolStripMenuItem->Name = L"portSettingsToolStripMenuItem";
			this->portSettingsToolStripMenuItem->Size = System::Drawing::Size(50, 20);
			this->portSettingsToolStripMenuItem->Text = L"Связь";
			// 
			// portNameToolStripMenuItem
			// 
			this->portNameToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->com1,
					this->com2, this->com3, this->com4, this->com5
			});
			this->portNameToolStripMenuItem->Name = L"portNameToolStripMenuItem";
			this->portNameToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->portNameToolStripMenuItem->Text = L"Порт";
			// 
			// com1
			// 
			this->com1->Name = L"com1";
			this->com1->Size = System::Drawing::Size(108, 22);
			this->com1->Text = L"COM1";
			this->com1->Click += gcnew System::EventHandler(this, &MyForm::com1_Click);
			// 
			// com2
			// 
			this->com2->Name = L"com2";
			this->com2->Size = System::Drawing::Size(108, 22);
			this->com2->Text = L"COM2";
			this->com2->Click += gcnew System::EventHandler(this, &MyForm::com2_Click);
			// 
			// com3
			// 
			this->com3->Name = L"com3";
			this->com3->Size = System::Drawing::Size(108, 22);
			this->com3->Text = L"COM3";
			this->com3->Click += gcnew System::EventHandler(this, &MyForm::com3_Click);
			// 
			// com4
			// 
			this->com4->Name = L"com4";
			this->com4->Size = System::Drawing::Size(108, 22);
			this->com4->Text = L"COM4";
			this->com4->Click += gcnew System::EventHandler(this, &MyForm::com4_Click);
			// 
			// com5
			// 
			this->com5->Name = L"com5";
			this->com5->Size = System::Drawing::Size(108, 22);
			this->com5->Text = L"COM5";
			this->com5->Click += gcnew System::EventHandler(this, &MyForm::com5_Click);
			// 
			// portSpeedToolStripMenuItem
			// 
			this->portSpeedToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {
				this->speed1200,
					this->speed2400, this->speed4800, this->speed9600, this->speed19200, this->speed38400, this->speed57600, this->speed115200
			});
			this->portSpeedToolStripMenuItem->Name = L"portSpeedToolStripMenuItem";
			this->portSpeedToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->portSpeedToolStripMenuItem->Text = L"Скорость";
			// 
			// speed1200
			// 
			this->speed1200->Name = L"speed1200";
			this->speed1200->Size = System::Drawing::Size(110, 22);
			this->speed1200->Text = L"1200";
			this->speed1200->Click += gcnew System::EventHandler(this, &MyForm::speed1200_Click);
			// 
			// speed2400
			// 
			this->speed2400->Name = L"speed2400";
			this->speed2400->Size = System::Drawing::Size(110, 22);
			this->speed2400->Text = L"2400";
			this->speed2400->Click += gcnew System::EventHandler(this, &MyForm::speed2400_Click);
			// 
			// speed4800
			// 
			this->speed4800->Name = L"speed4800";
			this->speed4800->Size = System::Drawing::Size(110, 22);
			this->speed4800->Text = L"4800";
			this->speed4800->Click += gcnew System::EventHandler(this, &MyForm::speed4800_Click);
			// 
			// speed9600
			// 
			this->speed9600->Name = L"speed9600";
			this->speed9600->Size = System::Drawing::Size(110, 22);
			this->speed9600->Text = L"9600";
			this->speed9600->Click += gcnew System::EventHandler(this, &MyForm::speed9600_Click);
			// 
			// speed19200
			// 
			this->speed19200->Name = L"speed19200";
			this->speed19200->Size = System::Drawing::Size(110, 22);
			this->speed19200->Text = L"19200";
			this->speed19200->Click += gcnew System::EventHandler(this, &MyForm::speed19200_Click);
			// 
			// speed38400
			// 
			this->speed38400->Name = L"speed38400";
			this->speed38400->Size = System::Drawing::Size(110, 22);
			this->speed38400->Text = L"38400";
			this->speed38400->Click += gcnew System::EventHandler(this, &MyForm::speed38400_Click);
			// 
			// speed57600
			// 
			this->speed57600->Name = L"speed57600";
			this->speed57600->Size = System::Drawing::Size(110, 22);
			this->speed57600->Text = L"57600";
			this->speed57600->Click += gcnew System::EventHandler(this, &MyForm::speed57600_Click);
			// 
			// speed115200
			// 
			this->speed115200->Name = L"speed115200";
			this->speed115200->Size = System::Drawing::Size(110, 22);
			this->speed115200->Text = L"115200";
			this->speed115200->Click += gcnew System::EventHandler(this, &MyForm::speed115200_Click);
			// 
			// portConnectToolStripMenuItem
			// 
			this->portConnectToolStripMenuItem->Name = L"portConnectToolStripMenuItem";
			this->portConnectToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->portConnectToolStripMenuItem->Text = L"Подключить";
			this->portConnectToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::portConnectToolStripMenuItem_Click);
			// 
			// statusStrip1
			// 
			this->statusStrip1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(205)), static_cast<System::Int32>(static_cast<System::Byte>(215)),
				static_cast<System::Int32>(static_cast<System::Byte>(61)));
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->portNameStatusLabel,
					this->portSpeedStatusLabel, this->isConnectStatusLabel
			});
			this->statusStrip1->Location = System::Drawing::Point(0, 378);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(500, 22);
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
			this->isConnectStatusLabel->Text = L"Не подключено!";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(500, 400);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public: void outThread();

	private: System::Void com1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void com2_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void com3_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void com4_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void com5_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void speed1200_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void speed2400_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void speed4800_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void speed9600_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void speed19200_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void speed38400_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void speed57600_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void speed115200_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void portConnectToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
};



}