#include "frmMain.h"
#include "Figure.h"

#include <Windows.h>
#include <iostream>

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void CODE() {
	//using namespace std;

	/*Figure fig1;
	fig1.koord.x = 10;
	fig1.koord.y = 20;
	Figure fig2(110, 120);*/
	//vector<Figure> figs(4);

	//cout << "Figures are set" << endl;
}

void APPLICATION_START() {
	setlocale(LC_ALL, "RU_ru");
	system("color 70");
	std::cout << "\n APPLICATION START\n\n";
	std::cout << "\tStatistic:\n\n";

	// Let's code
	std::cout << "\tInfo of Application here =/\n";
	CODE();

	std::cout << "\n\n";
}
void APPLICATION_FORM() {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	KillMe::frmMain form;
	Application::Run(% form);
}
void APPLICATION_END() {
	std::cout << "\n APPLICATION END\n\n";
	//system("pause");
}

/// ver 0.1.0
int main(array<String^>^ args) {
	APPLICATION_START();
	APPLICATION_FORM();
	APPLICATION_END();
	return 0;
}



/// TODO:
// 
// (+) MVP
// (+) GIT Connection
// (+) GIT Make "Develop" branch
// 
// -------------------
// ( ) Task
// -------------------
// ( ) Task
// ( ) Task
//
//
/// BUGS:
//
// ( ) Component: the essence of the problem
// ( ) 