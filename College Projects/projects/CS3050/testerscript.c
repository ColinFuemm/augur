#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int k = 200;
    printf("%d", ((k % 13) + 6 * (1 + (k % 11))) % 13 );
    return 0;
}