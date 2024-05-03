#include "2DIntArray.h"
#include <stdio.h>
#include <stdlib.h>

void initializeDynamicIntArray(int ***arr, int *rows, int *cols)
{
	printf("\n Enter number of rows and columns for Dynamic Array:");
	scanf("%d %d",rows, cols);
	
	if(*rows<1 || *cols<1)
	{
		printf("\n Invalid input !....\n");
		return;
	}

	*arr = (int**)calloc(*rows, sizeof(int*));
	
	for(int j,  i = 0; i<*rows; ++i)
	{
		(*arr)[i] = (int*)calloc(*cols, sizeof(int));
		printf("\n Enter elements for row %d ", i+1);
		for(j = 0; j <*cols; ++j)
		{
			printf("\n Enter element (%d,%d) :",i+1, j+1);
			scanf("%d",((*arr)[i]+j));
	
		}
	
	}

}

void getSumOfTwoDynamicArrays(int ***arrSum, const int **arr1, const int **arr2, int rows, int cols)
{
	if(rows<1 || cols<1)
	{
		printf("\n Invalid input !....\n");
		return;
	}

	*arrSum = (int**)calloc(rows, sizeof(int*));
	
	for(int j,  i = 0; i<rows; ++i)
	{
		(*arrSum)[i] = (int*)calloc(cols, sizeof(int));
		for(j = 0; j <cols; ++j)
		{
			(*arrSum)[i][j]= arr1[i][j]+arr2[i][j];
	
		}
	
	}


}

void printDynamicIntArray(const int **arr, int rows, int cols)
{
	
	long int size = sizeof(arr);
	if(rows==0 || cols==0 || arr==NULL)
	{
		printf("\n Array Empty or not initialized !..\n");
		return;
	}

	printf("\n Dynamic Array Elements :\n");
	printf("\n---------------------------\n");
	for(int j, i = 0; i<rows;i++)
	{
				
		for(j = 0 ;j<cols; ++j)
		{
			printf(" %d ",arr[i][j]);
 			size+=sizeof(arr[i][j]);
		}
		printf("\n");
	
	
	
	}
	printf("---------------------------\n");
	printf("\n The total size of Dynamic Array = %lu \n",size);


}


void deleteDynamicIntArray(int ***arr, int rows, int cols)
{
	for(int i = 0; i<rows; i++)
	{
		free((*arr)[i]);
		printf("\n Deleting row %d \n",i+1);
		
	}
	free(*arr);
	printf("\n Deleting dynamic array \n");

}


void initializeStaticIntArray(int arr[][MAX_INT_ARR_SIZE], int *rows, int *cols)
{

	printf("\n Enter number of rows and columns for Static Array:");
	scanf("%d %d",rows, cols);

	if(*rows>MAX_INT_ARR_SIZE || *cols >MAX_INT_ARR_SIZE ||*rows<1 || *cols<1)
	{
		printf("\n Invalid input !....\n");
		return;
	
	}
	
	for(int j,  i = 0; i<*rows; ++i)
	{
		printf("\n Enter elements for row %d ", i+1);
		for(j = 0; j <*cols; ++j)
		{
			printf("\n Enter element (%d,%d) :",i+1, j+1);
			scanf("%d",&arr[i][j]);
	
		}
	
	}




}

void printStaticIntArray(const int arr[][MAX_INT_ARR_SIZE], int rows, int cols)
{
	if(rows==0 || cols==0)
	{
		printf("\n Array Empty !..\n");
		return;
	}

	printf("\n Static Array Elements :\n");
	printf("\n---------------------------\n");
	for(int j, i = 0; i<rows;i++)
	{
				
		for(j = 0 ;j<cols; ++j)
		{
			printf(" %d ",arr[i][j]);
 		
		}
		printf("\n");
	
	
	
	}
	printf("---------------------------\n");
	



}
