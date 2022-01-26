#include <stdio.h>
#include <stdlib.h>

int arraySearch(int *array, int size, int query);

int arraySearch(int *array, int size, int query)
{
    int x = 0;

    for(int i = 0; i < size; i++)
    {
        if(query == array[i]) x++;
    }

    return x;
}