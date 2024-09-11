#include <Windows.h>
#include <iostream>

#pragma once

public struct koordinates { int x; int y; };
public struct sizes		  { int w; int h; };
public struct _Figurist {
	std::string name;
	int x; int y; int w; int h;
};

//this->Write(Context->ExecMacro("$(End)"));

public class Figure
{
public:
	 Figure();	
	 /// <summary> �������� ������ � ������� �� ����������� X � Y </summary>
		/// <param name="x">���������� X ������ �������</param>
		/// <param name="y">���������� Y ������ �������</param>		
	 Figure(int x, int y);
	 /// <summary> �������� ������ � ������� �� ����������� X � Y </summary>		
		/// <param name="x">���������� X ������ �������</param>
		/// <param name="y">���������� Y ������ �������</param>
		/// <param name="w">������ ���������� �������</param>
		/// <param name="h">������ ���������� �������</param>
	 Figure(int x, int y, int width, int height);
	 /// <summary> �������� ������ � ������� �� ����������� X � Y </summary>
		/// <param name="name">��� ��� �������</param>
		/// <param name="x">���������� X ������ �������</param>
		/// <param name="y">���������� Y ������ �������</param>		
	 Figure(std::string name, int x, int y);	 
	 /// <summary> �������� ������ � ������� �� ����������� X � Y </summary>
		/// <param name="name">��� ��� �������</param>
		/// <param name="x">���������� X ������ �������</param>
		/// <param name="y">���������� Y ������ �������</param>
		/// <param name="w">������ ���������� �������</param>
		/// <param name="h">������ ���������� �������</param>
	 Figure(std::string name, int x, int y, int width, int height);

	 ~Figure() { std::cout << "\t~Figure()" << std::endl; };

	koordinates koord;
	sizes size;
	void sizes(int, int);
	void koords(int, int);

	std::string name;


	void repaintFigure(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e);
	virtual void GAVKA();

	

	void Click();
	

private:
	int _id;
	int __varka;

	void __FSet(_Figurist figure_data);

	void GenerateSummaryText() {
		
	}

	/// <summary> <# GenerateSummaryText(); #> </summary>

};

