#include "lab2.h"

void printIntArray(int *array, int size) {
	printf("[ ");
	for(int i = 0; i < size; ++i) {
		printf("%d%s", array[i], ((i + 1 == size) ? "" : ", "));
	}
	printf(" ]\n");
}

char* filename = "hexadecimals.txt";

int main() {
    FILE *file = fopen(filename, "r");
    if(!file) {
		fprintf(stderr, "The file [ %s ] was not successfully opened\n", filename);
		return -1;
	}
	int *size = malloc(sizeof(int));
	
	int *array = readHexFromFile(file, size);

	printIntArray(array, *size);
	
	freeIntArray(&array);
	if(array == NULL) printf(":D\n");

	fclose(file);
	return 0;
}
