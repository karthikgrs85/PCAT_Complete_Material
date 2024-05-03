#include "2DIntArray.h"
#include <stdio.h>



int main()
{
	//Pointers to dynamic array of rows X columns
	int **dynArr1 = NULL, **dynArr2 = NULL, **dynSumArr=NULL, statArr[MAX_INT_ARR_SIZE][MAX_INT_ARR_SIZE];
	int d_rows1, d_cols1, d_rows2, d_cols2, s_rows, s_cols;
	
	//Initialize static Array and print contents
	initializeStaticIntArray(statArr, &s_rows, &s_cols);
	printStaticIntArray(statArr, s_rows, s_cols);
	printf("\n The size of Static Array = %lu \n",sizeof(statArr));
	
	
	initializeDynamicIntArray(&dynArr1,&d_rows1, &d_cols1);
	printDynamicIntArray((const int**)dynArr1, d_rows1, d_cols1);
	//printf("\n The size of Dynamic Array = %lu \n",sizeof(dynArr1));
	
	initializeDynamicIntArray(&dynArr2,&d_rows2, &d_cols2);
	printDynamicIntArray((const int**)dynArr2, d_rows2, d_cols2);
	//printf("\n The size of Dynamic Array = %lu \n",sizeof(dynArr2));
	if((d_rows1==d_rows2)&&(d_cols1==d_cols2))
	{
		getSumOfTwoDynamicArrays(&dynSumArr,(const int**) dynArr1, (const int**)dynArr2, d_rows1, d_cols1);
		printf("\n The sum of the two 2D arrays is :\n");
		printDynamicIntArray((const int**)dynSumArr, d_rows1, d_cols1);
		//printf("\n The size of Dynamic Array = %lu \n",sizeof(dynSumArr));
		deleteDynamicIntArray(&dynSumArr, d_rows1, d_cols1);
	}
	
	deleteDynamicIntArray(&dynArr1, d_rows1, d_cols1);
	deleteDynamicIntArray(&dynArr2, d_rows2, d_cols2);
	
	


}
