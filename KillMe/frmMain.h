#include "Figure.h"
#include "CFigure.h"

#include <Windows.h>
#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <thread>

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
	vector <Figure*> figs;



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
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ btnInfo;
	private: System::Windows::Forms::MenuStrip^ HotKeys;
	private: System::Windows::Forms::ToolStripMenuItem^ F1;
	private: System::Windows::Forms::ToolStripMenuItem^ lCtrl;
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
			   this->btnInfo = (gcnew System::Windows::Forms::Button());
			   this->pnlField = (gcnew System::Windows::Forms::Panel());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->lblInfo3 = (gcnew System::Windows::Forms::Label());
			   this->lblInfo2 = (gcnew System::Windows::Forms::Label());
			   this->lblInfo1 = (gcnew System::Windows::Forms::Label());
			   this->btnRespawn = (gcnew System::Windows::Forms::Button());
			   this->HotKeys = (gcnew System::Windows::Forms::MenuStrip());
			   this->F1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->lCtrl = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->pnlLeft->SuspendLayout();
			   this->pnlRight->SuspendLayout();
			   this->pnlTop->SuspendLayout();
			   this->pnlBottom->SuspendLayout();
			   this->HotKeys->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // pnlLeft
			   // 
			   this->pnlLeft->BackColor = System::Drawing::Color::Orange;
			   this->pnlLeft->Controls->Add(this->lblInfo3);
			   this->pnlLeft->Controls->Add(this->lblInfo1);
			   this->pnlLeft->Location = System::Drawing::Point(41, 91);
			   this->pnlLeft->Name = L"pnlLeft";
			   this->pnlLeft->Size = System::Drawing::Size(50, 160);
			   this->pnlLeft->TabIndex = 0;
			   // 
			   // pnlRight
			   // 
			   this->pnlRight->BackColor = System::Drawing::Color::Orange;
			   this->pnlRight->Controls->Add(this->lblInfo2);
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
			   this->pnlBottom->Controls->Add(this->button1);
			   this->pnlBottom->Controls->Add(this->btnInfo);
			   this->pnlBottom->Controls->Add(this->btnRespawn);
			   this->pnlBottom->Location = System::Drawing::Point(41, 257);
			   this->pnlBottom->Name = L"pnlBottom";
			   this->pnlBottom->Size = System::Drawing::Size(361, 50);
			   this->pnlBottom->TabIndex = 3;
			   // 
			   // btnInfo
			   // 
			   this->btnInfo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left));
			   this->btnInfo->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnInfo->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			   this->btnInfo->Location = System::Drawing::Point(25, 15);
			   this->btnInfo->Name = L"btnInfo";
			   this->btnInfo->Size = System::Drawing::Size(75, 23);
			   this->btnInfo->TabIndex = 1;
			   this->btnInfo->Text = L"Info";
			   this->btnInfo->UseVisualStyleBackColor = true;
			   this->btnInfo->Click += gcnew System::EventHandler(this, &frmMain::btnInfo_Click);
			   // 
			   // pnlField
			   // 
			   this->pnlField->BackColor = System::Drawing::Color::White;
			   this->pnlField->Location = System::Drawing::Point(97, 91);
			   this->pnlField->Name = L"pnlField";
			   this->pnlField->Size = System::Drawing::Size(249, 160);
			   this->pnlField->TabIndex = 1;
			   this->pnlField->Click += gcnew System::EventHandler(this, &frmMain::pnlField_Click);
			   this->pnlField->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &frmMain::pnlField_Paint);
			   this->pnlField->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &frmMain::pnlField_MouseClick);
			   this->pnlField->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &frmMain::pnlField_MouseDown);
			   this->pnlField->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &frmMain::pnlField_MouseMove);
			   this->pnlField->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &frmMain::pnlField_MouseUp);
			   // 
			   // button1
			   // 
			   this->button1->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			   this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button1->Location = System::Drawing::Point(225, 15);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(56, 23);
			   this->button1->TabIndex = 4;
			   this->button1->Text = L"Refresh";
			   this->button1->UseVisualStyleBackColor = true;
			   this->button1->Click += gcnew System::EventHandler(this, &frmMain::button1_Click);
			   // 
			   // lblInfo3
			   // 
			   this->lblInfo3->AutoSize = true;
			   this->lblInfo3->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			   this->lblInfo3->Location = System::Drawing::Point(6, 10);
			   this->lblInfo3->Name = L"lblInfo3";
			   this->lblInfo3->Size = System::Drawing::Size(41, 13);
			   this->lblInfo3->TabIndex = 3;
			   this->lblInfo3->Text = L"lblInfo3";
			   // 
			   // lblInfo2
			   // 
			   this->lblInfo2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			   this->lblInfo2->AutoSize = true;
			   this->lblInfo2->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			   this->lblInfo2->Location = System::Drawing::Point(6, 118);
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
			   this->lblInfo1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			   this->lblInfo1->Location = System::Drawing::Point(6, 118);
			   this->lblInfo1->Name = L"lblInfo1";
			   this->lblInfo1->Size = System::Drawing::Size(41, 13);
			   this->lblInfo1->TabIndex = 1;
			   this->lblInfo1->Text = L"lblInfo1";
			   // 
			   // btnRespawn
			   // 
			   this->btnRespawn->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			   this->btnRespawn->BackColor = System::Drawing::Color::White;
			   this->btnRespawn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnRespawn->Location = System::Drawing::Point(141, 15);
			   this->btnRespawn->Name = L"btnRespawn";
			   this->btnRespawn->Size = System::Drawing::Size(75, 23);
			   this->btnRespawn->TabIndex = 0;
			   this->btnRespawn->Text = L"Spawn";
			   this->btnRespawn->UseVisualStyleBackColor = false;
			   this->btnRespawn->Click += gcnew System::EventHandler(this, &frmMain::btnRespawn_Click);
			   // 
			   // HotKeys
			   // 
			   this->HotKeys->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->F1, this->lCtrl });
			   this->HotKeys->Location = System::Drawing::Point(0, 0);
			   this->HotKeys->Name = L"HotKeys";
			   this->HotKeys->Size = System::Drawing::Size(1059, 24);
			   this->HotKeys->TabIndex = 4;
			   this->HotKeys->Text = L"menuStrip1";
			   this->HotKeys->Visible = false;
			   // 
			   // F1
			   // 
			   this->F1->Name = L"F1";
			   this->F1->ShortcutKeys = System::Windows::Forms::Keys::F1;
			   this->F1->Size = System::Drawing::Size(31, 20);
			   this->F1->Text = L"F1";
			   this->F1->Click += gcnew System::EventHandler(this, &frmMain::F1_Click);
			   // 
			   // lCtrl
			   // 
			   this->lCtrl->Name = L"lCtrl";
			   this->lCtrl->Size = System::Drawing::Size(41, 20);
			   this->lCtrl->Text = L"lCtrl";
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
			   this->Controls->Add(this->HotKeys);
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			   this->MainMenuStrip = this->HotKeys;
			   this->Name = L"frmMain";
			   this->Text = L"frmMain";
			   this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &frmMain::frmMain_FormClosed);
			   this->Load += gcnew System::EventHandler(this, &frmMain::frmMain_Load);
			   this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &frmMain::frmMain_KeyDown);
			   this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &frmMain::frmMain_KeyPress);
			   this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &frmMain::frmMain_KeyUp);
			   this->pnlLeft->ResumeLayout(false);
			   this->pnlLeft->PerformLayout();
			   this->pnlRight->ResumeLayout(false);
			   this->pnlRight->PerformLayout();
			   this->pnlTop->ResumeLayout(false);
			   this->pnlBottom->ResumeLayout(false);
			   this->HotKeys->ResumeLayout(false);
			   this->HotKeys->PerformLayout();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

public:
	//virtual bool ProcessCmdKey(Message% msg, Keys keyData) override
	//{
	//	if (keyData == Keys::F2)
	//	{
	//		this->Focus();
	//		MessageBox::Show("F2");
	//		return true;
	//	}
	//	/*if (keyData == Keys::LControlKey)*/
	//	if (keyData == Keys::Modifiers)
	//	{
	//		this->Focus();
	//		MessageBox::Show("LCtrl");
	//		return true;
	//	}
	//	if (keyData == Keys::Escape)
	//	{
	//		this->Focus();
	//		Close();
	//		return true;
	//	}

	//	return Form::ProcessCmdKey(msg, keyData);
	//}



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
			this->SetStyle(
				ControlStyles::AllPaintingInWmPaint |
				ControlStyles::OptimizedDoubleBuffer |
				ControlStyles::ResizeRedraw |
				ControlStyles::SupportsTransparentBackColor |
				ControlStyles::UserPaint, true
			);
			this->DoubleBuffered = true;
#pragma endregion

			figs.reserve(10);
		}

		int COL = 50;
		int selObj = -1;
		int focObj = -1;
		int entObj = -1;
		bool drag = false;
		bool lCtrlD = false;
		System::Void btnRespawn_Click(System::Object^ sender, System::EventArgs^ e) {
			isFiguresSpawn = true;


			figs.push_back(
				new Figure(
					figureCounter, "Manul " + to_string(figureCounter),
					100 + figureCounter % 8 * 100, COL, 50, 20
				)
			);
			figureCounter++;

			if (figureCounter % 8 == 0) COL += 50;

			

			//this->Refresh();
			pnlField->Refresh();
			//pnlField->Invalidate();
			


			lblInfo1->Text = gcnew String((
					"Figs.Size: " + to_string(figs.size()) + "\n" +
					"Figs.Capa: " + to_string(figs.capacity()) + "\n"
				).c_str()
			);

		}

		
		System::Void pnlField_Click(System::Object^ sender, System::EventArgs^ e) { 
			pnlBottom->Enabled = false;
			this->Focus(); 
		}
		System::Void pnlField_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
			/*BufferedGraphics^ bg = 
				BufferedGraphicsManager::Current->Allocate(
					e->Graphics, pnlField->ClientRectangle);
			bg->Graphics->SmoothingMode = Drawing2D::SmoothingMode::AntiAlias;*/

			//bg->Graphics->Clear(pnlField->BackColor);
			//bg->Render();
			//delete bg;

			e->Graphics->Clear(pnlField->BackColor);
			
			if (isFiguresSpawn) 
				for (auto i = 0; i < figs.size(); i++)
					figs.at(i)->repaintFigure(sender, e);

			
			

		}
		System::Void pnlField_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
		{
			/*if (figureCounter != 0 && entObj != -1) {

				if (e->Button == System::Windows::Forms::MouseButtons::Left) {
					if (figs.at(selObj).entered)
						{
							selObj = entObj;

							figs.at(selObj).MouseClick(0x01);
							figs.at(selObj).selected = true;
							lblInfo2->Text = figs.at(selObj).selected ? "sel" : "unsel";
						}
					else
						{
							figs.at(selObj).selected = false;
							lblInfo2->Text = figs.at(selObj).selected ? "sel" : "unsel";
							selObj = -1;
						}
				}

				if (e->Button == System::Windows::Forms::MouseButtons::Right) {
					if (figs.at(selObj).entered)
						{
							selObj = entObj;

							figs.at(selObj).MouseClick(0x02);
							figs.at(selObj).selected = true;
							lblInfo2->Text = figs.at(selObj).selected ? "sel" : "unsel";
						}
					else 
						{
							figs.at(selObj).selected = false;
							lblInfo2->Text = figs.at(selObj).selected ? "sel" : "unsel";
							selObj = -1;
						}
				}
				
				
			}*/
			

			


			
		}
		System::Void pnlField_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			int x = e->X; int y = e->Y;

			if (isFiguresSpawn) {
				for (auto i = 0; i < figs.size(); i++) {

					figs.at(i)->MouseMove(x, y);

					if (figs.at(i)->entered) {
						entObj = i;
						break;
					}
					else {
						entObj = -1;
					}
				}

				pnlField->Refresh();
				//this->Refresh();
				lblInfo3->Text = gcnew String(("entObj: " + to_string(entObj)).c_str());
			}


			//if (isFiguresSpawn) {
			//	if (drag) {
			//		figs.at(selObj)->koord.x = x;
			//		figs.at(selObj)->koord.y = y;
			//		/*figs.at(entObj)->koord.x = x;
			//		figs.at(entObj)->koord.y = y;*/
			//		pnlField->Refresh();
			//	}
			//}

		}
		System::Void pnlField_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			drag = false;
		}
		System::Void pnlField_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			drag = true;


			if (figureCounter != 0 && entObj != -1) 
			{			/// select one

				// ctrl
				if (1) drop_all();
				selObj = entObj;

				if (e->Button == System::Windows::Forms::MouseButtons::Left) {
					if (figs.at(selObj)->entered)
					{
							
							figs.at(selObj)->MouseClick(0x01);
							figs.at(selObj)->selected = true;
							
					}
					
				}

			}
			else
			{			/// drop all
				drop_all();
				
			}
		}
		void drop_all() {
			for (auto i : figs) i->selected = false;
			//figs.at(selObj)->selected = false;

			selObj = -1;
			pnlField->Refresh();
		}



		System::Void frmMain_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
			/*if (e->KeyCode == Keys::Control) lCtrlD = true;

			lblInfo2->Text = lCtrlD ? "true" : "false";*/


			MessageBox::Show("Down");
		}
		System::Void frmMain_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
			/*if (e->KeyCode == Keys::Control) lCtrlD = false;

			lblInfo2->Text = lCtrlD ? "true" : "false";*/

			MessageBox::Show("Up");
		}
		System::Void frmMain_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
			MessageBox::Show("Press");
		}
		System::Void frmMain_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
			for (auto i : figs) i->~Figure();
			figs.clear();
			cout << "Array size is " << figs.size() << "." << endl;
		}


		System::Void pnlTop_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) { drugMD(sender, e); }
		System::Void pnlTop_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) { drugMM(sender, e); }
		System::Void pnlTop_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)   { drugMU(sender, e); }
		System::Void pnlTop_MouseDoubleClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			WindowState = (WindowState == FormWindowState::Normal) ?
				FormWindowState::Maximized : FormWindowState::Normal;
		}

		System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) { Close(); }
		System::Void F1_Click(System::Object^ sender, System::EventArgs^ e) {
			MessageBox::Show("Huitler");
		}
		
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


	

	
	
	
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		pnlField->Refresh();
	}
		System::Void btnInfo_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ info = "";

			for (int i = 0; i < figs.size(); i++) {
				info += figs.at(i)->koord.x + "\n";
			}

			MessageBox::Show(info);
		}



		
	
	
	
	
	
		
	
	};

}



