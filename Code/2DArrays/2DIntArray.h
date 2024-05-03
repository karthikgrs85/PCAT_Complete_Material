#pragma once
#define MAX_INT_ARR_SIZE 15

void initializeDynamicIntArray(int ***arr, int *rows, int *cols);


void printDynamicIntArray(const int **arr, int rows, int cols);

void getSumOfTwoDynamicArrays(int ***arrSum, const int **arr1, const int **arr2, int rows, int cols);

void initializeStaticIntArray(int arr[][MAX_INT_ARR_SIZE], int *rows, int *cols);

void printStaticIntArray(const int arr[][MAX_INT_ARR_SIZE], int rows, int cols);

void deleteDynamicIntArray(int ***arr, int rows, int cols);

