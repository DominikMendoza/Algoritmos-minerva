#pragma once
#include "Princesas.hpp"

namespace Project102 {

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
		BufferedGraphics^ bf;
		BufferedGraphicsContext^ context;
		Bitmap^ bmpPrincesas;
		Princesas* princesas;
	private: System::Windows::Forms::Panel^ panel;
	private: System::Windows::Forms::Label^ lblVecesAsustaron;
	private: System::Windows::Forms::Label^ lblReporte;
	private: System::Windows::Forms::Timer^ timer;
	public:
		MyForm(void)
		{
			InitializeComponent();
			g = panel->CreateGraphics();
			context = BufferedGraphicsManager::Current;
			bf = context->Allocate(g, panel->ClientRectangle);

			bmpPrincesas = gcnew Bitmap("bmps/princesas.png");

			princesas = new Princesas(bmpPrincesas->Width / 5, bmpPrincesas->Height / 4);
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
			this->panel = (gcnew System::Windows::Forms::Panel());
			this->lblVecesAsustaron = (gcnew System::Windows::Forms::Label());
			this->lblReporte = (gcnew System::Windows::Forms::Label());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel
			// 
			this->panel->Controls->Add(this->lblVecesAsustaron);
			this->panel->Controls->Add(this->lblReporte);
			this->panel->Location = System::Drawing::Point(12, 12);
			this->panel->Name = L"panel";
			this->panel->Size = System::Drawing::Size(901, 567);
			this->panel->TabIndex = 0;
			// 
			// lblVecesAsustaron
			// 
			this->lblVecesAsustaron->AutoSize = true;
			this->lblVecesAsustaron->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblVecesAsustaron->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->lblVecesAsustaron->Location = System::Drawing::Point(680, 198);
			this->lblVecesAsustaron->Name = L"lblVecesAsustaron";
			this->lblVecesAsustaron->Size = System::Drawing::Size(25, 25);
			this->lblVecesAsustaron->TabIndex = 1;
			this->lblVecesAsustaron->Text = L"0";
			// 
			// lblReporte
			// 
			this->lblReporte->AutoSize = true;
			this->lblReporte->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblReporte->Location = System::Drawing::Point(573, 80);
			this->lblReporte->Name = L"lblReporte";
			this->lblReporte->Size = System::Drawing::Size(268, 66);
			this->lblReporte->TabIndex = 0;
			this->lblReporte->Text = L"Numero de veces \r\nque se asustaron:";
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
			this->ClientSize = System::Drawing::Size(925, 591);
			this->Controls->Add(this->panel);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->panel->ResumeLayout(false);
			this->panel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e) {
		bf->Graphics->Clear(Color::WhiteSmoke);

		princesas->mover();
		princesas->dibujar(bf->Graphics, bmpPrincesas);
		lblVecesAsustaron->Text = Convert::ToString(princesas->getSustos());

		bf->Render();
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode) {
		case Keys::A:
			princesas->setSustos(0);
			princesas->animar(true);
			/*lblReporte->Visible = false;
			lblVecesAsustaron->Visible = false;*/
			break;
		case Keys::F:
			princesas->animar(false);
			princesas->resetearSprite();
			/*lblReporte->Visible = true;
			lblVecesAsustaron->Visible = true;*/
			break;
		}
	}
};
}
