#include <Windows.h>

#pragma once

namespace KillMe {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class frmMain : public System::Windows::Forms::Form
	{
#pragma region Kernel
	public: 	frmMain(void) { InitializeComponent(); }
	protected: ~frmMain() { if (components) delete components; }
	private: System::Windows::Forms::Panel^ pnlLeft;
	protected:
	private: System::Windows::Forms::Panel^ pnlRight;
	private: System::Windows::Forms::Panel^ pnlTop;
	private: System::Windows::Forms::Panel^ pnlBottom;
	private: System::Windows::Forms::Panel^ pnlField;
	private: System::ComponentModel::Container^ components;
#pragma endregion Kernel

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->pnlLeft = (gcnew System::Windows::Forms::Panel());
			   this->pnlRight = (gcnew System::Windows::Forms::Panel());
			   this->pnlTop = (gcnew System::Windows::Forms::Panel());
			   this->pnlBottom = (gcnew System::Windows::Forms::Panel());
			   this->pnlField = (gcnew System::Windows::Forms::Panel());
			   this->SuspendLayout();
			   // 
			   // pnlLeft
			   // 
			   this->pnlLeft->BackColor = System::Drawing::Color::Orange;
			   this->pnlLeft->Location = System::Drawing::Point(41, 91);
			   this->pnlLeft->Name = L"pnlLeft";
			   this->pnlLeft->Size = System::Drawing::Size(50, 160);
			   this->pnlLeft->TabIndex = 0;
			   // 
			   // pnlRight
			   // 
			   this->pnlRight->BackColor = System::Drawing::Color::Orange;
			   this->pnlRight->Location = System::Drawing::Point(352, 91);
			   this->pnlRight->Name = L"pnlRight";
			   this->pnlRight->Size = System::Drawing::Size(50, 160);
			   this->pnlRight->TabIndex = 1;
			   // 
			   // pnlTop
			   // 
			   this->pnlTop->BackColor = System::Drawing::Color::Black;
			   this->pnlTop->Location = System::Drawing::Point(41, 35);
			   this->pnlTop->Name = L"pnlTop";
			   this->pnlTop->Size = System::Drawing::Size(360, 50);
			   this->pnlTop->TabIndex = 2;
			   // 
			   // pnlBottom
			   // 
			   this->pnlBottom->BackColor = System::Drawing::Color::Black;
			   this->pnlBottom->Location = System::Drawing::Point(41, 257);
			   this->pnlBottom->Name = L"pnlBottom";
			   this->pnlBottom->Size = System::Drawing::Size(360, 50);
			   this->pnlBottom->TabIndex = 3;
			   // 
			   // pnlField
			   // 
			   this->pnlField->BackColor = System::Drawing::Color::White;
			   this->pnlField->Location = System::Drawing::Point(97, 91);
			   this->pnlField->Name = L"pnlField";
			   this->pnlField->Size = System::Drawing::Size(249, 160);
			   this->pnlField->TabIndex = 1;
			   // 
			   // frmMain
			   // 
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			   this->ClientSize = System::Drawing::Size(1059, 627);
			   this->Controls->Add(this->pnlField);
			   this->Controls->Add(this->pnlBottom);
			   this->Controls->Add(this->pnlTop);
			   this->Controls->Add(this->pnlRight);
			   this->Controls->Add(this->pnlLeft);
			   this->Name = L"frmMain";
			   this->Text = L"frmMain";
			   this->Load += gcnew System::EventHandler(this, &frmMain::frmMain_Load);
			   this->ResumeLayout(false);

		   }
#pragma endregion

#pragma region Voids
	private:
		System::Void frmMain_Load(System::Object^ sender, System::EventArgs^ e) {
			pnlTop->Dock = DockStyle::Top;			pnlTop->SendToBack();
			pnlBottom->Dock = DockStyle::Bottom;	pnlBottom->SendToBack();
			pnlLeft->Dock = DockStyle::Left;
			pnlRight->Dock = DockStyle::Right;
			pnlField->Dock = DockStyle::Fill;
		}
#pragma endregion


	};
}
