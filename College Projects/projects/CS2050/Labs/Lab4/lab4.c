#include "lab4.h"

//this function takes a long double array with a hidden size,
//calculates the product of each array value multiplied together,
//then places the product at the end of the array as a long long int
void calculateArrayProduct(long double *array)
{
    long long product = 1;
    int size = getArraySize(array);
    
    for(int i = 0; i < size; ++i) {
        product = (long long)(product * (array[i]));
        //printf("Product: %lld\n", product);
    }
    array += (size * sizeof(long double));
    *((long long*)array) = product;
    array -= (size * sizeof(long double));
}

//this function retrieves the product calculated by calculateArrayProduct
//by accessing the long long value at the end of the long double array
long long getArrayProduct(long double *array)
{
    return *((long long*)((long double*)array + (getArraySize(array)*sizeof(long double))));
}

//this function creates an array of (size) length, taking the size of
//your preffered data type in elemSize. in addition, this function
//stores a size variable before the index of the array and an extraBytes
//variable to be used how the user sees fit
void *createArray(int size, size_t elemSize, size_t extraBytes)
{
    void* array = malloc(size*(elemSize)+(sizeof(int))+extraBytes);

    if(array == NULL)
    {
        printf("Error: Unable to allocate memory");
        return NULL;
    }

    *((int*)array) = size;
    array += sizeof(int);

    return array;
}

//this function receives an array of any type and returns the int size
//stored before the starting index
int getArraySize(void *array)
{
    return *((int*)array-1);
}

//this function receives an array of any type and frees the allocated
//memory, accounting for an indexed size at the beginning
void freeArray(void **array)
{
    free (*(array)-(sizeof(int)));
    *array = NULL;
}

