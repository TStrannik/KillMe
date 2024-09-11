#include "Figure.h"

using namespace std;
using namespace System;
using namespace System::Windows;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Data;

Figure::Figure()											 { __FSet({ "",   10, 10, 0, 0 }); }
Figure::Figure(int x, int y)								 { __FSet({ "",   x,  y,  0, 0 }); }
Figure::Figure(std::string name, int x, int y)				 { __FSet({ name, x,  y,  0, 0 }); }
Figure::Figure(int x, int y, int w, int h)					 { __FSet({ "",   x,  y,  w, h }); }
Figure::Figure(std::string name, int x, int y, int w, int h) { __FSet({ name, x,  y,  w, h }); }

void Figure::__FSet(_Figurist figure_data) {
	this->name = figure_data.name;
	koords(figure_data.x, figure_data.y);
	sizes(figure_data.w, figure_data.h);

	cout << "Figure set" << endl;
	
}

void Figure::koords(int x, int y) { this->koord.x = x; this->koord.y = y; }
void Figure::sizes(int w, int h)  { this->size.w = w;  this->size.h = h;  }

void Figure::Click() { cout << "\tFigure::Click()" << endl; }

void Figure::GAVKA() { cout << "\tFigure::GAVKA" << endl; }




void Figure::repaintFigure(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	Panel^ p = (Panel^)sender;
#pragma region def
	Graphics^ g = e->Graphics;
	g->SmoothingMode = Drawing2D::SmoothingMode::AntiAlias;
	
	uint8_t w = p->Width - 1, h = p->Height - 1;
	uint8_t r = 1;

	Font^ font = p->Font;
	StringFormat^ SF = gcnew StringFormat;
	SF->Alignment = StringAlignment::Near;
	SF->LineAlignment = StringAlignment::Near;

	Pen^ pen = gcnew Pen(Color::Black);
	Brush^ txBrush = gcnew SolidBrush(Color::Black);
#pragma endregion

#pragma region drawing
	String^ str = gcnew String(this->name.c_str());
	int X = this->koord.x;
	int Y = this->koord.y;
	int W = this->size.w;
	int H = this->size.h;

	g->DrawArc(pen, X - r, Y - r, r * 2, r * 2, 0, 360);

	if (w != 0 && h != 0)
		g->DrawArc(pen, X - W / 2, Y - H / 2, W, H, 0, 360);

		//g->DrawLine(pen, X - W / 2, Y - H / 2, X + W / 2, Y - H / 2);


	

	g->DrawString(str, font, txBrush, X + r + W / 2, Y - font->Size / 2, SF);
#pragma endregion

}