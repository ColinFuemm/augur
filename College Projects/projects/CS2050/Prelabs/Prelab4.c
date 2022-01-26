#include <stdio.h>
#include <stdlib.h>

void* createArray(int size, int dataTypeSize);
int getArraySize(void* array);
void freeArray(void** array);

int main()
{
    double* rainfall = createArray(8, sizeof(double));

    printf("Array Size : %d\n", getArraySize(rainfall));

    freeArray(&rainfall);
    if(rainfall == NULL) printf(":D");

    return 0;
}

void* createArray(int size, int dataTypeSize)
{
    void* array = malloc(size*(dataTypeSize)+(sizeof(int)));

    if(array == NULL)
    {
        printf("Error: Unable to allocate memory");
        return NULL;
    }

    *((int*)array) = size;
    array += sizeof(int);

    return array;
}

int getArraySize(void* array)
{
    return *((int*)array-1);
}

void freeArray(void** array)
{
    free(*(array)-(sizeof(int)));
    *array = NULL;
}