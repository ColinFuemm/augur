#include "lab4.h"

void printLongDoubleArray(long double *array) {
	printf("Printing array\n[");
	for(int i = 0; i < getArraySize(array); ++i) {
		printf("%lf%s", array[i], ((i + 1 == getArraySize(array)) ? " ]\n" : ", "));
	}
}

int main() {
    long double *array = createArray(10, sizeof(long double), sizeof(long long));

    for(int i = 1; i < 10; ++i) {
        array[i] = 5.364*(long double)i;
    }
    
    calculateArrayProduct(array);
    printf("Array product is %lld\n", getArrayProduct(array));
    printLongDoubleArray(array);
    freeArray((void*)&array);
    if(array == NULL) printf(":D");

    return 0;
}
