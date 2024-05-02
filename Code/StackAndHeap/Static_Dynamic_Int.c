// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_INT_ARR 50
#define BUF_LEN 50

void createStaticIntArray(int arr[], int *size)
{
    printf("\n Enter number of elements for static int array :");
    scanf("%d",size);
    printf("\n Enter the elements :\n");
    if(*size > MAX_INT_ARR)
        *size = MAX_INT_ARR;
    for(int i = 0; i< *size; ++i)
        scanf("%d",arr+i);
}

void createDynamicIntArray(int **arr, int *size)
{
    printf("\n Enter number of elements for dynamic int array :");
    scanf("%d",size);
    *arr = (int*)calloc(*size, sizeof(int));
    printf("\n Enter the elements :\n");
    for(int i = 0; i< *size; ++i)
        scanf("%d",(*arr)+i);
        //equivalent of scanf("%d",&arr[i]);
    
}
void createDynamicIntArray_1(int *arr, int *size)
{
    printf("\n Enter number of elements for dynamic int array :");
    scanf("%d",size);
    arr = (int*)calloc(*size, sizeof(int));
    printf("\n Enter the elements :\n");
    for(int i = 0; i< *size; ++i)
        scanf("%d",arr+i);
        //equivalent of scanf("%d",&arr[i]);
    
}

void printAllElements(const int arr[], int size)
{
    if(size==0)
    {
        printf("\n Array Empty !...");
        return;
    }
    int i;
    printf("\n Elements in Array :\n");
    for( i =0; i<size-1;++i)
    {
        printf(" %d, ",arr[i]);
    }
    printf(" %d", arr[i]);
}


int main() {
    // Write C code here
    int staticArr[MAX_INT_ARR];
    int *dynamicArr = NULL;
    
    int size_static=0, size_dynamic = 0;
    
    createStaticIntArray(staticArr, &size_static);
    
    printf("\n Static Array :");
    printAllElements(staticArr, size_static);
    
    createDynamicIntArray(&dynamicArr, &size_dynamic);
    
    //The below statement will not work
    //createDynamicIntArray_1(dynamicArr, &size_dynamic);
    
    printf("\n Dynamic Array :");
    printAllElements(dynamicArr, size_dynamic);
    //printf("Try programiz.pro");
    free(dynamicArr);
    
    
    return 0;
}