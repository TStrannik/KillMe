#pragma once

//ref struct koordinates { int x; int y; };

ref class Figure
{
public:
	 Figure() { repaintFigure(); };
	 Figure(int x, int y);
	~Figure() {};

	//koordinates koord;
	//void koords(int, int);

	int X;
	int Y;

	void repaintFigure();
	virtual void GAVKA();


private:
	int _id;
	

};

