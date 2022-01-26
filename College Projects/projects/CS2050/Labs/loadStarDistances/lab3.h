#include <stdio.h>
#include <stdlib.h>

#define SECT_F
long long* loadStarDistances(FILE *file, int *startIndex, int *length);
void freeLongLongArray(long long **array, int startIndex);
