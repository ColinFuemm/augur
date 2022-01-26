#include <stdio.h>
#include <stdlib.h>

int findLEQ(float * array, int arraySize, float num, float *sum);

int main()
{
    int size = 5;
    float a[] = {9, 1, 13.006, 6.104, 27};
    float par = 83;
    float *ptr;

    if(findLEQ(a, size, par, ptr) == 1)
    {
        printf("Error: Invalid Query");
    } 
    else printf("%f", *ptr);
}

int findLEQ(float * array, int arraySize, float num, float *sum)
{
    float lesserNum, greaterNum;
    float greatestNum, leastNum = array[0];

    for (int j = 0; j < arraySize; j++)
    {
        if(array[j] > greatestNum)
        {
            greatestNum = array[j];
        }
    }
    if (greatestNum <= num)
    {
        return 1;
    }
    else greaterNum = greatestNum;
    for (int k = 0; k < arraySize; k++)
    {
        if(array[k] < leastNum)
        {
            leastNum = array[k];
        }
    }
    if (leastNum >= num)
    {
        return 1;
    }
    for(int i = 0; i < arraySize; i++)
    {
        if(array[i] > num && array[i] < greaterNum)
        {
            greaterNum = array[i];
        }
        if(array[i] < num && array[i] > lesserNum)
        {
            lesserNum = array[i];
        }
    }
    
    *sum = (lesserNum + greaterNum);
    return 0;
}