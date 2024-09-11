#include "Figure.h"

using namespace std;

Figure::Figure()
{
	this->name = "Osas";	
	/*this->koord.x = 10;
	this->koord.y = 10;*/
	X = 10; Y = 10;
	repaintFigure();
}
Figure::Figure(int x, int y)
{	
	/*this->koord.x = x;
	this->koord.y = y;*/
	X = x; Y = y;
	this->name = "Ubemugbe "; // +x + " " + y;
	repaintFigure();
}

//Figure::Figure(int x, int y) { this->X = x; this->Y = y; repaintFigure(); }



void Figure::GAVKA() { cout << "Figure::GAVKA" << endl; }
//void Figure::koords(int x, int y) { this->koord.x = x; this->koord.y = y; }

void Figure::repaintFigure() {
	cout << "repaintFigure" << endl;
}