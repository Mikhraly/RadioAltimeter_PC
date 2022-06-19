#pragma once

#include <array>
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


	private: System::Windows::Forms::Button^ buttonOpenPort;
	private: System::Windows::Forms::Button^ buttonClosePort;
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
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem3;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem4;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem5;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem6;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem7;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem8;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem9;
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
			this->buttonOpenPort = (gcnew System::Windows::Forms::Button());
			this->buttonClosePort = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->portSettingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->portNameToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->com1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->com2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->com3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->com4 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->com5 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->portSpeedToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem4 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem5 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem6 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem7 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem8 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem9 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->portConnectToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->portNameStatusLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->portSpeedStatusLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->isConnectStatusLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->menuStrip1->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// buttonOpenPort
			// 
			this->buttonOpenPort->Location = System::Drawing::Point(155, 67);
			this->buttonOpenPort->Name = L"buttonOpenPort";
			this->buttonOpenPort->Size = System::Drawing::Size(100, 30);
			this->buttonOpenPort->TabIndex = 0;
			this->buttonOpenPort->Text = L"OpenPort";
			this->buttonOpenPort->UseVisualStyleBackColor = true;
			this->buttonOpenPort->Click += gcnew System::EventHandler(this, &MyForm::buttonOpenPort_Click);
			// 
			// buttonClosePort
			// 
			this->buttonClosePort->Location = System::Drawing::Point(261, 67);
			this->buttonClosePort->Name = L"buttonClosePort";
			this->buttonClosePort->Size = System::Drawing::Size(100, 30);
			this->buttonClosePort->TabIndex = 1;
			this->buttonClosePort->Text = L"ClosePort";
			this->buttonClosePort->UseVisualStyleBackColor = true;
			this->buttonClosePort->Click += gcnew System::EventHandler(this, &MyForm::buttonClosePort_Click);
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
			this->portSettingsToolStripMenuItem->Size = System::Drawing::Size(112, 20);
			this->portSettingsToolStripMenuItem->Text = L"Настройки связи";
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
			this->com1->Size = System::Drawing::Size(180, 22);
			this->com1->Text = L"COM1";
			this->com1->Click += gcnew System::EventHandler(this, &MyForm::com1_Click);
			// 
			// com2
			// 
			this->com2->Name = L"com2";
			this->com2->Size = System::Drawing::Size(108, 22);
			this->com2->Text = L"COM2";
			// 
			// com3
			// 
			this->com3->Name = L"com3";
			this->com3->Size = System::Drawing::Size(108, 22);
			this->com3->Text = L"COM3";
			// 
			// com4
			// 
			this->com4->Name = L"com4";
			this->com4->Size = System::Drawing::Size(108, 22);
			this->com4->Text = L"COM4";
			// 
			// com5
			// 
			this->com5->Name = L"com5";
			this->com5->Size = System::Drawing::Size(108, 22);
			this->com5->Text = L"COM5";
			// 
			// portSpeedToolStripMenuItem
			// 
			this->portSpeedToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {
				this->toolStripMenuItem2,
					this->toolStripMenuItem3, this->toolStripMenuItem4, this->toolStripMenuItem5, this->toolStripMenuItem6, this->toolStripMenuItem7,
					this->toolStripMenuItem8, this->toolStripMenuItem9
			});
			this->portSpeedToolStripMenuItem->Name = L"portSpeedToolStripMenuItem";
			this->portSpeedToolStripMenuItem->Size = System::Drawing::Size(144, 22);
			this->portSpeedToolStripMenuItem->Text = L"Скорость";
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(110, 22);
			this->toolStripMenuItem2->Text = L"1200";
			// 
			// toolStripMenuItem3
			// 
			this->toolStripMenuItem3->Name = L"toolStripMenuItem3";
			this->toolStripMenuItem3->Size = System::Drawing::Size(110, 22);
			this->toolStripMenuItem3->Text = L"2400";
			// 
			// toolStripMenuItem4
			// 
			this->toolStripMenuItem4->Name = L"toolStripMenuItem4";
			this->toolStripMenuItem4->Size = System::Drawing::Size(110, 22);
			this->toolStripMenuItem4->Text = L"4800";
			// 
			// toolStripMenuItem5
			// 
			this->toolStripMenuItem5->Name = L"toolStripMenuItem5";
			this->toolStripMenuItem5->Size = System::Drawing::Size(110, 22);
			this->toolStripMenuItem5->Text = L"9600";
			// 
			// toolStripMenuItem6
			// 
			this->toolStripMenuItem6->Name = L"toolStripMenuItem6";
			this->toolStripMenuItem6->Size = System::Drawing::Size(110, 22);
			this->toolStripMenuItem6->Text = L"19200";
			// 
			// toolStripMenuItem7
			// 
			this->toolStripMenuItem7->Name = L"toolStripMenuItem7";
			this->toolStripMenuItem7->Size = System::Drawing::Size(110, 22);
			this->toolStripMenuItem7->Text = L"38400";
			// 
			// toolStripMenuItem8
			// 
			this->toolStripMenuItem8->Name = L"toolStripMenuItem8";
			this->toolStripMenuItem8->Size = System::Drawing::Size(110, 22);
			this->toolStripMenuItem8->Text = L"57600";
			// 
			// toolStripMenuItem9
			// 
			this->toolStripMenuItem9->Name = L"toolStripMenuItem9";
			this->toolStripMenuItem9->Size = System::Drawing::Size(110, 22);
			this->toolStripMenuItem9->Text = L"115200";
			// 
			// portConnectToolStripMenuItem
			// 
			this->portConnectToolStripMenuItem->Name = L"portConnectToolStripMenuItem";
			this->portConnectToolStripMenuItem->Size = System::Drawing::Size(144, 22);
			this->portConnectToolStripMenuItem->Text = L"Подключить";
			// 
			// statusStrip1
			// 
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
			this->Controls->Add(this->buttonOpenPort);
			this->Controls->Add(this->buttonClosePort);
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

	private: System::Void buttonOpenPort_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonClosePort_Click(System::Object^ sender, System::EventArgs^ e);

	public: void outThread();

	private: System::Void com1_Click(System::Object^ sender, System::EventArgs^ e);
	};



}