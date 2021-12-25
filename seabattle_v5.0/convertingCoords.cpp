#include "convertingCoords.h"
#include "menu.h"
#include "enums.h"
#include <Windows.h>

// converts the coordinates entered by the mouse into coordinates for the array
void converting_coords_right_part(int& xShotPlayer, int& yShotPlayer, int& startingPoint, int& middle_menu_choice) {	
	HANDLE hin = GetStdHandle(STD_INPUT_HANDLE); //get the descriptor
	INPUT_RECORD InputRecord; //used to return information about input messages in the console input buffer 
	DWORD Events; // unsigned long
	COORD coord{0}; // for coords X, Y

	//deny console highlighting
	DWORD prev_mode;
	GetConsoleMode(hin, &prev_mode);
	SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), ENABLE_EXTENDED_FLAGS | (prev_mode & ~ENABLE_QUICK_EDIT_MODE));
	SetConsoleMode(hin, ENABLE_MOUSE_INPUT); // allow mouse handling 

	while (true)
	{
		ReadConsoleInput(hin, &InputRecord, 1, &Events); //reading
		if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)   //left batton
		{
			coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
			coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
			//cout << coord.X << "    " << coord.Y;				
			if (coord.Y == MENU_TITLE_COORDY && coord.X >= MENU_TITLE_FST_COORDX && coord.X <= MENU_TITLE_SCD_COORDX) {
				middle_menu_control(middle_menu_choice);
				if (middle_menu_choice == END_GAME_MIDDLE_MENU) {
					return;
				}
				break;
			}
			if (coord.X > FIELD_FIRST_XCOORD_PLAYER2 && coord.X < FIELD_SCD_XCOORD_PLAYER2) {
				xShotPlayer = -1;
				for (int i = FIELD_FIRST_XCOORD_PLAYER2; i < coord.X; i += STEP_BY_COORDX, xShotPlayer++);
			}
			if (coord.Y > FIELD_FIRST_YCOORD_PLAYER2 && coord.Y < FIELD_SCD_XCOORD_PLAYER2) {
				yShotPlayer = -1;
				for (int i = FIELD_FIRST_YCOORD_PLAYER2; i < coord.Y; i += STEP_BY_COORDY, yShotPlayer++);
			}
			if (coord.X > FIELD_FIRST_XCOORD_PLAYER2 && coord.X < FIELD_SCD_XCOORD_PLAYER2 && coord.Y > FIELD_FIRST_YCOORD_PLAYER2 && coord.Y < FIELD_SCD_YCOORD_PLAYER2)
				break;
		}
	}
}

void converting_coords_left_part(int& xShotPlayer, int& yShotPlayer, int& startingPoint, int& middle_menu_choice) {

	HANDLE hin = GetStdHandle(STD_INPUT_HANDLE); //get the descriptor
	INPUT_RECORD InputRecord; //used to return information about input messages in the console input buffer 
	DWORD Events; // unsigned long
	COORD coord{0}; // for coords X, Y

	//deny console highlighting
	DWORD prev_mode;
	GetConsoleMode(hin, &prev_mode);
	SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), ENABLE_EXTENDED_FLAGS | (prev_mode & ~ENABLE_QUICK_EDIT_MODE));
	SetConsoleMode(hin, ENABLE_MOUSE_INPUT); // allow mouse handling 

	while (true)
	{
		ReadConsoleInput(hin, &InputRecord, 1, &Events); //reading
		if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)   //left batton
		{
			coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
			coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
			//cout << coord.X << "    " << coord.Y;				
			if (coord.Y == MENU_TITLE_COORDY && coord.X >= MENU_TITLE_FST_COORDX && coord.X <= MENU_TITLE_SCD_COORDX) {
				middle_menu_control(middle_menu_choice);
				if (middle_menu_choice == END_GAME_MIDDLE_MENU) {
					return;
				}
				break;
			}
			if (coord.X > FIELD_FIRST_XCOORD_PLAYER1 && coord.X < FIELD_SCD_XCOORD_PLAYER1) {
				xShotPlayer = -1;
				for (int i = FIELD_FIRST_XCOORD_PLAYER1; i < coord.X; i += STEP_BY_COORDX, xShotPlayer++);
			}
			if (coord.Y > FIELD_FIRST_YCOORD_PLAYER1 && coord.Y < FIELD_SCD_YCOORD_PLAYER1) {
				yShotPlayer = -1;
				for (int i = FIELD_FIRST_YCOORD_PLAYER1; i < coord.Y; i += STEP_BY_COORDY, yShotPlayer++);
			}
			if (coord.X > FIELD_FIRST_XCOORD_PLAYER1 && coord.X < FIELD_SCD_XCOORD_PLAYER1 && coord.Y > FIELD_FIRST_YCOORD_PLAYER1 && coord.Y < FIELD_SCD_YCOORD_PLAYER1)
				break;
		}
	}
}

	
