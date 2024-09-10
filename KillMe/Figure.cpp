#include "Figure.h"
#include <iostream>

using namespace std;


//Figure::Figure(int x, int y) { this->koord.x = x; this->koord.y = y; repaintFigure(); }
Figure::Figure(int x, int y) { this->X = x; this->Y = y; repaintFigure(); }



void Figure::GAVKA() { cout << "Figure::GAVKA" << endl; }
//void Figure::koords(int x, int y) { this->koord.x = x; this->koord.y = y; }

void Figure::repaintFigure() {
	cout << "repaintFigure" << endl;
}