#pragma once
#include "Hulk.hpp"
namespace Project100 {

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
		Hulk* hulk;
		Bitmap^ bmpHulk;
		Graphics^ g;
		BufferedGraphics^ bf;
		BufferedGraphicsContext^ context;
	private: System::Windows::Forms::Panel^ canvas;
	private: System::Windows::Forms::Label^ lblZonaSegura;
	private: System::Windows::Forms::Label^ lblZonaPeligrosa;
	private: System::Windows::Forms::Timer^ timer;
	public:
		MyForm(void)
		{
			InitializeComponent();
			bmpHulk = gcnew Bitmap("Bitmaps/hulk.png");
			bmpHulk->MakeTransparent(bmpHulk->GetPixel(0, 0));
			g = canvas->CreateGraphics();
			context = BufferedGraphicsManager::Current;
			bf = context->Allocate(g, canvas->ClientRectangle);
			hulk = new Hulk(bmpHulk->Width / 4, bmpHulk->Height / 4);
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
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->canvas = (gcnew System::Windows::Forms::Panel());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblZonaPeligrosa = (gcnew System::Windows::Forms::Label());
			this->lblZonaSegura = (gcnew System::Windows::Forms::Label());
			this->canvas->SuspendLayout();
			this->SuspendLayout();
			// 
			// canvas
			// 
			this->canvas->Controls->Add(this->lblZonaSegura);
			this->canvas->Controls->Add(this->lblZonaPeligrosa);
			this->canvas->Location = System::Drawing::Point(12, 12);
			this->canvas->Name = L"canvas";
			this->canvas->Size = System::Drawing::Size(905, 633);
			this->canvas->TabIndex = 0;
			this->canvas->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::canvas_Paint);
			// 
			// timer
			// 
			this->timer->Enabled = true;
			this->timer->Interval = 150;
			this->timer->Tick += gcnew System::EventHandler(this, &MyForm::timer_Tick);
			// 
			// lblZonaPeligrosa
			// 
			this->lblZonaPeligrosa->AutoSize = true;
			this->lblZonaPeligrosa->BackColor = System::Drawing::Color::IndianRed;
			this->lblZonaPeligrosa->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblZonaPeligrosa->Location = System::Drawing::Point(52, 51);
			this->lblZonaPeligrosa->Name = L"lblZonaPeligrosa";
			this->lblZonaPeligrosa->Size = System::Drawing::Size(222, 33);
			this->lblZonaPeligrosa->TabIndex = 0;
			this->lblZonaPeligrosa->Text = L"Zona peligrosa";
			this->lblZonaPeligrosa->Visible = false;
			// 
			// lblZonaSegura
			// 
			this->lblZonaSegura->AutoSize = true;
			this->lblZonaSegura->BackColor = System::Drawing::Color::PaleGreen;
			this->lblZonaSegura->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblZonaSegura->Location = System::Drawing::Point(592, 51);
			this->lblZonaSegura->Name = L"lblZonaSegura";
			this->lblZonaSegura->Size = System::Drawing::Size(189, 33);
			this->lblZonaSegura->TabIndex = 1;
			this->lblZonaSegura->Text = L"Zona segura";
			this->lblZonaSegura->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(929, 657);
			this->Controls->Add(this->canvas);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->canvas->ResumeLayout(false);
			this->canvas->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void canvas_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		
	}
	private: System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e) {
		bf->Graphics->Clear(Color::WhiteSmoke); 
		int limite = canvas->Width / 2;

		if (hulk->getX() > limite - 20) {
			lblZonaSegura->Visible = true;
			lblZonaPeligrosa->Visible = false;
			Rectangle recZonaSegura = canvas->ClientRectangle;
			recZonaSegura.X = canvas->Width / 2;
			recZonaSegura.Width = canvas->Width / 2;
			SolidBrush^ sb = gcnew SolidBrush(Color::PaleGreen);
			bf->Graphics->FillRectangle(sb, recZonaSegura);
		}
		else {
			lblZonaSegura->Visible = false;
			lblZonaPeligrosa->Visible = true;
			Rectangle recZonaPeligrosa = canvas->ClientRectangle;
			recZonaPeligrosa.Width = canvas->Width / 2;
			SolidBrush^ b = gcnew SolidBrush(Color::IndianRed);
			bf->Graphics->FillRectangle(b, recZonaPeligrosa);
		}
		hulk->dibujar(bf->Graphics, bmpHulk);
		bf->Render();
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode) {
		case Keys::W:
		case Keys::Up:
			hulk->mover(bf->Graphics, 'W');
			break;
		case Keys::A:
		case Keys::Left:
			hulk->mover(bf->Graphics, 'A');
			break;
		case Keys::S:
		case Keys::Down:
			hulk->mover(bf->Graphics, 'S');
			break;
		case Keys::D:
		case Keys::Right:
			hulk->mover(bf->Graphics, 'D');
			break;
		}
	}
	};
}
