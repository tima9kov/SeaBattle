#include "placement.h"
#include "checkDirection.h"
#include "drawsAShip.h"
#include "show_a_field.h"
#include <Windows.h>
#include <iostream>
#include <string>
#include <iomanip>
#include "menu.h"
#include "convertingCoords.h"
#include "enums.h"
using namespace std;

void random_placement(string **array , string forCheck) {
	int amount{ 0 } , cells{ 0 };
	do {
		
		int xCoordinate{ 0 }, yCoordinate{ 0 }, decks{ 0 };
		int checkUp{0}, checkDown{0}, checkLeft{0}, checkRight{0};
		int direction{ 0 };
		//amount of decks for a computer 
		if (amount == 0) {
			decks = 4;
			cells += 4;
			amount += 1;
		}
		else {
			if (amount == 1 || amount == 2) {
				decks = 3;
				cells += 3;
				amount += 1;
			}
			else {
				if (amount == 3 || amount == 4 || amount == 5) {
					decks = 2;
					cells += 2;
					amount += 1;
				}
				else
					if (amount >= 6) {
						decks = 1;
						cells += 1;
						amount += 1;
					}
			}
		}

		//coordinates for the computer ship 
		do {
			xCoordinate = rand() % AMOUNT_OF_CELLS;
			yCoordinate = rand() % AMOUNT_OF_CELLS;
			checkUp = check_direction_up(array, checkUp, xCoordinate, yCoordinate, decks, forCheck);
			checkDown = check_direction_down(array, checkDown, xCoordinate, yCoordinate, decks, forCheck);
			checkLeft = check_direction_left(array, checkLeft, xCoordinate, yCoordinate, decks, forCheck);
			checkRight = check_direction_right(array, checkRight, xCoordinate, yCoordinate, decks, forCheck);
		} while (checkUp == 1 && checkDown == 1 && checkLeft == 1 && checkRight== 1);


		direction = forCheckingSides(checkUp, checkDown, checkLeft, checkRight, direction);
		//fills the ship into an array 
		if (direction == 1) {
			drawsaboatup (array, xCoordinate, yCoordinate, decks);
		}
		if (direction == 2) {
			drawsaboatdown(array, xCoordinate, yCoordinate, decks);
		}
		if (direction == 3) {
			drawsaboatleft(array, xCoordinate, yCoordinate,decks);
		}
		if (direction == 4) {
			drawsaboatright(array, xCoordinate, yCoordinate, decks);
		}

	} while (cells < 20);	
}

void user_placement(string** array, string forCheck, int &middle_menu_choice) {
	//state variables 
	int checkUp{ 0 }, checkDown{ 0 }, checkLeft{ 0 }, checkRight{ 0 };

	//coordinates entered by the player 
	int xPlayer{ 0 }, yPlayer{ 0 };

	//direction
	string direction;

	//variables created to edit the output (colors)
	string red = "\x1b[31m", white = "\x1b[0m", green = "\x1b[32m", gold = "\x1b[33m";

	//the counter of filled cells of the player 
	int countOfPlayerCells{ 0 };

	//counter of 4-deck, 3-deck, 2-deck and 1-deck ships, respectively 
	int fourDecksShipsPlayer{ 0 }, threeDecksShipsPlayer{ 0 }, twoDecksShipsPlayer{ 0 }, oneDeckShipsPlayer{ 0 };

	//number of player ship decks 
	int playerDecks;

	int startingPoint{ 0 };

	do {
		//clears the screen
		system("CLS");

		//field output
		field_output(green, white, red);

		//player ships output
		ships_output(array, SHIPS_FIRST_X_PLAYER1, SHIPS_FIRST_Y_PLAYER1);

		//computer ships output
		//ships_output(computerShips, 53, 4);


		//coordinates for formatted output		

		

		//output formatting 

		COORD position = { SHIPS_EXAMPLES_COORDX , SHIPS_EXAMPLES_COORDY }; //coords x and y
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hConsole, position);
		
		//communication with the user
		cout << green << "What kind of ship ? \n" << white << endl;

		int outputX = SHIPS_EXAMPLES_COORDX, outputY = SHIPS_EXAMPLES_COORDY;
		//output of ship samples
		position.Y += 1;
		SetConsoleCursorPosition(hConsole, position);
		 
		//4-deck
		ship_for_choice(outputX, outputY, FOUR_DECK_FOR_CHOICE);
		cout << " " << 1 - fourDecksShipsPlayer;
		//y-shift by 4
		outputY += STEP_BETWEEN_EXSHIPS_COORDY;

		//3-deck
		ship_for_choice(outputX, outputY, THREE_DECK_FOR_CHOICE);
		cout << " " << 2 - threeDecksShipsPlayer;

		//y-shift by 4
		outputY += STEP_BETWEEN_EXSHIPS_COORDY;

		//2-deck
		ship_for_choice(outputX, outputY, TWO_DECK_FOR_CHOICE);
		cout << " " << 3 - twoDecksShipsPlayer;

		//y-shift by 4
		outputY += STEP_BETWEEN_EXSHIPS_COORDY;
		//1-deck
		ship_for_choice(outputX, outputY, ONE_DECK_FOR_CHOICE);
		cout << " " << 4 - oneDeckShipsPlayer;

		//switch to mouse control
		HANDLE hin = GetStdHandle(STD_INPUT_HANDLE); //get the descriptor
		INPUT_RECORD InputRecord; //used to return information about input messages in the console input buffer
		DWORD Events; // unsigned long
		COORD coord; //for coords x and y

		//Prevent console highlighting
		DWORD prev_mode;
		GetConsoleMode(hin, &prev_mode);
		SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), ENABLE_EXTENDED_FLAGS | (prev_mode & ~ENABLE_QUICK_EDIT_MODE));

		SetConsoleMode(hin, ENABLE_MOUSE_INPUT); //allow mouse handling

		while (true)
		{
			ReadConsoleInput(hin, &InputRecord, 1, &Events); //reading


			if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)   //left buttom
			{
				coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
				coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
				//cout << "left - X" << coord.X << ", Y = " << coord.Y << endl;
				if (coord.Y == 35 && coord.X >= 7 && coord.X <= 13) {
					middle_menu_control(middle_menu_choice);
					if (middle_menu_choice == 2) {
						return;
					}
					break;
				}
				if (coord.X > FOUR_DECK_EXAMPLE_FSTCOORDX && coord.X < FOUR_DECK_EXAMPLE_SCDCOORDX && coord.Y > FOUR_DECK_EXAMPLE_FSTCOORDY && coord.Y < FOUR_DECK_EXAMPLE_SCDCOORDY) {

					playerDecks = 4;
					if (fourDecksShipsPlayer >= 1) {
						cout << "\a";
					}
					else {
						++fourDecksShipsPlayer;
						countOfPlayerCells += 4;
						position.X = 2;
						position.Y = 26;
						SetConsoleCursorPosition(hConsole, position);

						//communication with user
						cout << "You choosed four deck ship"; break;
					}
				}
				if (coord.X > THREE_DECK_EXAMPLE_FSTCOORDX && coord.X < THREE_DECK_EXAMPLE_SCDCOORDX && coord.Y > THREE_DECK_EXAMPLE_FSTCOORDY && coord.Y < THREE_DECK_EXAMPLE_SCDCOORDY) {
					playerDecks = 3;
					if (threeDecksShipsPlayer >= 2) {
						cout << "\a";
					}
					else {
						++threeDecksShipsPlayer;
						countOfPlayerCells += 3;
						position.X = 2;
						position.Y = 26;
						SetConsoleCursorPosition(hConsole, position);

						//communication with user
						cout << "You choosed three deck ship"; break;
					}
				}
				if (coord.X > TWO_DECK_EXAMPLE_FSTCOORDX && coord.X < TWO_DECK_EXAMPLE_SCDCOORDX && coord.Y > TWO_DECK_EXAMPLE_FSTCOORDY && coord.Y < TWO_DECK_EXAMPLE_SCDCOORDY) {
					playerDecks = 2;
					if (twoDecksShipsPlayer >= 3) {
						cout << "\a";
					}
					else {
						++twoDecksShipsPlayer;
						countOfPlayerCells += 2;
						position.X = 2;
						position.Y = 26;
						SetConsoleCursorPosition(hConsole, position);

						//communication with user
						cout << "You choosed two deck ship"; break;
					}
				}
				if (coord.X > ONE_DECK_EXAMPLE_FSTCOORDX && coord.X < ONE_DECK_EXAMPLE_SCDCOORDX && coord.Y > ONE_DECK_EXAMPLE_FSTCOORDY && coord.Y < ONE_DECK_EXAMPLE_SCDCOORDY) {
					playerDecks = 1;
					if (oneDeckShipsPlayer >= 4) {
						cout << "\a";
					}
					else {
						++oneDeckShipsPlayer;
						countOfPlayerCells += 1;
						position.X = 2;
						position.Y = 26;
						SetConsoleCursorPosition(hConsole, position);

						//communication with user
						cout << "You choosed one deck ship"; break;
					}
				}
			}
		}

		//prompting the user to enter the coordinates of the ships
		do {		
			//no_cursor();
			//move cursor
			position.X = 2;
			position.Y = 27;
			SetConsoleCursorPosition(hConsole, position);

			//communication with user
			cout << green << "Where do u want to place a ship ?" << white;
			
			converting_coords_left_part(xPlayer,yPlayer,startingPoint,middle_menu_choice);
	
			checkUp = check_direction_up(array, checkUp, xPlayer, yPlayer, playerDecks, forCheck);
			checkDown = check_direction_down(array, checkDown, xPlayer, yPlayer, playerDecks, forCheck);
			checkLeft = check_direction_left(array, checkLeft, xPlayer, yPlayer, playerDecks, forCheck);
			checkRight = check_direction_right(array, checkRight, xPlayer, yPlayer, playerDecks, forCheck);
		} while (checkUp == 1 && checkDown == 1 && checkLeft == 1 && checkRight == 1);

		//move cursor again
		position.X = 2;
		position.Y = 29;
		int xForOutput = position.X;
		int yForOutput = position.Y + 1;
		SetConsoleCursorPosition(hConsole, position);

		//begins entering the direction of the ships by the player

		//communicating with user
		cout << red << "where do u want to turn your ship ?" << white;
		position.Y += 1;
		SetConsoleCursorPosition(hConsole, position);

		checkUp = check_direction_up(array, checkUp, xPlayer, yPlayer, playerDecks, forCheck);
		checkDown = check_direction_down(array, checkDown, xPlayer, yPlayer, playerDecks, forCheck);
		checkLeft = check_direction_left(array, checkLeft, xPlayer, yPlayer, playerDecks, forCheck);
		checkRight = check_direction_right(array, checkRight, xPlayer, yPlayer, playerDecks, forCheck);
		
		
		if (checkUp == NO && checkDown == NO && checkLeft == NO && checkRight == YES) {
			cout << setw(28) << "right" << endl;//RIGHT
			for (;;)
			{
				ReadConsoleInput(hin, &InputRecord, 1, &Events); //reading
				if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) //left button
				{
					coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
					coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;				
					if (coord.X > INSCRIPTION_RIGHT_FSTXCOORD && coord.X < INSCRIPTION_RIGHT_SCDXCOORD && coord.Y == INSCRIPTION_COORDY) {
						direction = "R"; break;
					}
				}
			}
		}//1.
		if (checkUp == NO && checkDown == NO && checkLeft == YES && checkRight == NO) {
			cout << setw(21) << "left" << endl;//LEFT
			for (;;)
			{
				ReadConsoleInput(hin, &InputRecord, 1, &Events); //reading
				if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) //left button
				{
					coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
					coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
					if (coord.X > INSCRIPTION_LEFT_FSTXCOORD && coord.X < INSCRIPTION_LEFT_SCDXCOORD && coord.Y == INSCRIPTION_COORDY) {
						direction = "L"; break;
					}
				}
			}
		}//2.
		if (checkUp == NO && checkDown == NO && checkLeft == YES && checkRight == YES) {
			cout << setw(21) << "left" << setw(7) << "right" << endl; //L R
			for (;;)
			{
				ReadConsoleInput(hin, &InputRecord, 1, &Events); //reading
				if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) //left button
				{
					coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
					coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
					if (coord.X > INSCRIPTION_LEFT_FSTXCOORD && coord.X < INSCRIPTION_LEFT_SCDXCOORD && coord.Y == INSCRIPTION_COORDY) {
						direction = "L"; break;
					}
					if (coord.X > INSCRIPTION_RIGHT_FSTXCOORD && coord.X < INSCRIPTION_RIGHT_SCDXCOORD && coord.Y == INSCRIPTION_COORDY) {
						direction = "R"; break;
					}
				}
			}
		}//3.
		if (checkUp == NO && checkDown == YES && checkLeft == 1 && checkRight == NO) {
			cout << setw(14) << "down" << endl;//D
			for (;;)
			{
				ReadConsoleInput(hin, &InputRecord, 1, &Events); //reading
				if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) //left button
				{
					coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
					coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
					if (coord.X > INSCRIPTION_DOWN_FSTXCOORD && coord.X < INSCRIPTION_DOWN_SCDXCOORD && coord.Y == INSCRIPTION_COORDY) {
						direction = "D"; break;
					}
				}
			}
		}//4.
		if (checkUp == NO && checkDown == YES && checkLeft == NO && checkRight == YES) {
			cout << setw(14) << "down" << setw(14) << "right" << endl;// R D
			for (;;)
			{
				ReadConsoleInput(hin, &InputRecord, 1, &Events); //reading
				if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) //left button
				{
					coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
					coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
					if (coord.X > INSCRIPTION_DOWN_FSTXCOORD && coord.X < INSCRIPTION_DOWN_SCDXCOORD && coord.Y == INSCRIPTION_COORDY) {
						direction = "D"; break;
					}
					if (coord.X > INSCRIPTION_RIGHT_FSTXCOORD && coord.X < INSCRIPTION_RIGHT_SCDXCOORD && coord.Y == INSCRIPTION_COORDY) {
						direction = "R"; break;
					}
				}
			}
		}//5.
		if (checkUp == NO && checkDown == YES && checkLeft == YES && checkRight == NO) {
			cout << setw(14) << "down" << setw(7) << "left" << endl;// L D
			for (;;)
			{
				ReadConsoleInput(hin, &InputRecord, 1, &Events); // reading
				if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) // left button
				{
					coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
					coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
					if (coord.X > INSCRIPTION_DOWN_FSTXCOORD && coord.X < INSCRIPTION_DOWN_SCDXCOORD && coord.Y == INSCRIPTION_COORDY) {
						direction = "D"; break;
					}
					if (coord.X > INSCRIPTION_LEFT_FSTXCOORD && coord.X < INSCRIPTION_LEFT_SCDXCOORD && coord.Y == INSCRIPTION_COORDY) {
						direction = "L"; break;
					}
				}
			}
		}//6.
		if (checkUp == NO && checkDown == YES && checkLeft == YES && checkRight == YES) {
			cout << setw(14) << "down" << setw(7) << "left" << setw(7) << "right" << endl;// D L R
			for (;;)
			{
				ReadConsoleInput(hin, &InputRecord, 1, &Events); //reading
				if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) //left button
				{
					coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
					coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
					if (coord.X > INSCRIPTION_DOWN_FSTXCOORD && coord.X < INSCRIPTION_DOWN_SCDXCOORD && coord.Y == INSCRIPTION_COORDY) {
						direction = "D"; break;
					}
					if (coord.X > INSCRIPTION_LEFT_FSTXCOORD && coord.X < INSCRIPTION_LEFT_SCDXCOORD && coord.Y == INSCRIPTION_COORDY) {
						direction = "L"; break;
					}
					if (coord.X > INSCRIPTION_RIGHT_FSTXCOORD && coord.X < INSCRIPTION_RIGHT_SCDXCOORD && coord.Y == INSCRIPTION_COORDY) {
						direction = "R"; break;
					}
				}
			}
		}//7.
		if (checkUp == YES && checkDown == NO && checkLeft == NO && checkRight == NO) {
			cout << setw(7) << "up" << endl;//U
			for (;;)
			{
				ReadConsoleInput(hin, &InputRecord, 1, &Events); //reading
				if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) //left button
				{
					coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
					coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
					if (coord.X == INSCRIPTION_UP_FSTXCOORD || coord.X == INSCRIPTION_UP_SCDXCOORD && coord.Y == INSCRIPTION_COORDY) {
						direction = "U"; break;
					}
				}
			}
		}//8.
		if (checkUp == YES && checkDown == NO && checkLeft == NO && checkRight == YES) {
			cout << setw(7) << "up" << setw(21) << "right" << endl;// U R
			for (;;)
			{
				ReadConsoleInput(hin, &InputRecord, 1, &Events); //reading
				if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) //left button
				{
					coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
					coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
					if (coord.X == INSCRIPTION_UP_FSTXCOORD || coord.X == INSCRIPTION_UP_SCDXCOORD && coord.Y == INSCRIPTION_COORDY) {
						direction = "U"; break;
					}
					if (coord.X > INSCRIPTION_RIGHT_FSTXCOORD && coord.X < INSCRIPTION_RIGHT_SCDXCOORD && coord.Y == INSCRIPTION_COORDY) {
						direction = "R"; break;
					}
				}
			}
		}//9.
		if (checkUp == YES && checkDown == NO && checkLeft == YES && checkRight == NO) {
			cout << setw(7) << "up" << setw(14) << "left" << endl;// U L
			for (;;)
			{
				ReadConsoleInput(hin, &InputRecord, 1, &Events); //reading
				if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) //left button
				{
					coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
					coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
					if (coord.X == INSCRIPTION_UP_FSTXCOORD || coord.X == INSCRIPTION_UP_SCDXCOORD && coord.Y == INSCRIPTION_COORDY) {
						direction = "U"; break;
					}
					if (coord.X > INSCRIPTION_LEFT_FSTXCOORD && coord.X < INSCRIPTION_LEFT_SCDXCOORD && coord.Y == INSCRIPTION_COORDY) {
						direction = "L"; break;
					}
				}
			}
		}//10.
		if (checkUp == YES && checkDown == NO && checkLeft == YES && checkRight == YES) {
			cout << setw(7) << "up" << setw(14) << "left" << setw(7) << "right" << endl;// L R
			for (;;)
			{
				ReadConsoleInput(hin, &InputRecord, 1, &Events); //reading
				if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) //left button
				{
					coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
					coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
					if (coord.X == INSCRIPTION_UP_FSTXCOORD || coord.X == INSCRIPTION_UP_SCDXCOORD && coord.Y == INSCRIPTION_COORDY) {
						direction = "U"; break;
					}
					if (coord.X > INSCRIPTION_LEFT_FSTXCOORD && coord.X < INSCRIPTION_LEFT_SCDXCOORD && coord.Y == INSCRIPTION_COORDY) {
						direction = "L"; break;
					}
					if (coord.X > INSCRIPTION_RIGHT_FSTXCOORD && coord.X < INSCRIPTION_RIGHT_SCDXCOORD && coord.Y == INSCRIPTION_COORDY) {
						direction = "R"; break;
					}
				}
			}
		}//11.
		if (checkUp == YES && checkDown == YES && checkLeft == NO && checkRight == NO) {
			cout << setw(7) << "up" << setw(7) << "down" << endl; // U D
			for (;;)
			{
				ReadConsoleInput(hin, &InputRecord, 1, &Events); //reading
				if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) //left button
				{
					coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
					coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
					if (coord.X == INSCRIPTION_UP_FSTXCOORD || coord.X == INSCRIPTION_UP_SCDXCOORD && coord.Y == INSCRIPTION_COORDY) {
						direction = "U"; break;
					}
					if (coord.X > INSCRIPTION_DOWN_FSTXCOORD && coord.X < INSCRIPTION_DOWN_SCDXCOORD && coord.Y == INSCRIPTION_COORDY) {
						direction = "D"; break;
					}
				}
			}
		}//12.
		if (checkUp == YES && checkDown == YES && checkLeft == NO && checkRight == YES) {
			cout << setw(7) << "up" << setw(7) << "down" << setw(14) << "right";// U D R
			for (;;)
			{
				ReadConsoleInput(hin, &InputRecord, 1, &Events); //reading
				if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) //left button
				{
					coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
					coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
					if (coord.X == INSCRIPTION_UP_FSTXCOORD || coord.X == INSCRIPTION_UP_SCDXCOORD && coord.Y == INSCRIPTION_COORDY) {
						direction = "U"; break;
					}
					if (coord.X > INSCRIPTION_DOWN_FSTXCOORD && coord.X < INSCRIPTION_DOWN_SCDXCOORD && coord.Y == INSCRIPTION_COORDY) {
						direction = "D"; break;
					}
					if (coord.X > INSCRIPTION_RIGHT_FSTXCOORD && coord.X < INSCRIPTION_RIGHT_SCDXCOORD && coord.Y == INSCRIPTION_COORDY) {
						direction = "R"; break;
					}
				}
			}
		}//13.
		if (checkUp == YES && checkDown == YES && checkLeft == YES && checkRight == NO) {
			cout << setw(7) << "up" << setw(7) << "down" << setw(7) << "left" << endl;// U D L
			for (;;)
			{
				ReadConsoleInput(hin, &InputRecord, 1, &Events); //reading
				if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) //left button
				{
					coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
					coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
					if (coord.X == INSCRIPTION_UP_FSTXCOORD || coord.X == INSCRIPTION_UP_SCDXCOORD && coord.Y == INSCRIPTION_COORDY) {
						direction = "U"; break;
					}
					if (coord.X > INSCRIPTION_DOWN_FSTXCOORD && coord.X < INSCRIPTION_DOWN_SCDXCOORD && coord.Y == INSCRIPTION_COORDY) {
						direction = "D"; break;
					}
					if (coord.X > INSCRIPTION_LEFT_FSTXCOORD && coord.X < INSCRIPTION_LEFT_SCDXCOORD && coord.Y == INSCRIPTION_COORDY) {
						direction = "L"; break;
					}
				}
			}
		}//14.
		if (checkUp == YES && checkDown == YES && checkLeft == YES && checkRight == YES) {
			cout << setw(7) << "up" << setw(7) << "down" << setw(7) << "left" << setw(7) << "right" << endl;// U D L R
			for (;;)
			{
				ReadConsoleInput(hin, &InputRecord, 1, &Events); //reading
				if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) //left button
				{
					coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
					coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
					if (coord.X == INSCRIPTION_UP_FSTXCOORD || coord.X == INSCRIPTION_UP_SCDXCOORD && coord.Y == INSCRIPTION_COORDY) {
						direction = "U"; break;
					}
					if (coord.X > INSCRIPTION_DOWN_FSTXCOORD && coord.X < INSCRIPTION_DOWN_SCDXCOORD && coord.Y == INSCRIPTION_COORDY) {
						direction = "D"; break;
					}
					if (coord.X > INSCRIPTION_LEFT_FSTXCOORD && coord.X < INSCRIPTION_LEFT_SCDXCOORD && coord.Y == INSCRIPTION_COORDY) {
						direction = "L"; break;
					}
					if (coord.X > INSCRIPTION_RIGHT_FSTXCOORD && coord.X < INSCRIPTION_RIGHT_SCDXCOORD && coord.Y == INSCRIPTION_COORDY) {
						direction = "R"; break;
					}
				}
			}
		}//15.

		//draws the player's ships
		if (direction == "U") {
			drawsaboatup(array, xPlayer, yPlayer, playerDecks);
		}
		if (direction == "D") {
			drawsaboatdown(array, xPlayer, yPlayer, playerDecks);
		}
		if (direction == "L") {
			drawsaboatleft(array, xPlayer, yPlayer, playerDecks);
		}
		if (direction == "R") {
			drawsaboatright(array, xPlayer, yPlayer, playerDecks);
		}
		//end of the loop drawing the player's ships
	} while (countOfPlayerCells < MAX_AMOUNT_OF_DECKS);
}