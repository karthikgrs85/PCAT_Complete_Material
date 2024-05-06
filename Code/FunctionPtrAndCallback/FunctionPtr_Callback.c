// Online C compiler to run C program online
#include <stdio.h>
#include <stdbool.h>

bool sort_asc(int a, int b) { return a<b; }
bool sort_desc(int a, int b) { return a>b;}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
    
}

void printArr(int arr[], int n)
{
    printf("\n Elements in array :\n");
    int i;
    for( i = 0;i<n-1 ;i++)
        printf("%d ", arr[i]);
    printf("%d\n", arr[i]);
    
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



int main() {
    // Write C code here
    printf("Try programiz.pro");
    int size = 0;
    int choice = 0;
    int arr[] = {3, 5, 7, 2, 1, 6, 8, 10, 11, 9, 4, 15, 3};
    bool (*fnPtr[])(int, int) = {&sort_asc, &sort_desc};
    size = sizeof(arr) / sizeof(int);
    printf("\n Array Before Sort :\n");
    printArr(arr, size);
    
    printf("\n Enter 1 for ascending sort, 2 for descending sort :\n");
    scanf("%d",&choice);
    if(choice !=1 && choice !=2)
    {
        printf("\n Undefined input ..\n");
        return -1;
        
    }
    printf("\n Using function pointer :\n");
    quickSort(arr, 0, size-1, fnPtr[choice-1]);
    
    printArr(arr, size);
    
    return 0;
}