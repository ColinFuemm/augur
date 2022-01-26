#include "lab3.h"

char* filename = "starDistances.txt";

int main()
{
    FILE *file = fopen(filename, "r");
    if(!file) {
		fprintf(stderr, "The file [ %s ] was not successfully opened\n", filename);
		return -1;
	}
    int *size = malloc(sizeof(int));
    int *index = malloc(sizeof(int));

    long long* starDistances = loadStarDistances(file, index, size);

    printf("Size: %d\n", *size);
    for (int i = *index; i <= *size; i++) {
        printf("Star %d: %lld\n", i, starDistances[i]);
    }
   
    freeLongLongArray(&starDistances, *index);
    if(starDistances == NULL) printf(":D");

    fclose(file);
    return 0;
}
