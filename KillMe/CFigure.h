//#pragma once
class CFigure
{
public:
	 CFigure() { repaintFigure(); };
	 CFigure(int x, int y);
	~CFigure() {};

	//koordinates koord;
	//void koords(int, int);

	int X;
	int Y;

	void repaintFigure();
	virtual void GAVKA();


private:
	int _id;

};