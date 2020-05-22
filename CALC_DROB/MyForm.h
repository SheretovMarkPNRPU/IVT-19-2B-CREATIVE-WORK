#pragma once
#include <cmath>
#include <vector>
namespace CALCDROB {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	struct operation
	{
		Decimal ch1;
		Decimal zn1;
		Decimal cel1;
		
		Decimal ch2;
		Decimal zn2;
		Decimal cel2;

		Decimal nstn;
		int opt;
	};

	

	//ГЛОБАЛЫ
	bool CalcType;								//false - обычн, true - с целой частью
	bool nightTheme;							//Если false - дневная тема, если true ночная
	bool isStart;								//true - начало, false - далее
	int optype;									//тип операции
	int optypebuff;
	double subuff;
	System::Decimal buffZN1;					//Буфер, чтобы не было деления на 0
	operation lOperation;
	//

	/// <summary>
	/// Сводка для MyForm
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
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::NumericUpDown^ CH1;
	protected:
	private: System::Windows::Forms::NumericUpDown^ ZN1;


	private: System::Windows::Forms::Button^ BPLUS;
	private: System::Windows::Forms::Button^ BMINUS;
	private: System::Windows::Forms::Button^ BMULT;
	private: System::Windows::Forms::Button^ BDIV;
	private: System::Windows::Forms::Button^ BN;
	private: System::Windows::Forms::Button^ BSOKR;
	private: System::Windows::Forms::Button^ BPM;
	private: System::Windows::Forms::Button^ BZNCH;
	private: System::Windows::Forms::Button^ BLOPER;



	private: System::Windows::Forms::Label^ LDOUBLE1;
	private: System::Windows::Forms::Button^ BTCH;
	private: System::Windows::Forms::NumericUpDown^ CEL1;
	private: System::Windows::Forms::NumericUpDown^ CH2;
	private: System::Windows::Forms::NumericUpDown^ CEL2;
	private: System::Windows::Forms::NumericUpDown^ ZN2;
	private: System::Windows::Forms::Label^ LZNAK;
	private: System::Windows::Forms::NumericUpDown^ NSTN;
	private: System::Windows::Forms::Label^ LSTN;
	private: System::Windows::Forms::Button^ BAC;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ BTHEMECHANGER;
	private: System::Windows::Forms::Label^ label3;


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->CH1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->ZN1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->BPLUS = (gcnew System::Windows::Forms::Button());
			this->BMINUS = (gcnew System::Windows::Forms::Button());
			this->BMULT = (gcnew System::Windows::Forms::Button());
			this->BDIV = (gcnew System::Windows::Forms::Button());
			this->BN = (gcnew System::Windows::Forms::Button());
			this->BSOKR = (gcnew System::Windows::Forms::Button());
			this->BPM = (gcnew System::Windows::Forms::Button());
			this->BZNCH = (gcnew System::Windows::Forms::Button());
			this->BLOPER = (gcnew System::Windows::Forms::Button());
			this->LDOUBLE1 = (gcnew System::Windows::Forms::Label());
			this->BTCH = (gcnew System::Windows::Forms::Button());
			this->CEL1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->CH2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->CEL2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->ZN2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->LZNAK = (gcnew System::Windows::Forms::Label());
			this->NSTN = (gcnew System::Windows::Forms::NumericUpDown());
			this->LSTN = (gcnew System::Windows::Forms::Label());
			this->BAC = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->BTHEMECHANGER = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CH1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ZN1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CEL1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CH2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CEL2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ZN2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NSTN))->BeginInit();
			this->SuspendLayout();
			// 
			// CH1
			// 
			this->CH1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(216)), static_cast<System::Int32>(static_cast<System::Byte>(217)),
				static_cast<System::Int32>(static_cast<System::Byte>(221)));
			this->CH1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->CH1->Cursor = System::Windows::Forms::Cursors::Default;
			this->CH1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(75)), static_cast<System::Int32>(static_cast<System::Byte>(74)),
				static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->CH1->Location = System::Drawing::Point(85, 29);
			this->CH1->Margin = System::Windows::Forms::Padding(6, 7, 6, 7);
			this->CH1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4096, 0, 0, 0 });
			this->CH1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4096, 0, 0, System::Int32::MinValue });
			this->CH1->Name = L"CH1";
			this->CH1->Size = System::Drawing::Size(104, 31);
			this->CH1->TabIndex = 0;
			this->CH1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->CH1->UpDownAlign = System::Windows::Forms::LeftRightAlignment::Left;
			this->CH1->ValueChanged += gcnew System::EventHandler(this, &MyForm::CH1_VALCH);
			// 
			// ZN1
			// 
			this->ZN1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(216)), static_cast<System::Int32>(static_cast<System::Byte>(217)),
				static_cast<System::Int32>(static_cast<System::Byte>(221)));
			this->ZN1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->ZN1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(75)), static_cast<System::Int32>(static_cast<System::Byte>(74)),
				static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->ZN1->Location = System::Drawing::Point(85, 62);
			this->ZN1->Margin = System::Windows::Forms::Padding(6, 7, 6, 7);
			this->ZN1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4096, 0, 0, 0 });
			this->ZN1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4096, 0, 0, System::Int32::MinValue });
			this->ZN1->Name = L"ZN1";
			this->ZN1->Size = System::Drawing::Size(104, 31);
			this->ZN1->TabIndex = 0;
			this->ZN1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->ZN1->UpDownAlign = System::Windows::Forms::LeftRightAlignment::Left;
			this->ZN1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->ZN1->ValueChanged += gcnew System::EventHandler(this, &MyForm::ZN1_VALCH);
			// 
			// BPLUS
			// 
			this->BPLUS->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(194)), static_cast<System::Int32>(static_cast<System::Byte>(195)),
				static_cast<System::Int32>(static_cast<System::Byte>(199)));
			this->BPLUS->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BPLUS->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->BPLUS->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(75)), static_cast<System::Int32>(static_cast<System::Byte>(74)),
				static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->BPLUS->Location = System::Drawing::Point(0, 330);
			this->BPLUS->Name = L"BPLUS";
			this->BPLUS->Size = System::Drawing::Size(50, 40);
			this->BPLUS->TabIndex = 1;
			this->BPLUS->Text = L"+";
			this->BPLUS->UseVisualStyleBackColor = false;
			this->BPLUS->Click += gcnew System::EventHandler(this, &MyForm::BPLUS_Click);
			// 
			// BMINUS
			// 
			this->BMINUS->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(194)), static_cast<System::Int32>(static_cast<System::Byte>(195)),
				static_cast<System::Int32>(static_cast<System::Byte>(199)));
			this->BMINUS->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BMINUS->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->BMINUS->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(75)), static_cast<System::Int32>(static_cast<System::Byte>(74)),
				static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->BMINUS->Location = System::Drawing::Point(51, 330);
			this->BMINUS->Name = L"BMINUS";
			this->BMINUS->Size = System::Drawing::Size(50, 40);
			this->BMINUS->TabIndex = 1;
			this->BMINUS->Text = L"-";
			this->BMINUS->UseVisualStyleBackColor = false;
			this->BMINUS->Click += gcnew System::EventHandler(this, &MyForm::BMINUS_Click);
			// 
			// BMULT
			// 
			this->BMULT->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(194)), static_cast<System::Int32>(static_cast<System::Byte>(195)),
				static_cast<System::Int32>(static_cast<System::Byte>(199)));
			this->BMULT->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BMULT->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 18, System::Drawing::FontStyle::Bold));
			this->BMULT->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(75)), static_cast<System::Int32>(static_cast<System::Byte>(74)),
				static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->BMULT->Location = System::Drawing::Point(0, 371);
			this->BMULT->Name = L"BMULT";
			this->BMULT->Size = System::Drawing::Size(50, 40);
			this->BMULT->TabIndex = 1;
			this->BMULT->Text = L"*";
			this->BMULT->UseVisualStyleBackColor = false;
			this->BMULT->Click += gcnew System::EventHandler(this, &MyForm::BMULT_Click);
			// 
			// BDIV
			// 
			this->BDIV->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(194)), static_cast<System::Int32>(static_cast<System::Byte>(195)),
				static_cast<System::Int32>(static_cast<System::Byte>(199)));
			this->BDIV->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BDIV->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->BDIV->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(75)), static_cast<System::Int32>(static_cast<System::Byte>(74)),
				static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->BDIV->Location = System::Drawing::Point(51, 371);
			this->BDIV->Name = L"BDIV";
			this->BDIV->Size = System::Drawing::Size(50, 40);
			this->BDIV->TabIndex = 1;
			this->BDIV->Text = L"/";
			this->BDIV->UseVisualStyleBackColor = false;
			this->BDIV->Click += gcnew System::EventHandler(this, &MyForm::BDIV_Click);
			// 
			// BN
			// 
			this->BN->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(194)), static_cast<System::Int32>(static_cast<System::Byte>(195)),
				static_cast<System::Int32>(static_cast<System::Byte>(199)));
			this->BN->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BN->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->BN->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(75)), static_cast<System::Int32>(static_cast<System::Byte>(74)),
				static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->BN->Location = System::Drawing::Point(102, 330);
			this->BN->Name = L"BN";
			this->BN->Size = System::Drawing::Size(50, 40);
			this->BN->TabIndex = 1;
			this->BN->Text = L"^n";
			this->BN->UseVisualStyleBackColor = false;
			this->BN->Click += gcnew System::EventHandler(this, &MyForm::BN_Click);
			// 
			// BSOKR
			// 
			this->BSOKR->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(194)), static_cast<System::Int32>(static_cast<System::Byte>(195)),
				static_cast<System::Int32>(static_cast<System::Byte>(199)));
			this->BSOKR->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BSOKR->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 14, System::Drawing::FontStyle::Bold));
			this->BSOKR->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(75)), static_cast<System::Int32>(static_cast<System::Byte>(74)),
				static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->BSOKR->Location = System::Drawing::Point(0, 412);
			this->BSOKR->Name = L"BSOKR";
			this->BSOKR->Size = System::Drawing::Size(50, 40);
			this->BSOKR->TabIndex = 1;
			this->BSOKR->Text = L"RE";
			this->BSOKR->UseVisualStyleBackColor = false;
			this->BSOKR->Click += gcnew System::EventHandler(this, &MyForm::BSOKR_Click);
			// 
			// BPM
			// 
			this->BPM->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(194)), static_cast<System::Int32>(static_cast<System::Byte>(195)),
				static_cast<System::Int32>(static_cast<System::Byte>(199)));
			this->BPM->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BPM->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->BPM->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(75)), static_cast<System::Int32>(static_cast<System::Byte>(74)),
				static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->BPM->Location = System::Drawing::Point(102, 371);
			this->BPM->Name = L"BPM";
			this->BPM->Size = System::Drawing::Size(50, 40);
			this->BPM->TabIndex = 1;
			this->BPM->Text = L"+/-";
			this->BPM->UseVisualStyleBackColor = false;
			this->BPM->Click += gcnew System::EventHandler(this, &MyForm::BPM_Click);
			// 
			// BZNCH
			// 
			this->BZNCH->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(194)), static_cast<System::Int32>(static_cast<System::Byte>(195)),
				static_cast<System::Int32>(static_cast<System::Byte>(199)));
			this->BZNCH->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->BZNCH->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BZNCH->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 9, System::Drawing::FontStyle::Bold));
			this->BZNCH->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(75)), static_cast<System::Int32>(static_cast<System::Byte>(74)),
				static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->BZNCH->Location = System::Drawing::Point(51, 412);
			this->BZNCH->Name = L"BZNCH";
			this->BZNCH->Size = System::Drawing::Size(50, 40);
			this->BZNCH->TabIndex = 1;
			this->BZNCH->Text = L"-><-";
			this->BZNCH->UseVisualStyleBackColor = false;
			this->BZNCH->Click += gcnew System::EventHandler(this, &MyForm::BZNCH_Click);
			// 
			// BLOPER
			// 
			this->BLOPER->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(194)), static_cast<System::Int32>(static_cast<System::Byte>(195)),
				static_cast<System::Int32>(static_cast<System::Byte>(199)));
			this->BLOPER->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->BLOPER->Enabled = false;
			this->BLOPER->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BLOPER->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 16, System::Drawing::FontStyle::Bold));
			this->BLOPER->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(75)), static_cast<System::Int32>(static_cast<System::Byte>(74)),
				static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->BLOPER->Location = System::Drawing::Point(102, 412);
			this->BLOPER->Name = L"BLOPER";
			this->BLOPER->Size = System::Drawing::Size(50, 40);
			this->BLOPER->TabIndex = 1;
			this->BLOPER->Text = L"<-";
			this->BLOPER->UseVisualStyleBackColor = false;
			this->BLOPER->Click += gcnew System::EventHandler(this, &MyForm::BLOPER_Click);
			// 
			// LDOUBLE1
			// 
			this->LDOUBLE1->AutoSize = true;
			this->LDOUBLE1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->LDOUBLE1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(75)), static_cast<System::Int32>(static_cast<System::Byte>(74)),
				static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->LDOUBLE1->Location = System::Drawing::Point(42, 297);
			this->LDOUBLE1->MaximumSize = System::Drawing::Size(150, 0);
			this->LDOUBLE1->Name = L"LDOUBLE1";
			this->LDOUBLE1->Size = System::Drawing::Size(24, 30);
			this->LDOUBLE1->TabIndex = 2;
			this->LDOUBLE1->Text = L"0";
			this->LDOUBLE1->UseMnemonic = false;
			// 
			// BTCH
			// 
			this->BTCH->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(194)), static_cast<System::Int32>(static_cast<System::Byte>(195)),
				static_cast<System::Int32>(static_cast<System::Byte>(199)));
			this->BTCH->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BTCH->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 10, System::Drawing::FontStyle::Bold));
			this->BTCH->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(75)), static_cast<System::Int32>(static_cast<System::Byte>(74)),
				static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->BTCH->Location = System::Drawing::Point(153, 371);
			this->BTCH->Name = L"BTCH";
			this->BTCH->Size = System::Drawing::Size(50, 40);
			this->BTCH->TabIndex = 1;
			this->BTCH->Text = L"TCH";
			this->BTCH->UseVisualStyleBackColor = false;
			this->BTCH->Click += gcnew System::EventHandler(this, &MyForm::BTCH_Click);
			// 
			// CEL1
			// 
			this->CEL1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(216)), static_cast<System::Int32>(static_cast<System::Byte>(217)),
				static_cast<System::Int32>(static_cast<System::Byte>(221)));
			this->CEL1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->CEL1->Enabled = false;
			this->CEL1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(75)), static_cast<System::Int32>(static_cast<System::Byte>(74)),
				static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->CEL1->Location = System::Drawing::Point(3, 37);
			this->CEL1->Margin = System::Windows::Forms::Padding(6, 7, 6, 7);
			this->CEL1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4096, 0, 0, 0 });
			this->CEL1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4096, 0, 0, System::Int32::MinValue });
			this->CEL1->Name = L"CEL1";
			this->CEL1->Size = System::Drawing::Size(78, 31);
			this->CEL1->TabIndex = 0;
			this->CEL1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->CEL1->UpDownAlign = System::Windows::Forms::LeftRightAlignment::Left;
			this->CEL1->Visible = false;
			this->CEL1->ValueChanged += gcnew System::EventHandler(this, &MyForm::CEL1_VALCH);
			// 
			// CH2
			// 
			this->CH2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(216)), static_cast<System::Int32>(static_cast<System::Byte>(217)),
				static_cast<System::Int32>(static_cast<System::Byte>(221)));
			this->CH2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->CH2->Enabled = false;
			this->CH2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(75)), static_cast<System::Int32>(static_cast<System::Byte>(74)),
				static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->CH2->Location = System::Drawing::Point(85, 145);
			this->CH2->Margin = System::Windows::Forms::Padding(6, 7, 6, 7);
			this->CH2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4096, 0, 0, 0 });
			this->CH2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4096, 0, 0, System::Int32::MinValue });
			this->CH2->Name = L"CH2";
			this->CH2->Size = System::Drawing::Size(104, 31);
			this->CH2->TabIndex = 0;
			this->CH2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->CH2->UpDownAlign = System::Windows::Forms::LeftRightAlignment::Left;
			this->CH2->Visible = false;
			this->CH2->ValueChanged += gcnew System::EventHandler(this, &MyForm::CH2_VALCH);
			// 
			// CEL2
			// 
			this->CEL2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(216)), static_cast<System::Int32>(static_cast<System::Byte>(217)),
				static_cast<System::Int32>(static_cast<System::Byte>(221)));
			this->CEL2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->CEL2->Enabled = false;
			this->CEL2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(75)), static_cast<System::Int32>(static_cast<System::Byte>(74)),
				static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->CEL2->Location = System::Drawing::Point(3, 156);
			this->CEL2->Margin = System::Windows::Forms::Padding(6, 7, 6, 7);
			this->CEL2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4096, 0, 0, 0 });
			this->CEL2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4096, 0, 0, System::Int32::MinValue });
			this->CEL2->Name = L"CEL2";
			this->CEL2->Size = System::Drawing::Size(78, 31);
			this->CEL2->TabIndex = 0;
			this->CEL2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->CEL2->UpDownAlign = System::Windows::Forms::LeftRightAlignment::Left;
			this->CEL2->Visible = false;
			this->CEL2->ValueChanged += gcnew System::EventHandler(this, &MyForm::CEL2_VALCH);
			// 
			// ZN2
			// 
			this->ZN2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(216)), static_cast<System::Int32>(static_cast<System::Byte>(217)),
				static_cast<System::Int32>(static_cast<System::Byte>(221)));
			this->ZN2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->ZN2->Enabled = false;
			this->ZN2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(75)), static_cast<System::Int32>(static_cast<System::Byte>(74)),
				static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->ZN2->Location = System::Drawing::Point(85, 182);
			this->ZN2->Margin = System::Windows::Forms::Padding(6, 7, 6, 7);
			this->ZN2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4096, 0, 0, 0 });
			this->ZN2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4096, 0, 0, System::Int32::MinValue });
			this->ZN2->Name = L"ZN2";
			this->ZN2->Size = System::Drawing::Size(104, 31);
			this->ZN2->TabIndex = 0;
			this->ZN2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->ZN2->UpDownAlign = System::Windows::Forms::LeftRightAlignment::Left;
			this->ZN2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->ZN2->Visible = false;
			this->ZN2->ValueChanged += gcnew System::EventHandler(this, &MyForm::ZN2_VALCH);
			// 
			// LZNAK
			// 
			this->LZNAK->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LZNAK->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(75)), static_cast<System::Int32>(static_cast<System::Byte>(74)),
				static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->LZNAK->Location = System::Drawing::Point(12, 88);
			this->LZNAK->Name = L"LZNAK";
			this->LZNAK->Size = System::Drawing::Size(27, 39);
			this->LZNAK->TabIndex = 3;
			this->LZNAK->Text = L"+";
			this->LZNAK->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->LZNAK->Visible = false;
			// 
			// NSTN
			// 
			this->NSTN->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(216)), static_cast<System::Int32>(static_cast<System::Byte>(217)),
				static_cast<System::Int32>(static_cast<System::Byte>(221)));
			this->NSTN->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->NSTN->Enabled = false;
			this->NSTN->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(75)), static_cast<System::Int32>(static_cast<System::Byte>(74)),
				static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->NSTN->Location = System::Drawing::Point(46, 227);
			this->NSTN->Margin = System::Windows::Forms::Padding(6, 7, 6, 7);
			this->NSTN->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4096, 0, 0, 0 });
			this->NSTN->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4096, 0, 0, System::Int32::MinValue });
			this->NSTN->Name = L"NSTN";
			this->NSTN->Size = System::Drawing::Size(78, 31);
			this->NSTN->TabIndex = 0;
			this->NSTN->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->NSTN->UpDownAlign = System::Windows::Forms::LeftRightAlignment::Left;
			this->NSTN->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->NSTN->Visible = false;
			this->NSTN->ValueChanged += gcnew System::EventHandler(this, &MyForm::NSTN_VALCH);
			// 
			// LSTN
			// 
			this->LSTN->AutoSize = true;
			this->LSTN->Enabled = false;
			this->LSTN->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(75)), static_cast<System::Int32>(static_cast<System::Byte>(74)),
				static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->LSTN->Location = System::Drawing::Point(12, 247);
			this->LSTN->Name = L"LSTN";
			this->LSTN->Size = System::Drawing::Size(39, 30);
			this->LSTN->TabIndex = 2;
			this->LSTN->Text = L"n^";
			this->LSTN->UseMnemonic = false;
			this->LSTN->Visible = false;
			// 
			// BAC
			// 
			this->BAC->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(194)), static_cast<System::Int32>(static_cast<System::Byte>(195)),
				static_cast<System::Int32>(static_cast<System::Byte>(199)));
			this->BAC->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->BAC->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BAC->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->BAC->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(75)), static_cast<System::Int32>(static_cast<System::Byte>(74)),
				static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->BAC->Location = System::Drawing::Point(153, 330);
			this->BAC->Name = L"BAC";
			this->BAC->Size = System::Drawing::Size(50, 40);
			this->BAC->TabIndex = 1;
			this->BAC->Text = L"AC";
			this->BAC->UseVisualStyleBackColor = false;
			this->BAC->Click += gcnew System::EventHandler(this, &MyForm::BAC_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(75)), static_cast<System::Int32>(static_cast<System::Byte>(74)),
				static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->label1->Location = System::Drawing::Point(59, 34);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(148, 30);
			this->label1->TabIndex = 4;
			this->label1->Text = L"_______________";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(75)), static_cast<System::Int32>(static_cast<System::Byte>(74)),
				static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->label2->Location = System::Drawing::Point(59, 154);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(148, 30);
			this->label2->TabIndex = 4;
			this->label2->Text = L"_______________";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label2->Visible = false;
			// 
			// BTHEMECHANGER
			// 
			this->BTHEMECHANGER->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(194)), static_cast<System::Int32>(static_cast<System::Byte>(195)),
				static_cast<System::Int32>(static_cast<System::Byte>(199)));
			this->BTHEMECHANGER->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BTHEMECHANGER->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 18, System::Drawing::FontStyle::Bold));
			this->BTHEMECHANGER->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(75)), static_cast<System::Int32>(static_cast<System::Byte>(74)),
				static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->BTHEMECHANGER->Location = System::Drawing::Point(153, 412);
			this->BTHEMECHANGER->Name = L"BTHEMECHANGER";
			this->BTHEMECHANGER->Size = System::Drawing::Size(50, 40);
			this->BTHEMECHANGER->TabIndex = 1;
			this->BTHEMECHANGER->Text = L"T";
			this->BTHEMECHANGER->UseVisualStyleBackColor = false;
			this->BTHEMECHANGER->Click += gcnew System::EventHandler(this, &MyForm::BTHEMECH_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(188)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(75)), static_cast<System::Int32>(static_cast<System::Byte>(74)),
				static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->label3->Location = System::Drawing::Point(12, 297);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(27, 30);
			this->label3->TabIndex = 2;
			this->label3->Text = L"=";
			this->label3->UseMnemonic = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 30);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(188)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->ClientSize = System::Drawing::Size(204, 451);
			this->Controls->Add(this->LZNAK);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->BAC);
			this->Controls->Add(this->BLOPER);
			this->Controls->Add(this->BZNCH);
			this->Controls->Add(this->BPM);
			this->Controls->Add(this->BSOKR);
			this->Controls->Add(this->BN);
			this->Controls->Add(this->BDIV);
			this->Controls->Add(this->BMULT);
			this->Controls->Add(this->BMINUS);
			this->Controls->Add(this->BTHEMECHANGER);
			this->Controls->Add(this->BTCH);
			this->Controls->Add(this->BPLUS);
			this->Controls->Add(this->NSTN);
			this->Controls->Add(this->ZN2);
			this->Controls->Add(this->ZN1);
			this->Controls->Add(this->CEL2);
			this->Controls->Add(this->CH2);
			this->Controls->Add(this->CEL1);
			this->Controls->Add(this->CH1);
			this->Controls->Add(this->LSTN);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->LDOUBLE1);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(125)), static_cast<System::Int32>(static_cast<System::Byte>(124)),
				static_cast<System::Int32>(static_cast<System::Byte>(130)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(6, 7, 6, 7);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CH1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ZN1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CEL1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CH2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CEL2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ZN2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NSTN))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) 
	{
		optype = 1;
		CalcType = false;
		
		lOperation.opt = optype;

		int hour = DateTime::Now.Hour;
		if (hour < 5 || hour >20) nightTheme = true;
		else nightTheme = false;
		ChangeTheme();

		RESULT(optype);
		buffZN1 = ZN1->Value;
		isStart = true;
	}
	private: System::Void ZN1_VALCH(System::Object^ sender, System::EventArgs^ e) 
	{
		BLOPER->Enabled = true;



		if (ZN1->Value == 0 && buffZN1 == 1)
			ZN1->Value = -1;
		else if (ZN1->Value >= 0 && buffZN1 == -1)
			ZN1->Value = 1;
		else if (ZN1->Value == 0)
			ZN1->Value = 1;
		buffZN1 = ZN1->Value;

		if (CH1->Value == ZN1->Value && CalcType)
		{
			CH1->Value = 0;
			CEL1->Value++;
		}

		if (CalcType && ZN1->Value < 0)
		{
			ZN1->Value = 1;
			CEL1->Value = -CEL1->Value;
		}


		RESULT(optype);
		
	}
	private: System::Void CH1_VALCH(System::Object^ sender, System::EventArgs^ e)
	{
		BLOPER->Enabled = true;


		if (CH1->Value >= ZN1->Value && CalcType)
		{
			CH1->Value = 0;
			CEL1->Value++;
		}

		

		if (CalcType && CH1->Value < 0)
		{
			CH1->Value = 0;
			CEL1->Value = -CEL1->Value;
		}

		RESULT(optype);
	}
	
private: System::Void BTCH_Click(System::Object^ sender, System::EventArgs^ e) 
{
	BLOPER->Enabled = true;


	CalcType = !CalcType;
	
	if (CalcType == false)
	{
		

		CH1->Value = Convert::ToDecimal(Convert::ToInt32(CH1->Value) + Convert::ToInt32(CEL1->Value * ZN1->Value));
		CEL1->Value = 0;
		CEL1->Visible = false;
		CEL1->Enabled = false;
		if (!isStart)
		{
			
			CEL2->Visible = false;
			CEL2->Enabled = false;

			CH2->Value = Convert::ToDecimal(Convert::ToInt32(CH2->Value) + Convert::ToInt32(CEL2->Value * ZN2->Value));
			CEL2->Value = 0;
		}

	}
	else
	{
		CEL1->Value = 0;
		CEL1->Visible = true;
		CEL1->Enabled = true;
		CEL1->Value = Convert::ToDecimal(Convert::ToInt32(CH1->Value) - Convert::ToInt32(CH1->Value%ZN1->Value))/ ZN1->Value;
		CH1->Value = Convert::ToInt32(CH1->Value % ZN1->Value);

		if (!isStart)
		{
			
			CEL2->Visible = true;
			CEL2->Enabled = true;
			CEL2->Value = 0;
			CEL2->Value = Convert::ToDecimal(Convert::ToInt32(CH2->Value) - Convert::ToInt32(CH2->Value % ZN2->Value)) / ZN2->Value;
			CH2->Value = Convert::ToInt32(CH2->Value % ZN2->Value);
			
		}
	}

}
private: System::Void CEL1_VALCH(System::Object^ sender, System::EventArgs^ e)
{
	BLOPER->Enabled = true;


	RESULT(optype);
}
private: System::Void BPLUS_Click(System::Object^ sender, System::EventArgs^ e) 
{
	BLOPER->Enabled = true;



	optype = 2;

	
	CH2->Enabled = true;
	CH2->Visible = true;
	if (CEL1->Visible == true)
	{
		CEL2->Enabled = true;
		CEL2->Visible = true;
	}
	ZN2->Enabled = true;
	ZN2->Visible = true;
	isStart = false;

	LSTN->Visible = false;
	NSTN->Visible = false;
	NSTN->Value = 1;
	NSTN->Enabled = false;
	LSTN->Enabled = false;

	
	LZNAK->Visible = true;
	RESULT(optype);

	BLOPER_METHOD(2);
}
private: System::Void CEL2_VALCH(System::Object^ sender, System::EventArgs^ e)
{
	BLOPER->Enabled = true;


	RESULT(optype);
}
private: System::Void CH2_VALCH(System::Object^ sender, System::EventArgs^ e) 
{
	BLOPER->Enabled = true;

	

	if (CH2->Value >= ZN2->Value && CalcType)
	{
		CH2->Value = 0;
		CEL2->Value++;
	}


	if (CalcType && CH2->Value < 0)
	{
		CH2->Value = 0;
		CEL2->Value = -CEL2->Value;
	}


	RESULT(optype);
}
	private: System::Void BMINUS_Click(System::Object^ sender, System::EventArgs^ e)
	{
		BLOPER->Enabled = true;

		

		optype = 3;
		

		CH2->Enabled = true;
		CH2->Visible = true;
		if (CEL1->Visible == true)
		{
			CEL2->Enabled = true;
			CEL2->Visible = true;
		}
		ZN2->Enabled = true;
		ZN2->Visible = true;
		isStart = false;

		LSTN->Visible = false;
		NSTN->Visible = false;
		NSTN->Value = 1;
		NSTN->Enabled = false;
		LSTN->Enabled = false;

		
		LZNAK->Visible = true;
		RESULT(optype);
		BLOPER_METHOD(3);
	}
	private: System::Void RESULT(int a)
	{
		switch (a)
		{
		case 1://1
			subuff = (System::Convert::ToDouble(CEL1->Value) + System::Convert::ToDouble(CH1->Value / ZN1->Value));
			LDOUBLE1->Text = (System::Convert::ToDouble(CEL1->Value) + System::Convert::ToDouble(CH1->Value / ZN1->Value)).ToString();
			optypebuff = 1;
			NSTN->Visible = false;
			NSTN->Enabled = false;
			break;
		case 2://+
			LZNAK->Text = "+";
			NSTN->Visible = false;
			NSTN->Enabled = false;
			subuff = (System::Convert::ToDouble(CEL1->Value) + System::Convert::ToDouble(CH1->Value / ZN1->Value) + Convert::ToDouble(CEL2->Value) + Convert::ToDouble(CH2->Value / ZN2->Value));
			LDOUBLE1->Text = (System::Convert::ToDouble(CEL1->Value) + System::Convert::ToDouble(CH1->Value / ZN1->Value) + Convert::ToDouble(CEL2->Value) + Convert::ToDouble(CH2->Value / ZN2->Value)).ToString();
			label2->Visible = true;
			optypebuff = 2;
			break;
		case 3://-
			LZNAK->Text = "-";
			NSTN->Visible = false;
			NSTN->Enabled = false;
			subuff = ((System::Convert::ToDouble(CEL1->Value) + System::Convert::ToDouble(CH1->Value / ZN1->Value)) - (Convert::ToDouble(CEL2->Value) + Convert::ToDouble(CH2->Value / ZN2->Value)));
			LDOUBLE1->Text = ((System::Convert::ToDouble(CEL1->Value) + System::Convert::ToDouble(CH1->Value / ZN1->Value)) - (Convert::ToDouble(CEL2->Value) + Convert::ToDouble(CH2->Value / ZN2->Value))).ToString();
			label2->Visible = true;
			optypebuff = 3;
			break;
		case 4://*
			LZNAK->Text = "*";
			NSTN->Visible = false;
			NSTN->Enabled = false;
			subuff = ((System::Convert::ToDouble(CEL1->Value) + System::Convert::ToDouble(CH1->Value / ZN1->Value)) * (Convert::ToDouble(CEL2->Value) + Convert::ToDouble(CH2->Value / ZN2->Value)));
			LDOUBLE1->Text = ((System::Convert::ToDouble(CEL1->Value) + System::Convert::ToDouble(CH1->Value / ZN1->Value)) * (Convert::ToDouble(CEL2->Value) + Convert::ToDouble(CH2->Value / ZN2->Value))).ToString();
			label2->Visible = true;
			optypebuff = 4;
			break;
		case 5:// /
			LZNAK->Text = "/";
			NSTN->Visible = false;
			NSTN->Enabled = false;
			label2->Visible = true;
			if ((Convert::ToDouble(CEL2->Value) + Convert::ToDouble(CH2->Value / ZN2->Value)) == 0)
				LDOUBLE1->Text = "n/0 = inf!";
			else
			{
				subuff = ((System::Convert::ToDouble(CEL1->Value) + System::Convert::ToDouble(CH1->Value / ZN1->Value)) / (Convert::ToDouble(CEL2->Value) + Convert::ToDouble(CH2->Value / ZN2->Value)));
				LDOUBLE1->Text = ((System::Convert::ToDouble(CEL1->Value) + System::Convert::ToDouble(CH1->Value / ZN1->Value)) / (Convert::ToDouble(CEL2->Value) + Convert::ToDouble(CH2->Value / ZN2->Value))).ToString();
			}
			optypebuff = 5;
			break;
		case 6: // ^n
			LDOUBLE1->Text = (pow(subuff, Convert::ToInt32(NSTN->Value))).ToString();
			optypebuff = 6;
			break;
		case 7: // +/-
			subuff = -subuff;
			NSTN->Visible = false;
			NSTN->Enabled = false;
			LDOUBLE1->Text = Convert::ToString(subuff);
			optype = optypebuff;
			break;
		}
		
	}
private: System::Void BMULT_Click(System::Object^ sender, System::EventArgs^ e)
{
	BLOPER->Enabled = true;

	

	optype = 4;

	CH2->Enabled = true;
	CH2->Visible = true;
	if (CEL1->Visible == true)
	{
		CEL2->Enabled = true;
		CEL2->Visible = true;
	}
	ZN2->Enabled = true;
	ZN2->Visible = true;
	isStart = false;

	LSTN->Visible = false;
	NSTN->Visible = false;
	NSTN->Value = 1;
	NSTN->Enabled = false;
	LSTN->Enabled = false;

	
	LZNAK->Visible = true;
	RESULT(optype);
	BLOPER_METHOD(4);
}
private: System::Void BDIV_Click(System::Object^ sender, System::EventArgs^ e) 
{
	BLOPER->Enabled = true;

	


	optype = 5;

	CH2->Enabled = true;
	CH2->Visible = true;
	if (CEL1->Visible == true)
	{
		CEL2->Enabled = true;
		CEL2->Visible = true;
	}
	ZN2->Enabled = true;
	ZN2->Visible = true;
	isStart = false;

	LSTN->Visible = false;
	NSTN->Visible = false;
	NSTN->Value = 1;
	NSTN->Enabled = false;
	LSTN->Enabled = false;

	
	LZNAK->Visible = true;
	RESULT(optype);
	BLOPER_METHOD(5);
}
private: System::Void BN_Click(System::Object^ sender, System::EventArgs^ e) 
{
	BLOPER->Enabled = true;

	

	LSTN->Visible = true;
	LSTN->Enabled = true;
	NSTN->Visible = true;
	NSTN->Enabled = true;
	optype = 6;

	RESULT(optype);
	BLOPER_METHOD(6);
}
private: System::Void NSTN_VALCH(System::Object^ sender, System::EventArgs^ e) 
{
	BLOPER->Enabled = true;

	
	optype = 6;
	RESULT(optype);
}
private: System::Void BSOKR_Click(System::Object^ sender, System::EventArgs^ e)
{
	BLOPER->Enabled = true;

	int ch1 = Convert::ToDouble(CH1->Value);
	int zn1 = Convert::ToDouble(ZN1->Value);

	int nod = EuqlideNOD(ch1, zn1);
	ch1 /= nod;
	zn1 /= nod;

	int ch2 = Convert::ToDouble(CH2->Value);
	int zn2 = Convert::ToDouble(ZN2->Value);

	int node1 = EuqlideNOD(ch2, zn2);
	ch2 /= node1;
	zn2 /= node1;

	CH1->Value = ch1;
	CH2->Value = ch2;
	ZN1->Value = zn1;
	ZN2->Value = zn2;
}

	   private: int EuqlideNOD(int a, int b)
	   {
		   while (a != 0 && b != 0)
		   {
			   if (a > b)
				   a %= b;
			   else
				   b %= a;
		   }
		   return a + b;
	   }
private: System::Void BPM_Click(System::Object^ sender, System::EventArgs^ e) 
{
	BLOPER->Enabled = true;

	
	optype = 7;
	RESULT(optype);
	BLOPER_METHOD(7);
}
private: System::Void ZN2_VALCH(System::Object^ sender, System::EventArgs^ e) 
{

	BLOPER->Enabled = true;

	

	if (ZN2->Value == 0 && buffZN1 == 1)
		ZN2->Value = -1;
	else if (ZN2->Value >= 0 && buffZN1 == -1)
		ZN2->Value = 1;
	else if (ZN2->Value == 0)
		ZN2->Value = 1;
	buffZN1 = ZN2->Value;




	if (CH2->Value == ZN2->Value && CalcType)
	{
		CH2->Value = 0;
		CEL2->Value++;
	}

	if (CalcType && ZN2->Value < 0)
	{
		ZN2->Value = 1;
		CEL2->Value = -CEL2->Value;
	}


	RESULT(optype);

}
private: System::Void BZNCH_Click(System::Object^ sender, System::EventArgs^ e)
{
	BLOPER->Enabled = true;

	


	System::Decimal c;
	c = CH1->Value;
	CH1->Value = ZN1->Value;
	ZN1->Value = c;

	c = CH2->Value;
	CH2->Value = ZN2->Value;
	ZN2->Value = c;

	BLOPER_METHOD(1);
}
private: System::Void BLOPER_Click(System::Object^ sender, System::EventArgs^ e) 
{
	BLOPER->Enabled = false;

	switch (optypebuff)
	{
	case 1:
		CH2->Visible = false;
		CH2->Enabled = false;
		ZN2->Visible = false;
		ZN2->Enabled = false;
		CEL2->Visible = false;
		CEL2->Enabled = false;
		NSTN->Visible = false;
		NSTN->Enabled = false;
		LSTN->Visible = false;
		CH1->Value = lOperation.ch1;
		ZN1->Value = lOperation.zn1;
		CEL1->Value = lOperation.cel1;
		LZNAK->Text = "";
		RESULT(1);
		break;
	case 2:
		CH2->Visible = true;
		CH2->Enabled = true;
		ZN2->Visible = true;
		ZN2->Enabled = true;
		CEL1->Visible = true;
		CEL1->Enabled = true;
		CEL2->Visible = true;
		CEL2->Enabled = true;
		NSTN->Visible = false;
		NSTN->Enabled = false;
		LSTN->Visible = false;
		CH1->Value = lOperation.ch1;
		ZN1->Value = lOperation.zn1;
		CEL1->Value = lOperation.cel1;
		CEL2->Value = lOperation.cel2;
		CH2->Value = lOperation.ch2;
		ZN2->Value = lOperation.zn2;
		LZNAK->Text = "+";
		RESULT(2);
		break;
	case 3:
		CH2->Visible = true;
		CH2->Enabled = true;
		ZN2->Visible = true;
		ZN2->Enabled = true;
		CEL1->Visible = true;
		CEL1->Enabled = true;
		CEL2->Visible = true;
		CEL2->Enabled = true;
		NSTN->Visible = false;
		NSTN->Enabled = false;
		LSTN->Visible = false;
		CH1->Value = lOperation.ch1;
		ZN1->Value = lOperation.zn1;
		CEL1->Value = lOperation.cel1;
		CEL2->Value = lOperation.cel2;
		CH2->Value = lOperation.ch2;
		ZN2->Value = lOperation.zn2;
		LZNAK->Text = "-";
		RESULT(3);
		break;
	case 4:
		CH2->Visible = true;
		CH2->Enabled = true;
		ZN2->Visible = true;
		ZN2->Enabled = true;
		CEL1->Visible = true;
		CEL1->Enabled = true;
		CEL2->Visible = true;
		CEL2->Enabled = true;
		NSTN->Visible = false;
		NSTN->Enabled = false;
		LSTN->Visible = false;
		CH1->Value = lOperation.ch1;
		ZN1->Value = lOperation.zn1;
		CEL1->Value = lOperation.cel1;
		CEL2->Value = lOperation.cel2;
		CH2->Value = lOperation.ch2;
		ZN2->Value = lOperation.zn2;
		LZNAK->Text = "*";
		RESULT(4);
		break;
	case 5:
		CH2->Visible = true;
		CH2->Enabled = true;
		ZN2->Visible = true;
		ZN2->Enabled = true;
		CEL1->Visible = true;
		CEL1->Enabled = true;
		CEL2->Visible = true;
		CEL2->Enabled = true;
		NSTN->Visible = false;
		NSTN->Enabled = false;
		LSTN->Visible = false;
		CH1->Value = lOperation.ch1;
		ZN1->Value = lOperation.zn1;
		CEL1->Value = lOperation.cel1;
		CEL2->Value = lOperation.cel2;
		CH2->Value = lOperation.ch2;
		ZN2->Value = lOperation.zn2;
		LZNAK->Text = "/";
		RESULT(5);
		break;
	case 6:
		CH2->Visible = true;
		CH2->Enabled = true;
		ZN2->Visible = true;
		ZN2->Enabled = true;
		CEL1->Visible = true;
		CEL1->Enabled = true;
		CEL2->Visible = true;
		CEL2->Enabled = true;
		NSTN->Visible = true;
		NSTN->Enabled = true;
		LSTN->Visible = true;
		CH1->Value = lOperation.ch1;
		ZN1->Value = lOperation.zn1;
		CEL1->Value = lOperation.cel1;
		CEL2->Value = lOperation.cel2;
		CH2->Value = lOperation.ch2;
		ZN2->Value = lOperation.zn2;
		RESULT(6);
		break;
	case 7:
		CH2->Visible = true;
		CH2->Enabled = true;
		ZN2->Visible = true;
		ZN2->Enabled = true;
		CEL1->Visible = true;
		CEL1->Enabled = true;
		CEL2->Visible = true;
		CEL2->Enabled = true;
		
		LSTN->Visible = false;
		CH1->Value = lOperation.ch1;
		ZN1->Value = lOperation.zn1;
		CEL1->Value = lOperation.cel1;
		CEL2->Value = lOperation.cel2;
		CH2->Value = lOperation.ch2;
		ZN2->Value = lOperation.zn2;
		RESULT(7);
		break;
	}


}

	private: System::Void BLOPER_METHOD(int a)
	{
		switch (a)
		{
		case 1:
			lOperation.cel1 = CEL1->Value;
			lOperation.ch1 = CH1->Value;
			lOperation.zn1 = ZN1->Value;
			lOperation.opt = 1;
			break;
		case 2:
			lOperation.cel1 = CEL1->Value;
			lOperation.ch1 = CH1->Value;
			lOperation.zn1 = ZN1->Value;
			lOperation.cel2 = CEL2->Value;
			lOperation.ch2 = CH2->Value;
			lOperation.zn2 = ZN2->Value;
			lOperation.opt = 2;
			break;
		case 3:
			lOperation.cel1 = CEL1->Value;
			lOperation.ch1 = CH1->Value;
			lOperation.zn1 = ZN1->Value;
			lOperation.cel2 = CEL2->Value;
			lOperation.ch2 = CH2->Value;
			lOperation.zn2 = ZN2->Value;
			lOperation.opt = 3;
			break;
		case 4:
			lOperation.cel1 = CEL1->Value;
			lOperation.ch1 = CH1->Value;
			lOperation.zn1 = ZN1->Value;
			lOperation.cel2 = CEL2->Value;
			lOperation.ch2 = CH2->Value;
			lOperation.zn2 = ZN2->Value;
			lOperation.opt = 4;
			break;
		case 5:
			lOperation.cel1 = CEL1->Value;
			lOperation.ch1 = CH1->Value;
			lOperation.zn1 = ZN1->Value;
			lOperation.cel2 = CEL2->Value;
			lOperation.ch2 = CH2->Value;
			lOperation.zn2 = ZN2->Value;
			lOperation.opt = 5;
			break;
		case 6:
			lOperation.cel1 = CEL1->Value;
			lOperation.ch1 = CH1->Value;
			lOperation.zn1 = ZN1->Value;
			lOperation.cel2 = CEL2->Value;
			lOperation.ch2 = CH2->Value;
			lOperation.zn2 = ZN2->Value;
			lOperation.opt = 6;
			lOperation.nstn = NSTN->Value;
			break;
		case 7:
			lOperation.cel1 = CEL1->Value;
			lOperation.ch1 = CH1->Value;
			lOperation.zn1 = ZN1->Value;
			lOperation.cel2 = CEL2->Value;
			lOperation.ch2 = CH2->Value;
			lOperation.zn2 = ZN2->Value;
			lOperation.opt = 7;
			lOperation.nstn = NSTN->Value;
			break;

		}
	}
private: System::Void BAC_Click(System::Object^ sender, System::EventArgs^ e)
{
	optype = 1;
	CalcType = false;

	lOperation.opt = optype;

	CH1->Value = 0;
	ZN1->Value = 1;
	CEL1->Value = 0;
	
	CEL1->Visible = false;
	CEL2->Visible = false;
	CH2->Visible = false;
	ZN2->Visible = false;
	LZNAK->Visible = false;
	LSTN->Visible = false;
	NSTN->Visible = false;
	BLOPER->Enabled = false;
	label2->Visible = false;

	RESULT(optype);
	buffZN1 = ZN1->Value;
	isStart = true;
}

	   private: System::Void ChangeTheme()
	   {
		   if (nightTheme)
		   {
			   //Фон формы
			   MyForm::BackColor = Color::FromArgb(29, 40, 60);
			   //Кнопки фон
			   BPLUS->BackColor = Color::FromArgb(8, 10, 125);
			   BMINUS->BackColor = Color::FromArgb(8, 10, 125);
			   BMULT->BackColor = Color::FromArgb(8, 10, 125);
			   BDIV->BackColor = Color::FromArgb(8, 10, 125);
			   BAC->BackColor = Color::FromArgb(8, 10, 125);
			   BPM->BackColor = Color::FromArgb(8, 10, 125);
			   BTCH->BackColor = Color::FromArgb(8, 10, 125);
			   BSOKR->BackColor = Color::FromArgb(8, 10, 125);
			   BZNCH->BackColor = Color::FromArgb(8, 10, 125);
			   BLOPER->BackColor = Color::FromArgb(8, 10, 125);
			   BN->BackColor = Color::FromArgb(8, 10, 125);
			   BTHEMECHANGER->BackColor = Color::FromArgb(8, 10, 125);

			   //кнопки шрифт
			   BPLUS->ForeColor = Color::FromArgb(228, 227, 249);
			   BN->ForeColor = Color::FromArgb(228, 227, 249);
			   BMINUS->ForeColor = Color::FromArgb(228, 227, 249);
			   BMULT->ForeColor = Color::FromArgb(228, 227, 249);
			   BDIV->ForeColor = Color::FromArgb(228, 227, 249);
			   BAC->ForeColor = Color::FromArgb(228, 227, 249);
			   BPM->ForeColor = Color::FromArgb(228, 227, 249);
			   BTCH->ForeColor = Color::FromArgb(228, 227, 249);
			   BSOKR->ForeColor = Color::FromArgb(228, 227, 249);
			   BZNCH->ForeColor = Color::FromArgb(228, 227, 249);
			   BLOPER->ForeColor = Color::FromArgb(228, 227, 249);
			   BTHEMECHANGER->ForeColor = Color::FromArgb(228, 227, 249);
				//Лейблы шрифт цвет
			   LZNAK->ForeColor = Color::FromArgb(228, 227, 249);
			   LDOUBLE1->ForeColor = Color::FromArgb(228, 227, 249);
			   LSTN->ForeColor = Color::FromArgb(228, 227, 249);
			   label1->ForeColor = Color::FromArgb(228, 227, 249);
			   label2->ForeColor = Color::FromArgb(228, 227, 249);
			   label3->ForeColor = Color::FromArgb(228, 227, 249);
			   //лейблы фон цвет
			   LZNAK->BackColor = Color::FromArgb(29, 40, 60);
			   LDOUBLE1->BackColor = Color::FromArgb(29, 40, 60);
			   LSTN->BackColor = Color::FromArgb(29, 40, 60);
			   label1->BackColor = Color::FromArgb(29, 40, 60);
			   label2->BackColor = Color::FromArgb(29, 40, 60);
			   label3->BackColor = Color::FromArgb(29, 40, 60);
			   //Нумерики цвет
			   CEL1->BackColor = Color::FromArgb(69, 71, 83);
			   CEL2->BackColor = Color::FromArgb(69, 71, 83);
			   CH1->BackColor = Color::FromArgb(69, 71, 83);
			   CH2->BackColor = Color::FromArgb(69, 71, 83);
			   ZN1->BackColor = Color::FromArgb(69, 71, 83);
			   ZN2->BackColor = Color::FromArgb(69, 71, 83);
			   NSTN->BackColor = Color::FromArgb(69, 71, 83);
			   //нумерики шрифт цвет
			   CEL1->ForeColor = Color::FromArgb(228, 227, 249);
			   CEL2->ForeColor = Color::FromArgb(228, 227, 249);
			   CH1->ForeColor = Color::FromArgb(228, 227, 249);
			   CH2->ForeColor = Color::FromArgb(228, 227, 249);
			   ZN1->ForeColor = Color::FromArgb(228, 227, 249);
			   ZN2->ForeColor = Color::FromArgb(228, 227, 249);
			   NSTN->ForeColor = Color::FromArgb(228, 227, 249);

			   nightTheme = !nightTheme;
		   }
		   else
		   {
			   //Фон формы
			   MyForm::BackColor = Color::FromArgb(188, 190, 192);
			   //Кнопки фон
			   BPLUS->BackColor = Color::FromArgb(194, 195, 199);
			   BMINUS->BackColor = Color::FromArgb(194, 195, 199);
			   BMULT->BackColor = Color::FromArgb(194, 195, 199);
			   BDIV->BackColor = Color::FromArgb(194, 195, 199);
			   BAC->BackColor = Color::FromArgb(194, 195, 199);
			   BPM->BackColor = Color::FromArgb(194, 195, 199);
			   BTCH->BackColor = Color::FromArgb(194, 195, 199);
			   BSOKR->BackColor = Color::FromArgb(194, 195, 199);
			   BZNCH->BackColor = Color::FromArgb(194, 195, 199);
			   BLOPER->BackColor = Color::FromArgb(194, 195, 199);
			   BN->BackColor = Color::FromArgb(194, 195, 199);
			   BTHEMECHANGER->BackColor = Color::FromArgb(194, 195, 199);

			   //кнопки шрифт
			   BPLUS->ForeColor = Color::FromArgb(75, 74, 80);
			   BN->ForeColor = Color::FromArgb(75, 74, 80);
			   BMINUS->ForeColor = Color::FromArgb(75, 74, 80);
			   BMULT->ForeColor = Color::FromArgb(75, 74, 80);
			   BDIV->ForeColor = Color::FromArgb(75, 74, 80);
			   BAC->ForeColor = Color::FromArgb(75, 74, 80);
			   BPM->ForeColor = Color::FromArgb(75, 74, 80);
			   BTCH->ForeColor = Color::FromArgb(75, 74, 80);
			   BSOKR->ForeColor = Color::FromArgb(75, 74, 80);
			   BZNCH->ForeColor = Color::FromArgb(75, 74, 80);
			   BLOPER->ForeColor = Color::FromArgb(75, 74, 80);
			   BTHEMECHANGER->ForeColor = Color::FromArgb(75, 74, 80);
			   //Лейблы шрифт цвет
			   LZNAK->ForeColor = Color::FromArgb(75, 74, 80);
			   LDOUBLE1->ForeColor = Color::FromArgb(75, 74, 80);
			   LSTN->ForeColor = Color::FromArgb(75, 74, 80);
			   label1->ForeColor = Color::FromArgb(75, 74, 80);
			   label2->ForeColor = Color::FromArgb(75, 74, 80);
			   label3->ForeColor = Color::FromArgb(75, 74, 80);
			   //лейблы фон цвет
			   LZNAK->BackColor = Color::FromArgb(188, 190, 192);
			   LDOUBLE1->BackColor = Color::FromArgb(188, 190, 192);
			   LSTN->BackColor = Color::FromArgb(188, 190, 192);
			   label1->BackColor = Color::FromArgb(188, 190, 192);
			   label2->BackColor = Color::FromArgb(188, 190, 192);
			   label3->BackColor = Color::FromArgb(188, 190, 192);
			   //Нумерики цвет
			   CEL1->BackColor = Color::FromArgb(216, 217, 221);
			   CEL2->BackColor = Color::FromArgb(216, 217, 221);
			   CH1->BackColor = Color::FromArgb(216, 217, 221);
			   CH2->BackColor = Color::FromArgb(216, 217, 221);
			   ZN1->BackColor = Color::FromArgb(216, 217, 221);
			   ZN2->BackColor = Color::FromArgb(216, 217, 221);
			   NSTN->BackColor = Color::FromArgb(216, 217, 221);
			   //нумерики шрифт цвет
			   CEL1->ForeColor = Color::FromArgb(75, 74, 80);
			   CEL2->ForeColor = Color::FromArgb(75, 74, 80);
			   CH1->ForeColor = Color::FromArgb(75, 74, 80);
			   CH2->ForeColor = Color::FromArgb(75, 74, 80);
			   ZN1->ForeColor = Color::FromArgb(75, 74, 80);
			   ZN2->ForeColor = Color::FromArgb(75, 74, 80);
			   NSTN->ForeColor = Color::FromArgb(75, 74, 80);

			   nightTheme = !nightTheme;
		   }
	   }
private: System::Void BTHEMECH_Click(System::Object^ sender, System::EventArgs^ e) 
{
	ChangeTheme();
}
};
}
