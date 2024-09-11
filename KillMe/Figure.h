#include <Windows.h>
#include <iostream>

#pragma once

using namespace System;

public struct koordinates { int x; int y; };

public class Figure
{
public:
	 Figure();
	 Figure(int x, int y);
	~Figure() {};

	koordinates koord;
	void koords(int, int);
	/*int X;
	int Y;*/

	std::string name;



	void repaintFigure();
	virtual void GAVKA();

	


private:
	int _id;


};

