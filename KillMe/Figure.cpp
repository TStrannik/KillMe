#include "Figure.h"

using namespace std;
using namespace System;
using namespace System::Windows;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Data;





#pragma region CONSTRUCTORS etc
Figure::Figure()														 { __FSet({  0, "",   10, 10, 0, 0 }); }
Figure::Figure(int x, int y)											 { __FSet({  0, "",   x,  y,  0, 0 }); }
Figure::Figure(std::string name, int x, int y)							 { __FSet({  0, name, x,  y,  0, 0 }); }
Figure::Figure(int x, int y, int w, int h)								 { __FSet({  0, "",   x,  y,  w, h }); }
Figure::Figure(std::string name, int x, int y, int w, int h)			 { __FSet({  0, name, x,  y,  w, h }); }
Figure::Figure(int32_t id, std::string name, int x, int y, int w, int h) { __FSet({ id, name, x,  y,  w, h }); }

void Figure::__FSet(_Figurist figure_data) {
	_id =  figure_data.id;
	this->name = figure_data.name;
	koords(figure_data.x, figure_data.y);
	sizes(figure_data.w, figure_data.h);



	entered  = false;
	selected = false;



	cout << "\tFigure set" << endl;
	
}
void Figure::koords(int x, int y) { this->koord.x = x; this->koord.y = y; }
void Figure::sizes(int w, int h) { this->size.w = w;  this->size.h = h; }
#pragma endregion




#pragma region Mouse Events
void Figure::MouseClick(uint8_t button) {
	if (button == _MB_LEFT)  cout << "\tClick(Left) "  << _id << endl; 
	if (button == _MB_RIGHT) cout << "\tClick(Rught) " << _id << endl;	
}

uint32_t Figure::MouseMove(int x, int y) {
	int L = this->koord.x - this->size.w / 2;
	int T = this->koord.y - this->size.h / 2;
	int R = this->koord.x + this->size.w / 2;
	int B = this->koord.y + this->size.h / 2;;
	
	bool cond1 = (x >= L) && (x <= R);
	bool cond2 = (y >= T) && (y <= B);
	entered = cond1 && cond2;
		
	return _id;
}

#pragma endregion





#pragma region Painting
void Figure::repaintFigure(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	Panel^ p = (Panel^)sender;



#pragma region def
	
	Graphics^ g = e->Graphics;
	g->SmoothingMode = Drawing2D::SmoothingMode::AntiAlias;

	/*BufferedGraphics^ bg = BufferedGraphicsManager::Current->Allocate(e->Graphics, p->ClientRectangle);
	bg->Graphics->SmoothingMode = Drawing2D::SmoothingMode::AntiAlias;*/


	Drawing2D::GraphicsPath^ gp = gcnew Drawing2D::GraphicsPath();

	uint8_t w = p->Width - 1, h = p->Height - 1;
	uint8_t r = 1;

	Font^ font = p->Font;
	StringFormat^ SF = gcnew StringFormat;
	SF->Alignment = StringAlignment::Near;
	SF->LineAlignment = StringAlignment::Near;

	Pen^ pen = gcnew Pen(Color::Red);
	Brush^ txBrush  = gcnew SolidBrush(Color::Black);
	/*Brush^ bgBrush  = gcnew SolidBrush(Color::Transparent);*/
	Brush^ bgBrush = gcnew SolidBrush(Color::White);
	Brush^ bgBrushE = gcnew SolidBrush(Color::Yellow);
	
#pragma endregion



#pragma region drawing
	String^ str = gcnew String(this->name.c_str());
	int X = this->koord.x;
	int Y = this->koord.y;
	int W = this->size.w;
	int H = this->size.h;


	if (w != 0 && h != 0) {
		
		g->DrawLine(pen, X - W / 2, Y - H / 2, X + W / 2, Y - H / 2);
		g->DrawLine(pen, X + W / 2, Y - H / 2, X + W / 2, Y + H / 2);
		g->DrawLine(pen, X + W / 2, Y + H / 2, X - W / 2, Y + H / 2);
		g->DrawLine(pen, X - W / 2, Y - H / 2, X - W / 2, Y + H / 2);

		/*bg->Graphics->DrawLine(pen, X - W / 2, Y - H / 2, X + W / 2, Y - H / 2);
		bg->Graphics->DrawLine(pen, X + W / 2, Y - H / 2, X + W / 2, Y + H / 2);
		bg->Graphics->DrawLine(pen, X + W / 2, Y + H / 2, X - W / 2, Y + H / 2);
		bg->Graphics->DrawLine(pen, X - W / 2, Y - H / 2, X - W / 2, Y + H / 2);*/

		/////g->DrawArc(pen, X - W / 2, Y - H / 2, W, H, 0, 360);

		gp->StartFigure();
		gp->AddLine(X - W / 2, Y - H / 2, X + W / 2, Y - H / 2);
		gp->AddLine(X + W / 2, Y - H / 2, X + W / 2, Y + H / 2);
		gp->AddLine(X + W / 2, Y + H / 2, X - W / 2, Y + H / 2);
		gp->AddLine(X - W / 2, Y - H / 2, X - W / 2, Y + H / 2);
		gp->CloseFigure();

		if (entered)  g->FillPath(bgBrushE, gp);
		if (!entered) g->FillPath(bgBrush, gp);
		/*if (entered)  bg->Graphics->FillPath(bgBrushE, gp);
		if (!entered) bg->Graphics->FillPath(bgBrush, gp);*/
		
		if (selected) g->DrawArc(pen, X - r, Y - r, r * 5, r * 5, 0, 360);
		if (!selected)  g->DrawArc(pen, X - r, Y - r, r * 2, r * 2, 0, 360);
		/*if (selected)	bg->Graphics->DrawArc(pen, X - r, Y - r, r * 5, r * 5, 0, 360);
		if (!selected)  bg->Graphics->DrawArc(pen, X - r, Y - r, r * 2, r * 2, 0, 360); */

	}
		
	


	
	//bg->Graphics->DrawString(str, font, txBrush, X + r + W / 2, Y - font->Size / 2, SF);
	g->DrawString(str, font, txBrush, X + r + W / 2, Y - font->Size / 2, SF);

	/*bg->Render();
	delete bg;*/

#pragma endregion

}

#pragma endregion