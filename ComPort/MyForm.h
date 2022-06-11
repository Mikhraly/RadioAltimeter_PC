#pragma once

namespace ComPort {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO::Ports;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}


	private:
		System::Windows::Forms::Button^ buttonOpenPort;


		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::IContainer^ components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->buttonOpenPort = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// buttonOpenPort
			// 
			this->buttonOpenPort->Location = System::Drawing::Point(96, 112);
			this->buttonOpenPort->Name = L"buttonOpenPort";
			this->buttonOpenPort->Size = System::Drawing::Size(100, 30);
			this->buttonOpenPort->TabIndex = 0;
			this->buttonOpenPort->Text = L"OpenPort";
			this->buttonOpenPort->UseVisualStyleBackColor = true;
			this->buttonOpenPort->Click += gcnew System::EventHandler(this, &MyForm::buttonOpenPort_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->buttonOpenPort);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void buttonOpenPort_Click(System::Object^ sender, System::EventArgs^ e);
	};



}