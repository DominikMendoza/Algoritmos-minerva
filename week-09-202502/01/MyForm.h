#pragma once
#include "Circulo.hpp"
#include "Rectangulo.hpp"

namespace Project97 {

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
		Figura* fig;
	private: System::Windows::Forms::GroupBox^ gbRectangulo;
	private: System::Windows::Forms::Label^ lblRecArea;

	private: System::Windows::Forms::Label^ lblRecLado1;
	private: System::Windows::Forms::Label^ lblRecLado2;

	private: System::Windows::Forms::TextBox^ tbRecLado1;
	private: System::Windows::Forms::TextBox^ tbRecLado2;
	private: System::Windows::Forms::Label^ lblRecAreaResultado;
	private: System::Windows::Forms::GroupBox^ gbElipse;
	private: System::Windows::Forms::Label^ lblElipseAreaResultado;
	private: System::Windows::Forms::Label^ lblElipseArea;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ tbElipseRadio;

	private: System::Windows::Forms::GroupBox^ gbDibujo;
	private: System::Windows::Forms::ComboBox^ cbFiguras;
	private: System::Windows::Forms::Label^ lblFigura;
		   Graphics^ g;
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
	private: System::Windows::Forms::Button^ btnDibujar;
	private: System::Windows::Forms::TextBox^ tbPosX;
	private: System::Windows::Forms::Label^ lblPosX;


	private: System::Windows::Forms::TextBox^ tbPosY;
	private: System::Windows::Forms::Label^ lblPosY;
	private: System::Windows::Forms::GroupBox^ gbCoordenadas;
	private: System::Windows::Forms::Panel^ canvas;


	protected:

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
			this->btnDibujar = (gcnew System::Windows::Forms::Button());
			this->tbPosX = (gcnew System::Windows::Forms::TextBox());
			this->lblPosX = (gcnew System::Windows::Forms::Label());
			this->tbPosY = (gcnew System::Windows::Forms::TextBox());
			this->lblPosY = (gcnew System::Windows::Forms::Label());
			this->gbCoordenadas = (gcnew System::Windows::Forms::GroupBox());
			this->canvas = (gcnew System::Windows::Forms::Panel());
			this->gbRectangulo = (gcnew System::Windows::Forms::GroupBox());
			this->lblRecAreaResultado = (gcnew System::Windows::Forms::Label());
			this->lblRecArea = (gcnew System::Windows::Forms::Label());
			this->lblRecLado1 = (gcnew System::Windows::Forms::Label());
			this->lblRecLado2 = (gcnew System::Windows::Forms::Label());
			this->tbRecLado1 = (gcnew System::Windows::Forms::TextBox());
			this->tbRecLado2 = (gcnew System::Windows::Forms::TextBox());
			this->gbElipse = (gcnew System::Windows::Forms::GroupBox());
			this->lblElipseAreaResultado = (gcnew System::Windows::Forms::Label());
			this->lblElipseArea = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tbElipseRadio = (gcnew System::Windows::Forms::TextBox());
			this->gbDibujo = (gcnew System::Windows::Forms::GroupBox());
			this->lblFigura = (gcnew System::Windows::Forms::Label());
			this->cbFiguras = (gcnew System::Windows::Forms::ComboBox());
			this->gbCoordenadas->SuspendLayout();
			this->gbRectangulo->SuspendLayout();
			this->gbElipse->SuspendLayout();
			this->gbDibujo->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnDibujar
			// 
			this->btnDibujar->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->btnDibujar->Enabled = false;
			this->btnDibujar->Location = System::Drawing::Point(404, 13);
			this->btnDibujar->Name = L"btnDibujar";
			this->btnDibujar->Size = System::Drawing::Size(408, 35);
			this->btnDibujar->TabIndex = 0;
			this->btnDibujar->Text = L"Dibujar";
			this->btnDibujar->UseVisualStyleBackColor = false;
			this->btnDibujar->Click += gcnew System::EventHandler(this, &MyForm::btnDibujar_Click);
			this->btnDibujar->MouseLeave += gcnew System::EventHandler(this, &MyForm::btnDibujar_MouseLeave);
			this->btnDibujar->MouseHover += gcnew System::EventHandler(this, &MyForm::btnDibujar_MouseHover);
			// 
			// tbPosX
			// 
			this->tbPosX->BackColor = System::Drawing::SystemColors::Info;
			this->tbPosX->Location = System::Drawing::Point(78, 36);
			this->tbPosX->Name = L"tbPosX";
			this->tbPosX->Size = System::Drawing::Size(100, 20);
			this->tbPosX->TabIndex = 1;
			// 
			// lblPosX
			// 
			this->lblPosX->AutoSize = true;
			this->lblPosX->Location = System::Drawing::Point(26, 43);
			this->lblPosX->Name = L"lblPosX";
			this->lblPosX->Size = System::Drawing::Size(35, 13);
			this->lblPosX->TabIndex = 2;
			this->lblPosX->Text = L"Pos X";
			// 
			// tbPosY
			// 
			this->tbPosY->BackColor = System::Drawing::SystemColors::Info;
			this->tbPosY->Location = System::Drawing::Point(78, 73);
			this->tbPosY->Name = L"tbPosY";
			this->tbPosY->Size = System::Drawing::Size(100, 20);
			this->tbPosY->TabIndex = 3;
			// 
			// lblPosY
			// 
			this->lblPosY->AutoSize = true;
			this->lblPosY->Location = System::Drawing::Point(26, 73);
			this->lblPosY->Name = L"lblPosY";
			this->lblPosY->Size = System::Drawing::Size(35, 13);
			this->lblPosY->TabIndex = 4;
			this->lblPosY->Text = L"Pos Y";
			// 
			// gbCoordenadas
			// 
			this->gbCoordenadas->Controls->Add(this->lblPosX);
			this->gbCoordenadas->Controls->Add(this->lblPosY);
			this->gbCoordenadas->Controls->Add(this->tbPosX);
			this->gbCoordenadas->Controls->Add(this->tbPosY);
			this->gbCoordenadas->Location = System::Drawing::Point(49, 70);
			this->gbCoordenadas->Name = L"gbCoordenadas";
			this->gbCoordenadas->Size = System::Drawing::Size(242, 135);
			this->gbCoordenadas->TabIndex = 5;
			this->gbCoordenadas->TabStop = false;
			this->gbCoordenadas->Text = L"Posicion Inicial";
			// 
			// canvas
			// 
			this->canvas->Location = System::Drawing::Point(11, 224);
			this->canvas->Name = L"canvas";
			this->canvas->Size = System::Drawing::Size(848, 375);
			this->canvas->TabIndex = 6;
			// 
			// gbRectangulo
			// 
			this->gbRectangulo->Controls->Add(this->lblRecAreaResultado);
			this->gbRectangulo->Controls->Add(this->lblRecArea);
			this->gbRectangulo->Controls->Add(this->lblRecLado1);
			this->gbRectangulo->Controls->Add(this->lblRecLado2);
			this->gbRectangulo->Controls->Add(this->tbRecLado1);
			this->gbRectangulo->Controls->Add(this->tbRecLado2);
			this->gbRectangulo->Enabled = false;
			this->gbRectangulo->Location = System::Drawing::Point(618, 70);
			this->gbRectangulo->Name = L"gbRectangulo";
			this->gbRectangulo->Size = System::Drawing::Size(216, 135);
			this->gbRectangulo->TabIndex = 6;
			this->gbRectangulo->TabStop = false;
			this->gbRectangulo->Text = L"Rectangulo";
			// 
			// lblRecAreaResultado
			// 
			this->lblRecAreaResultado->AutoSize = true;
			this->lblRecAreaResultado->Location = System::Drawing::Point(76, 98);
			this->lblRecAreaResultado->Name = L"lblRecAreaResultado";
			this->lblRecAreaResultado->Size = System::Drawing::Size(100, 13);
			this->lblRecAreaResultado->TabIndex = 6;
			this->lblRecAreaResultado->Text = L"Mostrar el area aqui";
			// 
			// lblRecArea
			// 
			this->lblRecArea->AutoSize = true;
			this->lblRecArea->Location = System::Drawing::Point(24, 98);
			this->lblRecArea->Name = L"lblRecArea";
			this->lblRecArea->Size = System::Drawing::Size(29, 13);
			this->lblRecArea->TabIndex = 5;
			this->lblRecArea->Text = L"Area";
			// 
			// lblRecLado1
			// 
			this->lblRecLado1->AutoSize = true;
			this->lblRecLado1->Location = System::Drawing::Point(24, 27);
			this->lblRecLado1->Name = L"lblRecLado1";
			this->lblRecLado1->Size = System::Drawing::Size(40, 13);
			this->lblRecLado1->TabIndex = 2;
			this->lblRecLado1->Text = L"Lado 1";
			// 
			// lblRecLado2
			// 
			this->lblRecLado2->AutoSize = true;
			this->lblRecLado2->Location = System::Drawing::Point(24, 57);
			this->lblRecLado2->Name = L"lblRecLado2";
			this->lblRecLado2->Size = System::Drawing::Size(40, 13);
			this->lblRecLado2->TabIndex = 4;
			this->lblRecLado2->Text = L"Lado 2";
			// 
			// tbRecLado1
			// 
			this->tbRecLado1->BackColor = System::Drawing::SystemColors::Info;
			this->tbRecLado1->Location = System::Drawing::Point(76, 20);
			this->tbRecLado1->Name = L"tbRecLado1";
			this->tbRecLado1->Size = System::Drawing::Size(100, 20);
			this->tbRecLado1->TabIndex = 1;
			// 
			// tbRecLado2
			// 
			this->tbRecLado2->BackColor = System::Drawing::SystemColors::Info;
			this->tbRecLado2->Location = System::Drawing::Point(76, 57);
			this->tbRecLado2->Name = L"tbRecLado2";
			this->tbRecLado2->Size = System::Drawing::Size(100, 20);
			this->tbRecLado2->TabIndex = 3;
			// 
			// gbElipse
			// 
			this->gbElipse->Controls->Add(this->lblElipseAreaResultado);
			this->gbElipse->Controls->Add(this->lblElipseArea);
			this->gbElipse->Controls->Add(this->label3);
			this->gbElipse->Controls->Add(this->tbElipseRadio);
			this->gbElipse->Enabled = false;
			this->gbElipse->Location = System::Drawing::Point(353, 70);
			this->gbElipse->Name = L"gbElipse";
			this->gbElipse->Size = System::Drawing::Size(216, 135);
			this->gbElipse->TabIndex = 7;
			this->gbElipse->TabStop = false;
			this->gbElipse->Text = L"Elipse";
			// 
			// lblElipseAreaResultado
			// 
			this->lblElipseAreaResultado->AutoSize = true;
			this->lblElipseAreaResultado->Location = System::Drawing::Point(76, 89);
			this->lblElipseAreaResultado->Name = L"lblElipseAreaResultado";
			this->lblElipseAreaResultado->Size = System::Drawing::Size(100, 13);
			this->lblElipseAreaResultado->TabIndex = 6;
			this->lblElipseAreaResultado->Text = L"Mostrar el area aqui";
			// 
			// lblElipseArea
			// 
			this->lblElipseArea->AutoSize = true;
			this->lblElipseArea->Location = System::Drawing::Point(24, 89);
			this->lblElipseArea->Name = L"lblElipseArea";
			this->lblElipseArea->Size = System::Drawing::Size(29, 13);
			this->lblElipseArea->TabIndex = 5;
			this->lblElipseArea->Text = L"Area";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(24, 47);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Radio";
			// 
			// tbElipseRadio
			// 
			this->tbElipseRadio->BackColor = System::Drawing::SystemColors::Info;
			this->tbElipseRadio->Location = System::Drawing::Point(76, 40);
			this->tbElipseRadio->Name = L"tbElipseRadio";
			this->tbElipseRadio->Size = System::Drawing::Size(100, 20);
			this->tbElipseRadio->TabIndex = 1;
			// 
			// gbDibujo
			// 
			this->gbDibujo->Controls->Add(this->lblFigura);
			this->gbDibujo->Controls->Add(this->cbFiguras);
			this->gbDibujo->Controls->Add(this->btnDibujar);
			this->gbDibujo->Location = System::Drawing::Point(49, 10);
			this->gbDibujo->Name = L"gbDibujo";
			this->gbDibujo->Size = System::Drawing::Size(785, 54);
			this->gbDibujo->TabIndex = 8;
			this->gbDibujo->TabStop = false;
			// 
			// lblFigura
			// 
			this->lblFigura->AutoSize = true;
			this->lblFigura->Location = System::Drawing::Point(26, 24);
			this->lblFigura->Name = L"lblFigura";
			this->lblFigura->Size = System::Drawing::Size(65, 13);
			this->lblFigura->TabIndex = 2;
			this->lblFigura->Text = L"Elegir Figura";
			// 
			// cbFiguras
			// 
			this->cbFiguras->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->cbFiguras->FormattingEnabled = true;
			this->cbFiguras->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Elipse", L"Rectangulo" });
			this->cbFiguras->Location = System::Drawing::Point(138, 19);
			this->cbFiguras->Name = L"cbFiguras";
			this->cbFiguras->Size = System::Drawing::Size(153, 21);
			this->cbFiguras->TabIndex = 1;
			this->cbFiguras->SelectedValueChanged += gcnew System::EventHandler(this, &MyForm::cbFiguras_SelectedValueChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(871, 611);
			this->Controls->Add(this->gbDibujo);
			this->Controls->Add(this->gbElipse);
			this->Controls->Add(this->gbRectangulo);
			this->Controls->Add(this->canvas);
			this->Controls->Add(this->gbCoordenadas);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->gbCoordenadas->ResumeLayout(false);
			this->gbCoordenadas->PerformLayout();
			this->gbRectangulo->ResumeLayout(false);
			this->gbRectangulo->PerformLayout();
			this->gbElipse->ResumeLayout(false);
			this->gbElipse->PerformLayout();
			this->gbDibujo->ResumeLayout(false);
			this->gbDibujo->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnDibujar_MouseHover(System::Object^ sender, System::EventArgs^ e) {
		this->btnDibujar->BackColor = Color::Green;
	}
	private: System::Void btnDibujar_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		this->btnDibujar->BackColor = System::Drawing::SystemColors::ActiveCaption;
	}
	private: System::Void btnDibujar_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!inputsAreValid()) return;

		g->Clear(Color::WhiteSmoke);
		delete fig;
		int x = Convert::ToInt32(tbPosX->Text);
		int y = Convert::ToInt32(tbPosY->Text);

		if (cbFiguras->Text == "Rectangulo") {
			int lado1 = Convert::ToInt32(tbRecLado1->Text);
			int lado2 = Convert::ToInt32(tbRecLado2->Text);
			fig = new Rectangulo(x, y, lado1, lado2);
			lblRecAreaResultado->Text = Convert::ToString(fig->getArea()) + " u^2";
		}
		if (cbFiguras->Text == "Elipse") {
			int radio = Convert::ToInt32(tbElipseRadio->Text);
			fig = new Circulo(x, y, radio);
			lblElipseAreaResultado->Text = Convert::ToString(fig->getArea()) + " u^2";
		}

		fig->dibujar(g);
	}
	private: System::Void cbFiguras_SelectedValueChanged(System::Object^ sender, System::EventArgs^ e) {
		btnDibujar->Enabled = true;
		if (cbFiguras->Text == "Rectangulo") {
			gbElipse->Enabled = false;
			gbRectangulo->Enabled = true;
		}
		if (cbFiguras->Text == "Elipse") {
			gbElipse->Enabled = true;
			gbRectangulo->Enabled = false;
		}
	}

	private: bool inputsAreValid() {
		if (String::IsNullOrEmpty(tbPosX->Text) || String::IsNullOrEmpty(tbPosY->Text)) {
			MessageBox::Show("Please enter x and y", "Input error");
			return false;
		}

		if (cbFiguras->Text == "Rectangulo") {
			if (String::IsNullOrEmpty(tbRecLado1->Text) || String::IsNullOrEmpty(tbRecLado2->Text)) {
				MessageBox::Show("Please enter lado 1 and lado 2 for Rectangle", "Input error");
				return false;
			}
		}
		if (cbFiguras->Text == "Elipse") {
			if (String::IsNullOrEmpty(tbElipseRadio->Text)) {
				MessageBox::Show("Please enter the radio for Elipse", "Input error");
				return false;
			}
		}
		return true;
	}
};
}
