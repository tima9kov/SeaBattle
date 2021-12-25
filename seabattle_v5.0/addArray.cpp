#include "addArray.h"
#include "enums.h"

string** add_array()
{
    string** array;
    array = new string * [AMOUNT_OF_CELLS]; 
    for (int i = 0; i < AMOUNT_OF_CELLS; i++) {
        array[i] = new string[AMOUNT_OF_CELLS];
    }
    return array;
}