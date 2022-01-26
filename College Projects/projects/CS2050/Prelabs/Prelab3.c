#include <stdio.h>
#include <stdlib.h>

double* createDoubleArray(int minIndex, int maxIndex);
void freeDoubleArray(double** array, int index);

char* filename = "rainfall.txt";

int main()
{
    FILE *file = fopen(filename, "r");
    if(!file) {
		fprintf(stderr, "The file [ %s ] was not successfully opened\n", filename);
		return -1;
	}
    int min = 1;
    int max = 20;
    double* rainfall = createDoubleArray(min, max);

    for (int i = min; i <= max; i++) {
        fscanf(file, "%lf", &rainfall[i]);
    }

    double sum = 0.0;
    for (int i = 3; i < 13; i++) sum += rainfall[i];
    printf("Average: %lf\n", sum/10);

    freeDoubleArray(&rainfall, min);
    if(rainfall == NULL) printf(":D");

    fclose(file);
    return 0;
}

double* createDoubleArray(int minIndex, int maxIndex)
{
    double* array = malloc((maxIndex-minIndex)*sizeof(double));

    if(array == NULL)
    {
        printf("Error: Unable to allocate memory");
        return NULL;
    }

    array -= minIndex;

    return array;
}

void freeDoubleArray(double** array, int index)
{
    free(*(array)+index);
    *array = NULL;
}