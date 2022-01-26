#include "lab3.h"

/*This function will read long long integers representing distances to 
Earth’s nearest stars into a dynamically allocated array from the given 
file pointer. The first number in the file should be interpreted as the 
size of the resulting array, and the second number in the file should 
be interpreted as the starting index of the resulting array. The starting 
index of the array is stored in the startIndex variable, and the size of 
the array is stored in the length variable, such that they both can be 
used in the calling function. The pointer returned from this function 
is offset using the startIndex variable from the calling function.*/
long long* loadStarDistances(FILE *file, int *startIndex, int *length)
{
    if (!file) {
        printf("Error: File not found.");
        return NULL;
    }
    
    fscanf(file, "%d", length);
    printf("Length: %d\n", *length);

    fscanf(file, "%d", startIndex);
    printf("Start Index: %d\n", *startIndex);
    
    long long *array = malloc(*length * sizeof(long long));
    if(array == NULL)
    {
        printf("Error: Unable to allocate memory");
        return NULL;
    }
    
    array -= (int)*startIndex;
    
    for(int i = *startIndex; i <= *length; i++)
    {
        fscanf(file, "%lld", (array + i));
    }
    
    return array;
}

/*This function takes a double long long pointeras well as the starting 
index of the given array,and frees the memory being pointed to.*/
void freeLongLongArray(long long **array, int startIndex)
{
    free(*(array)+startIndex);
    *array = NULL;
}
