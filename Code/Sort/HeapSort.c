#include "Array.h"
#include "HeapSort.h"


//heapify the function:
//for root node i select largest of arr[i], arr[2*i+1], arr[2*i+2]
//swap the largest with arr[i]

int getLargest(int arr[], int i, int n)
{
	int largest = i;
	int left_child = 2*i+1, right_child = 2*i+2;
	if(left_child<=n-1 && arr[largest] < arr[left_child])
		largest = left_child;
	if(right_child<=n-1 && arr[largest] < arr[right_child])
		largest = right_child;
	return largest;	 

}

void heapify(int arr[], int n)
{
	int i ,  largest;
	for(i = n/2 -1; i>=0; --i)
	{
		largest = getLargest(arr, i, n);
		swap(&arr[largest], &arr[i]);
	}
	
	
}

void heapSort(int arr[], int n)
{
	for(int i = n; i >=1 ;i--)
	{
		heapify(arr, i);
		swap(&arr[i-1], &arr[0]);

	}	
	
}




