// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_LEN 50


void createDynamicArrayOfCBuf(char ***cBufArr, int *size)
{
    char temp[BUF_LEN];
    printf("\n Enter the number of character buffers :");
    scanf("%d", size);
    getchar();
    *cBufArr = (char**)(calloc(*size, sizeof(char*)));
    //To flush \n 
    for(int i = 0; i< *size; ++i)
    {
        printf("\n Enter character buffer %d ",i+1);
        fgets(temp, BUF_LEN, stdin);
        temp[strlen(temp)-1] ='\0';
        (*cBufArr)[i] = (char*)calloc(strlen(temp)+1, sizeof(char));
        strcpy((*cBufArr)[i], temp);
    }
    
}

void printDynamicArrayOfCBuf(char **cBufArr, int size)
{
    printf("\n Elements in Dynamic Array of Char Buffers :\n");
    for(int i = 0; i<size; i++)
    printf("\n Buffer %d : %s", i+1, cBufArr[i]);
    printf("\n");
}

void deleteDynamicArrayOfCBuf(char **cBufArr, int size)
{
    for(int i = 0; i<size; ++i)
    {
        printf("\n Freeing memory for %s ", cBufArr[i]);
        free(cBufArr[i]);
    }
    
    printf("\n Freeing complete memory for cBufArr\n");    
    free(cBufArr);
    
}

int main() {
    // Write C code here
    char **cDynArrBuf = NULL;
	int size_cBufDyn =0;
    createDynamicArrayOfCBuf(&cDynArrBuf,&size_cBufDyn);
    printDynamicArrayOfCBuf(cDynArrBuf,size_cBufDyn);
    deleteDynamicArrayOfCBuf(cDynArrBuf,size_cBufDyn);
    
    return 0;
}