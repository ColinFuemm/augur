#include "lab0.h"

/* REQUIRED CODE GOES HERE */

int countOccurrences(int size, int array[], int query)
{
    int x = 0;

    for(int i = 0; i < size; i++)
    {
        if(query == array[i]) x++;
    }

    return x;
}