#include "Increment.h"
#include <stdio.h>

int incrVal = 1;

void printArray(int arr[], int size)
{	
	if(size ==0)
	{
		printf("\n Array Empty !...\n");
		return;
	
	}
	int i =0;
	printf("\n Elements in array :\n");
	for(;i<size-1;++i)
	{
		printf(" %d, ",arr[i]);
	
	} 
	printf("%d \n",arr[i]);
}

void incrementAllElements(int arr[], int size)
{
	static int counter = 0;
	for(int i = 0;i<size;++i)
	{
		arr[i]+=incrVal;
	
	}
	
	printf("\n Function incrementAllElements called %d times "
		"\n Current value of Global variable incrVal = %d \n",++counter, incrVal);

}
