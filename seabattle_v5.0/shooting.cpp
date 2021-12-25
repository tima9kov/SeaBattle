#include "shooting.h"
#include "convertingCoords.h"
#include "drawsAShip.h"
#include "show_a_field.h"
#include <string>
#include <Windows.h>
#include <iostream>
#include "enums.h"
#include "checkDirection.h"
using namespace std;


string red = "\x1b[31m", white = "\x1b[0m", green = "\x1b[32m", gold = "\x1b[33m";

void output_for_algm(string** array) {
	system("cls");
	field_output(green, white, red);
	ships_output(array, SHIPS_FIRST_X_PLAYER1, SHIPS_FIRST_Y_PLAYER1);
	Sleep(2000);
}
void coloured_output_for_algm(string** array) {
	system("cls");
	field_output(green, white, red);
	cout << red << endl;
	ships_output(array, SHIPS_FIRST_X_PLAYER1, SHIPS_FIRST_Y_PLAYER1);
	cout << white << endl;
	Sleep(2000);
}

//since there algoritm starts
int check_shooting_up(string** array, int checkUp, int xCoord, int yCoord, string forCheck)
{
	checkUp = 1;
	if (yCoord == 0) {
		checkUp == 1;
	}
	if (yCoord > 0)
		if (array[yCoord - 1][xCoord] == forCheck)
			checkUp = 0;
	return checkUp;
}

int check_shooting_down(string** array, int checkDown, int xCoord, int yCoord, string forCheck)
{
	checkDown = 1;
	if (yCoord == 9) {
		checkDown == 1;
	}
	if (yCoord < 9)
		if (array[yCoord + 1][xCoord] == forCheck)
			checkDown = 0;
	return checkDown;
}

int check_shooting_left(string** array, int checkLeft, int xCoord, int yCoord, string forCheck)
{
	checkLeft = 1;
	if (xCoord == 0) {
		checkLeft == 1;
	}
	if (xCoord > 0)
		if (array[yCoord][xCoord - 1] == forCheck)
			checkLeft = 0;
	return checkLeft;
}

int check_shooting_right(string** array, int checkRight, int xCoord, int yCoord, string forCheck)
{
	checkRight = 1;
	if (xCoord == 9) {
		checkRight == 1;
	}
	if (xCoord < 9)
		if (array[yCoord][xCoord + 1] == forCheck)
			checkRight = 0;
	return checkRight;
}

int xShots[50] = { 0,0,1,1,2,2,2,3,3,3,4,4,5,5,6,6,6,7,7,7,8,8,9,9,0,0,0,1,1,1,2,2,3,3,4,4,4,5,5,5,6,6,7,7,8,8,8,9,9,9 };
int yShots[50] = { 3,7,2,6,1,5,9,0,4,8,3,7,2,6,1,5,9,0,4,8,3,7,2,6,1,5,9,0,4,8,3,7,2,6,1,5,9,0,4,8,3,7,2,6,1,5,9,0,4,8 };

void shoot_around_one_cell_ud(string** array,string**array1, int abilityToShootUp, int abilityToShootDown, int abilityToShootLeft, int abilityToShootRight, int xCoord, int yCoord, string EMPTY, string missed) {
	if (check_shooting_up(array, abilityToShootUp, xCoord, yCoord, EMPTY) == 0) {
		array[yCoord - 1][xCoord] = missed;
		array1[yCoord - 1][xCoord] = missed;
	}
	//corners
	if (check_shooting_up(array, abilityToShootUp, xCoord - 1, yCoord, EMPTY) == 0) {
		array[yCoord - 1][xCoord - 1] = missed;
		array1[yCoord - 1][xCoord - 1] = missed;
	}
	if (check_shooting_up(array, abilityToShootUp, xCoord + 1, yCoord, EMPTY) == 0) {
		array[yCoord - 1][xCoord + 1] = missed;
		array1[yCoord - 1][xCoord + 1] = missed;
	}
	if (check_shooting_down(array, abilityToShootDown, xCoord - 1, yCoord, EMPTY) == 0) {
		array[yCoord + 1][xCoord - 1] = missed;
		array1[yCoord + 1][xCoord - 1] = missed;
	}
	if (check_shooting_down(array, abilityToShootDown, xCoord + 1, yCoord, EMPTY) == 0) {
		array[yCoord + 1][xCoord + 1] = missed;
		array1[yCoord + 1][xCoord + 1] = missed;
	}
	//

	if (check_shooting_down(array, abilityToShootDown, xCoord, yCoord, EMPTY) == 0) {
		array[yCoord + 1][xCoord] = missed;
		array1[yCoord + 1][xCoord] = missed;
	}
	if (check_shooting_left(array, abilityToShootLeft, xCoord, yCoord, EMPTY) == 0) {
		array[yCoord][xCoord - 1] = missed;
		array1[yCoord][xCoord - 1] = missed;
	}
	if (check_shooting_right(array, abilityToShootRight, xCoord, yCoord, EMPTY) == 0) {
		array[yCoord][xCoord + 1] = missed;
		array1[yCoord][xCoord + 1] = missed;
	}
}

void shoot_around_one_cell_lr(string** array,string**array1, int abilityToShootUp, int abilityToShootDown, int abilityToShootLeft, int abilityToShootRight, int xCoord, int yCoord, string EMPTY, string missed) {
	if (check_shooting_left(array, abilityToShootLeft, xCoord, yCoord, EMPTY) == 0) {
		array[yCoord][xCoord - 1] = missed;
		array1[yCoord][xCoord - 1] = missed;
	}
	//corners
	if (check_shooting_up(array, abilityToShootUp, xCoord - 1, yCoord, EMPTY) == 0) {
		array[yCoord - 1][xCoord - 1] = missed;
		array1[yCoord - 1][xCoord - 1] = missed;
	}
	if (check_shooting_up(array, abilityToShootUp, xCoord + 1, yCoord, EMPTY) == 0) {
		array[yCoord - 1][xCoord + 1] = missed;
		array1[yCoord - 1][xCoord + 1] = missed;

	}
	if (check_shooting_down(array, abilityToShootDown, xCoord - 1, yCoord, EMPTY) == 0) {
		array[yCoord + 1][xCoord - 1] = missed;
		array1[yCoord + 1][xCoord - 1] = missed;

	}
	if (check_shooting_down(array, abilityToShootDown, xCoord + 1, yCoord, EMPTY) == 0) {
		array[yCoord + 1][xCoord + 1] = missed;
		array1[yCoord + 1][xCoord + 1] = missed;
	}
	//

	if (check_shooting_right(array, abilityToShootRight, xCoord, yCoord, EMPTY) == 0) {
		array[yCoord][xCoord + 1] = missed;
		array1[yCoord][xCoord + 1] = missed;
	}
	if (check_shooting_up(array, abilityToShootUp, xCoord, yCoord, EMPTY) == 0) {
		array[yCoord - 1][xCoord] = missed;
		array1[yCoord - 1][xCoord] = missed;
	}
	if (check_shooting_down(array, abilityToShootDown, xCoord, yCoord, EMPTY) == 0) {
		array[yCoord + 1][xCoord] = missed;
		array1[yCoord + 1][xCoord] = missed;
	}
}


void finish_of(string** array, string **array1, int xCoord, int yCoord, string forCheck, int& amountOfShots, int& amountOfBroken) {
	string red = "\x1b[31m", white = "\x1b[0m";
	int abilityToShootUp{ 0 }, abilityToShootDown{ 0 }, abilityToShootLeft{ 0 }, abilityToShootRight{ 0 };
	string broken; broken = char(BROKEN);
	string missed; missed = char(MISSED);
	string EMPTY = " ";
	int shootDirection{ 0 };
	
	abilityToShootUp = check_shooting_up(array, abilityToShootUp, xCoord, yCoord, forCheck);
	abilityToShootDown = check_shooting_down(array, abilityToShootDown, xCoord, yCoord, forCheck);
	abilityToShootLeft = check_shooting_left(array, abilityToShootLeft, xCoord, yCoord, forCheck);
	abilityToShootRight = check_shooting_right(array, abilityToShootRight, xCoord, yCoord, forCheck);
	
	if (abilityToShootUp == 0)
		for (int y = yCoord; abilityToShootUp == 0; y--, array[y][xCoord] = broken, array1[y][xCoord] = broken,amountOfShots++, amountOfBroken++, abilityToShootUp = check_shooting_up(array, abilityToShootUp, xCoord, y, forCheck)) {
			output_for_algm(array);
		}

	if (abilityToShootDown == 0)
		for (int y = yCoord; abilityToShootDown == 0; y++, array[y][xCoord] = broken, array1[y][xCoord] = broken, amountOfShots++, amountOfBroken++, abilityToShootDown = check_shooting_down(array, abilityToShootDown, xCoord, y, forCheck)) {
			output_for_algm(array);
		}

	if (abilityToShootLeft == 0)
		for (int x = xCoord; abilityToShootLeft == 0; x--, array[yCoord][x] = broken, array1[yCoord][x] = broken, amountOfShots++, amountOfBroken++, abilityToShootLeft = check_shooting_left(array, abilityToShootLeft, x, yCoord, forCheck)) {
			output_for_algm(array);
		}

	if (abilityToShootRight == 0)
		for (int x = xCoord; abilityToShootRight == 0; x++, array[yCoord][x] = broken, array1[yCoord][x] = broken ,amountOfShots++, amountOfBroken++, abilityToShootRight = check_shooting_right(array, abilityToShootRight, x, yCoord, forCheck)) {
			output_for_algm(array);
		}
		
	if (abilityToShootUp == 1 && abilityToShootDown == 1 && abilityToShootLeft == 1 && abilityToShootRight == 1) {
		array[yCoord][xCoord] = broken;
		array1[yCoord][xCoord] = broken;

		shoot_around_one_cell_ud(array,array1, abilityToShootUp, abilityToShootDown, abilityToShootLeft, abilityToShootRight, xCoord, yCoord, EMPTY, missed);

		if (check_shooting_up(array, abilityToShootUp, xCoord, yCoord, broken) == 0) {
			int counter{ 0 };
			while (check_shooting_up(array, abilityToShootUp, xCoord, yCoord - counter, broken) == 0)
				counter++;
			for (int i = 0; i <= counter; shoot_around_one_cell_ud(array,array1, abilityToShootUp, abilityToShootDown, abilityToShootLeft, abilityToShootRight, xCoord, yCoord - i, EMPTY, missed), i++);
		}

		if (check_shooting_down(array, abilityToShootDown, xCoord, yCoord, broken) == 0) {
			int counter{ 0 };
			while (check_shooting_down(array, abilityToShootDown, xCoord, yCoord + counter, broken) == 0)
				counter++;
			for (int i = 1; i <= counter; shoot_around_one_cell_ud(array,array1, abilityToShootUp, abilityToShootDown, abilityToShootLeft, abilityToShootRight, xCoord, yCoord + i, EMPTY, missed), i++);
		}

		if (check_shooting_left(array, abilityToShootLeft, xCoord, yCoord, broken) == 0) {
			int counter{ 0 };
			while (check_shooting_left(array, abilityToShootLeft, xCoord - counter, yCoord, broken) == 0)
				counter++;
			for (int i = 1; i <= counter; shoot_around_one_cell_lr(array,array1, abilityToShootUp, abilityToShootDown, abilityToShootLeft, abilityToShootRight, xCoord - i, yCoord, EMPTY, missed), i++);
		}

		if (check_shooting_right(array, abilityToShootRight, xCoord, yCoord, broken) == 0) {
			int counter{ 0 };
			while (check_shooting_right(array, abilityToShootRight, xCoord + counter, yCoord, broken) == 0)
				counter++;
			for (int i = 1; i <= counter; shoot_around_one_cell_lr(array, array1, abilityToShootUp, abilityToShootDown, abilityToShootLeft, abilityToShootRight, xCoord + i, yCoord, EMPTY, missed), i++);
		}
	}
}

/*
// алгоритм с непродуманным добиванием
void shooting_algoritm(string** array, string**array1, int &xShot, int &yShot, string forCheck, int& amountOfBroken, int& amountOfShots, int& countForAlgm) {
	string broken; broken = char(BROKEN);
	string MISS; MISS = char(MISSED);
	string EMPTY; EMPTY = " ";
	int direction{0};
	int miss{ 0 };
	int abilityToShootUp{ 0 }, abilityToShootDown{ 0 }, abilityToShootLeft{ 0 }, abilityToShootRight{ 0 };
	
	if (countForAlgm < 48) {
		do {			
			xShot = xShots[countForAlgm];
			yShot = yShots[countForAlgm];			
		
			if (array[yShot][xShot] == forCheck) {
				array[yShot][xShot] = broken;
				array1[yShot][xShot] = broken;				
				amountOfBroken++;
				amountOfShots++;

				if (amountOfShots == MAX_AMOUNT_OF_BROKEN)
					return;
			
					finish_of(array, array1, xShot, yShot, forCheck, amountOfShots, amountOfBroken);
					cout << "\a";					
			}
			else {
				if (array[yShot][xShot] == " " ) 
				{
					array[yShot][xShot] = MISS;
					array1[yShot][xShot] = MISS;
					countForAlgm++;
					miss = 0;

				}
				else {					
					countForAlgm++;
					miss = 1;
				}
			}
		} while (miss == 1);
	}
	else {
	xShot = rand() % AMOUNT_OF_CELLS;
	yShot = rand() % AMOUNT_OF_CELLS;
		do {
			if (array[yShot][xShot] == forCheck) {
				amountOfShots++;
				amountOfBroken++;
				array[yShot][xShot] = broken;
				array1[yShot][xShot] = broken;
				if (amountOfBroken == MAX_AMOUNT_OF_BROKEN)
					return;
				finish_of(array, array1, xShot, yShot, forCheck, amountOfShots, amountOfBroken);
				countForAlgm++;
				xShot = rand() % AMOUNT_OF_CELLS;
				yShot = rand() % AMOUNT_OF_CELLS;
				miss = 1;
			}
			else {
				if (array[yShot][xShot] == " ")
				{
					array[yShot][xShot] = MISS;
					array1[yShot][xShot] = MISS;
					amountOfShots++;
					miss = 0;
				}
				else {
					countForAlgm++;
					xShot = rand() % AMOUNT_OF_CELLS;
					yShot = rand() % AMOUNT_OF_CELLS;
					miss = 1;
				}
			}
		} while (miss == 1);
	}
}
*/
//конец алгоритма с непродуманным добиванием

//попытка создания нормального алгоритма
void shooting_algoritm(string** array, string** outputArray, int xShotAlgm, int yShotAlgm, string forCheck, int& amountOfBroken, int& amountOfShots, int& countForAlgm, int &condition, int&xFixed, int &yFixed, int& obviously_upward_direction, int& obviously_downward_direction,int & obviously_direction_to_the_left, int& obviously_direction_to_the_right){
	string broken; broken = char(BROKEN);
	string MISS; MISS = char(MISSED);
	string EMPTY; EMPTY = " ";
	int direction{ 0 };
	int miss{ 0 };
	int abilityToShootUp{ 0 }, abilityToShootDown{ 0 }, abilityToShootLeft{ 0 }, abilityToShootRight{ 0 };
	int checkUp{ 0 }, checkDown{ 0 }, checkLeft{ 0 }, checkRight{ 0 };

	//if (countForAlgm < 48) {
		do {
			if (condition == 0) {
				if (countForAlgm < 48) {
					xShotAlgm = xShots[countForAlgm];
					yShotAlgm = yShots[countForAlgm];
				}
				else {
					xShotAlgm = rand() % AMOUNT_OF_CELLS;
					yShotAlgm = rand() % AMOUNT_OF_CELLS;
				}
				if (array[yShotAlgm][xShotAlgm] == forCheck) {
					array[yShotAlgm][xShotAlgm] = broken;
					outputArray[yShotAlgm][xShotAlgm] = broken;
					amountOfBroken++;
					amountOfShots++;
					xFixed = xShotAlgm;
					yFixed = yShotAlgm;
					if (amountOfShots == MAX_AMOUNT_OF_BROKEN)
						return;
					//проверка - однопалубный или нет
						//если однопалубный - добиваем и стреляем дальше
					abilityToShootUp = check_shooting_up(array, abilityToShootUp, xShotAlgm, yShotAlgm, forCheck);
					abilityToShootDown = check_shooting_down(array, abilityToShootDown, xShotAlgm, yShotAlgm, forCheck);
					abilityToShootLeft = check_shooting_left(array, abilityToShootLeft, xShotAlgm, yShotAlgm, forCheck);
					abilityToShootRight = check_shooting_right(array, abilityToShootRight, xShotAlgm, yShotAlgm, forCheck);

					if (abilityToShootUp == 1 && abilityToShootDown == 1 && abilityToShootLeft == 1 && abilityToShootRight == 1) {
						abilityToShootUp == 0; abilityToShootDown == 0; abilityToShootLeft == 0; abilityToShootRight == 0;
						finish_of(array, outputArray, xShotAlgm, yShotAlgm, forCheck, amountOfShots, amountOfBroken);
						cout << "\a"; miss = 1; countForAlgm++; condition = 0;
						if (countForAlgm >= 48) {
							xShotAlgm = rand() % AMOUNT_OF_CELLS;
							yShotAlgm = rand() % AMOUNT_OF_CELLS;
						}
					}
					else {
						condition = 1; miss = 1;
					}					
				}
				else {
					if (array[yShotAlgm][xShotAlgm] == " ")
					{
						array[yShotAlgm][xShotAlgm] = MISS;
						outputArray[yShotAlgm][xShotAlgm] = MISS;						
						countForAlgm++;
						miss = 0;
					}
					else {
						countForAlgm++;						
						miss = 1;					
					}
				}
			}
			if (condition == 1) {
			
				xShotAlgm = xFixed;
				yShotAlgm = yFixed;

				if (obviously_upward_direction == 0) {
					direction = 1; obviously_upward_direction = 1;
				}else if (obviously_downward_direction == 0) {
					direction = 2; obviously_downward_direction = 1;
				}
				else if (obviously_direction_to_the_left == 0) {
					direction = 3; obviously_direction_to_the_left = 1;
				}
				else if (obviously_direction_to_the_right == 0) {
					direction = 4; obviously_direction_to_the_right = 1;
				}
				else {
					//для фиксированной координаты проверяем возможность стрельбы на массиве вывода - наличие пустой клетки
					checkUp = check_shooting_up(outputArray, checkUp, xShotAlgm, yShotAlgm, EMPTY);
					checkDown = check_shooting_down(outputArray, checkDown, xShotAlgm, yShotAlgm, EMPTY);
					checkLeft = check_shooting_left(outputArray, checkLeft, xShotAlgm, yShotAlgm, EMPTY);
					checkRight = check_shooting_right(outputArray, checkRight, xShotAlgm, yShotAlgm, EMPTY);
					//ВЫБИРАЕМ РАНДОМНОЕ НАППРАВЛЕНИЕ СРЕДИ ВОЗМОЖНЫХ
					direction = forCheckingSides(checkUp, checkDown, checkLeft, checkRight, direction);
				}		
			
				//стреляем по выбранному направлению
				//1й  случай - направление вверх, промах				
				if (direction == 1) {				
					if (array[yShotAlgm - 1][xShotAlgm] == " ") {
						//cout << "dead in 1" << endl; system("pause");
						array[yShotAlgm - 1][xShotAlgm] = MISSED;
						outputArray[yShotAlgm - 1][xShotAlgm] = MISSED;
						condition = 1; miss = 0; break;
					}
					output_for_algm(array);				
				}

				//2й  случай - направление вниз, промах
				if (direction == 2) {
					if (array[yShotAlgm + 1][xShotAlgm] == " ") {
						//cout << "dead in 2" << endl; system("pause");
						array[yShotAlgm + 1][xShotAlgm] = MISSED;
						outputArray[yShotAlgm + 1][xShotAlgm] = MISSED;
						condition = 1; miss = 0; break;
					}
					output_for_algm(array);				
				}

				//3й  случай - направление влево - промах
				if (direction == 3) {
					if (array[yShotAlgm][xShotAlgm - 1] == " ") {
						//cout << "dead in 3" << endl;system("pause");
						array[yShotAlgm][xShotAlgm - 1] = MISSED;
						outputArray[yShotAlgm][xShotAlgm - 1] = MISSED;
						condition = 1; miss = 0; break;				
					}
					output_for_algm(array);			
				}

				//4й  случай - направление вправо - промах
				if (direction == 4) {
					if (array[yShotAlgm][xShotAlgm + 1] == " ") {
						//cout << "dead in 4" << endl; system("pause");
						array[yShotAlgm][xShotAlgm + 1] = MISSED;
						outputArray[yShotAlgm][xShotAlgm + 1] = MISSED;
						condition = 1; miss = 0; break;
					}
					output_for_algm(array);							
				}

				//5й  случай - направление вверх, снизу есть не сломанная палуба
				if (direction == 1) {
					if (array[yShotAlgm - 1][xShotAlgm] == forCheck && check_shooting_down(array, checkDown, xShotAlgm, yShotAlgm, forCheck) == 0) {						
						int i {1};
						do {
							if (check_shooting_up(outputArray, checkUp, xShotAlgm, yShotAlgm - i + 1, " ") == 1) {
								finish_of(array, outputArray, xShotAlgm, yShotAlgm, forCheck, amountOfShots, amountOfBroken);
								cout << "\a"; miss = 1; condition = 0; countForAlgm++;
								coloured_output_for_algm(array);
							break;
							}
							else if (array[yShotAlgm - i][xShotAlgm] == forCheck) {							
								array[yShotAlgm - i][xShotAlgm] = broken;
								outputArray[yShotAlgm - i][xShotAlgm] = broken;
								condition = 1; ++i;
								amountOfBroken++, amountOfShots++;
								output_for_algm(array);							
							}
							else if (array[yShotAlgm - i][xShotAlgm] == " ") {
								array[yShotAlgm - i][xShotAlgm] = MISSED;						
								outputArray[yShotAlgm - i][xShotAlgm] = MISSED;
								condition = 1; miss = 0; amountOfShots++;
								output_for_algm(array);								
								obviously_downward_direction = 0;
							}							
						} while (check_shooting_up(outputArray, checkUp, xShotAlgm, yShotAlgm - i + 1, EMPTY) == 0);
						
					}
				}

				//6й  случай - направление вверх, снизу нет палубы			
				if (direction == 1) {
					if (array[yShotAlgm - 1][xShotAlgm] == forCheck && check_shooting_down(array, checkDown, xShotAlgm, yShotAlgm, forCheck) == 1) {
					
						abilityToShootUp == 0; abilityToShootDown == 0; abilityToShootLeft == 0; abilityToShootRight == 0;
						finish_of(array, outputArray, xShotAlgm, yShotAlgm, forCheck, amountOfShots, amountOfBroken);
						cout << "\a"; miss = 1; condition = 0; countForAlgm++;						
						coloured_output_for_algm(array);								
					}			
				}

				//7й  случай - направление вниз, сверху есть не сломанная палуба
				if (direction == 2) {
					if (array[yShotAlgm + 1][xShotAlgm] == forCheck && check_shooting_up(array, checkUp, xShotAlgm, yShotAlgm, forCheck) == 0) {						
						int i{ 1 };
						do {
							if (check_shooting_down(outputArray, checkDown, xShotAlgm, yShotAlgm + i - 1, " ") == 1) {
								finish_of(array, outputArray, xShotAlgm, yShotAlgm, forCheck, amountOfShots, amountOfBroken);
								cout << "\a"; miss = 1; condition = 0; countForAlgm++;
								coloured_output_for_algm(array);							
								break;
							}
							else if (array[yShotAlgm + i][xShotAlgm] == forCheck) {							
								array[yShotAlgm + i][xShotAlgm] = broken;
								outputArray[yShotAlgm + i][xShotAlgm] = broken;
								condition = 1; ++i;
								amountOfBroken++, amountOfShots++;
								output_for_algm(array);							
								obviously_upward_direction = 0;
							}else if (array[yShotAlgm + i][xShotAlgm] == " ") {
									array[yShotAlgm + i][xShotAlgm] = MISSED;									
									outputArray[yShotAlgm + i][xShotAlgm] = MISSED;
									condition = 1; miss = 0; amountOfShots++; 
									field_output(green, white, red);
									ships_output(array, SHIPS_FIRST_X_PLAYER1, SHIPS_FIRST_Y_PLAYER1);
									Sleep(2000);
							}	
						} while (check_shooting_down(outputArray, checkDown, xShotAlgm, yShotAlgm + i - 1, " ") == 0);						
					}
				}

				//8й  случай - направление вниз, сверху нет палубы	
				if (direction == 2) {
					if (array[yShotAlgm + 1][xShotAlgm] == forCheck && check_shooting_up(array, checkUp, xShotAlgm, yShotAlgm, forCheck) == 1) {				
						abilityToShootUp == 0; abilityToShootDown == 0; abilityToShootLeft == 0; abilityToShootRight == 0;
						finish_of(array, outputArray, xShotAlgm, yShotAlgm, forCheck, amountOfShots, amountOfBroken);
						cout << "\a"; miss = 1; condition = 0; countForAlgm++;
						coloured_output_for_algm(array);						
					}			
				}

				//9й  случай - направление влево, справа есть не сломанная палуба
				if (direction == 3) {
					if (array[yShotAlgm][xShotAlgm - 1] == forCheck && check_shooting_right(array, checkRight, xShotAlgm, yShotAlgm, forCheck) == 0) {						
						int i{ 1 };					
							do{
								if (check_shooting_left(outputArray, checkLeft, xShotAlgm - i + 1, yShotAlgm, " ") == 1) {
									finish_of(array, outputArray, xShotAlgm, yShotAlgm, forCheck, amountOfShots, amountOfBroken);
									cout << "\a"; miss = 1; condition = 0; countForAlgm++;
									coloured_output_for_algm(array);									
									break;
								}else if (array[yShotAlgm][xShotAlgm - 1] == forCheck) {									
									array[yShotAlgm][xShotAlgm - 1] = broken;
									outputArray[yShotAlgm][xShotAlgm - 1] = broken;
									condition = 1; ++i;
									amountOfBroken++, amountOfShots++;
									output_for_algm(array);								
									obviously_direction_to_the_right = 0;
								}else if (array[yShotAlgm][xShotAlgm - i] == " ") {									
									array[yShotAlgm][xShotAlgm - i] = MISSED;
									outputArray[yShotAlgm][xShotAlgm - i] = MISSED;
									condition = 1; miss = 0; amountOfShots++;  break;								
								}							
							} while (check_shooting_left(outputArray, checkLeft, xShotAlgm - i + 1, yShotAlgm, " ") == 0);
					}
				}

				//10й случай - направление влево, справа нет палубы
				if (direction == 3) {
					if (array[yShotAlgm][xShotAlgm - 1] == forCheck && check_shooting_right(array, checkRight, xShotAlgm, yShotAlgm, forCheck) == 1) {					
						abilityToShootUp == 0; abilityToShootDown == 0; abilityToShootLeft == 0; abilityToShootRight == 0;
						finish_of(array, outputArray, xShotAlgm, yShotAlgm, forCheck, amountOfShots, amountOfBroken);
						cout << "\a"; miss = 1; condition = 0; countForAlgm++;
						coloured_output_for_algm(array);						
					}				
				}

				//11й случай - направление вправо, слева есть не сломанная палуба
				if (direction == 4) {
					if (array[yShotAlgm][xShotAlgm + 1] == forCheck && check_shooting_left(array, checkLeft, xShotAlgm, yShotAlgm, forCheck) == 0) {						
						int i{ 0 };
						do {
							if (check_shooting_right(outputArray, checkRight, xShotAlgm + i - 1, yShotAlgm, " ") == 1) {
								finish_of(array, outputArray, xShotAlgm, yShotAlgm, forCheck, amountOfShots, amountOfBroken);
								cout << "\a"; miss = 1; condition = 0; countForAlgm++;
								coloured_output_for_algm(array);								
								break;
							}else if (array[yShotAlgm][xShotAlgm + i] == forCheck) {										
								array[yShotAlgm][xShotAlgm + i] = broken;
								outputArray[yShotAlgm][xShotAlgm + i] = broken;
								condition = 1; ++i;
								amountOfBroken++, amountOfShots++;
								output_for_algm(array);
								obviously_direction_to_the_left = 0;
							}
							else if (array[yShotAlgm][xShotAlgm + i] == " ") {						
								array[yShotAlgm][xShotAlgm + i] = MISSED;
								outputArray[yShotAlgm][xShotAlgm + i] = MISSED;
								condition = 1; miss = 0; amountOfShots++; break;
								output_for_algm(array);								
							}
							
						} while (check_shooting_right(outputArray, checkRight, xShotAlgm + i - 1, yShotAlgm, " ") == 0);
						
					}
				}

				//12й случай - направление вправо, слева нет палубы
				if (direction == 4) {
					if (array[yShotAlgm][xShotAlgm + 1] == forCheck && check_shooting_left(array, checkLeft, xShotAlgm, yShotAlgm, forCheck) == 1) {					
						abilityToShootUp == 0; abilityToShootDown == 0; abilityToShootLeft == 0; abilityToShootRight == 0;
						finish_of(array, outputArray, xShotAlgm, yShotAlgm, forCheck, amountOfShots, amountOfBroken);
						cout << "\a"; miss = 1; condition = 0; countForAlgm++;
						coloured_output_for_algm(array);						
					}									
				}			
			}		
		} while (miss == 1);
}

void ouputForUserShooting( string **outputArray) {
	cout << "\a";
	system("cls");
	field_output(green, white, red);
	cout << gold;
	ships_output(outputArray, SHIPS_FIRST_X_PLAYER2, SHIPS_FIRST_Y_PLAYER2);
	Sleep(2000);
	cout << white;
}
//users shooting 
void user_shooting(string** playerArray, string** computerArray, string** outputArray, string forCheck, int& amountOfBrokenPlayer, int& amountOfShots, int& middle_menu_choice) {
	int abilityToShootUp{ 0 }, abilityToShootDown{ 0 }, abilityToShootLeft{ 0 }, abilityToShootRight{ 0 };
	int presence_through_one_up{ 0 }, presence_through_one_down{ 0 }, presence_through_one_left{ 0 }, presence_through_one_right{ 0 };
	int presence_upBr{ 0 }, presence_downBr{ 0 }, presence_leftBr{ 0 }, presence_rightBr{ 0 };
	//the coordinates of the player's shots 
	int xShotPlayer(0), yShotPlayer(0);	
	//for converting coords
	int startingPoint{ 0 };
	//broken cage 
	string broken;
	broken = char(BROKEN);
	//miss 
	string MISS;
	MISS = char(MISSED);
	//player shooting 
	int miss_player = 1;
	do {
		//output fields 
		system("cls");
		COORD position{ 130, 4 };
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hConsole, position);

		field_output(green, white, red);
		ships_output(playerArray, SHIPS_FIRST_X_PLAYER1, SHIPS_FIRST_Y_PLAYER1);
		ships_output(outputArray, SHIPS_FIRST_X_PLAYER2, SHIPS_FIRST_Y_PLAYER2);
		//communication with the user 
		cout << green << "Where do you want to SHOOT?" << white << "\t";

		//input of coordinates 
		converting_coords_right_part(xShotPlayer, yShotPlayer, startingPoint, middle_menu_choice);
		if (middle_menu_choice == END_GAME_MIDDLE_MENU) {
			return;
		}

		if (computerArray[yShotPlayer][xShotPlayer] == forCheck) {
			computerArray[yShotPlayer][xShotPlayer] = broken;
			outputArray[yShotPlayer][xShotPlayer] = broken;
			miss_player = 1;
			amountOfBrokenPlayer += 1;
			amountOfShots += 1;
		
			if (amountOfBrokenPlayer == MAX_AMOUNT_OF_BROKEN)
				return;
			
			abilityToShootUp = check_shooting_up(computerArray, abilityToShootUp, xShotPlayer, yShotPlayer, forCheck);
			abilityToShootDown = check_shooting_down(computerArray, abilityToShootDown, xShotPlayer, yShotPlayer, forCheck);
			abilityToShootLeft = check_shooting_left(computerArray, abilityToShootLeft, xShotPlayer, yShotPlayer, forCheck);
			abilityToShootRight = check_shooting_right(computerArray, abilityToShootRight, xShotPlayer, yShotPlayer, forCheck);

			if (abilityToShootUp == 1 && abilityToShootDown == 1 && abilityToShootLeft == 1 && abilityToShootRight == 1 ) {
				
				presence_upBr = check_shooting_up(computerArray, presence_upBr, xShotPlayer, yShotPlayer, broken);
				presence_downBr = check_shooting_down(computerArray, presence_downBr, xShotPlayer, yShotPlayer, broken);
				presence_leftBr = check_shooting_left(computerArray, presence_leftBr, xShotPlayer, yShotPlayer, broken);
				presence_rightBr = check_shooting_right(computerArray, presence_rightBr, xShotPlayer, yShotPlayer, broken);

				if (abilityToShootUp == 1 && presence_upBr == 0) {
					if (presence_through_one_up = check_shooting_up(computerArray, presence_through_one_up, xShotPlayer, yShotPlayer - 1, forCheck) == 1) {
						finish_of(computerArray, outputArray, xShotPlayer, yShotPlayer, forCheck, amountOfShots, amountOfBrokenPlayer);
						ouputForUserShooting(outputArray);						
					}
				}else if (abilityToShootDown == 1 && presence_downBr == 0) {
					if (presence_through_one_down = check_shooting_down(computerArray, presence_through_one_down, xShotPlayer, yShotPlayer + 1, forCheck) == 1) {
						finish_of(computerArray, outputArray, xShotPlayer, yShotPlayer, forCheck, amountOfShots, amountOfBrokenPlayer);
						ouputForUserShooting(outputArray);					
					}
				}
				else if (abilityToShootLeft == 1 && presence_leftBr == 0) {
					if (presence_through_one_left = check_shooting_left(computerArray, presence_through_one_left, xShotPlayer - 1, yShotPlayer, forCheck) == 1) {
						finish_of(computerArray, outputArray, xShotPlayer, yShotPlayer, forCheck, amountOfShots, amountOfBrokenPlayer);
						ouputForUserShooting(outputArray);						
					}
				}
				else if (abilityToShootRight == 1 && presence_rightBr == 0) {
					if (presence_through_one_right = check_shooting_right(computerArray, presence_through_one_right, xShotPlayer + 1, yShotPlayer, forCheck) == 1) {
						finish_of(computerArray, outputArray, xShotPlayer, yShotPlayer, forCheck, amountOfShots, amountOfBrokenPlayer);
						ouputForUserShooting(outputArray);					
					}
				}
				else {
					finish_of(computerArray, outputArray, xShotPlayer, yShotPlayer, forCheck, amountOfShots, amountOfBrokenPlayer);
					ouputForUserShooting(outputArray);				
				}				
			}
			else {
				system("cls");
				field_output(green, white, red);
				ships_output(playerArray, SHIPS_FIRST_X_PLAYER1, SHIPS_FIRST_Y_PLAYER1);
				ships_output(outputArray, SHIPS_FIRST_X_PLAYER2, SHIPS_FIRST_Y_PLAYER2);
			}
		}
		else {
			if (computerArray[yShotPlayer][xShotPlayer] == " ")
			{
				computerArray[yShotPlayer][xShotPlayer] = char(MISSED);
				outputArray[yShotPlayer][xShotPlayer] = char(MISSED);
				amountOfShots += 1;
				miss_player = 0;
			}
			else {
				system("cls");
				field_output(green, white, red);
				ships_output(playerArray, SHIPS_FIRST_X_PLAYER1, SHIPS_FIRST_Y_PLAYER1);
				ships_output(outputArray, SHIPS_FIRST_X_PLAYER2, SHIPS_FIRST_Y_PLAYER2);
				cout << green << "Where do you want to SHOOT?" << white << "\t";
				converting_coords_right_part(xShotPlayer, yShotPlayer, startingPoint, middle_menu_choice);
				miss_player = 1;
			}
		}
	} while (miss_player == 1);
}


void random_shooting(int yShot, int xShot, string** computerArray, string** playerArray, string forCheck, int& amount_of_broken, int& amountOfShots) {
	int condition{ 0 };
	//variables created to edit the output (colors)
	string red = "\x1b[31m", white = "\x1b[0m", green = "\x1b[32m", gold = "\x1b[33m";

	//broken cell
	string broken;
	broken = red + char(BROKEN) + white;

	xShot = rand() % AMOUNT_OF_CELLS;
	yShot = rand() % AMOUNT_OF_CELLS;

	int miss(0);

	do {
		if (playerArray[yShot][xShot] == forCheck) {
			playerArray[yShot][xShot] = broken;
			amount_of_broken += 1;
			amountOfShots += 1;
			if (amount_of_broken == MAX_AMOUNT_OF_BROKEN)
				return;
			xShot = rand() % AMOUNT_OF_CELLS;
			yShot = rand() % AMOUNT_OF_CELLS;
		}
		else {
			if (playerArray[yShot][xShot] == " ")
			{
				playerArray[yShot][xShot] = char(MISSED);

				miss = 0;
				amountOfShots += 1;
			}
			else {
				xShot = rand() % AMOUNT_OF_CELLS;
				yShot = rand() % AMOUNT_OF_CELLS;
				miss = 1;
			}
		}
	} while (miss == 1);
}

