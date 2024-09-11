#include "Figure.h"

using namespace std;
using namespace System;
using namespace System::Windows;
using namespace System::Windows::Forms;
using namespace System::Drawing;


void Figure::FSet(_Figurist figure_data) {
	this->name = figure_data.name;
	koords(figure_data.x, figure_data.y);
	sizes(figure_data.w, figure_data.h);
}

Figure::Figure()
{
	FSet({ "", 10, 10, 0, 0 });

	/*this->name = "";
	koords(10, 10);
	sizes(0, 0);*/
}
Figure::Figure(int x, int y)
{	
	FSet({ "", x, y, 0, 0 });

	/*this->name = "";
	koords(x, y);
	sizes(0, 0);	*/
}
Figure::Figure(std::string name, int x, int y)
{
	FSet({ name, x, y, 0, 0 });

	/*this->name = name;
	koords(x, y);
	sizes(0, 0);	*/
}
Figure::Figure(int x, int y, int w, int h)
{
	FSet({ "", x, y, w, h });

	/*this->name = "Figure";
	koords(x, y);
	sizes(w, h);	*/
}
Figure::Figure(std::string name, int x, int y, int w, int h)
{
	this->name = name;
	koords(x, y);
	sizes(w, h);
}

void Figure::koords(int x, int y) { this->koord.x = x; this->koord.y = y; }
void Figure::sizes(int w, int h)  { this->size.w = w;  this->size.h = h;  }


void Figure::GAVKA() { cout << "Figure::GAVKA" << endl; }




void Figure::repaintFigure(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	cout << "repaintFigure" << endl;
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

	String^ str = gcnew String(this->name.c_str());
	int X = this->koord.x;
	int Y = this->koord.y;


	g->DrawArc(pen, X - r, Y - r, r * 2, r * 2, 0, 360);

	if (w != 0 && h != 0) 
		g->DrawArc(pen, X - w, Y - h, w * 2, h * 2, 0, 360);

	g->DrawString(str, font, txBrush, X + r, Y - font->Size / 2, SF);

}