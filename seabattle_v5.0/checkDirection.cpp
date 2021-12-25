#include "checkDirection.h"
#include "enums.h"

int check_direction_down(string** array, int checkDown, int xCoord, int yCoord, int decks, string forCheck)
{
	checkDown = 0;

	if ((yCoord + decks) > AMOUNT_OF_CELLS) {
		checkDown = 1;
	} 	
	if (xCoord == 0 && yCoord == 0) {
		for (int x = xCoord; x <= xCoord + 1; ++x) {
			for (int y = yCoord; y <= (yCoord + decks); ++y) {
				if (array[y][x] == forCheck)
					checkDown = 1;
			}
		}
	}
	
	if (xCoord == 0 && yCoord > 0 && yCoord + decks < AMOUNT_OF_CELLS) {
		for (int x = xCoord; x <= xCoord + 1; ++x) {
			for (int y = yCoord - 1; y <= (yCoord + decks); ++y) {
				if (array[y][x] == forCheck)
					checkDown = 1;
			}
		}
	}
	
	if (xCoord == 0 && yCoord + decks == AMOUNT_OF_CELLS) {
		for (int x = xCoord; x <= xCoord + 1; ++x) {
			for (int y = yCoord - 1; y <= (yCoord + decks - 1); ++y) {
				if (array[y][x] == forCheck)
					checkDown = 1;
			}
		}
	}
	
	if (xCoord == AMOUNT_OF_CELLS - 1 && yCoord == 0) {
		for (int x = xCoord - 1; x <= xCoord; ++x) {
			for (int y = yCoord; y <= (yCoord + decks); ++y) {
				if (array[y][x] == forCheck)
					checkDown = 1;
			}
		}
	}
	
	if (xCoord == AMOUNT_OF_CELLS - 1 && yCoord > 0 && yCoord + decks < AMOUNT_OF_CELLS) {
		for (int x = xCoord - 1; x <= xCoord; ++x) {
			for (int y = yCoord - 1; y <= (yCoord + decks); ++y) {
				if (array[y][x] == forCheck)
					checkDown = 1;
			}
		}
	}
	
	if (xCoord == AMOUNT_OF_CELLS - 1 && yCoord + decks == AMOUNT_OF_CELLS) {
		for (int x = xCoord - 1; x <= xCoord; ++x) {
			for (int y = yCoord - 1; y <= (yCoord + decks - 1); ++y) {
				if (array[y][x] == forCheck)
					checkDown = 1;
			}
		}
	}
	
	if (xCoord > 0 && xCoord < AMOUNT_OF_CELLS - 1 && yCoord == 0) {
		for (int x = xCoord - 1; x <= xCoord + 1; ++x) {
			for (int y = yCoord; y <= (yCoord + decks); ++y) {
				if (array[y][x] == forCheck)
					checkDown = 1;
			}
		}
	}
	
	if (xCoord > 0 && xCoord < AMOUNT_OF_CELLS - 1 && yCoord + decks == AMOUNT_OF_CELLS) {
		for (int x = xCoord - 1; x <= xCoord + 1; ++x) {
			for (int y = yCoord - 1; y <= (yCoord + decks - 1); ++y) {
				if (array[y][x] == forCheck)
					checkDown = 1;
			}
		}
	}
	
	if (xCoord > 0 && xCoord < AMOUNT_OF_CELLS - 1 && yCoord + decks < AMOUNT_OF_CELLS && yCoord > 0) {
		for (int x = xCoord - 1; x <= xCoord + 1; ++x) {
			for (int y = yCoord - 1; y <= (yCoord + decks); ++y) {
				if (array[y][x] == forCheck)
					checkDown = 1;
			}
		}
	}
	return checkDown;
}

int check_direction_left(string** array, int checkLeft, int xCoord, int yCoord, int decks, string forCheck)
{
	checkLeft = 0;
	
	if (xCoord - decks + 1 < 0) {
		checkLeft = 1;
	}
	
	if (xCoord == AMOUNT_OF_CELLS - 1 && yCoord == 0) {
		for (int x = xCoord - decks; x <= xCoord; ++x) {
			for (int y = yCoord; y <= yCoord + 1; ++y) {
				if (array[y][x] == forCheck)
					checkLeft = 1;
			}
		}
	}
	
	if (xCoord - decks >= 0 && xCoord < AMOUNT_OF_CELLS - 1 && yCoord == 0) {
		for (int x = xCoord - decks; x <= xCoord + 1; ++x) {
			for (int y = yCoord; y <= yCoord + 1; ++y) {
				if (array[y][x] == forCheck)
					checkLeft = 1;
			}
		}
	}
	
	if (xCoord - decks + 1 == 0 && yCoord == 0) {
		for (int x = xCoord - decks + 1; x <= xCoord + 1; ++x) {
			for (int y = yCoord; y <= yCoord + 1; ++y) {
				if (array[y][x] == forCheck)
					checkLeft = 1;
			}
		}
	}
	
	if (xCoord == AMOUNT_OF_CELLS - 1 && yCoord == AMOUNT_OF_CELLS - 1) {
		for (int x = xCoord - decks; x <= xCoord; ++x) {
			for (int y = yCoord - 1; y <= yCoord; ++y) {
				if (array[y][x] == forCheck)
					checkLeft = 1;
			}
		}
	}
	
	if (xCoord - decks >= 0 && xCoord < AMOUNT_OF_CELLS - 1 && yCoord == 9) {
		for (int x = xCoord - decks; x <= xCoord + 1; ++x) {
			for (int y = yCoord - 1; y <= yCoord; ++y) {
				if (array[y][x] == forCheck)
					checkLeft = 1;
			}
		}
	}
	
	if (xCoord - decks + 1 == 0 && yCoord == AMOUNT_OF_CELLS - 1) {
		for (int x = xCoord - decks + 1; x <= xCoord + 1; ++x) {
			for (int y = yCoord - 1; y <= yCoord; ++y) {
				if (array[y][x] == forCheck)
					checkLeft = 1;
			}
		}
	}

	if (xCoord == AMOUNT_OF_CELLS - 1 && yCoord > 0 && yCoord < AMOUNT_OF_CELLS - 1) {
		for (int x = xCoord - decks; x <= xCoord; ++x) {
			for (int y = yCoord - 1; y <= yCoord + 1; ++y) {
				if (array[y][x] == forCheck)
					checkLeft = 1;
			}
		}
	}

	if (xCoord - decks + 1 == 0 && yCoord < AMOUNT_OF_CELLS - 1 && yCoord > 0) {
		for (int x = xCoord - decks + 1; x <= xCoord + 1; ++x) {
			for (int y = yCoord - 1; y <= yCoord + 1; ++y) {
				if (array[y][x] == forCheck)
					checkLeft = 1;
			}
		}
	}
	
	if (xCoord - decks + 1 > 0 && xCoord < AMOUNT_OF_CELLS - 1 && yCoord < AMOUNT_OF_CELLS - 1 && yCoord > 0) {
		for (int x = xCoord - decks; x <= xCoord + 1; ++x) {
			for (int y = yCoord - 1; y <= yCoord + 1; ++y) {
				if (array[y][x] == forCheck)
					checkLeft = 1;
			}
		}
	}
	return checkLeft;
}

int check_direction_right(string** array, int checkRight, int xCoord, int yCoord, int decks, string forCheck) {
	checkRight = 0;

	
	if (xCoord + decks > AMOUNT_OF_CELLS) {
		checkRight = 1;
	}

	
	if (xCoord == 0 && yCoord == 0) {

		for (int x = xCoord; x <= (xCoord + decks); ++x) {
			for (int y = yCoord; y <= yCoord + 1; ++y) {
				if (array[y][x] == forCheck)
					checkRight = 1;
			}
		}
	}

	if (xCoord > 0 && xCoord + decks < AMOUNT_OF_CELLS && yCoord == 0) {

		for (int x = xCoord - 1; x <= (xCoord + decks); ++x) {
			for (int y = yCoord; y <= yCoord + 1; ++y) {
				if (array[y][x] == forCheck)
					checkRight = 1;
			}
		}
	}

	if (yCoord == 0 && xCoord + decks == AMOUNT_OF_CELLS) {

		for (int x = (xCoord - 1); x <= (xCoord + decks - 1); ++x) {
			for (int y = yCoord; y <= yCoord + 1; ++y) {
				if (array[y][x] == forCheck)
					checkRight = 1;
			}
		}
	}

	if (xCoord == 0 && yCoord == AMOUNT_OF_CELLS - 1) {
		for (int x = xCoord; x <= (xCoord + decks); ++x) {
			for (int y = yCoord - 1; y <= yCoord; ++y) {
				if (array[y][x] == forCheck)
					checkRight = 1;
			}
		}
	}

	if (xCoord > 0 && xCoord + decks < AMOUNT_OF_CELLS && yCoord == AMOUNT_OF_CELLS - 1) {
		for (int x = xCoord - 1; x <= (xCoord + decks); ++x) {
			for (int y = yCoord - 1; y <= yCoord; ++y) {
				if (array[y][x] == forCheck)
					checkRight = 1;
			}
		}
	}

	if (yCoord == AMOUNT_OF_CELLS - 1 && xCoord + decks == AMOUNT_OF_CELLS) {
		for (int x = xCoord - 1; x <= (xCoord + decks - 1); ++x) {
			for (int y = yCoord - 1; y <= yCoord; ++y) {
				if (array[y][x] == forCheck)
					checkRight = 1;
			}
		}
	}
	
	if (xCoord == 0 && yCoord > 0 && yCoord < AMOUNT_OF_CELLS - 1) {
		for (int x = xCoord; x <= xCoord + decks; ++x) {
			for (int y = yCoord - 1; y <= yCoord + 1; ++y) {
				if (array[y][x] == forCheck)
					checkRight = 1;
			}
		}
	}

	if (xCoord + decks == AMOUNT_OF_CELLS && yCoord > 0 && yCoord < AMOUNT_OF_CELLS - 1) {
		for (int x = xCoord - 1; x <= (xCoord + decks - 1); ++x) {
			for (int y = yCoord - 1; y <= yCoord + 1; ++y) {
				if (array[y][x] == forCheck)
					checkRight = 1;
			}
		}
	}
	
	if (xCoord > 0 && xCoord + decks < AMOUNT_OF_CELLS && yCoord > 0 && yCoord < AMOUNT_OF_CELLS - 1) {
		for (int x = xCoord - 1; x <= xCoord + decks; ++x) {
			for (int y = yCoord - 1; y <= yCoord + 1; ++y) {
				if (array[y][x] == forCheck)
					checkRight = 1;
			}
		}
	}

	return checkRight;
}

int check_direction_up(string** array, int checkUp, int xCoord, int yCoord, int decks, string forCheck)
{
	checkUp = 0;

	if (yCoord - decks + 1 < 0) {
		checkUp = 1;
	}

	
	if (xCoord == 0 && yCoord == AMOUNT_OF_CELLS - 1) {
		for (int x = xCoord; x <= xCoord + 1; ++x) {
			for (int y = yCoord - decks; y <= yCoord; ++y) {
				if (array[y][x] == forCheck)
					checkUp = 1;
			}
		}
	}

	if (xCoord == 0 && yCoord - decks >= 0 && yCoord < AMOUNT_OF_CELLS - 1) {
		for (int x = xCoord; x <= xCoord + 1; ++x) {
			for (int y = yCoord - decks; y <= (yCoord + 1); ++y) {
				if (array[y][x] == forCheck)
					checkUp = 1;
			}
		}
	}
	
	if (xCoord == 0 && yCoord - decks + 1 == 0) {
		for (int x = xCoord; x <= xCoord + 1; ++x) {
			for (int y = yCoord - decks + 1; y <= yCoord + 1; ++y) {
				if (array[y][x] == forCheck)
					checkUp = 1;
			}
		}
	}
	
	if (xCoord == AMOUNT_OF_CELLS - 1 && yCoord == AMOUNT_OF_CELLS - 1) {
		for (int x = xCoord - 1; x <= xCoord; ++x) {
			for (int y = yCoord - decks; y <= yCoord; ++y) {
				if (array[y][x] == forCheck)
					checkUp = 1;
			}
		}
	}
	
	if (xCoord == AMOUNT_OF_CELLS - 1 && yCoord - decks >= 0 && yCoord < AMOUNT_OF_CELLS - 1) {
		for (int x = xCoord - 1; x <= xCoord; ++x) {
			for (int y = yCoord - decks; y <= (yCoord + 1); ++y) {
				if (array[y][x] == forCheck)
					checkUp = 1;
			}
		}
	}
	
	if (xCoord == AMOUNT_OF_CELLS - 1 && yCoord - decks + 1 == 0) {
		for (int x = xCoord - 1; x <= xCoord; ++x) {
			for (int y = (yCoord - decks + 1); y <= (yCoord + 1); ++y) {
				if (array[y][x] == forCheck)
					checkUp = 1;
			}
		}
	}
	
	if (xCoord > 0 && xCoord < AMOUNT_OF_CELLS - 1 && yCoord == AMOUNT_OF_CELLS - 1) {
		for (int x = xCoord - 1; x <= xCoord + 1; ++x) {
			for (int y = yCoord - decks; y <= yCoord; ++y) {
				if (array[y][x] == forCheck)
					checkUp = 1;
			}
		}
	}
	
	if (xCoord > 0 && xCoord < AMOUNT_OF_CELLS - 1 && yCoord - decks + 1 == 0) {
		for (int x = xCoord - 1; x <= xCoord + 1; ++x) {
			for (int y = yCoord - decks + 1; y <= (yCoord + 1); ++y) {
				if (array[y][x] == forCheck)
					checkUp = 1;
			}
		}
	}
	
	if (xCoord > 0 && xCoord < AMOUNT_OF_CELLS - 1 && yCoord - decks + 1 > 0 && yCoord < AMOUNT_OF_CELLS - 1) {
		for (int x = xCoord - 1; x <= xCoord + 1; ++x) {
			for (int y = yCoord - decks; y <= (yCoord + 1); ++y) {
				if (array[y][x] == forCheck)
					checkUp = 1;
			}
		}
	}
	return checkUp;
}

int forCheckingSides(int checkUp, int checkDown , int checkLeft , int checkRight, int direction) {
	if (checkUp == 1 && checkDown == 1 && checkLeft == 1 && checkRight == 0) {
		direction = 4;
	}//1.
	if (checkUp == 1 && checkDown == 1 && checkLeft == 0 && checkRight == 1) {
		direction = 3;
	}//2.
	if (checkUp == 1 && checkDown == 1 && checkLeft == 0 && checkRight == 0) {
		direction = (rand() % 2) ? 3 : 4;
	}//3.
	if (checkUp == 1 && checkDown == 0 && checkLeft == 1 && checkRight == 1) {
		direction = 2;
	}//4.
	if (checkUp == 1 && checkDown == 0 && checkLeft == 1 && checkRight == 0) {
		direction = (rand() % 2) ? 2 : 4;
	}//5.
	if (checkUp == 1 && checkDown == 0 && checkLeft == 0 && checkRight == 1) {
		direction = (rand() % 2) ? 2 : 3;
	}//6.
	if (checkUp == 1 && checkDown == 0 && checkLeft == 0 && checkRight == 0) {
		int arr[3]{ 2 , 3 , 4 };
		int l = rand() % 3;
		direction = arr[l];
	}//7.
	if (checkUp == 0 && checkDown == 1 && checkLeft == 1 && checkRight == 1) {
		direction = 1;
	}//8.
	if (checkUp == 0 && checkDown == 1 && checkLeft == 1 && checkRight == 0) {
		direction = (rand() % 2) ? 1 : 4;
	}//9.
	if (checkUp == 0 && checkDown == 1 && checkLeft == 0 && checkRight == 1) {
		direction = (rand() % 2) ? 1 : 3;
	}//10.
	if (checkUp == 0 && checkDown == 1 && checkLeft == 0 && checkRight == 0) {
		int arr[3]{ 1 , 3 , 4 };
		int l = rand() % 3;
		direction = arr[l];
	}//11.
	if (checkUp == 0 && checkDown == 0 && checkLeft == 1 && checkRight == 1) {
		direction = (rand() % 2) ? 1 : 2;
	}//12.
	if (checkUp == 0 && checkDown == 0 && checkLeft == 1 && checkRight == 0) {
		int arr[3]{ 1 , 2 , 4 };
		int l = rand() % 3;
		direction = arr[l];
	}//13.
	if (checkUp == 0 && checkDown == 0 && checkLeft == 0 && checkRight == 1) {
		int arr[3]{ 1 , 2 , 3 };
		int l = rand() % 3;
		direction = arr[l];
	}//14.
	if (checkUp == 0 && checkDown == 0 && checkLeft == 0 && checkRight == 0) {
		int arr[4]{ 1 , 2 , 3 , 4 };
		int l = rand() % 4;
		direction = arr[l];
	}//15.
	return direction;
}