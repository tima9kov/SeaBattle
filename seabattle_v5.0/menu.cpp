#include "menu.h"
#include <iostream>
#include <Windows.h>
#include <string>
#include "enums.h"
using namespace std;

void show_vertical_part(const int X_OUTPUT , int &y_fixed) {
	COORD position = { X_OUTPUT, y_fixed }; //our coordinates of x and y
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, position);
	for (int i = 0; i < 3; i++) {
		position.X = X_OUTPUT;
		position.Y += 1;
		y_fixed = position.Y;
		SetConsoleCursorPosition(hConsole, position);
		cout << char(VERTICAL);
		position.X += 61;
		SetConsoleCursorPosition(hConsole, position);
		cout << char(VERTICAL);
		y_fixed += 1;
	}
}

void show_horizontal_part(const int X_OUTPUT, int& y_fixed) {
	COORD position = { X_OUTPUT, y_fixed }; //our coordinates of x and y
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, position);
	cout << char(LEFT_CONNECTOR);
	for (int i = 0; i < 60; ++i)
		cout << char(HORIZONTAL);
	cout << char(RIGHT_CONNECTOR);
}

void show_letters_for_first(const int X_OUTPUT, const int Y_OUTPUT, int &y_fixed) {
	string green = "\x1b[32m", red = "\x1b[31m", purple = "\x1b[35m", white = "\x1b[0m";
	COORD position = { X_OUTPUT, y_fixed }; //our coordinates of x and y
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, position);
	position.X = X_OUTPUT + 15;
	position.Y = Y_OUTPUT + 2;
	SetConsoleCursorPosition(hConsole, position);
	cout << green << "P L A Y E R _ V S _ C O M P U T E R" << white;

	position.X = X_OUTPUT + 11;
	position.Y = Y_OUTPUT + 6;
	SetConsoleCursorPosition(hConsole, position);
	cout << green << "C O M P U T E R _ V S _ C O M P U T E R" << white;

	position.X = X_OUTPUT + 23;
	position.Y = Y_OUTPUT + 10;
	SetConsoleCursorPosition(hConsole, position);
	cout << red << "E N D ___ G A M E" << white;
}

void show_letters_for_second(const int X_OUTPUT, const int Y_OUTPUT, int& y_fixed) {
	string green = "\x1b[32m", red = "\x1b[31m", purple = "\x1b[35m", white = "\x1b[0m";
	COORD position = { X_OUTPUT, y_fixed }; //our coordinates of x and y
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, position);
	position.X = X_OUTPUT + 16;
	position.Y = Y_OUTPUT + 2;
	SetConsoleCursorPosition(hConsole, position);
	cout << green << "R A N D O M ___ P L A C E M E N T" << white;

	position.X = X_OUTPUT + 16;
	position.Y = Y_OUTPUT + 6;
	SetConsoleCursorPosition(hConsole, position);
	cout << green << "D E F O L T ___ P L A C E M E N T" << white;

	position.X = X_OUTPUT + 22;
	position.Y = Y_OUTPUT + 10;
	SetConsoleCursorPosition(hConsole, position);
	cout << red << "E N D ___ G A M E" << white;
}

void show_letters_for_third(const int X_OUTPUT, const int Y_OUTPUT, int& y_fixed) {
	string green = "\x1b[32m", red = "\x1b[31m", purple = "\x1b[35m", white = "\x1b[0m";
	COORD position = { X_OUTPUT, y_fixed }; //our coordinates of x and y
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, position);
	position.X = X_OUTPUT + 14;
	position.Y = Y_OUTPUT + 2;
	SetConsoleCursorPosition(hConsole, position);
	cout << green << "W I T H O U T ___ A L G O R I T M" << white;

	position.X = X_OUTPUT + 18;
	position.Y = Y_OUTPUT + 6;
	SetConsoleCursorPosition(hConsole, position);
	cout << green << "U S I N G ___ A L G O R I T M" << white;

	position.X = X_OUTPUT + 22;
	position.Y = Y_OUTPUT + 10;
	SetConsoleCursorPosition(hConsole, position);
	cout << red << "E N D ___ G A M E" << white;
}

void show_frame(const int X_OUTPUT , const int Y_OUTPUT , int &y_fixed , int amount) {
	
	system("cls");
	//some colors for formatted output
	string green = "\x1b[32m", red = "\x1b[31m", purple = "\x1b[35m", white = "\x1b[0m";
	
	//start of menu creation
	COORD position = { X_OUTPUT, Y_OUTPUT }; //our coordinates of x and y
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, position);

	//upper line
	cout << purple << char(UPPER_LEFT_CORNER);
	for (int i = 0; i < 60; ++i)
		cout << char(HORIZONTAL);
	cout << char(UPPER_RIGHT_CORNER);

	//middle lines
	for (int i = 0; i < amount - 1; i++) {
		show_vertical_part(X_OUTPUT, y_fixed);
		show_horizontal_part(X_OUTPUT, y_fixed);
	}
	show_vertical_part(X_OUTPUT, y_fixed);

	//bottom line
	position.X = X_OUTPUT;
	position.Y = y_fixed;
	SetConsoleCursorPosition(hConsole, position);
	cout << char(DOWNER_LEFT_CORNER);
	for (int i = 0; i < 60; ++i)
		cout << char(HORIZONTAL);
	cout << char(DOWNER_RIGHT_CORNER);	
}

void say_goodbuy() {
	system("cls");
	COORD position = { 25, 10 }; //our coordinates of x and y
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, position);
	cout << "\x1b[33m\t\t\tG O O D B U Y";
	position.Y += 2;
	SetConsoleCursorPosition(hConsole, position);
	cout << "W I L L _ B E _ G L A D _ T O _ S E E _ Y O U _ A G A I N \x1b[0m";
	position.Y += 5;
	SetConsoleCursorPosition(hConsole, position);
}

void show_middle_menu(const int X_OUTPUT, const int Y_OUTPUT, int& y_fixed) {

	system("cls");
	//some colors for formatted output
	string green = "\x1b[32m", red = "\x1b[31m", purple = "\x1b[35m", white = "\x1b[0m";

	//start of menu creation
	COORD position = { X_OUTPUT, Y_OUTPUT }; //our coordinates of x and y
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, position);

	//upper line
	cout << purple << char(UPPER_LEFT_CORNER);
	for (int i = 0; i < 60; ++i)
		cout << char(HORIZONTAL);
	cout << char(UPPER_RIGHT_CORNER);

	//middle lines
	for (int i = 0; i < 1; i++) {
		show_vertical_part(X_OUTPUT, y_fixed);
		show_horizontal_part(X_OUTPUT, y_fixed);
	}
	show_vertical_part(X_OUTPUT, y_fixed);

	//bottom line
	position.X = X_OUTPUT;
	position.Y = y_fixed;
	SetConsoleCursorPosition(hConsole, position);
	cout << char(DOWNER_LEFT_CORNER);
	for (int i = 0; i < 60; ++i)
		cout << char(HORIZONTAL);
	cout << char(DOWNER_RIGHT_CORNER);
			
	position.X = X_OUTPUT + 26;
	position.Y = Y_OUTPUT + 2;
	SetConsoleCursorPosition(hConsole, position);
	cout << green << "B R E A K" << white;

	position.X = X_OUTPUT + 23;
	position.Y = Y_OUTPUT + 6;
	SetConsoleCursorPosition(hConsole, position);
	cout << green << "E N D ___ G A M E" << white;
}

void middle_menu_control(int &middle_menu_choice) {
	const int X_OUTPUT = 10, Y_OUTPUT = 5;
	int y_fixed = Y_OUTPUT;
	show_middle_menu(X_OUTPUT, Y_OUTPUT, y_fixed);
	
	//now users choice
	//control will be performed by the mouse
	HANDLE hin = GetStdHandle(STD_INPUT_HANDLE); //get the descriptor
	INPUT_RECORD InputRecord; //used to return information about input messages in the console input buffer 
	DWORD Events; // unsigned long
	COORD coord{0}; // for coords X, Y

	//deny console highlighting
	DWORD prev_mode;
	GetConsoleMode(hin, &prev_mode);
	SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), ENABLE_EXTENDED_FLAGS | (prev_mode & ~ENABLE_QUICK_EDIT_MODE));

	SetConsoleMode(hin, ENABLE_MOUSE_INPUT); // allow mouse handling 

	//FIRST PART OF MENU

	while (true)
	{
		ReadConsoleInput(hin, &InputRecord, 1, &Events); //reading


		if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)   //left batton
		{
			coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
			coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;

			if (coord.X >= X_OUTPUT + 1 && coord.X <= X_OUTPUT + 60 && coord.Y >= coord.Y && coord.Y <= coord.Y + 12) {
				if (coord.Y >= 5 && coord.Y <= 8) {
					middle_menu_choice = BREAK;
					for (int i = 30; i != 0; i--) {
						system("cls");
						cout << "\n\n\n\t\t\t\x1b[31m" << i << " S E C O N D S _ L E F T\x1b[0m";
						Sleep(1000);
					}
					break;
				}
				else if (coord.Y >= 9 && coord.Y <= 12) {
					middle_menu_choice = END_GAME_MIDDLE_MENU;
					break;
				}
			}
		}
	}
}

void menu_control(int &first_menu_choice, int &second_menu_choice, int &third_menu_choice) {
	const int X_OUTPUT = 10, Y_OUTPUT = 5;
	int y_fixed = Y_OUTPUT;
	show_frame(X_OUTPUT, Y_OUTPUT, y_fixed, 3);
	show_letters_for_first(X_OUTPUT, Y_OUTPUT, y_fixed);
	//now users choice
	//control will be performed by the mouse
	HANDLE hin = GetStdHandle(STD_INPUT_HANDLE); //get the descriptor
	INPUT_RECORD InputRecord; //used to return information about input messages in the console input buffer 
	DWORD Events; // unsigned long
	COORD coord{0}; // for coords X, Y

	//deny console highlighting
	DWORD prev_mode;
	GetConsoleMode(hin, &prev_mode);
	SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), ENABLE_EXTENDED_FLAGS | (prev_mode & ~ENABLE_QUICK_EDIT_MODE));

	SetConsoleMode(hin, ENABLE_MOUSE_INPUT); // allow mouse handling 

	//FIRST PART OF MENU

	while (true)
	{
		ReadConsoleInput(hin, &InputRecord, 1, &Events); //reading


		if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)   //left batton
		{
			coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
			coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
			
			if (coord.X >= X_OUTPUT + 1 && coord.X <= X_OUTPUT + 60 && coord.Y >= coord.Y && coord.Y <= coord.Y + 12) {
				if (coord .Y >= 5 && coord.Y <= 8){
					first_menu_choice = PLAYER_VS_COMPUTER;
					break;
				}else if (coord .Y >= 9 && coord.Y <= 12){
					first_menu_choice = COMPUTER_VS_COMPUTER;
					break;
				}
				else if (coord .Y >= 12 && coord.Y <= 17){
					first_menu_choice = END_GAME;
					break;
				}				
			}			
		}
	}
	if (first_menu_choice == END_GAME) {
		return;
	}
	
	if (first_menu_choice == PLAYER_VS_COMPUTER) {
		//SECOND PART OF MENU

		y_fixed = Y_OUTPUT;
		show_frame(X_OUTPUT, Y_OUTPUT, y_fixed, 3);
		show_letters_for_second(X_OUTPUT, Y_OUTPUT, y_fixed);		

		SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), ENABLE_EXTENDED_FLAGS | (prev_mode & ~ENABLE_QUICK_EDIT_MODE));
		SetConsoleMode(hin, ENABLE_MOUSE_INPUT); // allow mouse handling 
		while (true)
		{
			ReadConsoleInput(hin, &InputRecord, 1, &Events); //reading
			if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)   //left batton
			{
				coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
				coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;

				if (coord.X >= X_OUTPUT + 1 && coord.X <= X_OUTPUT + 60  && coord.Y >= coord.Y && coord.Y <= coord.Y + 12) {
					if (coord.Y >= 5 && coord.Y <= 8) {
						second_menu_choice = RANDOM_PLACEMENT;
						break;
					}
					else if (coord.Y >= 9 && coord.Y <= 12) {
						second_menu_choice = DEFOLT_PLACEMENT;
						break;
					}
					else if (coord.Y >= 12 && coord.Y <= 17) {
						second_menu_choice = END_GAME;
						break;
					}
				}
			}
		}
	}
	if (second_menu_choice == END_GAME)
		return;

	y_fixed = Y_OUTPUT;
	show_frame(X_OUTPUT, Y_OUTPUT, y_fixed, 3);
	show_letters_for_third(X_OUTPUT, Y_OUTPUT, y_fixed);	

	SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), ENABLE_EXTENDED_FLAGS | (prev_mode & ~ENABLE_QUICK_EDIT_MODE));
	SetConsoleMode(hin, ENABLE_MOUSE_INPUT); // allow mouse handling 
	while (true)
	{
		ReadConsoleInput(hin, &InputRecord, 1, &Events); //reading
		if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)   //left batton
		{
			coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
			coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;

			if (coord.X >= X_OUTPUT + 1 && coord.X <= X_OUTPUT + 60 && coord.Y >= coord.Y && coord.Y <= coord.Y + 12) {
				if (coord.Y >= 5 && coord.Y <= 8) {
					third_menu_choice = WITHOUT_ALGORITM;
					break;
				}
				else if (coord.Y >= 9 && coord.Y <= 12) {
					third_menu_choice = USE_ALGORITM;
					break;
				}
				else if (coord.Y >= 12 && coord.Y <= 17) {
					third_menu_choice = END_GAME;
					break;
				}
			}
		}
	}
}