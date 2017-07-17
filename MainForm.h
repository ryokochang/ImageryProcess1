#pragma once
#include "diptools.h"

namespace ImageryProcess {
	
	// Global Variables
	int Red = 2, Green = 1, Blue = 0;
	int threshold_value = 0;
	int watershed_fg = 0;
	int watershed_bg = 0;
	int const watershed_max = 3;
	int bandSelected = 4;
	int threshold_type = 3;
	int const max_value = 255;
	int const max_type = 4;
	int const max_BINARY_value = 255;
	char* trackbar_type = "Type: \n 0: Binary \n 1: Binary Inverted \n 2: Truncate \n 3: To Zero \n 4: To Zero Inverted";
	char* trackbar_value = "Value";
	Mat src, src_gray, dst1, resizeimage, mainMat; // Need to create a Mat type for the src image.
	std::vector<Mat> bgr;
	cv::String MainWindow = "Main Window";
	diptools Tools;
	

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  menuToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sairToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  salvarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripMenuItem^  carregarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  funçõesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  thresholdToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  binarioToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  binarioInvertidoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  truncadoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  zeroToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  zeroInvertidoToolStripMenuItem;
	private: System::Windows::Forms::TabPage^  tabMain;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::RadioButton^  radioButtonNir;
	private: System::Windows::Forms::TextBox^  textBoxGsd;
	private: System::Windows::Forms::TextBox^  textBoxFocalDistance;
	private: System::Windows::Forms::TextBox^  textBoxFlightHeight;
	private: System::Windows::Forms::TextBox^  textBoxSizePixelH;
	private: System::Windows::Forms::TextBox^  textBoxSensorH;
	private: System::Windows::Forms::TextBox^  textBoxSensorW;
	private: System::Windows::Forms::TextBox^  textBoxSizePixelW;
	private: System::Windows::Forms::TextBox^  textBoxLine;
	private: System::Windows::Forms::TextBox^  textBoxColumn;
	private: System::Windows::Forms::TextBox^  textBoxImages;
	private: System::Windows::Forms::Label^  labelFocalDistance;
	private: System::Windows::Forms::Label^  labelFlightHeight;
	private: System::Windows::Forms::Label^  labelSensor;
	private: System::Windows::Forms::Label^  labelSizePixel;
	private: System::Windows::Forms::Label^  labelTotalnumbers;
	private: System::Windows::Forms::Label^  labelLine;
	private: System::Windows::Forms::Label^  labelColumn;
	private: System::Windows::Forms::Label^  labelResolution;
	private: System::Windows::Forms::PictureBox^  ptbSource;
	private: System::Windows::Forms::Label^  labelTotalImage;
	private: System::Windows::Forms::Button^  buttonCalculateGsd;
	private: System::Windows::Forms::Label^  labelGsd;
	private: System::Windows::Forms::RadioButton^  radiobBlue;
	private: System::Windows::Forms::RadioButton^  radiobGreen;
	private: System::Windows::Forms::RadioButton^  radiobRed;
	private: System::Windows::Forms::Label^  labelSelectBand;
	private: System::Windows::Forms::Label^  labelLoadImages;
	private: System::Windows::Forms::Button^  buttonLoad;
	private: System::Windows::Forms::TabControl^  tabControl;
	private: System::Windows::Forms::ToolStripMenuItem^  thresholdOtsuToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  binarioToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  triangulaçãoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;
	private: System::Windows::Forms::ToolStripMenuItem^  binarioToolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  binarioInvertidoToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  truncadoToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  zeroToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  zeroInvertidoToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  binarioInvertidoToolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  truncadoToolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  zeroToolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  zeroInvertidoToolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  segmentaçãoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  distanciaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator3;
	private: System::Windows::Forms::ToolStripMenuItem^  watershedToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  erodingAndDilatingToolStripMenuItem;

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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->menuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->carregarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->salvarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->sairToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->funçõesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->thresholdToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->binarioToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->binarioInvertidoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->truncadoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->zeroToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->zeroInvertidoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->thresholdOtsuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->binarioToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->binarioInvertidoToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->truncadoToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->zeroToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->zeroInvertidoToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->triangulaçãoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->binarioToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->binarioInvertidoToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->truncadoToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->zeroToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->zeroInvertidoToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->segmentaçãoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->distanciaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->erodingAndDilatingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator3 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->watershedToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->tabMain = (gcnew System::Windows::Forms::TabPage());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->radioButtonNir = (gcnew System::Windows::Forms::RadioButton());
			this->textBoxGsd = (gcnew System::Windows::Forms::TextBox());
			this->textBoxFocalDistance = (gcnew System::Windows::Forms::TextBox());
			this->textBoxFlightHeight = (gcnew System::Windows::Forms::TextBox());
			this->textBoxSizePixelH = (gcnew System::Windows::Forms::TextBox());
			this->textBoxSensorH = (gcnew System::Windows::Forms::TextBox());
			this->textBoxSensorW = (gcnew System::Windows::Forms::TextBox());
			this->textBoxSizePixelW = (gcnew System::Windows::Forms::TextBox());
			this->textBoxLine = (gcnew System::Windows::Forms::TextBox());
			this->textBoxColumn = (gcnew System::Windows::Forms::TextBox());
			this->textBoxImages = (gcnew System::Windows::Forms::TextBox());
			this->labelFocalDistance = (gcnew System::Windows::Forms::Label());
			this->labelFlightHeight = (gcnew System::Windows::Forms::Label());
			this->labelSensor = (gcnew System::Windows::Forms::Label());
			this->labelSizePixel = (gcnew System::Windows::Forms::Label());
			this->labelTotalnumbers = (gcnew System::Windows::Forms::Label());
			this->labelLine = (gcnew System::Windows::Forms::Label());
			this->labelColumn = (gcnew System::Windows::Forms::Label());
			this->labelResolution = (gcnew System::Windows::Forms::Label());
			this->ptbSource = (gcnew System::Windows::Forms::PictureBox());
			this->labelTotalImage = (gcnew System::Windows::Forms::Label());
			this->buttonCalculateGsd = (gcnew System::Windows::Forms::Button());
			this->labelGsd = (gcnew System::Windows::Forms::Label());
			this->radiobBlue = (gcnew System::Windows::Forms::RadioButton());
			this->radiobGreen = (gcnew System::Windows::Forms::RadioButton());
			this->radiobRed = (gcnew System::Windows::Forms::RadioButton());
			this->labelSelectBand = (gcnew System::Windows::Forms::Label());
			this->labelLoadImages = (gcnew System::Windows::Forms::Label());
			this->buttonLoad = (gcnew System::Windows::Forms::Button());
			this->tabControl = (gcnew System::Windows::Forms::TabControl());
			this->menuStrip1->SuspendLayout();
			this->tabMain->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ptbSource))->BeginInit();
			this->tabControl->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->menuToolStripMenuItem,
					this->funçõesToolStripMenuItem
			});
			this->menuStrip1->LayoutStyle = System::Windows::Forms::ToolStripLayoutStyle::HorizontalStackWithOverflow;
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(406, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// menuToolStripMenuItem
			// 
			this->menuToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->carregarToolStripMenuItem,
					this->salvarToolStripMenuItem, this->toolStripSeparator1, this->sairToolStripMenuItem
			});
			this->menuToolStripMenuItem->Name = L"menuToolStripMenuItem";
			this->menuToolStripMenuItem->Size = System::Drawing::Size(50, 20);
			this->menuToolStripMenuItem->Text = L"Menu";
			// 
			// carregarToolStripMenuItem
			// 
			this->carregarToolStripMenuItem->Name = L"carregarToolStripMenuItem";
			this->carregarToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->carregarToolStripMenuItem->Text = L"Carregar";
			this->carregarToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::carregarToolStripMenuItem_Click);
			// 
			// salvarToolStripMenuItem
			// 
			this->salvarToolStripMenuItem->Name = L"salvarToolStripMenuItem";
			this->salvarToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->salvarToolStripMenuItem->Text = L"Salvar";
			this->salvarToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::salvarToolStripMenuItem_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(149, 6);
			// 
			// sairToolStripMenuItem
			// 
			this->sairToolStripMenuItem->Name = L"sairToolStripMenuItem";
			this->sairToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->sairToolStripMenuItem->Text = L"Sair";
			this->sairToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::sairToolStripMenuItem_Click);
			// 
			// funçõesToolStripMenuItem
			// 
			this->funçõesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->thresholdToolStripMenuItem,
					this->thresholdOtsuToolStripMenuItem, this->triangulaçãoToolStripMenuItem, this->segmentaçãoToolStripMenuItem, this->toolStripSeparator2
			});
			this->funçõesToolStripMenuItem->Name = L"funçõesToolStripMenuItem";
			this->funçõesToolStripMenuItem->Size = System::Drawing::Size(63, 20);
			this->funçõesToolStripMenuItem->Text = L"Funções";
			// 
			// thresholdToolStripMenuItem
			// 
			this->thresholdToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->binarioToolStripMenuItem,
					this->binarioInvertidoToolStripMenuItem, this->truncadoToolStripMenuItem, this->zeroToolStripMenuItem, this->zeroInvertidoToolStripMenuItem
			});
			this->thresholdToolStripMenuItem->Name = L"thresholdToolStripMenuItem";
			this->thresholdToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->thresholdToolStripMenuItem->Text = L"Threshold";
			// 
			// binarioToolStripMenuItem
			// 
			this->binarioToolStripMenuItem->Name = L"binarioToolStripMenuItem";
			this->binarioToolStripMenuItem->Size = System::Drawing::Size(161, 22);
			this->binarioToolStripMenuItem->Text = L"Binario";
			this->binarioToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::binarioToolStripMenuItem_Click);
			// 
			// binarioInvertidoToolStripMenuItem
			// 
			this->binarioInvertidoToolStripMenuItem->Name = L"binarioInvertidoToolStripMenuItem";
			this->binarioInvertidoToolStripMenuItem->Size = System::Drawing::Size(161, 22);
			this->binarioInvertidoToolStripMenuItem->Text = L"Binario Invertido";
			this->binarioInvertidoToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::binarioInvertidoToolStripMenuItem_Click);
			// 
			// truncadoToolStripMenuItem
			// 
			this->truncadoToolStripMenuItem->Name = L"truncadoToolStripMenuItem";
			this->truncadoToolStripMenuItem->Size = System::Drawing::Size(161, 22);
			this->truncadoToolStripMenuItem->Text = L"Truncado";
			this->truncadoToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::truncadoToolStripMenuItem_Click);
			// 
			// zeroToolStripMenuItem
			// 
			this->zeroToolStripMenuItem->Name = L"zeroToolStripMenuItem";
			this->zeroToolStripMenuItem->Size = System::Drawing::Size(161, 22);
			this->zeroToolStripMenuItem->Text = L"Zero";
			this->zeroToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::zeroToolStripMenuItem_Click);
			// 
			// zeroInvertidoToolStripMenuItem
			// 
			this->zeroInvertidoToolStripMenuItem->Name = L"zeroInvertidoToolStripMenuItem";
			this->zeroInvertidoToolStripMenuItem->Size = System::Drawing::Size(161, 22);
			this->zeroInvertidoToolStripMenuItem->Text = L"Zero Invertido";
			this->zeroInvertidoToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::zeroInvertidoToolStripMenuItem_Click);
			// 
			// thresholdOtsuToolStripMenuItem
			// 
			this->thresholdOtsuToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->binarioToolStripMenuItem1,
					this->binarioInvertidoToolStripMenuItem1, this->truncadoToolStripMenuItem1, this->zeroToolStripMenuItem1, this->zeroInvertidoToolStripMenuItem1
			});
			this->thresholdOtsuToolStripMenuItem->Name = L"thresholdOtsuToolStripMenuItem";
			this->thresholdOtsuToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->thresholdOtsuToolStripMenuItem->Text = L"Otsu";
			// 
			// binarioToolStripMenuItem1
			// 
			this->binarioToolStripMenuItem1->Name = L"binarioToolStripMenuItem1";
			this->binarioToolStripMenuItem1->Size = System::Drawing::Size(161, 22);
			this->binarioToolStripMenuItem1->Text = L"Binario";
			this->binarioToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainForm::binarioToolStripMenuItem1_Click);
			// 
			// binarioInvertidoToolStripMenuItem1
			// 
			this->binarioInvertidoToolStripMenuItem1->Name = L"binarioInvertidoToolStripMenuItem1";
			this->binarioInvertidoToolStripMenuItem1->Size = System::Drawing::Size(161, 22);
			this->binarioInvertidoToolStripMenuItem1->Text = L"Binario Invertido";
			this->binarioInvertidoToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainForm::binarioInvertidoToolStripMenuItem1_Click);
			// 
			// truncadoToolStripMenuItem1
			// 
			this->truncadoToolStripMenuItem1->Name = L"truncadoToolStripMenuItem1";
			this->truncadoToolStripMenuItem1->Size = System::Drawing::Size(161, 22);
			this->truncadoToolStripMenuItem1->Text = L"Truncado";
			this->truncadoToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainForm::truncadoToolStripMenuItem1_Click);
			// 
			// zeroToolStripMenuItem1
			// 
			this->zeroToolStripMenuItem1->Name = L"zeroToolStripMenuItem1";
			this->zeroToolStripMenuItem1->Size = System::Drawing::Size(161, 22);
			this->zeroToolStripMenuItem1->Text = L"Zero";
			this->zeroToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainForm::zeroToolStripMenuItem1_Click);
			// 
			// zeroInvertidoToolStripMenuItem1
			// 
			this->zeroInvertidoToolStripMenuItem1->Name = L"zeroInvertidoToolStripMenuItem1";
			this->zeroInvertidoToolStripMenuItem1->Size = System::Drawing::Size(161, 22);
			this->zeroInvertidoToolStripMenuItem1->Text = L"Zero Invertido";
			this->zeroInvertidoToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainForm::zeroInvertidoToolStripMenuItem1_Click);
			// 
			// triangulaçãoToolStripMenuItem
			// 
			this->triangulaçãoToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->binarioToolStripMenuItem2,
					this->binarioInvertidoToolStripMenuItem2, this->truncadoToolStripMenuItem2, this->zeroToolStripMenuItem2, this->zeroInvertidoToolStripMenuItem2
			});
			this->triangulaçãoToolStripMenuItem->Name = L"triangulaçãoToolStripMenuItem";
			this->triangulaçãoToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->triangulaçãoToolStripMenuItem->Text = L"Triangulação";
			// 
			// binarioToolStripMenuItem2
			// 
			this->binarioToolStripMenuItem2->Name = L"binarioToolStripMenuItem2";
			this->binarioToolStripMenuItem2->Size = System::Drawing::Size(161, 22);
			this->binarioToolStripMenuItem2->Text = L"Binario";
			this->binarioToolStripMenuItem2->Click += gcnew System::EventHandler(this, &MainForm::binarioToolStripMenuItem2_Click);
			// 
			// binarioInvertidoToolStripMenuItem2
			// 
			this->binarioInvertidoToolStripMenuItem2->Name = L"binarioInvertidoToolStripMenuItem2";
			this->binarioInvertidoToolStripMenuItem2->Size = System::Drawing::Size(161, 22);
			this->binarioInvertidoToolStripMenuItem2->Text = L"Binario Invertido";
			this->binarioInvertidoToolStripMenuItem2->Click += gcnew System::EventHandler(this, &MainForm::binarioInvertidoToolStripMenuItem2_Click);
			// 
			// truncadoToolStripMenuItem2
			// 
			this->truncadoToolStripMenuItem2->Name = L"truncadoToolStripMenuItem2";
			this->truncadoToolStripMenuItem2->Size = System::Drawing::Size(161, 22);
			this->truncadoToolStripMenuItem2->Text = L"Truncado";
			this->truncadoToolStripMenuItem2->Click += gcnew System::EventHandler(this, &MainForm::truncadoToolStripMenuItem2_Click);
			// 
			// zeroToolStripMenuItem2
			// 
			this->zeroToolStripMenuItem2->Name = L"zeroToolStripMenuItem2";
			this->zeroToolStripMenuItem2->Size = System::Drawing::Size(161, 22);
			this->zeroToolStripMenuItem2->Text = L"Zero";
			this->zeroToolStripMenuItem2->Click += gcnew System::EventHandler(this, &MainForm::zeroToolStripMenuItem2_Click);
			// 
			// zeroInvertidoToolStripMenuItem2
			// 
			this->zeroInvertidoToolStripMenuItem2->Name = L"zeroInvertidoToolStripMenuItem2";
			this->zeroInvertidoToolStripMenuItem2->Size = System::Drawing::Size(161, 22);
			this->zeroInvertidoToolStripMenuItem2->Text = L"Zero Invertido";
			this->zeroInvertidoToolStripMenuItem2->Click += gcnew System::EventHandler(this, &MainForm::zeroInvertidoToolStripMenuItem2_Click);
			// 
			// segmentaçãoToolStripMenuItem
			// 
			this->segmentaçãoToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->distanciaToolStripMenuItem,
					this->erodingAndDilatingToolStripMenuItem, this->toolStripSeparator3, this->watershedToolStripMenuItem1
			});
			this->segmentaçãoToolStripMenuItem->Name = L"segmentaçãoToolStripMenuItem";
			this->segmentaçãoToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->segmentaçãoToolStripMenuItem->Text = L"Segmentação";
			// 
			// distanciaToolStripMenuItem
			// 
			this->distanciaToolStripMenuItem->Name = L"distanciaToolStripMenuItem";
			this->distanciaToolStripMenuItem->Size = System::Drawing::Size(170, 22);
			this->distanciaToolStripMenuItem->Text = L"Distância";
			this->distanciaToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::distanciaToolStripMenuItem_Click);
			// 
			// erodingAndDilatingToolStripMenuItem
			// 
			this->erodingAndDilatingToolStripMenuItem->Name = L"erodingAndDilatingToolStripMenuItem";
			this->erodingAndDilatingToolStripMenuItem->Size = System::Drawing::Size(170, 22);
			this->erodingAndDilatingToolStripMenuItem->Text = L"Erosão e Dilatação";
			this->erodingAndDilatingToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::erodingAndDilatingToolStripMenuItem_Click);
			// 
			// toolStripSeparator3
			// 
			this->toolStripSeparator3->Name = L"toolStripSeparator3";
			this->toolStripSeparator3->Size = System::Drawing::Size(167, 6);
			// 
			// watershedToolStripMenuItem1
			// 
			this->watershedToolStripMenuItem1->Name = L"watershedToolStripMenuItem1";
			this->watershedToolStripMenuItem1->Size = System::Drawing::Size(170, 22);
			this->watershedToolStripMenuItem1->Text = L"Watershed";
			this->watershedToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainForm::watershedToolStripMenuItem1_Click);
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(149, 6);
			// 
			// tabMain
			// 
			this->tabMain->AutoScroll = true;
			this->tabMain->Controls->Add(this->label1);
			this->tabMain->Controls->Add(this->radioButtonNir);
			this->tabMain->Controls->Add(this->textBoxGsd);
			this->tabMain->Controls->Add(this->textBoxFocalDistance);
			this->tabMain->Controls->Add(this->textBoxFlightHeight);
			this->tabMain->Controls->Add(this->textBoxSizePixelH);
			this->tabMain->Controls->Add(this->textBoxSensorH);
			this->tabMain->Controls->Add(this->textBoxSensorW);
			this->tabMain->Controls->Add(this->textBoxSizePixelW);
			this->tabMain->Controls->Add(this->textBoxLine);
			this->tabMain->Controls->Add(this->textBoxColumn);
			this->tabMain->Controls->Add(this->textBoxImages);
			this->tabMain->Controls->Add(this->labelFocalDistance);
			this->tabMain->Controls->Add(this->labelFlightHeight);
			this->tabMain->Controls->Add(this->labelSensor);
			this->tabMain->Controls->Add(this->labelSizePixel);
			this->tabMain->Controls->Add(this->labelTotalnumbers);
			this->tabMain->Controls->Add(this->labelLine);
			this->tabMain->Controls->Add(this->labelColumn);
			this->tabMain->Controls->Add(this->labelResolution);
			this->tabMain->Controls->Add(this->ptbSource);
			this->tabMain->Controls->Add(this->labelTotalImage);
			this->tabMain->Controls->Add(this->buttonCalculateGsd);
			this->tabMain->Controls->Add(this->labelGsd);
			this->tabMain->Controls->Add(this->radiobBlue);
			this->tabMain->Controls->Add(this->radiobGreen);
			this->tabMain->Controls->Add(this->radiobRed);
			this->tabMain->Controls->Add(this->labelSelectBand);
			this->tabMain->Controls->Add(this->labelLoadImages);
			this->tabMain->Controls->Add(this->buttonLoad);
			this->tabMain->Location = System::Drawing::Point(4, 22);
			this->tabMain->Name = L"tabMain";
			this->tabMain->Padding = System::Windows::Forms::Padding(3);
			this->tabMain->Size = System::Drawing::Size(398, 581);
			this->tabMain->TabIndex = 0;
			this->tabMain->Text = L"Conf. Pincipal";
			this->tabMain->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(183, 383);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(66, 13);
			this->label1->TabIndex = 33;
			this->label1->Text = L"Visualização";
			// 
			// radioButtonNir
			// 
			this->radioButtonNir->AutoSize = true;
			this->radioButtonNir->Location = System::Drawing::Point(249, 158);
			this->radioButtonNir->Name = L"radioButtonNir";
			this->radioButtonNir->Size = System::Drawing::Size(44, 17);
			this->radioButtonNir->TabIndex = 16;
			this->radioButtonNir->Text = L"NIR";
			this->radioButtonNir->UseVisualStyleBackColor = true;
			// 
			// textBoxGsd
			// 
			this->textBoxGsd->Location = System::Drawing::Point(18, 499);
			this->textBoxGsd->Name = L"textBoxGsd";
			this->textBoxGsd->ReadOnly = true;
			this->textBoxGsd->Size = System::Drawing::Size(100, 20);
			this->textBoxGsd->TabIndex = 11;
			this->textBoxGsd->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBoxFocalDistance
			// 
			this->textBoxFocalDistance->Location = System::Drawing::Point(14, 267);
			this->textBoxFocalDistance->Name = L"textBoxFocalDistance";
			this->textBoxFocalDistance->Size = System::Drawing::Size(146, 20);
			this->textBoxFocalDistance->TabIndex = 4;
			this->textBoxFocalDistance->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBoxFlightHeight
			// 
			this->textBoxFlightHeight->Location = System::Drawing::Point(14, 224);
			this->textBoxFlightHeight->Name = L"textBoxFlightHeight";
			this->textBoxFlightHeight->Size = System::Drawing::Size(146, 20);
			this->textBoxFlightHeight->TabIndex = 3;
			this->textBoxFlightHeight->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBoxSizePixelH
			// 
			this->textBoxSizePixelH->Location = System::Drawing::Point(94, 399);
			this->textBoxSizePixelH->MaxLength = 7;
			this->textBoxSizePixelH->Name = L"textBoxSizePixelH";
			this->textBoxSizePixelH->ReadOnly = true;
			this->textBoxSizePixelH->Size = System::Drawing::Size(70, 20);
			this->textBoxSizePixelH->TabIndex = 8;
			// 
			// textBoxSensorH
			// 
			this->textBoxSensorH->Location = System::Drawing::Point(94, 349);
			this->textBoxSensorH->MaxLength = 6;
			this->textBoxSensorH->Name = L"textBoxSensorH";
			this->textBoxSensorH->Size = System::Drawing::Size(70, 20);
			this->textBoxSensorH->TabIndex = 6;
			// 
			// textBoxSensorW
			// 
			this->textBoxSensorW->Location = System::Drawing::Point(18, 349);
			this->textBoxSensorW->MaxLength = 6;
			this->textBoxSensorW->Name = L"textBoxSensorW";
			this->textBoxSensorW->Size = System::Drawing::Size(70, 20);
			this->textBoxSensorW->TabIndex = 5;
			this->textBoxSensorW->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// textBoxSizePixelW
			// 
			this->textBoxSizePixelW->Location = System::Drawing::Point(18, 399);
			this->textBoxSizePixelW->MaxLength = 7;
			this->textBoxSizePixelW->Name = L"textBoxSizePixelW";
			this->textBoxSizePixelW->ReadOnly = true;
			this->textBoxSizePixelW->Size = System::Drawing::Size(70, 20);
			this->textBoxSizePixelW->TabIndex = 7;
			this->textBoxSizePixelW->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// textBoxLine
			// 
			this->textBoxLine->Location = System::Drawing::Point(94, 451);
			this->textBoxLine->Name = L"textBoxLine";
			this->textBoxLine->ReadOnly = true;
			this->textBoxLine->Size = System::Drawing::Size(70, 20);
			this->textBoxLine->TabIndex = 10;
			// 
			// textBoxColumn
			// 
			this->textBoxColumn->Location = System::Drawing::Point(18, 451);
			this->textBoxColumn->Name = L"textBoxColumn";
			this->textBoxColumn->ReadOnly = true;
			this->textBoxColumn->Size = System::Drawing::Size(70, 20);
			this->textBoxColumn->TabIndex = 9;
			this->textBoxColumn->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// textBoxImages
			// 
			this->textBoxImages->Location = System::Drawing::Point(119, 30);
			this->textBoxImages->Name = L"textBoxImages";
			this->textBoxImages->Size = System::Drawing::Size(171, 20);
			this->textBoxImages->TabIndex = 1;
			// 
			// labelFocalDistance
			// 
			this->labelFocalDistance->AutoSize = true;
			this->labelFocalDistance->Location = System::Drawing::Point(11, 251);
			this->labelFocalDistance->Name = L"labelFocalDistance";
			this->labelFocalDistance->Size = System::Drawing::Size(108, 13);
			this->labelFocalDistance->TabIndex = 28;
			this->labelFocalDistance->Text = L"Distância Focal (mm):";
			// 
			// labelFlightHeight
			// 
			this->labelFlightHeight->AutoSize = true;
			this->labelFlightHeight->Location = System::Drawing::Point(15, 208);
			this->labelFlightHeight->Name = L"labelFlightHeight";
			this->labelFlightHeight->Size = System::Drawing::Size(91, 13);
			this->labelFlightHeight->TabIndex = 27;
			this->labelFlightHeight->Text = L"Altura de Voo (m):";
			// 
			// labelSensor
			// 
			this->labelSensor->AutoSize = true;
			this->labelSensor->Location = System::Drawing::Point(15, 333);
			this->labelSensor->Name = L"labelSensor";
			this->labelSensor->Size = System::Drawing::Size(185, 13);
			this->labelSensor->TabIndex = 24;
			this->labelSensor->Text = L"Tamanho do Sensor da Câmara (mm):";
			// 
			// labelSizePixel
			// 
			this->labelSizePixel->AutoSize = true;
			this->labelSizePixel->Location = System::Drawing::Point(15, 383);
			this->labelSizePixel->Name = L"labelSizePixel";
			this->labelSizePixel->Size = System::Drawing::Size(120, 13);
			this->labelSizePixel->TabIndex = 0;
			this->labelSizePixel->Text = L"Tamanho do Pixel (mm):";
			// 
			// labelTotalnumbers
			// 
			this->labelTotalnumbers->AutoSize = true;
			this->labelTotalnumbers->Enabled = false;
			this->labelTotalnumbers->Location = System::Drawing::Point(118, 85);
			this->labelTotalnumbers->Name = L"labelTotalnumbers";
			this->labelTotalnumbers->Size = System::Drawing::Size(10, 13);
			this->labelTotalnumbers->TabIndex = 18;
			this->labelTotalnumbers->Text = L"-";
			// 
			// labelLine
			// 
			this->labelLine->AutoSize = true;
			this->labelLine->Location = System::Drawing::Point(119, 303);
			this->labelLine->Name = L"labelLine";
			this->labelLine->Size = System::Drawing::Size(33, 13);
			this->labelLine->TabIndex = 17;
			this->labelLine->Text = L"Linha";
			// 
			// labelColumn
			// 
			this->labelColumn->AutoSize = true;
			this->labelColumn->Location = System::Drawing::Point(38, 303);
			this->labelColumn->Name = L"labelColumn";
			this->labelColumn->Size = System::Drawing::Size(40, 13);
			this->labelColumn->TabIndex = 16;
			this->labelColumn->Text = L"Coluna";
			// 
			// labelResolution
			// 
			this->labelResolution->AutoSize = true;
			this->labelResolution->Location = System::Drawing::Point(15, 435);
			this->labelResolution->Name = L"labelResolution";
			this->labelResolution->Size = System::Drawing::Size(116, 13);
			this->labelResolution->TabIndex = 15;
			this->labelResolution->Text = L"Resolução da Imagem:";
			// 
			// ptbSource
			// 
			this->ptbSource->BackColor = System::Drawing::Color::White;
			this->ptbSource->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->ptbSource->Cursor = System::Windows::Forms::Cursors::Default;
			this->ptbSource->Location = System::Drawing::Point(186, 399);
			this->ptbSource->Name = L"ptbSource";
			this->ptbSource->Size = System::Drawing::Size(204, 138);
			this->ptbSource->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->ptbSource->TabIndex = 14;
			this->ptbSource->TabStop = false;
			// 
			// labelTotalImage
			// 
			this->labelTotalImage->AutoSize = true;
			this->labelTotalImage->Location = System::Drawing::Point(20, 85);
			this->labelTotalImage->Name = L"labelTotalImage";
			this->labelTotalImage->Size = System::Drawing::Size(92, 13);
			this->labelTotalImage->TabIndex = 13;
			this->labelTotalImage->Text = L"Total de Imagens:";
			// 
			// buttonCalculateGsd
			// 
			this->buttonCalculateGsd->Location = System::Drawing::Point(49, 547);
			this->buttonCalculateGsd->Name = L"buttonCalculateGsd";
			this->buttonCalculateGsd->Size = System::Drawing::Size(75, 23);
			this->buttonCalculateGsd->TabIndex = 12;
			this->buttonCalculateGsd->Text = L"Calcular";
			this->buttonCalculateGsd->UseVisualStyleBackColor = true;
			this->buttonCalculateGsd->Click += gcnew System::EventHandler(this, &MainForm::buttonCalculateGsd_Click);
			// 
			// labelGsd
			// 
			this->labelGsd->AutoSize = true;
			this->labelGsd->Location = System::Drawing::Point(15, 483);
			this->labelGsd->Name = L"labelGsd";
			this->labelGsd->Size = System::Drawing::Size(82, 13);
			this->labelGsd->TabIndex = 7;
			this->labelGsd->Text = L"GSD (cm/pixel):";
			// 
			// radiobBlue
			// 
			this->radiobBlue->AutoSize = true;
			this->radiobBlue->Location = System::Drawing::Point(181, 158);
			this->radiobBlue->Name = L"radiobBlue";
			this->radiobBlue->Size = System::Drawing::Size(45, 17);
			this->radiobBlue->TabIndex = 15;
			this->radiobBlue->Text = L"Azul";
			this->radiobBlue->UseVisualStyleBackColor = true;
			this->radiobBlue->CheckedChanged += gcnew System::EventHandler(this, &MainForm::radiobBlue_CheckedChanged);
			// 
			// radiobGreen
			// 
			this->radiobGreen->AutoSize = true;
			this->radiobGreen->Location = System::Drawing::Point(99, 158);
			this->radiobGreen->Name = L"radiobGreen";
			this->radiobGreen->Size = System::Drawing::Size(53, 17);
			this->radiobGreen->TabIndex = 14;
			this->radiobGreen->Text = L"Verde";
			this->radiobGreen->UseVisualStyleBackColor = true;
			this->radiobGreen->CheckedChanged += gcnew System::EventHandler(this, &MainForm::radiobGreen_CheckedChanged);
			// 
			// radiobRed
			// 
			this->radiobRed->AutoSize = true;
			this->radiobRed->Location = System::Drawing::Point(13, 158);
			this->radiobRed->Name = L"radiobRed";
			this->radiobRed->Size = System::Drawing::Size(69, 17);
			this->radiobRed->TabIndex = 13;
			this->radiobRed->Text = L"Vermelho";
			this->radiobRed->UseVisualStyleBackColor = true;
			this->radiobRed->CheckedChanged += gcnew System::EventHandler(this, &MainForm::radiobRed_CheckedChanged);
			// 
			// labelSelectBand
			// 
			this->labelSelectBand->AutoSize = true;
			this->labelSelectBand->Location = System::Drawing::Point(96, 128);
			this->labelSelectBand->Name = L"labelSelectBand";
			this->labelSelectBand->Size = System::Drawing::Size(94, 13);
			this->labelSelectBand->TabIndex = 3;
			this->labelSelectBand->Text = L"Selecionar Banda:";
			// 
			// labelLoadImages
			// 
			this->labelLoadImages->AutoSize = true;
			this->labelLoadImages->Location = System::Drawing::Point(20, 33);
			this->labelLoadImages->Name = L"labelLoadImages";
			this->labelLoadImages->Size = System::Drawing::Size(93, 13);
			this->labelLoadImages->TabIndex = 2;
			this->labelLoadImages->Text = L"Carregar Imagens:";
			// 
			// buttonLoad
			// 
			this->buttonLoad->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonLoad->Location = System::Drawing::Point(296, 29);
			this->buttonLoad->Name = L"buttonLoad";
			this->buttonLoad->Size = System::Drawing::Size(75, 23);
			this->buttonLoad->TabIndex = 2;
			this->buttonLoad->Text = L"Carregar";
			this->buttonLoad->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->buttonLoad->UseVisualStyleBackColor = true;
			this->buttonLoad->Click += gcnew System::EventHandler(this, &MainForm::buttonLoad_Click);
			// 
			// tabControl
			// 
			this->tabControl->Controls->Add(this->tabMain);
			this->tabControl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl->Location = System::Drawing::Point(0, 24);
			this->tabControl->Name = L"tabControl";
			this->tabControl->SelectedIndex = 0;
			this->tabControl->Size = System::Drawing::Size(406, 607);
			this->tabControl->TabIndex = 0;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(406, 631);
			this->Controls->Add(this->tabControl);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainForm";
			this->Text = L"Imagery Process";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->tabMain->ResumeLayout(false);
			this->tabMain->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ptbSource))->EndInit();
			this->tabControl->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion

//private: Mat ToResize(Mat src) {	// Rezise image method
//	Mat dst;
//	resize(src, dst, cv::Size(800, 600), 0, 0, 1); // we need to define new size onn cv:Sizze(width, height)
//	return dst;
//
//}

private:
		 
public: System::Void carregarToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	buttonLoad_Click(sender, e);
}

public: System::Void buttonLoad_Click(System::Object^  sender, System::EventArgs^  e) {
		int firstImage = 0, band = 0;
		Tools.ResizeWin(MainWindow);

		// Load image from PC & show into picture box
		OpenFileDialog^ dgOpen = gcnew OpenFileDialog();
		dgOpen->Multiselect = true;
		dgOpen->Filter = "Image(*.bmp; *.jpg)|*.bmp;*.jpg|All files (*.*)|*.*||";

		if (dgOpen->ShowDialog() == System::Windows::Forms::DialogResult::Cancel)
		{
			return;
		}

		Bitmap^ bmpSrc = gcnew Bitmap(dgOpen->FileNames[firstImage]);
		this->textBoxImages->Text = dgOpen->FileNames[firstImage];
		

		//path of images
		auto pathList = dgOpen->FileNames;

		//update total of images displayed
		labelTotalnumbers->Text = System::Convert::ToString(dgOpen->FileNames->Length);
		labelTotalnumbers->Enabled = true;

		//load and refresh image
		ptbSource->Image = bmpSrc;
		ptbSource->Refresh();

		// get resolution of the first image
		int imageWidth = bmpSrc->Width;
		int imageHeight = bmpSrc->Height;		
		textBoxColumn->Text = System::Convert::ToString(imageWidth);
		textBoxLine->Text = System::Convert::ToString(imageHeight);

		

		// load image into src variable and show as OpenCV method.
		src = imread(Tools.ConvertString2Char(dgOpen->FileNames[firstImage]), CV_LOAD_IMAGE_COLOR); // We need to convert file name to char by Marshal method
		
		//check if everything was fine
		if (!src.data)
		{
			return ;
		}

		namedWindow(MainWindow);
		//resizeimage = ToResize(src);

		//convert to gray sacale
		cvtColor(src, src_gray, CV_BGR2GRAY);

		//show source image
		imshow(MainWindow, src_gray);
		//DrawCVImage(ptbSource, dst);
		//imshow("Source image showing via OpenCV", src);
	}

private: System::Void buttonCalculateGsd_Click(System::Object^  sender, System::EventArgs^  e) {
	double sensorW = 0, sensorH = 0, pixelW = 0, pixelH = 0, resolutionW = 0, resolutionH = 0, GSD = 0;

	if (System::String::IsNullOrWhiteSpace(textBoxFocalDistance->Text) ||  System::String::IsNullOrWhiteSpace(textBoxFlightHeight->Text) 
		|| System::String::IsNullOrWhiteSpace(textBoxSensorH->Text) || System::String::IsNullOrWhiteSpace(textBoxSensorW->Text) )
	{
		MessageBox::Show("Está faltando algum parâmetro.", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		return;
	}

	//Convert values to double
	sensorW = System::Convert::ToDouble(textBoxSensorW->Text);
	sensorH = System::Convert::ToDouble(textBoxSensorH->Text);
	resolutionW = System::Convert::ToDouble(textBoxColumn->Text);
	resolutionH = System::Convert::ToDouble(textBoxLine->Text);

	pixelW = sensorW / resolutionW;
	pixelH = sensorH / resolutionH;
	pixelW = round(pixelW * 10000) / 10000;
	pixelH = round(pixelH * 10000) / 10000;

	//convert values back to string
	this->textBoxSizePixelW->Text = System::Convert::ToString(pixelW);
	this->textBoxSizePixelH->Text = System::Convert::ToString(pixelH);

	//calculate GSD
	GSD = (System::Convert::ToDouble(textBoxFlightHeight->Text) / 
		(System::Convert::ToDouble(textBoxFocalDistance->Text)/1000)) * (pixelW/1000);
	this->textBoxGsd->Text = System::Convert::ToString(GSD*100);

}

private: System::Void sairToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	destroyAllWindows;
	Application::Exit();
}

private: System::Void MainForm_FormClosing(System::Object^  sender, System::EventArgs^  e) {
	sairToolStripMenuItem_Click(sender, e);
}

//SELEC BAND
private: System::Void radiobRed_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (System::String::IsNullOrWhiteSpace(textBoxImages->Text))
	{
		radiobRed->Checked = false;
		MessageBox::Show("Selecione as imagens primeiro.", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		return;
	}
	else if (radiobRed->Checked == true)
	{
		SelectBand(sender, e, Red);
	}
}
private: System::Void radiobGreen_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {	
	if (System::String::IsNullOrWhiteSpace(textBoxImages->Text))
	{
		radiobGreen->Checked = false;
		MessageBox::Show("Selecione as imagens primeiro.", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		return;
	}
	else if (radiobGreen->Checked == true)
	{
		SelectBand(sender, e, Green);
	}
}
private: System::Void radiobBlue_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {	
	if (System::String::IsNullOrWhiteSpace(textBoxImages->Text))
	{
		radiobBlue->Checked = false;
		MessageBox::Show("Selecione as imagens primeiro.", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);		
		return;
	}
	else if (radiobBlue->Checked == true)
	{
		SelectBand(sender, e, Blue);
	}
}

private: System::Void SelectBand(System::Object^ sender, System::EventArgs^ e, int choice)
{
	
	split(src, bgr);
	
	if (choice == Red)
	{

		imshow(MainWindow, bgr[Red]);
		bandSelected = Red;
		return;
	}
	else if (choice == Green)
	{
		imshow(MainWindow, bgr[Green]);
		bandSelected = Green;
		return;
	}
	else if (choice == Blue)
	{
		imshow(MainWindow, bgr[Blue]);
		bandSelected = Blue;
		return;
	}
	return;
}
		 
//THRESHOLD FUNCTIONS
private: System::Void binarioToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	Mat dst;
	if (System::String::IsNullOrWhiteSpace(textBoxImages->Text) || bandSelected >= 4)
	{
		MessageBox::Show("Selecione as imagens e a Banda.", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		return;
	}
	createTrackbar("Valor:", MainWindow, &threshold_value, max_value);
	while (1)
	{
		threshold(bgr[bandSelected], dst1, threshold_value, max_BINARY_value, THRESH_BINARY);
		imshow(MainWindow, dst1);
		int key = waitKey(20);
		if ((char)key == 27)
		{
			destroyWindow(MainWindow);
			Tools.ResizeWin(MainWindow);
			imshow(MainWindow, src_gray);
			break;
		}
	}
}
private: System::Void binarioInvertidoToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	Mat dst;
	if (System::String::IsNullOrWhiteSpace(textBoxImages->Text) || bandSelected >= 4)
	{
		MessageBox::Show("Selecione as imagens e a Banda.", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		return;
	}
	createTrackbar("Valor:", MainWindow, &threshold_value, max_value);
	while (1)
	{
		threshold(bgr[bandSelected], dst1, threshold_value, max_BINARY_value, THRESH_BINARY_INV);
		imshow(MainWindow, dst1);
		int key = waitKey(20);
		if ((char)key == 27)
		{
			destroyWindow(MainWindow);
			Tools.ResizeWin(MainWindow);
			imshow(MainWindow, src_gray);
			break;
		}
	}
}
private: System::Void truncadoToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	Mat dst;
	if (System::String::IsNullOrWhiteSpace(textBoxImages->Text) || bandSelected >= 4)
	{
		MessageBox::Show("Selecione as imagens e a Banda.", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		return;
	}
	createTrackbar("Valor:", MainWindow, &threshold_value, max_value);
	while (1)
	{
		threshold(bgr[bandSelected], dst1, threshold_value, max_BINARY_value, THRESH_TRUNC);
		imshow(MainWindow, dst1);
		int key = waitKey(20);
		if ((char)key == 27)
		{
			destroyWindow(MainWindow);
			Tools.ResizeWin(MainWindow);
			imshow(MainWindow, src_gray);
			break;
		}
	}
}
private: System::Void zeroToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	Mat dst;
	if (System::String::IsNullOrWhiteSpace(textBoxImages->Text) || bandSelected >= 4)
	{
		MessageBox::Show("Selecione as imagens e a Banda.", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		return;
	}
	createTrackbar("Valor:", MainWindow, &threshold_value, max_value);
	while (1)
	{
		threshold(bgr[bandSelected], dst1, threshold_value, max_BINARY_value, THRESH_TOZERO);
		imshow(MainWindow, dst1);
		int key = waitKey(20);
		if ((char)key == 27)
		{
			destroyWindow(MainWindow);
			Tools.ResizeWin(MainWindow);
			imshow(MainWindow, src_gray);
			break;
		}
	}
}
private: System::Void zeroInvertidoToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	Mat dst;
	if (System::String::IsNullOrWhiteSpace(textBoxImages->Text) || bandSelected >= 4)
	{
		MessageBox::Show("Selecione as imagens e a Banda.", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		return;
	}
	createTrackbar("Valor:", MainWindow, &threshold_value, max_value);
	while (1)
	{
		threshold(bgr[bandSelected], dst1, threshold_value, max_BINARY_value, THRESH_TOZERO_INV);
		imshow(MainWindow, dst1);
		int key = waitKey(20);
		if ((char)key == 27)
		{
			destroyWindow(MainWindow);
			Tools.ResizeWin(MainWindow);
			imshow(MainWindow, src_gray);
			break;
		}
	}
}
//END THRESHOLD FUNCIONS

//OTSU PART
private: System::Void binarioToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
	Mat dst;
	if (System::String::IsNullOrWhiteSpace(textBoxImages->Text) || bandSelected >= 4)
	{
		MessageBox::Show("Selecione as imagens e a Banda.", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		return;
	}

	//createTrackbar("Valor:", MainWindow, &threshold_value, max_value);
	while (1)
	{
		threshold(bgr[bandSelected], dst1, threshold_value, max_BINARY_value, THRESH_BINARY + THRESH_OTSU);
		imshow(MainWindow, dst1);
		int key = waitKey(20);
		if ((char)key == 27)
		{
			destroyWindow(MainWindow);
			Tools.ResizeWin(MainWindow);
			imshow(MainWindow, src_gray);
			break;
		}
	}
}
private: System::Void binarioInvertidoToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
			 Mat dst;
			 if (System::String::IsNullOrWhiteSpace(textBoxImages->Text) || bandSelected >= 4)
			 {
				 MessageBox::Show("Selecione as imagens e a Banda.", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
				 return;
			 }

			 //createTrackbar("Valor:", MainWindow, &threshold_value, max_value);
			 while (1)
			 {
				 threshold(bgr[bandSelected], dst1, threshold_value, max_BINARY_value, THRESH_BINARY_INV + THRESH_OTSU);
				 imshow(MainWindow, dst1);
				 int key = waitKey(20);
				 if ((char)key == 27)
				 {
					 destroyWindow(MainWindow);
					 Tools.ResizeWin(MainWindow);
					 imshow(MainWindow, src_gray);
					 break;
				 }
			 }
		 }
private: System::Void truncadoToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
	Mat dst;
	if (System::String::IsNullOrWhiteSpace(textBoxImages->Text) || bandSelected >= 4)
	{
		MessageBox::Show("Selecione as imagens e a Banda.", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		return;
	}

	//createTrackbar("Valor:", MainWindow, &threshold_value, max_value);
	while (1)
	{
		threshold(bgr[bandSelected], dst1, threshold_value, max_BINARY_value, THRESH_TRUNC + THRESH_OTSU);
		imshow(MainWindow, dst1);
		int key = waitKey(20);
		if ((char)key == 27)
		{
			destroyWindow(MainWindow);
			Tools.ResizeWin(MainWindow);
			imshow(MainWindow, src_gray);
			break;
		}
	}
}
private: System::Void zeroToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
	Mat dst;
	if (System::String::IsNullOrWhiteSpace(textBoxImages->Text) || bandSelected >= 4)
	{
		MessageBox::Show("Selecione as imagens e a Banda.", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		return;
	}

	//createTrackbar("Valor:", MainWindow, &threshold_value, max_value);
	while (1)
	{
		threshold(bgr[bandSelected], dst1, threshold_value, max_BINARY_value, THRESH_TOZERO + THRESH_OTSU);
		imshow(MainWindow, dst1);
		int key = waitKey(20);
		if ((char)key == 27)
		{
			destroyWindow(MainWindow);
			Tools.ResizeWin(MainWindow);
			imshow(MainWindow, src_gray);
			break;
		}
	}
}
private: System::Void zeroInvertidoToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
	Mat dst;
	if (System::String::IsNullOrWhiteSpace(textBoxImages->Text) || bandSelected >= 4)
	{
		MessageBox::Show("Selecione as imagens e a Banda.", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		return;
	}

	//createTrackbar("Valor:", MainWindow, &threshold_value, max_value);
	while (1)
	{
		threshold(bgr[bandSelected], dst1, threshold_value, max_BINARY_value, THRESH_TOZERO_INV + THRESH_OTSU);
		imshow(MainWindow, dst1);
		int key = waitKey(20);
		if ((char)key == 27)
		{
			destroyWindow(MainWindow);
			Tools.ResizeWin(MainWindow);
			imshow(MainWindow, src_gray);
			break;
		}
	}
}
//END OTSU

//TRIANGLE
private: System::Void binarioToolStripMenuItem2_Click(System::Object^  sender, System::EventArgs^  e) {
	Mat dst;
	if (System::String::IsNullOrWhiteSpace(textBoxImages->Text) || bandSelected >= 4)
	{
		MessageBox::Show("Selecione as imagens e a Banda.", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		return;
	}

	//createTrackbar("Valor:", MainWindow, &threshold_value, max_value);
	while (1)
	{
		threshold(bgr[bandSelected], dst1, threshold_value, max_BINARY_value, THRESH_BINARY + THRESH_TRIANGLE);
		imshow(MainWindow, dst1);
		int key = waitKey(20);
		if ((char)key == 27)
		{
			destroyWindow(MainWindow);
			Tools.ResizeWin(MainWindow);
			imshow(MainWindow, src_gray);
			break;
		}
	}
}
private: System::Void binarioInvertidoToolStripMenuItem2_Click(System::Object^  sender, System::EventArgs^  e) {
			 Mat dst;
			 if (System::String::IsNullOrWhiteSpace(textBoxImages->Text) || bandSelected >= 4)
			 {
				 MessageBox::Show("Selecione as imagens e a Banda.", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
				 return;
			 }

			 //createTrackbar("Valor:", MainWindow, &threshold_value, max_value);
			 while (1)
			 {
				 threshold(bgr[bandSelected], dst1, threshold_value, max_BINARY_value, THRESH_BINARY_INV + THRESH_TRIANGLE);
				 imshow(MainWindow, dst1);
				 int key = waitKey(20);
				 if ((char)key == 27)
				 {
					 destroyWindow(MainWindow);
					 Tools.ResizeWin(MainWindow);
					 imshow(MainWindow, src_gray);
					 break;
				 }
			 }
		 }
private: System::Void truncadoToolStripMenuItem2_Click(System::Object^  sender, System::EventArgs^  e) {
	Mat dst;
	if (System::String::IsNullOrWhiteSpace(textBoxImages->Text) || bandSelected >= 4)
	{
		MessageBox::Show("Selecione as imagens e a Banda.", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		return;
	}

	//createTrackbar("Valor:", MainWindow, &threshold_value, max_value);
	while (1)
	{
		threshold(bgr[bandSelected], dst1, threshold_value, max_BINARY_value, THRESH_TRUNC + THRESH_TRIANGLE);
		imshow(MainWindow, dst1);
		int key = waitKey(20);
		if ((char)key == 27)
		{
			destroyWindow(MainWindow);
			Tools.ResizeWin(MainWindow);
			imshow(MainWindow, src_gray);
			break;
		}
	}
}
private: System::Void zeroToolStripMenuItem2_Click(System::Object^  sender, System::EventArgs^  e) {
	Mat dst;
	if (System::String::IsNullOrWhiteSpace(textBoxImages->Text) || bandSelected >= 4)
	{
		MessageBox::Show("Selecione as imagens e a Banda.", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		return;
	}

	//createTrackbar("Valor:", MainWindow, &threshold_value, max_value);
	while (1)
	{
		threshold(bgr[bandSelected], dst1, threshold_value, max_BINARY_value, THRESH_TOZERO + THRESH_TRIANGLE);
		imshow(MainWindow, dst1);
		int key = waitKey(20);
		if ((char)key == 27)
		{
			destroyWindow(MainWindow);
			Tools.ResizeWin(MainWindow);
			imshow(MainWindow, src_gray);
			break;
		}
	}
}
private: System::Void zeroInvertidoToolStripMenuItem2_Click(System::Object^  sender, System::EventArgs^  e) {
	Mat dst;
	if (System::String::IsNullOrWhiteSpace(textBoxImages->Text) || bandSelected >= 4)
	{
		MessageBox::Show("Selecione as imagens e a Banda.", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		return;
	}

	//createTrackbar("Valor:", MainWindow, &threshold_value, max_value);
	while (1)
	{
		threshold(bgr[bandSelected], dst1, threshold_value, max_BINARY_value, THRESH_TOZERO_INV + THRESH_TRIANGLE);
		imshow(MainWindow, dst1);
		int key = waitKey(20);
		if ((char)key == 27)
		{
			destroyWindow(MainWindow);
			Tools.ResizeWin(MainWindow);
			imshow(MainWindow, src_gray);
			break;
		}
	}
}
//END TRIANGLE

private: System::Void watershedToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
	//Variables
	Mat temp;
	temp = bgr[bandSelected];
	Mat image, binary, fg, bg;

	std::vector <Mat> teste;
	split(src, teste);
	image = src;
	binary = teste[bandSelected];  // = cv::imread(argv[2], 0);
	//cv::cvtColor(image, binary, CV_BGR2GRAY);
	cv::threshold(binary, binary, 100, 255, THRESH_BINARY + THRESH_TRIANGLE);

	Tools.ResizeWin("final_result");
	namedWindow("fg", WINDOW_NORMAL);
	namedWindow("bg", WINDOW_NORMAL);
	namedWindow("bg1", WINDOW_NORMAL);
	namedWindow("markers", WINDOW_NORMAL);
	namedWindow("final_result", WINDOW_NORMAL);
	//imshow("originalimage", image);
	//imshow("originalbinary", binary);

	// Eliminate noise and smaller objects
	//cv::Mat fg;
	cv::erode(binary, fg, cv::Mat(), cv::Point(-1, -1), 0);
	imshow("fg", fg);


	// Identify image pixels without objects
	//cv::Mat bg;
	cv::dilate(binary, bg, cv::Mat(), cv::Point(-1, -1), 3);
	imshow("bg", bg);
	cv::threshold(bg, bg, 1, 128, cv::THRESH_BINARY + THRESH_TRIANGLE);
	imshow("bg1", bg);

	// Create markers image
	cv::Mat markers(binary.size(), CV_8U, cv::Scalar(0));
	markers = fg + bg;
	imshow("markers", markers);

	// Create watershed segmentation object
	diptools segmenter;
	segmenter.setMarkers(markers);

	cv::Mat result = segmenter.process(image);
	result.convertTo(result, CV_8U);
	imshow("final_result", result);
}

private: System::Void erodingAndDilatingToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	Mat image, binary, fg, bg;
	image = src;
	binary = dst1;
	//cv::threshold(binary, binary, 100, 255, THRESH_BINARY + THRESH_TRIANGLE);
	
	cv::erode(binary, fg, cv::Mat(), cv::Point(-1, -1), 0);

	cv::dilate(binary, bg, cv::Mat(), cv::Point(-1, -1), 3);


	cv::threshold(bg, bg, 1, 128, cv::THRESH_BINARY + THRESH_TRIANGLE);

	cv::Mat markers(binary.size(), CV_8U, cv::Scalar(0));

	markers = fg + bg;

	diptools segmenter;

	segmenter.setMarkers(markers);

	cv::Mat result = segmenter.process(image);

	result.convertTo(result, CV_8U);
	Tools.ResizeWin("Resultado Watershed");
	imshow("Resultado Watershed", result);

}

private: System::Void distanciaToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	// Load the image
	Mat src = bgr[bandSelected];
	// Check if everything was fine
	if (!src.data)
		return;
	// Show source image
	imshow("Source Image", src);
	// Change the background from white to black, since that will help later to extract
	// better results during the use of Distance Transform
	for (int x = 0; x < src.rows; x++) {
		for (int y = 0; y < src.cols; y++) {
			if (src.at<Vec3b>(x, y) == Vec3b(255, 255, 255)) {
				src.at<Vec3b>(x, y)[0] = 0;
				src.at<Vec3b>(x, y)[1] = 0;
				src.at<Vec3b>(x, y)[2] = 0;
			}
		}
	}
	// Show output image
	imshow("Black Background Image", src);
	// Create a kernel that we will use for accuting/sharpening our image
	Mat kernel = (Mat_<float>(3, 3) <<
		1, 1, 1,
		1, -8, 1,
		1, 1, 1); // an approximation of second derivative, a quite strong kernel
				  // do the laplacian filtering as it is
				  // well, we need to convert everything in something more deeper then CV_8U
				  // because the kernel has some negative values,
				  // and we can expect in general to have a Laplacian image with negative values
				  // BUT a 8bits unsigned int (the one we are working with) can contain values from 0 to 255
				  // so the possible negative number will be truncated
	Mat imgLaplacian;
	Mat sharp = src; // copy source image to another temporary one
	filter2D(sharp, imgLaplacian, CV_32F, kernel);
	src.convertTo(sharp, CV_32F);
	Mat imgResult = sharp - imgLaplacian;
	// convert back to 8bits gray scale
	imgResult.convertTo(imgResult, CV_8UC3);
	imgLaplacian.convertTo(imgLaplacian, CV_8UC3);
	// imshow( "Laplace Filtered Image", imgLaplacian );
	imshow("New Sharped Image", imgResult);
	src = imgResult; // copy back
					 // Create binary image from source image
	Mat bw;
	cvtColor(src, bw, CV_BGR2GRAY);
	threshold(bw, bw, 40, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);
	imshow("Binary Image", bw);
	// Perform the distance transform algorithm
	Mat dist;
	distanceTransform(bw, dist, CV_DIST_L2, 3);
	// Normalize the distance image for range = {0.0, 1.0}
	// so we can visualize and threshold it
	normalize(dist, dist, 0, 1., NORM_MINMAX);
	imshow("Distance Transform Image", dist);
	// Threshold to obtain the peaks
	// This will be the markers for the foreground objects
	threshold(dist, dist, .4, 1., CV_THRESH_BINARY);
	// Dilate a bit the dist image
	Mat kernel1 = Mat::ones(3, 3, CV_8UC1);
	dilate(dist, dist, kernel1);
	imshow("Peaks", dist);
	// Create the CV_8U version of the distance image
	// It is needed for findContours()
	Mat dist_8u;
	dist.convertTo(dist_8u, CV_8U);
	// Find total markers
	std::vector<std::vector<cv::Point> > contours;
	findContours(dist_8u, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);
	// Create the marker image for the watershed algorithm
	Mat markers = Mat::zeros(dist.size(), CV_32SC1);
	// Draw the foreground markers
	for (size_t i = 0; i < contours.size(); i++)
		drawContours(markers, contours, static_cast<int>(i), Scalar::all(static_cast<int>(i) + 1), -1);
	// Draw the background marker
	circle(markers, cv::Point::Point_(5, 5), 3, CV_RGB(255, 255, 255), -1);
	imshow("Markers", markers * 10000);
	// Perform the watershed algorithm
	watershed(src, markers);
	Mat mark = Mat::zeros(markers.size(), CV_8UC1);
	markers.convertTo(mark, CV_8UC1);
	bitwise_not(mark, mark);
	//    imshow("Markers_v2", mark); // uncomment this if you want to see how the mark
	// image looks like at that point
	// Generate random colors
	std::vector<Vec3b> colors;
	for (size_t i = 0; i < contours.size(); i++)
	{
		int b = theRNG().uniform(0, 255);
		int g = theRNG().uniform(0, 255);
		int r = theRNG().uniform(0, 255);
		colors.push_back(Vec3b((uchar)b, (uchar)g, (uchar)r));
	}
	// Create the result image
	Mat dst = Mat::zeros(markers.size(), CV_8UC3);
	// Fill labeled objects with random colors
	for (int i = 0; i < markers.rows; i++)
	{
		for (int j = 0; j < markers.cols; j++)
		{
			int index = markers.at<int>(i, j);
			if (index > 0 && index <= static_cast<int>(contours.size()))
				dst.at<Vec3b>(i, j) = colors[index - 1];
			else
				dst.at<Vec3b>(i, j) = Vec3b(0, 0, 0);
		}
	}
	// Visualize the final image
	imshow("Final Result", dst);

}
private: System::Void salvarToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	SaveFileDialog^ dgSave = gcnew SaveFileDialog();
	dgSave->Filter = "Image(*.bmp; *.jpg)|*.bmp;*.jpg|All files (*.*)|*.*||";
	dgSave->DefaultExt = ".jpg";
	dgSave->InitialDirectory = textBoxImages->Text;
	if (dgSave->ShowDialog() == System::Windows::Forms::DialogResult::Cancel)
	{
		return;
	}
	imwrite(Tools.ConvertString2Char(dgSave->FileName), dst1);
}
};
}




