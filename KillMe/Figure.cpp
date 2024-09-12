#include "Figure.h"

using namespace std;
using namespace System;
using namespace System::Windows;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Data;

Figure::Figure()														  { __FSet({  0, "",   10, 10, 0, 0 }); }
Figure::Figure(int x, int y)											  { __FSet({  0, "",   x,  y,  0, 0 }); }
Figure::Figure(std::string name, int x, int y)							  { __FSet({  0, name, x,  y,  0, 0 }); }
Figure::Figure(int x, int y, int w, int h)								  { __FSet({  0, "",   x,  y,  w, h }); }
Figure::Figure(std::string name, int x, int y, int w, int h)			  { __FSet({  0, name, x,  y,  w, h }); }
Figure::Figure(uint32_t id, std::string name, int x, int y, int w, int h) { __FSet({ id, name, x,  y,  w, h }); }

void Figure::__FSet(_Figurist figure_data) {
	_id =  figure_data.id;
	this->name = figure_data.name;
	koords(figure_data.x, figure_data.y);
	sizes(figure_data.w, figure_data.h);

	cout << "Figure set" << endl;
	
}

void Figure::koords(int x, int y) { this->koord.x = x; this->koord.y = y; }
void Figure::sizes(int w, int h)  { this->size.w = w;  this->size.h = h;  }

void Figure::Click() { cout << "\tFigure::Click()" << endl; }



uint32_t Figure::MouseMove(int x, int y) {
	int L = this->koord.x - this->size.w / 2;
	int T = this->koord.y - this->size.h / 2;
	int R = this->koord.x + this->size.w / 2;
	int B = this->koord.y + this->size.h / 2;;
	

	bool cond1 = (x >= L) && (x <= R);
	bool cond2 = (y >= T) && (y <= B);
	//bool once = false;
	if (cond1 && cond2) {
		cout << "\tManul " << _id << endl << x << ":" << y << endl;
	}
		
	return _id;
}





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

	if (w != 0 && h != 0) {
		g->DrawLine(pen, X - W / 2, Y - H / 2, X + W / 2, Y - H / 2);
		g->DrawLine(pen, X + W / 2, Y - H / 2, X + W / 2, Y + H / 2);
		g->DrawLine(pen, X - W / 2, Y + H / 2, X + W / 2, Y + H / 2);
		g->DrawLine(pen, X - W / 2, Y - H / 2, X - W / 2, Y + H / 2);

		//g->DrawArc(pen, X - W / 2, Y - H / 2, W, H, 0, 360);
	}
		
	


	

	g->DrawString(str, font, txBrush, X + r + W / 2, Y - font->Size / 2, SF);
#pragma endregion

}