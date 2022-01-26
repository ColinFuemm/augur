#include "lab1.h"

// Required code goes here


int avgWithin(float *array, int size, float *result, int beforeIndex, int afterIndex)
{
    float count = 0;
	float sum = 0;
	
	for(int i = 0; i < afterIndex; i++)
	{
		if( i > beforeIndex)
			{
				sum += array[i];
				count++;	
			}
	}
	if(count == 0)
	{
		return 0;
	}
	float total = (float)(sum/count);
	*result = total;
	printf("Average: %f\n", (*result = total));
	
	return 1;
}