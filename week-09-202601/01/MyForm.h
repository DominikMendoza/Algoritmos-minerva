#pragma once
#include "Elipse.hpp"
#include "Figura.hpp"
#include "Rectangulo.hpp"


namespace Project121 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		Graphics^ g;
		Figura* figura;
	public:
		MyForm(void)
		{
			InitializeComponent();
			g = canvas->CreateGraphics();
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
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txbPosicionEnX;
	private: System::Windows::Forms::TextBox^ txbPosicionEnY;



	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ gbElipse;

	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ txbRadio;
	private: System::Windows::Forms::GroupBox^ gbRectangulo;


	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ txbLado2;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ txbLado1;
	private: System::Windows::Forms::Label^ lblAreaElipse;
	private: System::Windows::Forms::Label^ lblAreaRectangulo;



	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Panel^ canvas;

	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ComboBox^ cbFigura;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txbPosicionEnX = (gcnew System::Windows::Forms::TextBox());
			this->txbPosicionEnY = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->gbElipse = (gcnew System::Windows::Forms::GroupBox());
			this->lblAreaElipse = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txbRadio = (gcnew System::Windows::Forms::TextBox());
			this->gbRectangulo = (gcnew System::Windows::Forms::GroupBox());
			this->lblAreaRectangulo = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->txbLado2 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->txbLado1 = (gcnew System::Windows::Forms::TextBox());
			this->canvas = (gcnew System::Windows::Forms::Panel());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->cbFigura = (gcnew System::Windows::Forms::ComboBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->gbElipse->SuspendLayout();
			this->gbRectangulo->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(20, 34);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(105, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Posicion en X";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(20, 75);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(105, 20);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Posicion en Y";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// txbPosicionEnX
			// 
			this->txbPosicionEnX->Location = System::Drawing::Point(141, 34);
			this->txbPosicionEnX->Name = L"txbPosicionEnX";
			this->txbPosicionEnX->Size = System::Drawing::Size(100, 20);
			this->txbPosicionEnX->TabIndex = 2;
			// 
			// txbPosicionEnY
			// 
			this->txbPosicionEnY->Location = System::Drawing::Point(141, 75);
			this->txbPosicionEnY->Name = L"txbPosicionEnY";
			this->txbPosicionEnY->Size = System::Drawing::Size(100, 20);
			this->txbPosicionEnY->TabIndex = 3;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->txbPosicionEnY);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->txbPosicionEnX);
			this->groupBox1->Location = System::Drawing::Point(12, 98);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(263, 128);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Posicion inicial";
			// 
			// gbElipse
			// 
			this->gbElipse->Controls->Add(this->lblAreaElipse);
			this->gbElipse->Controls->Add(this->label3);
			this->gbElipse->Controls->Add(this->label4);
			this->gbElipse->Controls->Add(this->txbRadio);
			this->gbElipse->Enabled = false;
			this->gbElipse->Location = System::Drawing::Point(314, 98);
			this->gbElipse->Name = L"gbElipse";
			this->gbElipse->Size = System::Drawing::Size(263, 128);
			this->gbElipse->TabIndex = 5;
			this->gbElipse->TabStop = false;
			this->gbElipse->Text = L"Elipse";
			// 
			// lblAreaElipse
			// 
			this->lblAreaElipse->AutoSize = true;
			this->lblAreaElipse->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblAreaElipse->Location = System::Drawing::Point(124, 75);
			this->lblAreaElipse->Name = L"lblAreaElipse";
			this->lblAreaElipse->Size = System::Drawing::Size(133, 20);
			this->lblAreaElipse->TabIndex = 3;
			this->lblAreaElipse->Text = L"Mostrar area aqui";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(20, 34);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(51, 20);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Radio";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(20, 75);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(43, 20);
			this->label4->TabIndex = 1;
			this->label4->Text = L"Area";
			// 
			// txbRadio
			// 
			this->txbRadio->Location = System::Drawing::Point(141, 34);
			this->txbRadio->Name = L"txbRadio";
			this->txbRadio->Size = System::Drawing::Size(100, 20);
			this->txbRadio->TabIndex = 2;
			// 
			// gbRectangulo
			// 
			this->gbRectangulo->Controls->Add(this->lblAreaRectangulo);
			this->gbRectangulo->Controls->Add(this->label9);
			this->gbRectangulo->Controls->Add(this->label5);
			this->gbRectangulo->Controls->Add(this->txbLado2);
			this->gbRectangulo->Controls->Add(this->label6);
			this->gbRectangulo->Controls->Add(this->txbLado1);
			this->gbRectangulo->Enabled = false;
			this->gbRectangulo->Location = System::Drawing::Point(629, 98);
			this->gbRectangulo->Name = L"gbRectangulo";
			this->gbRectangulo->Size = System::Drawing::Size(263, 167);
			this->gbRectangulo->TabIndex = 5;
			this->gbRectangulo->TabStop = false;
			this->gbRectangulo->Text = L"Rectangulo";
			// 
			// lblAreaRectangulo
			// 
			this->lblAreaRectangulo->AutoSize = true;
			this->lblAreaRectangulo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblAreaRectangulo->Location = System::Drawing::Point(124, 119);
			this->lblAreaRectangulo->Name = L"lblAreaRectangulo";
			this->lblAreaRectangulo->Size = System::Drawing::Size(133, 20);
			this->lblAreaRectangulo->TabIndex = 7;
			this->lblAreaRectangulo->Text = L"Mostrar area aqui";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(21, 119);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(43, 20);
			this->label9->TabIndex = 6;
			this->label9->Text = L"Area";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(20, 34);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(58, 20);
			this->label5->TabIndex = 0;
			this->label5->Text = L"Lado 1";
			// 
			// txbLado2
			// 
			this->txbLado2->Location = System::Drawing::Point(141, 75);
			this->txbLado2->Name = L"txbLado2";
			this->txbLado2->Size = System::Drawing::Size(100, 20);
			this->txbLado2->TabIndex = 3;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(20, 75);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(58, 20);
			this->label6->TabIndex = 1;
			this->label6->Text = L"Lado 2";
			// 
			// txbLado1
			// 
			this->txbLado1->Location = System::Drawing::Point(141, 34);
			this->txbLado1->Name = L"txbLado1";
			this->txbLado1->Size = System::Drawing::Size(100, 20);
			this->txbLado1->TabIndex = 2;
			// 
			// canvas
			// 
			this->canvas->Location = System::Drawing::Point(12, 271);
			this->canvas->Name = L"canvas";
			this->canvas->Size = System::Drawing::Size(885, 352);
			this->canvas->TabIndex = 6;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->button1);
			this->groupBox4->Controls->Add(this->cbFigura);
			this->groupBox4->Controls->Add(this->label10);
			this->groupBox4->Location = System::Drawing::Point(12, 9);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(885, 83);
			this->groupBox4->TabIndex = 7;
			this->groupBox4->TabStop = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(286, 31);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(572, 23);
			this->button1->TabIndex = 8;
			this->button1->Text = L"Dibujar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// cbFigura
			// 
			this->cbFigura->FormattingEnabled = true;
			this->cbFigura->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Elipse", L"Rectangulo" });
			this->cbFigura->Location = System::Drawing::Point(141, 31);
			this->cbFigura->Name = L"cbFigura";
			this->cbFigura->Size = System::Drawing::Size(121, 21);
			this->cbFigura->TabIndex = 5;
			this->cbFigura->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::cbFigura_SelectedIndexChanged);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(20, 29);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(98, 20);
			this->label10->TabIndex = 4;
			this->label10->Text = L"Elegir Figura";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(909, 635);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->canvas);
			this->Controls->Add(this->gbRectangulo);
			this->Controls->Add(this->gbElipse);
			this->Controls->Add(this->groupBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->gbElipse->ResumeLayout(false);
			this->gbElipse->PerformLayout();
			this->gbRectangulo->ResumeLayout(false);
			this->gbRectangulo->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		g->Clear(Color::White);
		int x, y, radio, lado1, lado2;

		x = Convert::ToInt32(txbPosicionEnX->Text);
		y = Convert::ToInt32(txbPosicionEnY->Text);
		
		if (cbFigura->SelectedItem == "Rectangulo") {
			lado1 = Convert::ToInt32(txbLado1->Text);
			lado2 = Convert::ToInt32(txbLado2->Text);
			figura = new Rectangulo(x, y, lado1, lado2);
			lblAreaRectangulo->Text = figura->calcularArea().ToString() + "u^2";
		}
		if (cbFigura->SelectedItem == "Elipse") {
			radio = Convert::ToInt32(txbRadio->Text);
			figura = new Elipse(x, y, radio);
			lblAreaElipse->Text = figura->calcularArea().ToString() + "u^2";
		}

		figura->dibujar(g);
		delete figura;
		
	}
private: System::Void cbFigura_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (cbFigura->SelectedItem == "Elipse") {
		gbElipse->Enabled = true;
		gbRectangulo->Enabled = false;
	}
	if (cbFigura->SelectedItem == "Rectangulo") {
		gbElipse->Enabled = false;
		gbRectangulo->Enabled = true;
	}
}
};
}
