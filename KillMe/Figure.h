#include <Windows.h>
#include <iostream>

#pragma once

public struct koordinates { int x; int y; };
public struct sizes		  { int w; int h; };
public struct _Figurist {
	std::string name;
	int x; int y; int w; int h;
};

public class Figure
{
public:
	 Figure();
	 Figure(int x, int y);
	 Figure(int x, int y, int w, int h);
	 Figure(std::string, int x, int y);
	 Figure(std::string, int x, int y, int w, int h);
	 ~Figure() { std::cout << "~Figure()" << std::endl; };

	koordinates koord;
	sizes size;
	void sizes(int, int);
	void koords(int, int);

	std::string name;


	void repaintFigure(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e);
	virtual void GAVKA();

	
	void FSet(_Figurist figure_data);

private:
	int _id;
	int __varka;

	

};

