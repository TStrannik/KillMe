#include "Figure.h"

using namespace std;
using namespace System;
using namespace System::Windows;
using namespace System::Windows::Forms;
using namespace System::Drawing;

Figure::Figure()
{
	this->name = "Osas";	
	this->koord.x = 10;
	this->koord.y = 10;
	//repaintFigure();
}
Figure::Figure(int x, int y)
{	
	this->koord.x = x;
	this->koord.y = y;
	this->name = "Ubemugbe "; // +x + " " + y;
	//repaintFigure();
}
Figure::Figure(std::string name, int x, int y) {
	this->koord.x = x;
	this->koord.y = y;
	this->name = name;
	//repaintFigure();
}




void Figure::GAVKA() { cout << "Figure::GAVKA" << endl; }
void Figure::koords(int x, int y) { this->koord.x = x; this->koord.y = y; }

void Figure::repaintFigure(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	cout << "repaintFigure" << endl;
	Panel^ p = (Panel^)sender;
#pragma region def
	Graphics^ g = e->Graphics;
	g->SmoothingMode = Drawing2D::SmoothingMode::AntiAlias;
	g->Clear(Color::LightYellow);
	uint8_t w = p->Width - 1, h = p->Height - 1;
	uint8_t r = 5;

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
	g->DrawString(str, font, txBrush, X + r, Y - font->Size / 3, SF);

}