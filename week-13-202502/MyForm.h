#pragma once
#include "Pokeball.hpp"
#include "Pikachu.hpp"
#include "Personaje.hpp"
#include "FileManager.hpp"

namespace Project104 {

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
		Pokeball* pb;
		Pikachu* pk;
		Personaje* per;
		FileManager* fm;

		Bitmap^ bmpPokeball;
		Bitmap^ bmpPikachu;
		Bitmap^ bmpPersonaje;
		Graphics^ g;
		BufferedGraphics^ bf;
	private: System::Windows::Forms::Timer^ tiempoLimite;
		   BufferedGraphicsContext^ context;
	public:
		MyForm(void)
		{
			InitializeComponent();
			g = panel->CreateGraphics();
			context = BufferedGraphicsManager::Current;
			bf = context->Allocate(g, panel->ClientRectangle);
			bmpPokeball = gcnew Bitmap("bmps/pokeball.png");
			bmpPokeball->MakeTransparent(bmpPokeball->GetPixel(0, 0));

			bmpPikachu = gcnew Bitmap("bmps/pikachu.png");
			bmpPikachu->MakeTransparent(bmpPikachu->GetPixel(0, 0));

			bmpPersonaje = gcnew Bitmap("bmps/hulk.png");
			bmpPersonaje->MakeTransparent(bmpPersonaje->GetPixel(0, 0));

			fm = new FileManager();
			int x, y, n, t;
			fm->leerValoresDeEjercicio(x, y, n, t, "config.txt");

			tiempoLimite->Interval = t * 1000;
			
			pb = new Pokeball(bmpPokeball->Width / 3, bmpPokeball->Height);
			pk = new Pikachu(bmpPikachu->Width / 4, bmpPikachu->Height / 4);
			per = new Personaje(x, y, bmpPersonaje->Width / 4, bmpPersonaje->Height / 4, n);
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

	protected:

	private: System::Windows::Forms::Panel^ panel;

	private: System::Windows::Forms::Timer^ timer;
	private: System::ComponentModel::IContainer^ components;

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
			this->panel = (gcnew System::Windows::Forms::Panel());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->tiempoLimite = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// panel
			// 
			this->panel->Location = System::Drawing::Point(12, 12);
			this->panel->Name = L"panel";
			this->panel->Size = System::Drawing::Size(1041, 718);
			this->panel->TabIndex = 2;
			// 
			// timer
			// 
			this->timer->Enabled = true;
			this->timer->Tick += gcnew System::EventHandler(this, &MyForm::timer_Tick);
			// 
			// tiempoLimite
			// 
			this->tiempoLimite->Enabled = true;
			this->tiempoLimite->Tick += gcnew System::EventHandler(this, &MyForm::tiempoLimite_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1065, 742);
			this->Controls->Add(this->panel);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e) {
		bf->Graphics->Clear(Color::WhiteSmoke);

		pb->mover(bf->Graphics, per->getDireccion());
		pb->dibujar(bf->Graphics, bmpPokeball);

		pk->mover(bf->Graphics);
		pk->dibujar(bf->Graphics, bmpPikachu);

		per->dibujar(bf->Graphics, bmpPersonaje);

		if (pb->estaColisionandoCon(pk)) {
			timer->Enabled = false;
		}

		bf->Render();
	}
	private: System::Void btnDisparo_Click(System::Object^ sender, System::EventArgs^ e) {
		timer->Enabled = true;
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode) {
		case Keys::W:
		case Keys::Up:
			per->mover(bf->Graphics, 'W');
			break;
		case Keys::A:
		case Keys::Left:
			per->mover(bf->Graphics, 'A');
			break;
		case Keys::S:
		case Keys::Down:
			per->mover(bf->Graphics, 'S');
			break;
		case Keys::D:
		case Keys::Right:
			per->mover(bf->Graphics, 'D');
			break;

		case Keys::Space:
			pb->resetearPokeball(per->getX(), per->getY(), per->getDireccion());
			pb->cambiarVisibilidad();
			break;
		}
		}
	private: System::Void tiempoLimite_Tick(System::Object^ sender, System::EventArgs^ e) {
		timer->Enabled = false;
		bf->Graphics->Clear(Color::Red);
		bf->Render();
		tiempoLimite->Enabled = false;
	}
};
}
