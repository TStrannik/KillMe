public class CCFigure
{
public:
	CCFigure() { };
	CCFigure(int x, int y) {};
	~CCFigure() {};

	//koordinates koord;
	//void koords(int, int);

	int X;
	int Y;

	/*void repaintFigure();
	virtual void GAVKA();*/
private:

};


#include "Figure.h"
#include "CFigure.h"

#include <Windows.h>
#include <iostream>
#include <vector>
#include <array>


#pragma once



namespace KillMe {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	

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
			   this->btnRespawn = (gcnew System::Windows::Forms::Button());
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
			   this->pnlField->Controls->Add(this->btnRespawn);
			   this->pnlField->Location = System::Drawing::Point(97, 91);
			   this->pnlField->Name = L"pnlField";
			   this->pnlField->Size = System::Drawing::Size(249, 160);
			   this->pnlField->TabIndex = 1;
			   this->pnlField->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &frmMain::pnlField_Paint);
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
			   this->pnlField->ResumeLayout(false);
			   this->ResumeLayout(false);

		   }
#pragma endregion

#pragma region Voids

	public:
		/*Figure fig;
		Figure^ fig0;
		Figure^ fig1;

		vector<Figure^> *figs;*/

		CCFigure *fig = new CCFigure();
		
		UINT16 figC = 0;
		CCFigure* figA = new CCFigure[10];

		
		//CCFigure fig;
		




		//Figure fig0;	// good if ref&ref
		//Figure^ figa = gcnew Figure(200, 20); // good if ref&ref


	private:
		System::Void frmMain_Load(System::Object^ sender, System::EventArgs^ e) {
			pnlTop->Dock = DockStyle::Top;			pnlTop->SendToBack();
			pnlBottom->Dock = DockStyle::Bottom;	pnlBottom->SendToBack();
			pnlLeft->Dock = DockStyle::Left;
			pnlRight->Dock = DockStyle::Right;
			pnlField->Dock = DockStyle::Fill;



			// CFigure fAra[10];	// WORK
			//vector <CFigure> figs;


			/*vector <Figure^> figs;*/
			
			

			/*fig0 = gcnew Figure();
			fig0->koord.x = 50;
			fig0->koord.y = 20;

			fig1 = gcnew Figure();*/


			//figs->push_back(gcnew Figure());
			

			cout << endl;

			//afigs[0] = new Figure();



			//figs->push_back(Figure(200, 200));
			//figs->push_back(Figure());

			
			
		}

		System::Void btnRespawn_Click(System::Object^ sender, System::EventArgs^ e) {

			
			//figs->push_back(Figure(200, 200));

			/*fig.koord.x = 300;
			fig.koord.y = 30;*/

			//figA[figC] = new CCFigure();
			figA[figC].X = 100; figA[figC].Y = 30;
			figC++;


			pnlField->Refresh();
			pnlField->Invalidate();

		}
		System::Void pnlField_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
			Graphics^ g = e->Graphics;
			g->SmoothingMode = Drawing2D::SmoothingMode::AntiAlias;
			//g->Clear(pnlField->BackColor);
			g->Clear(Color::White);

			uint8_t w = pnlField->Width - 1, h = pnlField->Height - 1;
			uint8_t r = 10;

			StringFormat^ SF = gcnew StringFormat;
			SF->Alignment = StringAlignment::Near;
			SF->LineAlignment = StringAlignment::Near;

			Pen^ pen = gcnew Pen(Color::Black);
			Brush^ txBrush = gcnew SolidBrush(Color::Black);




			/*g->DrawArc(pen, fig.koord.x - r, fig.koord.y - r, r, r, 0, 360);
			g->DrawString(fig.name, Font, txBrush, fig.koord.x, fig.koord.y, SF);*/

			g->DrawArc(pen, fig[0].X - r, fig[0].Y - r, r, r, 0, 360);
			



			/*g->DrawArc(pen, fig0->koord.x - r, fig0->koord.y - r, r, r, 0, 360);
			g->DrawArc(pen, fig1->koord.x - r, fig1->koord.y - r, r, r, 0, 360);
			g->DrawString(fig0->name, Font, txBrush, fig0->koord.x, fig0->koord.y, SF);
			g->DrawString(fig1->name, Font, txBrush, fig1->koord.x, fig1->koord.y, SF);*/



			/*Figure fig2(110, 120);
			g->DrawArc(pen, fig2.koord.x - r, fig2.koord.y - r, r, r, 0, 360);
			g->DrawString(fig2.name, Font, txBrush, fig2.koord.x, fig2.koord.y, SF);*/

			//g->DrawArc(pen, figs->at(0).koord.x - r, figs->at(0).koord.y - r, r, r, 0, 360);
		}
#pragma endregion

	};

}

