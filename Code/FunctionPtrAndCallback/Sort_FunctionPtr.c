#include "QuickSort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARR_MAX 50
#define TEMP_BUF 6

bool sort_asc(int a, int b) { return a<b; }
bool sort_desc(int a, int b) { return a>b;}

int main()
{
    int arr[ARR_MAX], size = 0, choice =0;
    char buf[TEMP_BUF];
    bool (*fnPtr[])(int, int) = {&sort_asc, &sort_desc};
    
    printf("\n Enter some numbers, stop to stop : \n");
    do
    {
    	fgets(buf, TEMP_BUF, stdin);
    	buf[strlen(buf)-1]='\0';
    	if(!strcmp(buf,"stop"))
    		break;    
    	arr[size++]=atoi(buf);
    
    }while(1);
    
    
    
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
    
    printf("\n Array After Sort :\n");
    printArr(arr, size);



}
