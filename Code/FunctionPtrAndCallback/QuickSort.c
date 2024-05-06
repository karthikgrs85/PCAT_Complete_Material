#include "QuickSort.h"
#include "Array.h"
#include <stdio.h>

int partition_highpivot(int arr[], int low, int high)
{
	int pivot = high;
	int i, secondpointer = low-1;
	for(i = low; i<high; i++)
	{
		if(arr[i]<arr[pivot])
		{
			secondpointer++;
			swap(&arr[i], &arr[secondpointer]);
		}
		
	}
	secondpointer++;
	swap(&arr[high], &arr[secondpointer]);
	return secondpointer;	
}

int partition_lowpivot(int arr[], int low, int high)
{
	int pivot = low;
	int i, secondpointer = high+1;
	for(i = high; i>low; i--)
	{
		if(arr[i]>arr[pivot])
		{
			secondpointer--;
			swap(&arr[i], &arr[secondpointer]);
		}
		
	}
	secondpointer--;
	swap(&arr[low], &arr[secondpointer]);
	return secondpointer;	
}



void quickSort(int arr[], int low, int high)
{
	if(low<high)
	{
		//int pivot = partition_highpivot(arr, low, high);
		int pivot = partition_lowpivot(arr, low, high);
		
		printf("\n After partition element with pivot index = %d\n", pivot);
		printArrayFrom(arr, low, high);
		quickSort(arr, low, pivot-1);
		quickSort(arr, pivot+1, high);	
	
	}

}


