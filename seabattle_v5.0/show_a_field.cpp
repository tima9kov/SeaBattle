#include "show_a_field.h"
#include <Windows.h>
#include <iostream>
#include "enums.h"
using namespace std;

void show_horizontal_line() {
	cout << char(HORIZONTAL) << char(HORIZONTAL) << char(HORIZONTAL);
}

void field_creation(int first_x, int first_y)
{
	COORD position = { first_x, first_y }; 
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, position);
	cout << char(UPPER_LEFT_CORNER); show_horizontal_line();
	for (int i = 0; i < AMOUNT_OF_CELLS - 1; ++i) {
		cout << char(UPPER_CONNECTOR); show_horizontal_line();
	}
	cout << char(UPPER_RIGHT_CORNER);
	position.Y++;
	SetConsoleCursorPosition(hConsole, position);
	cout << char(VERTICAL);
	for (int j = 0; j < AMOUNT_OF_CELLS - 1; ++j) {
		for (int k = 0; k < AMOUNT_OF_CELLS; ++k) {
			cout << "   " << char(VERTICAL);
		}
		position.Y++;
		SetConsoleCursorPosition(hConsole, position);
		cout << char(LEFT_CONNECTOR);
		for (int k = 0; k < AMOUNT_OF_CELLS - 1; ++k) {
			show_horizontal_line(); cout << char(CROSS);
		}
		show_horizontal_line(); cout  << char(RIGHT_CONNECTOR);

		position.Y++;
		SetConsoleCursorPosition(hConsole, position);
		cout << char(VERTICAL);

	}
	for (int f = 0; f < AMOUNT_OF_CELLS; ++f) {
		cout << "   " << char(VERTICAL);
	}
	position.Y++;
	SetConsoleCursorPosition(hConsole, position);
	cout << char(DOWNER_LEFT_CORNER);
	for (int h = 0; h < AMOUNT_OF_CELLS - 1; ++h) {
		show_horizontal_line(); cout << char(DOWNER_CONNECTOR);
	}
	show_horizontal_line(); cout << char(DOWNER_RIGHT_CORNER);

}	
void field_output(string green, string white, string red) {
	string gold = "\x1b[33m", blue = "\x1b[34m";
	COORD position = { INSCRIPTION_YOUR_BOARD_COORDX, INSCRIPTION_YOUR_BOARD_COORDY };
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, position);
	cout << green << "YOUR BOARD" << gold;
	
	position.X = CELL_NUMBERS_COORDX_FSTPLR;
	position.Y = CELL_NUMBERS_COORDY_FSTPLR;
	SetConsoleCursorPosition(hConsole, position);
	for (int i = 0; i < AMOUNT_OF_CELLS; ++i) {
		cout << i;
	position.Y += STEP_BY_COORDY;
	SetConsoleCursorPosition(hConsole, position);
	}
	
	position.X = ALPHABED_XCOORD_FST;
	position.Y = ALPHABED_YCOORD_FST;
	SetConsoleCursorPosition(hConsole, position);
	for (int i = 0; i < AMOUNT_OF_CELLS; ++i) {
		cout << char(LITERAL_A + i) << "   ";
	}
	cout << blue;
	
	position.X = INSCRIPTION_ENEMY_BOARD_COORDX;
	position.Y = INSCRIPTION_ENEMY_BOARD_COORDY;
	SetConsoleCursorPosition(hConsole, position);
	cout << red << "ENEMY BOARD" << gold;
	
	position.X = CELL_NUMBERS_COORDX_SCDPLR;
	position.Y = CELL_NUMBERS_COORDY_SCDPLR;
	SetConsoleCursorPosition(hConsole, position);
	for (int i = 0; i < AMOUNT_OF_CELLS; ++i) {
		cout << i;;
		position.Y += STEP_BY_COORDY;
		SetConsoleCursorPosition(hConsole, position);
	}
	
	position.X = ALPHABED_XCOORD_SCND;
	position.Y = ALPHABED_YCOORD_SCND;
	SetConsoleCursorPosition(hConsole, position);
	for (int i = 0; i < AMOUNT_OF_CELLS; ++i) {
		cout << char(LITERAL_A + i) << "   ";
	}
	cout << blue;
	
	position.X = MENU_TITLE_FST_COORDX; position.Y = MENU_TITLE_COORDY;
	SetConsoleCursorPosition(hConsole, position);
	cout << "M E N U";

	field_creation(FIELD_FIRST_XCOORD_PLAYER1, FIELD_FIRST_YCOORD_PLAYER1);
	field_creation(FIELD_FIRST_XCOORD_PLAYER2, FIELD_FIRST_YCOORD_PLAYER2);
	cout << white;
}