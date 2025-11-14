#pragma once
#include "Caballo.hpp"

namespace Project101 {

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
		Caballo* caballo;
		Graphics^ g;
		BufferedGraphics^ bf;
		BufferedGraphicsContext^ context;
		Bitmap^ bmpCaballo;
	public:
		MyForm(void)
		{
			InitializeComponent();
			g = panel->CreateGraphics();
			context = BufferedGraphicsManager::Current;
			bf = context->Allocate(g, panel->ClientRectangle);

			bmpCaballo = gcnew Bitmap("bmps/caballo.png");
			bmpCaballo->MakeTransparent(bmpCaballo->GetPixel(0, 0));

			caballo = new Caballo(bmpCaballo->Width / 6, bmpCaballo->Height / 8);
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
	private: System::Windows::Forms::Panel^ panel;
	private: System::Windows::Forms::Timer^ timer;
	protected:

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
			this->SuspendLayout();
			// 
			// panel
			// 
			this->panel->Location = System::Drawing::Point(12, 12);
			this->panel->Name = L"panel";
			this->panel->Size = System::Drawing::Size(715, 649);
			this->panel->TabIndex = 0;
			// 
			// timer
			// 
			this->timer->Enabled = true;
			this->timer->Tick += gcnew System::EventHandler(this, &MyForm::timer_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(739, 673);
			this->Controls->Add(this->panel);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e) {
		bf->Graphics->Clear(Color::WhiteSmoke);

		caballo->dibujar(bf->Graphics, bmpCaballo);

		bf->Render();
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		Keys keyPress = e->KeyCode;
		switch (keyPress) {
		case Keys::Up:
			caballo->mover(bf->Graphics, 'W');
			break;
		case Keys::Left:
			caballo->mover(bf->Graphics, 'A');
			break;
		case Keys::Down:
			caballo->mover(bf->Graphics, 'S');
			break;
		case Keys::Right:
			caballo->mover(bf->Graphics, 'D');
			break;
		case Keys::A:
		case Keys::Z:
		case Keys::V:
		case Keys::B:
			caballo->setColor(Convert::ToChar(keyPress));
		}
			
	}
	};
}
