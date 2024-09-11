#include <Windows.h>
#include <iostream>

#pragma once

public struct koordinates { int x; int y; };

public class Figure
{
public:
	 Figure();
	 Figure(int x, int y);
	 Figure(std::string, int x, int y);
	 ~Figure() { std::cout << "~Figure()" << std::endl; };

	koordinates koord;
	void koords(int, int);

	std::string name;


	void repaintFigure(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e);
	virtual void GAVKA();

	


private:
	int _id;


};

