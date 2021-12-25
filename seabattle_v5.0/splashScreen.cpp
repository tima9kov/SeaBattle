#include "splashScreen.h"
#include "enums.h"
#include <iostream>
#include <Windows.h>
using namespace std;
void splash_screen()
{
	COORD position = { SPLASH_SCREEN_XCOORD, SPLASH_SCREEN_YCOORD };
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, position);
	cout << "S E A		B A T T L E	  G A M E   ";
	position.Y += 1;
	SetConsoleCursorPosition(hConsole, position);
	cout << "B Y";
	position.Y += 1;
	SetConsoleCursorPosition(hConsole, position);
	cout << "S T U D E N T	    O F		        ";
	position.Y += 1;
	SetConsoleCursorPosition(hConsole, position);
	cout << "S T E P	  I T	    A C A D E M Y";
	position.Y += 1;
	SetConsoleCursorPosition(hConsole, position);
	cout << "T I M O F E Y	   D E V Y A T K O V";
	position.X += 50;
	position.Y -= 4;
	SetConsoleCursorPosition(hConsole, position);
	system("pause");
}