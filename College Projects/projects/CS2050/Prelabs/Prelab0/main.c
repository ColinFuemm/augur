#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[] = {3, 5, 7, 9, 32, 74, 89, 102, 52, 9};
    int s = 10;
    int q = 9;

    printf("Return Value: %d", (arraySearch( a, s, q)));

    return 0;
}