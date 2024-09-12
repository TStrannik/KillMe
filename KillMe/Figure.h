#include <Windows.h>
#include <iostream>

#pragma once

#pragma region STRUCTS & CONSTS
public struct koordinates { int x; int y; };
public struct sizes		  { int w; int h; };
public struct _Figurist {
	int32_t id;
	std::string name;
	int x; int y; int w; int h;
};

//this->Write(Context->ExecMacro("$(End)"));
#pragma endregion



public class Figure  {


public:
#pragma region CONSTRUCTORS &~
	 Figure();	
	 /// <summary> Создание фигуры с центром по координатам X и Y </summary>
		/// <param name="x">Координата X центра объекта</param>
		/// <param name="y">Координата Y центра объекта</param>		
	 Figure(int x, int y);
	 /// <summary> Создание фигуры с центром по координатам X и Y </summary>		
		/// <param name="x">Координата X центра объекта</param>
		/// <param name="y">Координата Y центра объекта</param>
		/// <param name="w">Ширина контейнера объекта</param>
		/// <param name="h">Высота контейнера объекта</param>
	 Figure(int x, int y, int width, int height);
	 /// <summary> Создание фигуры с центром по координатам X и Y </summary>
		/// <param name="name">Имя для объекта</param>
		/// <param name="x">Координата X центра объекта</param>
		/// <param name="y">Координата Y центра объекта</param>		
	 Figure(std::string name, int x, int y);	 
	 /// <summary> Создание фигуры с центром по координатам X и Y </summary>
		/// <param name="name">Имя для объекта</param>
		/// <param name="x">Координата X центра объекта</param>
		/// <param name="y">Координата Y центра объекта</param>
		/// <param name="w">Ширина контейнера объекта</param>
		/// <param name="h">Высота контейнера объекта</param>
	 Figure(std::string name, int x, int y, int width, int height);
	 /// <summary> Создание фигуры с центром по координатам X и Y </summary>
		/// <param name="id">Идентификатор объекта</param>
		/// <param name="name">Имя для объекта</param>
		/// <param name="x">Координата X центра объекта</param>
		/// <param name="y">Координата Y центра объекта</param>
		/// <param name="w">Ширина контейнера объекта</param>
		/// <param name="h">Высота контейнера объекта</param>
	 Figure(int32_t id, std::string name, int x, int y, int width, int height);

	 ~Figure() { std::cout << "\t\t~Figure()" << std::endl; };
#pragma endregion



public:
#pragma region Kernel
	koordinates koord;
	sizes size;
	void sizes(int, int);
	void koords(int, int);

	std::string name;


	void repaintFigure(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e);
	uint32_t MouseMove(int x, int y);

	
	bool entered  = false;
	bool selected = false;
	void MouseClick(uint8_t button);
#pragma endregion
	


private:
#pragma region Inside V&M
	int32_t _id = -1;
	
	int __varka;

	void __FSet(_Figurist figure_data);

	const uint8_t _MB_LEFT  = 0x01;
	const uint8_t _MB_RIGHT = 0x02;

	void GenerateSummaryText() {
		
	}

	/// <summary> <# GenerateSummaryText(); #> </summary>
#pragma endregion



};

