#include "Figure.h"
#include "CFigure.h"

#include <Windows.h>
#include <iostream>
#include <vector>
#include <array>
#include <string>

#pragma once

namespace KillMe {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	
	
	
	bool isFiguresSpawn = false;
	UINT8 figureCounter = 0;
	vector <Figure> figs;


	



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
	private: System::Windows::Forms::Button^ btnRespawn;
	private: System::Windows::Forms::Label^ lblInfo1;
	private: System::Windows::Forms::Button^ btnClose;
	private: System::Windows::Forms::Label^ lblInfo2;
	private: System::Windows::Forms::Label^ lblInfo3;
	private: System::ComponentModel::Container^ components;
#pragma endregion Kernel

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->pnlLeft = (gcnew System::Windows::Forms::Panel());
			   this->pnlRight = (gcnew System::Windows::Forms::Panel());
			   this->pnlTop = (gcnew System::Windows::Forms::Panel());
			   this->btnClose = (gcnew System::Windows::Forms::Button());
			   this->pnlBottom = (gcnew System::Windows::Forms::Panel());
			   this->pnlField = (gcnew System::Windows::Forms::Panel());
			   this->lblInfo2 = (gcnew System::Windows::Forms::Label());
			   this->lblInfo1 = (gcnew System::Windows::Forms::Label());
			   this->btnRespawn = (gcnew System::Windows::Forms::Button());
			   this->lblInfo3 = (gcnew System::Windows::Forms::Label());
			   this->pnlTop->SuspendLayout();
			   this->pnlField->SuspendLayout();
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
			   this->pnlTop->BackColor = System::Drawing::Color::DimGray;
			   this->pnlTop->Controls->Add(this->btnClose);
			   this->pnlTop->Location = System::Drawing::Point(41, 54);
			   this->pnlTop->Name = L"pnlTop";
			   this->pnlTop->Size = System::Drawing::Size(361, 30);
			   this->pnlTop->TabIndex = 2;
			   this->pnlTop->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &frmMain::pnlTop_MouseDoubleClick);
			   this->pnlTop->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &frmMain::pnlTop_MouseDown);
			   this->pnlTop->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &frmMain::pnlTop_MouseMove);
			   this->pnlTop->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &frmMain::pnlTop_MouseUp);
			   // 
			   // btnClose
			   // 
			   this->btnClose->Dock = System::Windows::Forms::DockStyle::Right;
			   this->btnClose->FlatAppearance->BorderSize = 0;
			   this->btnClose->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				   static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			   this->btnClose->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnClose->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->btnClose->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			   this->btnClose->Location = System::Drawing::Point(326, 0);
			   this->btnClose->Name = L"btnClose";
			   this->btnClose->Size = System::Drawing::Size(35, 30);
			   this->btnClose->TabIndex = 1;
			   this->btnClose->Text = L"X";
			   this->btnClose->UseVisualStyleBackColor = true;
			   this->btnClose->Click += gcnew System::EventHandler(this, &frmMain::btnClose_Click);
			   // 
			   // pnlBottom
			   // 
			   this->pnlBottom->BackColor = System::Drawing::Color::DimGray;
			   this->pnlBottom->Location = System::Drawing::Point(41, 257);
			   this->pnlBottom->Name = L"pnlBottom";
			   this->pnlBottom->Size = System::Drawing::Size(361, 50);
			   this->pnlBottom->TabIndex = 3;
			   // 
			   // pnlField
			   // 
			   this->pnlField->BackColor = System::Drawing::Color::White;
			   this->pnlField->Controls->Add(this->lblInfo3);
			   this->pnlField->Controls->Add(this->lblInfo2);
			   this->pnlField->Controls->Add(this->lblInfo1);
			   this->pnlField->Controls->Add(this->btnRespawn);
			   this->pnlField->Location = System::Drawing::Point(97, 91);
			   this->pnlField->Name = L"pnlField";
			   this->pnlField->Size = System::Drawing::Size(249, 160);
			   this->pnlField->TabIndex = 1;
			   this->pnlField->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &frmMain::pnlField_Paint);
			   this->pnlField->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &frmMain::pnlField_MouseMove);
			   // 
			   // lblInfo2
			   // 
			   this->lblInfo2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			   this->lblInfo2->AutoSize = true;
			   this->lblInfo2->Location = System::Drawing::Point(205, 118);
			   this->lblInfo2->Name = L"lblInfo2";
			   this->lblInfo2->Size = System::Drawing::Size(41, 13);
			   this->lblInfo2->TabIndex = 2;
			   this->lblInfo2->Text = L"lblInfo2";
			   this->lblInfo2->TextAlign = System::Drawing::ContentAlignment::TopRight;
			   // 
			   // lblInfo1
			   // 
			   this->lblInfo1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			   this->lblInfo1->AutoSize = true;
			   this->lblInfo1->Location = System::Drawing::Point(3, 118);
			   this->lblInfo1->Name = L"lblInfo1";
			   this->lblInfo1->Size = System::Drawing::Size(41, 13);
			   this->lblInfo1->TabIndex = 1;
			   this->lblInfo1->Text = L"lblInfo1";
			   // 
			   // btnRespawn
			   // 
			   this->btnRespawn->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			   this->btnRespawn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnRespawn->Location = System::Drawing::Point(88, 134);
			   this->btnRespawn->Name = L"btnRespawn";
			   this->btnRespawn->Size = System::Drawing::Size(75, 23);
			   this->btnRespawn->TabIndex = 0;
			   this->btnRespawn->Text = L"Spawn";
			   this->btnRespawn->UseVisualStyleBackColor = true;
			   this->btnRespawn->Click += gcnew System::EventHandler(this, &frmMain::btnRespawn_Click);
			   // 
			   // lblInfo3
			   // 
			   this->lblInfo3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			   this->lblInfo3->AutoSize = true;
			   this->lblInfo3->Location = System::Drawing::Point(3, 9);
			   this->lblInfo3->Name = L"lblInfo3";
			   this->lblInfo3->Size = System::Drawing::Size(41, 13);
			   this->lblInfo3->TabIndex = 3;
			   this->lblInfo3->Text = L"lblInfo3";
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
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			   this->Name = L"frmMain";
			   this->Text = L"frmMain";
			   this->Load += gcnew System::EventHandler(this, &frmMain::frmMain_Load);
			   this->pnlTop->ResumeLayout(false);
			   this->pnlField->ResumeLayout(false);
			   this->pnlField->PerformLayout();
			   this->ResumeLayout(false);

		   }
#pragma endregion

#pragma region Voids


	private:
		System::Void frmMain_Load(System::Object^ sender, System::EventArgs^ e) {

#pragma region startPos
			pnlTop->Dock = DockStyle::Top;			pnlTop->SendToBack();
			pnlBottom->Dock = DockStyle::Bottom;	pnlBottom->SendToBack();
			pnlLeft->Dock = DockStyle::Left;
			pnlRight->Dock = DockStyle::Right;
			pnlField->Dock = DockStyle::Fill;

			lblInfo1->Text = ""; lblInfo2->Text = ""; lblInfo3->Text = "";
#pragma endregion

#pragma region BUF
			SetStyle(
				ControlStyles::AllPaintingInWmPaint |
				ControlStyles::OptimizedDoubleBuffer |
				ControlStyles::ResizeRedraw |
				ControlStyles::SupportsTransparentBackColor |
				ControlStyles::UserPaint, true
			);
			DoubleBuffered = true;
#pragma endregion

			figs.reserve(10);
		}

		int COL = 50;
		System::Void btnRespawn_Click(System::Object^ sender, System::EventArgs^ e) {
			isFiguresSpawn = true;


			/*figs.push_back(
				Figure(
					"Gavka " + to_string(figureCounter),
					10 + figureCounter * 100,
					50
				)
			);*/

			figs.push_back(
				Figure(
					figureCounter + 1,
					"Manul " + to_string(figureCounter + 1),
					100 + figureCounter % 7 * 100,
					COL,
					50, 
					20
				)
			);
			figureCounter++;

			if (figureCounter % 7 == 0) COL += 50;

			


			pnlField->Refresh();
			//pnlField->Invalidate();

			lblInfo1->Text = gcnew String((
					"Figs.Size: " + to_string(figs.size()) + "\n" +
					"Figs.Capa: " + to_string(figs.capacity()) + "\n"
				).c_str()
			);

		}
		System::Void pnlField_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
			e->Graphics->Clear(pnlField->BackColor);
			//SwapBuffers

			if (isFiguresSpawn) 
				for (auto i = 0; i < figs.size(); i++)
					figs.at(i).repaintFigure(sender, e);

		}
		System::Void pnlField_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

			int x = e->X;
			int y = e->Y;
			lblInfo2->Text = x.ToString() +  ":" + y.ToString();


			if (isFiguresSpawn)
				for (auto i = 0; i < figs.size(); i++) {
					lblInfo3->Text = gcnew String((
						"Manul " + to_string(figs.at(i).MouseMove(x, y))
						).c_str()
					);

					//figs.at(i).MouseMove(x, y);
				}
					
		}

		System::Void pnlTop_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) { drugMD(sender, e); }
		System::Void pnlTop_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) { drugMM(sender, e); }
		System::Void pnlTop_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)   { drugMU(sender, e); }
		System::Void pnlTop_MouseDoubleClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			WindowState = (WindowState == FormWindowState::Normal) ?
				FormWindowState::Maximized : FormWindowState::Normal;
		}

		System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) { Close(); }
#pragma endregion


#pragma region Proger
	private:
		Point mouseOffset_;
		bool isMouseDown_ = false;
		int xOffset_, yOffset_;

		void drugMD(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			if (e->Button == Windows::Forms::MouseButtons::Left) {
				Control^ cont = (Control^)sender;
				int xOffset = cont->Left; int yOffset = cont->Top;
				if (cont->Name == Name) { xOffset = 0; yOffset = 0; }		//4
				xOffset_ = -e->X - SystemInformation::FrameBorderSize.Width + 0 - xOffset;
				yOffset_ = -e->Y - SystemInformation::FrameBorderSize.Height + 0 + yOffset;
				mouseOffset_ = System::Drawing::Point(xOffset_, yOffset_);
				isMouseDown_ = true;
			}
		}
		void drugMM(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			if (isMouseDown_) {
				Point mousePos = Control::MousePosition;
				mousePos.Offset(mouseOffset_.X, mouseOffset_.Y);
				Location = mousePos;
			}
		}
		void drugMU(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
				if (e->Button == Windows::Forms::MouseButtons::Left) { isMouseDown_ = false; }
			}
#pragma endregion


	

	
	};

}



