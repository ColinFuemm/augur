#include <stdio.h>
#include <stdlib.h>

float * readFloatFileIntoArray(FILE *fptr, int length);
void freeFloatArray(float **array);

char* filename = "floats.txt";

int main()
{
    FILE *file = fopen(filename, "r");
    if(!file) {
		fprintf(stderr, "The file [ %s ] was not successfully opened\n", filename);
		return -1;
	}

    int length;
    fscanf(file, "%d", &length);
    printf("Length: %d\n", length);

    float *array = readFloatFileIntoArray(file, length);
    if(array == NULL) return -2;
    for(int i = 0; i < length; i++)
    {
        printf("%.3f\n", *(array + i));
    }

    freeFloatArray(&array);
    if(array == NULL) printf(":D\n");

    fclose(file);
    return 0;
}

float * readFloatFileIntoArray(FILE *fptr, int length)
{
    if (!fptr) {
        return (float*)-1;
    }

    float *array = malloc(length * sizeof(float));
    if(array == NULL)
    {
        printf("Error: Unable to allocate memory");
        return NULL;
    }

    for(int i = 0; i < length; i++)
    {
        fscanf(fptr, "%f", (array + i));
    }
    
    return array;
}

void freeFloatArray(float **array)
{
    free(*(array));
    *array = NULL;
}
