// Online C compiler to run C program online
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define ARR_MAX 40
#define SMALL_BUF_LEN 6

//Arithmetic -> ()
//           *, /, %
//           + , -

//Relational Operators:
// <, <= , >, >=

//Logical Operators:
//&& (Logical AND) (True only if both are true, false otherwise)
//|| (Logical OR) (False only when both are false, true otherwise)
//!  (Logical NOT) (Invert the value)

//Input an array of size N
// If there are more than 2 sets of elements with the same value return true
//Else return false
// 1,2,3,4  -> false
// 1,1, 2, 3 -> false
// 1,1,2,2 -> true
// 1,1,1,2 ->false

void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void bubbleSort(int arr[], int n)
{
    for(int j, i = 0; i<n-1;i++)
    {
        for(j = i+1; j<n;j++)
          if(arr[i]>arr[j])
            swap( &arr[i], &arr[j]);
        
    }
}

//Call sort before getResult to ensure elements are sorted
//Function to return true if there are at least 2 sets of repeated elements
bool getResult(const int arr[], int size)
{
    int countRepeated = 0, startIdx = 0, endIdx =0;
	for(int i = 1; i<size; i++)
	{
		if(arr[startIdx] == arr[i])
		{
			 endIdx = i;
		}
		else if(startIdx!=endIdx)
		{
			countRepeated++;
			startIdx = i;
			endIdx = i;
		}
	}
    if(countRepeated >=2)
        return true;
    
    return false;
}


int main() {
    // Write C code here
    //printf("Try programiz.pro");
	int arr[ARR_MAX], count=0;
	char buf[SMALL_BUF_LEN];
	printf("\n Enter some numbers, stop to terminate :");
    do
    {
		fgets(buf, SMALL_BUF_LEN, stdin);
        buf[strlen(buf)-1]='\0';
		if(!strcmp(buf, "stop"))
			break;
        arr[count++] =atoi(buf);
        
    }while(1);
	
	bubbleSort(arr, count);
	
	getResult(arr, count)?(printf("\n Array contains at least 2 "
	"sets of repeated elements \n")):(printf("\n Array does not contain more than 2 sets of repeated elements \n"));
	
    return 0;
}