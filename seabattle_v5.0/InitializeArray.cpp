#include <iostream>
#include <string>
#include "enums.h"
using namespace std;
void initialize_array(string** array)
{
    for (int i = 0; i < AMOUNT_OF_CELLS; i++)
    {
        for (int j = 0; j < AMOUNT_OF_CELLS; j++)
        {
            array[i][j] = EMPTY;
        }
        cout << endl;
    }
}