#pragma once
#include <stdbool.h>

void swap(int *a, int *b);

void printArr(int arr[], int size);

int partition_highpivot(int arr[], int low, int high, bool (*fn)(int, int));

int partition_lowpivot(int arr[], int low, int high, bool (*fn)(int, int));

void quickSort(int arr[], int low, int high,  bool (*fn)(int, int));
