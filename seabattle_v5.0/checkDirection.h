#pragma once
#include <string>
using namespace std;
int check_direction_up(string** array, int checkuP, int xCoord, int yCoord, int decks, string forCheck);
int check_direction_down(string** array, int checkDown, int xCoord, int yCoord, int decks, string forCheck);
int check_direction_left(string** array, int checkLeft, int xCoord, int yCoord, int decks, string forCheck);
int check_direction_right(string** array, int checkRight, int xCoord, int yCoord, int decks, string forCheck);
int forCheckingSides(int checkUp, int checkDown, int checkLeft, int checkRight, int direction);