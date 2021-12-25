#include "drawsAShip.h"
#include "enums.h"
#include <string>
#include <Windows.h>
#include <iostream>

using namespace std;

void ship_for_choice(int outputX, int outputY, int decks) {
	COORD position = { outputX , outputY + 1 };
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, position);
	for (int i = 0; i < decks; ++i) {
		cout << char(UPPER_LEFT_CORNER);
		cout << char(HORIZONTAL) << char(HORIZONTAL) << char(UPPER_RIGHT_CORNER);
	}
	position.Y += 1;
	SetConsoleCursorPosition(hConsole, position);
	for (int i = 0; i < decks; ++i) {
		cout << char(DOWNER_LEFT_CORNER);
		cout << char(HORIZONTAL) << char(HORIZONTAL) << char(DOWNER_RIGHT_CORNER);
	}
}

void ships_output(string** array, int x, int y) {
	COORD position = { x, y };
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, position);

	for (int q = 0; q < AMOUNT_OF_CELLS; ++q) {
		for (int r = 0; r < AMOUNT_OF_CELLS; ++r) {
			position.X += STEP_BY_COORDX;
			SetConsoleCursorPosition(hConsole, position);
			cout << array[q][r];
		}
		position.X = x;
		position.Y += STEP_BY_COORDY;
		SetConsoleCursorPosition(hConsole, position);
	}
}

void drawsaboatdown(string** array, int xPlayer, int yPlayer, int playerDecks)
{
	array[yPlayer][xPlayer] = char(NOT_BROKEN);

	for (int i = 1; i < playerDecks; ++i) {
		yPlayer += 1;
		array[yPlayer][xPlayer] = char(NOT_BROKEN);
	}
}

void drawsaboatleft(string** array, int xPlayer, int yPlayer, int playerDecks)
{
	array[yPlayer][xPlayer] = char(NOT_BROKEN);

	for (int i = 1; i < playerDecks; ++i) {
		xPlayer -= 1;
		array[yPlayer][xPlayer] = char(NOT_BROKEN);
	}
}

void drawsaboatright(string** array, int xPlayer, int yPlayer, int playerDecks)
{
	array[yPlayer][xPlayer] = char(NOT_BROKEN);

	for (int i = 1; i < playerDecks; ++i) {
		xPlayer += 1;
		array[yPlayer][xPlayer] = char(NOT_BROKEN);
	}
}

void drawsaboatup(string** array, int xPlayer, int yPlayer, int playerDecks)
{
	array[yPlayer][xPlayer] = char(NOT_BROKEN);

	for (int i = 1; i < playerDecks; ++i) {
		yPlayer -= 1;
		array[yPlayer][xPlayer] = char(NOT_BROKEN);
	}
}