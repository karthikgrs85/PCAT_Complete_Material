#include <stdio.h>

#define MAX_LEN 50

void printArr(int arr[], int n)
{
    printf("\n Elements in array :\n");
    int i;
    for( i = 0;i<n-1 ;i++)
        printf("%d ", arr[i]);
    printf("%d\n", arr[i]);
    
}

void merge_asc(int arr[], int p, int q, int r)
{
    //p...q  -> L1[]
    //q+1..r -> L2[]
    int i, j, k, n1 = q-p+1 , n2 = r-q;
    int L1[n1], L2[n2];
    
    //Copy all elements from arr (p..q) to L1
    for(k=0,i = p; i<=q; ++i )
    {
        L1[k++] = arr[i];
    }
    
    //Copy all elements from arr (q+1...r) to L2
    for(k=0,i = q+1; i<=r; ++i )
    {
        L2[k++] = arr[i];
    }
    
    i = j = 0;
    k = p;
    
    //Merge the two sorted subarrays into arr
    while(i<n1 && j<n2)
    {
        if(L1[i]<=L2[j])
        {
            arr[k++]=L1[i++];
        }
        
        else 
        {
            arr[k++] = L2[j++];
        }
    }
    
    while(i<n1)
    {
        arr[k++]=L1[i++];
    }
    
    while(j<n2)
    {
        arr[k++]=L2[j++];
    }
    
    
    
}

void merge_desc(int arr[], int p, int q, int r)
{
    //p...q  -> L1[]
    //q+1..r -> L2[]
    int i, j, k, n1 = q-p+1 , n2 = r-q;
    int L1[n1], L2[n2];
    
    //Copy all elements from arr (p..q) to L1
    for(k=0,i = p; i<=q; ++i )
    {
        L1[k++] = arr[i];
    }
    
    //Copy all elements from arr (q+1...r) to L2
    for(k=0,i = q+1; i<=r; ++i )
    {
        L2[k++] = arr[i];
    }
    
    i = j = 0;
    k = p;
    
    //Merge the two sorted subarrays into arr
    while(i<n1 && j<n2)
    {
        if(L1[i]>=L2[j])
        {
            arr[k++]=L1[i++];
        }
        
        else 
        {
            arr[k++] = L2[j++];
        }
    }
    
    while(i<n1)
    {
        arr[k++]=L1[i++];
    }
    
    while(j<n2)
    {
        arr[k++]=L2[j++];
    }
    
    
    
}

void mergeSort_asc(int arr[], int low, int high)
{
    int mid =(low+high)/2;
    if(low<high)
    {
        mergeSort_asc(arr, low, mid);
        mergeSort_asc(arr, mid+1, high);
        merge_asc(arr, low, mid, high);
    }
}

void mergeSort_desc(int arr[], int low, int high)
{
    int mid =(low+high)/2;
    if(low<high)
    {
        mergeSort_desc(arr, low, mid);
        mergeSort_desc(arr, mid+1, high);
        merge_desc(arr, low, mid, high);
    }
}

int main() {
    // Write C code here
    //char name[MAX_NAME_LEN];
    int num = 0;
    int size = 0;
    int arr[] = {3, 5, 7, 2, 1, 6, 8, 10, 11, 9, 4, 15, 3};
    size = sizeof(arr) / sizeof(int);
    printf("\n Array Before Sort :\n");
    printArr(arr, size);

    mergeSort_asc(arr,0,size-1);
    
    printf("\n Array After Merge Sort Ascending :\n");
    printArr(arr,size);
    
    mergeSort_desc(arr,0,size-1);
    
    printf("\n Array After Merge Sort Descending :\n");
    printArr(arr,size);
    
    
    return 0;
}