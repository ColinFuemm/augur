#include "lab2.h"

/*This function takes a file pointer and an array size, then reads
 a file of hexadecimal integers and places them into an array.
 It reads the size, then allocates memory accordingly, before
 scanning through the array and getting each number.*/
int *readHexFromFile(FILE *file, int *length)
{
    if (!file) {
        printf("Error: File not found.");
        return NULL;
    }
    
    fscanf(file, "%d", length);
    printf("Length: %d\n", *length);

    int *array = malloc(*length * sizeof(int));
    if(array == NULL)
    {
        printf("Error: Unable to allocate memory");
        return NULL;
    }
    
    for(int i = 0; i < *length; i++)
    {
        fscanf(file, "%x", (array + i));
    }
    
    return array;
}

void freeIntArray(int **array)
{
    free(*(array));
    *array = NULL;
}