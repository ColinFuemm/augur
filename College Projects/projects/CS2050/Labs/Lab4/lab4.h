#include <stdio.h>
#include <stdlib.h>

#define SECT_F
void calculateArrayProduct(long double *array);
long long getArrayProduct(long double *array);
void *createArray(int size, size_t elemSize, size_t extraBytes);
int getArraySize(void *array);
void freeArray(void **array);
