#pragma once
#include <string>
using namespace std;
void drawsaboatup(string** array, int xPlayer, int yPlayer, int playerDecks);
void drawsaboatdown(string** array, int xPlayer, int yPlayer, int playerDecks);
void drawsaboatleft(string** array, int xPlayer, int yPlayer, int playerDecks);
void drawsaboatright(string** array, int xPlayer, int yPlayer, int playerDecks);
void ships_output(string** array, int x, int y);
void ship_for_choice(int outputX, int outputY, int decks);