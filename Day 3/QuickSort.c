#include <stdio.h>

void printArr(int arr[], int n)
{
    printf("\n Elements in array :\n");
    int i;
    for( i = 0;i<n-1 ;i++)
        printf("%d ", arr[i]);
    printf("%d\n", arr[i]);
    
}

void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

int partition_high(int arr[], int low, int high)
{
    int pivot = arr[high], i= low-1, j;
    for(j = low; j <high; ++j)
    {
        if(arr[j] <= pivot)
            {
                i++;
                swap(arr+i, arr+j);
            }
    }
    ++i;
    swap(arr+high, arr+i);
    return i;
}

int partition_low(int arr[], int low, int high)
{
    int pivot = arr[low], i = high+1, j;
    
    for(j = high; j> low; j--)
    {
        if(arr[j]>=pivot)
        {
            i--;
            swap(arr+i, arr+j);
        }
    }
    --i;
    swap(arr+i, arr+low);
    return i;
    
}

int partition_high_desc(int arr[], int low, int high)
{
    int pivot = arr[high], i= low-1, j;
    for(j = low; j <high; ++j)
    {
        if(arr[j] >= pivot)
            {
                i++;
                swap(arr+i, arr+j);
            }
    }
    ++i;
    swap(arr+high, arr+i);
    return i;
}



int partition_low_desc(int arr[], int low, int high)
{
    int pivot = arr[low], i = high+1, j;
    
    for(j = high; j> low; j--)
    {
        if(arr[j]<=pivot)
        {
            i--;
            swap(arr+i, arr+j);
        }
    }
    --i;
    swap(arr+i, arr+low);
    return i;
    
}

void quickSort(int arr[], int low, int high)
{
    int pivot = 0;
    if(low<high)
    {
        pivot = partition_high(arr, low, high);
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
    }
}

void quickSort_desc(int arr[], int low, int high)
{
    int pivot = 0;
    if(low<high)
    {
        pivot = partition_high_desc(arr, low, high);
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
    }
}

int main() {
    // Write C code here
    //char name[MAX_NAME_LEN];
    int num = 0;
    int arr[] = {3, 5, 7, 2, 1, 6, 8, 10, 11, 9, 4, 15, 3};
    printf("\n Array Before Sort :\n");
    printArr(arr, 13);

    quickSort(arr, 0, 12);
    printf("\n Array After Quick Sort Ascending :\n");
    printArr(arr,13);
    
    quickSort_desc(arr,0,12);
    printf("\n Array After Quick Sort Descending :\n");
    printArr(arr,13);
    return 0;
}