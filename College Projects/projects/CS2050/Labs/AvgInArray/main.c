#include "lab1.h"

void readArray(FILE *file, int size, float *array);
void printArray(float *array, int size);

char *filename = "numbers.txt";

int main() {
    // opening the file
	FILE *file = fopen(filename, "r");
	if(!file) {
		fprintf(stderr, "The file [ %s ] was not successfully opened\n", filename);
		return -1;
	}

    // reading the array size and creating the array
	int size;
	fscanf(file, "%d", &size);
	float array[20];
	readArray(file, size, array);
	printArray(array, size);

    // --- Your function call goes here ---
	float *result = 0;
	int beforeIndex = 1;
	int afterIndex = 3;

	if (avgWithin(array, size, result, beforeIndex, afterIndex) == 1)
	{
		printf("The result is %f", *result);
	}
	else { printf("Error: No values found.");}

	fclose(file);
}

void readArray(FILE *file, int size, float *array) {
	if(!file) {
		return;
	}
	for(int i = 0; i < size; ++i) {
		fscanf(file, "%f", (array + i));
	}
}

void printArray(float *array, int size) {
    printf("[ ");
	for(int i = 0; i < size; ++i) {
		printf("%.2f%s", array[i], ((i + 1 == size) ? "" : ", "));
	}
    puts(" ]");
}
