#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>

#include "placement.h"
#include "splashScreen.h"
#include "menu.h"
#include "show_a_field.h"
#include "convertingCoords.h"
#include "addArray.h"
#include "initializeArray.h"
#include "checkDirection.h"
#include "drawsAShip.h"
#include "shooting.h"
#include "enums.h"

using namespace std;

int main()
{
	srand(time(nullptr));
	//an array storing first and second player's values
	string **firstPlayerShips, **secondPlayerShips;
	string** firstPlayerShipsOutput, ** secondPlayerShipsOutput;
	//variables created to edit the output (colors)
	string red = "\x1b[31m", white = "\x1b[0m", green = "\x1b[32m", gold = "\x1b[33m";

	//to check shots 
	string forCheck;
	forCheck = char(NOT_BROKEN);

	int condition{ 0 };
	int xFixed{0}, yFixed{0};	
	int conditionPl{ 0 }, xFixedPl{ 0 }, yFixedPl{ 0 };
	int obviously_upward_direction{ 1 }, obviously_downward_direction{ 1 }, obviously_direction_to_the_left{ 1 }, obviously_direction_to_the_right{ 1 };
	//we declare the arrays of the player and the computer, respectively 
	firstPlayerShips  = add_array();
	secondPlayerShips = add_array();
	firstPlayerShipsOutput = add_array();
	secondPlayerShipsOutput = add_array();

	//initialize the player and computer arrays, respectively 
	initialize_array(firstPlayerShips);
	initialize_array(secondPlayerShips);
	initialize_array(firstPlayerShipsOutput);
	initialize_array(secondPlayerShipsOutput);

	int count = 0;

	//for menu controll
	int first_menu_choice { 0 };
	int second_menu_choice{ 0 };
	int third_menu_choice { 0 };
	int middle_menu_choice{ 0 };

	int countForAlgmFirstPlr{ 0 }, countForAlgmSecondPlr{ 0 };
	
	splash_screen();	

	menu_control(first_menu_choice, second_menu_choice, third_menu_choice);
	
	//if user wanted to end game
	if (first_menu_choice == END_GAME || second_menu_choice == END_GAME || third_menu_choice == END_GAME) {
		say_goodbuy();
		return 0;
	}

	//if (first_menu_choice != END_GAME) {
		if (second_menu_choice == DEFOLT_PLACEMENT) {			
		user_placement(firstPlayerShips, forCheck ,middle_menu_choice);
		if (middle_menu_choice == END_GAME_MIDDLE_MENU) {
			say_goodbuy();
			return 0;
		}

		}
		else {
			 random_placement(firstPlayerShips, forCheck);
		}

			//withdrawal of the last ship
			system("CLS");

			//field output 
			field_output(green, white, red);

			//player ships output
			ships_output(firstPlayerShips, SHIPS_FIRST_X_PLAYER1, SHIPS_FIRST_Y_PLAYER1);

			//computer ships output 
			ships_output(secondPlayerShipsOutput, SHIPS_FIRST_X_PLAYER2, SHIPS_FIRST_Y_PLAYER2);

			//FOR COMPUTER
			random_placement(secondPlayerShips, forCheck);
			
			//control will be performed by the mouse
			
			HANDLE hin = GetStdHandle(STD_INPUT_HANDLE); //get the descriptor
			INPUT_RECORD InputRecord{ 0 }; //used to return information about input messages in the console input buffer 
			DWORD Events{ 0 }; // unsigned long
			COORD coord{ 0 }; // for coords X, Y

			//deny console highlighting
			DWORD prev_mode;
			GetConsoleMode(hin, &prev_mode);
			SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), ENABLE_EXTENDED_FLAGS | (prev_mode & ~ENABLE_QUICK_EDIT_MODE));

			SetConsoleMode(hin, ENABLE_MOUSE_INPUT); // allow mouse handling 			
		
			//3d PART
			//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			//SHOOTING
			
			//coordinates of shots 
			int xShot{ 0 }, yShot{ 0 };

			//the number of shots fired by first and second players
			int amountOfFirstPlayerShots{0} , amountOfSecondPlayerShots{0};

			//the number of cells broken by first and second players
			int amountOfBrokenFirstPlayer{0} , amountOfBrokenSecondPlayer{0};

			//fixed values for x and y 
			int xShotFixed{0}, yShotFixed{0};

			//broken cage 
			string broken;
			broken = char(BROKEN);

			//miss 
			string MISS;
			MISS = char(MISSED);

			//for checking the ability to shoot (for a computer) 
			int shootUp(0), shootDown(0), shootLeft(0), shootRight(0);

			for (;;) {
			//player shooting
				if (first_menu_choice != COMPUTER_VS_COMPUTER) {
					user_shooting(firstPlayerShips, secondPlayerShips, secondPlayerShipsOutput, forCheck, amountOfBrokenFirstPlayer, amountOfFirstPlayerShots, middle_menu_choice);
					if (middle_menu_choice == END_GAME_MIDDLE_MENU) {
						say_goodbuy();
						return 0;
					}
				}
				else {		
					if (third_menu_choice == WITHOUT_ALGORITM)
					random_shooting(yShot, xShot, firstPlayerShips, secondPlayerShips, forCheck, amountOfBrokenFirstPlayer, amountOfFirstPlayerShots);
					if (third_menu_choice == USE_ALGORITM)

						//shooting_algoritm(secondPlayerShips, secondPlayerShipsOutput, xShot, yShot, forCheck, amountOfBrokenFirstPlayer, amountOfFirstPlayerShots, countForAlgm);
						
					shooting_algoritm(secondPlayerShips, secondPlayerShipsOutput, xShot, yShot, forCheck, amountOfBrokenFirstPlayer, amountOfFirstPlayerShots, countForAlgmFirstPlr, conditionPl, xFixedPl, yFixedPl, obviously_upward_direction, obviously_downward_direction, obviously_direction_to_the_left, obviously_direction_to_the_right);
					
					//system("pause");
				}
				if (amountOfBrokenFirstPlayer == MAX_AMOUNT_OF_BROKEN || amountOfFirstPlayerShots == MAX_AMOUNT_OF_SHOTS) break;
				
				//kompuchter shooting
				if (third_menu_choice == WITHOUT_ALGORITM)
				random_shooting(yShot, xShot, secondPlayerShips, firstPlayerShips, forCheck, amountOfBrokenSecondPlayer, amountOfSecondPlayerShots);							
				if (third_menu_choice == USE_ALGORITM)
			
				//shooting_algoritm(firstPlayerShips, firstPlayerShipsOutput, xShot, yShot, forCheck, amountOfBrokenSecondPlayer, amountOfSecondPlayerShots, countForAlgm);
				
				shooting_algoritm(firstPlayerShips, firstPlayerShipsOutput, xShot, yShot, forCheck, amountOfBrokenSecondPlayer, amountOfSecondPlayerShots, countForAlgmSecondPlr, condition, xFixed, yFixed, obviously_upward_direction, obviously_downward_direction, obviously_direction_to_the_left, obviously_direction_to_the_right);

				
			   // system("pause");
				if (amountOfBrokenSecondPlayer == MAX_AMOUNT_OF_BROKEN || amountOfSecondPlayerShots == MAX_AMOUNT_OF_SHOTS) break;

				//output
				system("cls");
				field_output(green, white, red);
				ships_output(firstPlayerShips , SHIPS_FIRST_X_PLAYER1, SHIPS_FIRST_Y_PLAYER1);
				ships_output(secondPlayerShipsOutput, SHIPS_FIRST_X_PLAYER2, SHIPS_FIRST_Y_PLAYER2);
			}
			system("cls");
			
			field_output(green, white, red);
			ships_output(firstPlayerShips, SHIPS_FIRST_X_PLAYER1, SHIPS_FIRST_Y_PLAYER1);
			ships_output(secondPlayerShipsOutput, SHIPS_FIRST_X_PLAYER2, SHIPS_FIRST_Y_PLAYER2);

			system("PAUSE");
			system("cls");

			COORD position = { GAME_RESULT_XCOORD , GAME_RESULT_YCOORD }; 
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleCursorPosition(hConsole, position);
			
			if (amountOfBrokenSecondPlayer == MAX_AMOUNT_OF_BROKEN) {

				cout << red << "YOU LOSE" << white << endl;
			}
			else {
				cout << gold << "YOU WIN" << white << endl;
			}
			position.Y += 10;
			SetConsoleCursorPosition(hConsole, position);
			system("pause");

			delete[] firstPlayerShips;
			delete[] secondPlayerShips;

	return 0;
}