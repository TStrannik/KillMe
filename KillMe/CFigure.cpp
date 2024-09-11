#include "CFigure.h"
#include <iostream>

using namespace std;


//CFigure::CFigure(int x, int y) { this->koord.x = x; this->koord.y = y; repaintFigure(); }
CFigure::CFigure(int x, int y) { this->X = x; this->Y = y; repaintFigure(); }



void CFigure::GAVKA() { cout << "Figure::GAVKA" << endl; }
//void Figure::koords(int x, int y) { this->koord.x = x; this->koord.y = y; }

void CFigure::repaintFigure() {
	cout << "repaintFigure" << endl;
}


