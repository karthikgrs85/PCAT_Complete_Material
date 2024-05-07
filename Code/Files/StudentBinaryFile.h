#pragma once
#include "Student.h"
#define ARR_MAX 40

int writeDynArrToBinaryFile(const Student **s, int size, const char fName[]);
int appendDynArrToBinaryFile(const Student **s, int size, const char fName[]);

//int writeStaticArrToBinaryFile(const Student s[], int size, const char fName[]);

int readFromBinaryFile(Student ***s, int *size, const char fName[]);
int readLastRecordFromBinaryFile(const char fName[]);
int deleteRecordFromBinaryFile(const char fName[], int rollNo);
