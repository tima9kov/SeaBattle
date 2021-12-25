#pragma once
#include <string>
using namespace std;

void user_shooting(string** playerArray, string** computerArray,string **outputArray, string forCheck, int &amountOfBrokenPlayer, int &amountOfShots, int& middle_menu_choice);
void random_shooting(int yShot, int xShot, string** computerArray, string** playerArray, string forCheck, int &amount_of_broken, int &amountOfShots);
//void shooting_algoritm(string** array, string** array1, int& xShot, int& yShot, string forCheck, int& amountOfBroken, int& amountOfShots, int& countForAlgm);
void shooting_algoritm(string** array, string** array1, int xShotAlgm, int yShotAlgm, string forCheck, int& amountOfBroken, int& amountOfShots, int& countForAlgm, int &condition, int& xFixed, int& yFixed, int& obviously_upward_direction, int& obviously_downward_direction, int& obviously_direction_to_the_left, int& obviously_direction_to_the_right);
