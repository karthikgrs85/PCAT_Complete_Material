#include "QuickSort.h"

#include <stdio.h>


void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
    
}

void printArr(int arr[], int size)
{
	int i = 0;
	printf("\n Elements in Array :\n");
	for(; i<size-1; i++)
	{
		printf(" %d, ", arr[i]);
	} 
	printf(" %d \n\n", arr[i]);
}

int partition_highpivot(int arr[], int low, int high, bool (*fn)(int, int))
{
	int pivot = high;
	int i, secondpointer = low-1;
	for(i = low; i<high; i++)
	{
		if(fn(arr[i],arr[pivot]))
		{
			secondpointer++;
			swap(&arr[i], &arr[secondpointer]);
		}
		
	}
	secondpointer++;
	swap(&arr[high], &arr[secondpointer]);
	return secondpointer;	
}

int partition_lowpivot(int arr[], int low, int high, bool (*fn)(int, int))
{
	int pivot = low;
	int i, secondpointer = high+1;
	for(i = high; i>low; i--)
	{
		if(fn(arr[i],arr[pivot]))
		{
			secondpointer--;
			swap(&arr[i], &arr[secondpointer]);
		}
		
	}
	secondpointer--;
	swap(&arr[low], &arr[secondpointer]);
	return secondpointer;	
}



void quickSort(int arr[], int low, int high,  bool (*fn)(int, int) )
{
	if(low<high)
	{
		//int pivot = partition_highpivot(arr, low, high);
		int pivot = partition_highpivot(arr, low, high, fn);
		
		/*printf("\n After partition element with pivot index = %d\n", pivot);
		*/
		quickSort(arr, low, pivot-1, fn);
		quickSort(arr, pivot+1, high, fn);	
	
	}

}



