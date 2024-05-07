#pragma once
#include "Student.h"

typedef struct{
	char fName[BUF_LEN], lName[BUF_LEN];
	int rollno;
	Date_bitfield dt_joined;
}Serialized_Student;

void serialize(Student s, Serialized_Student *ss);

void deserialize(Serialized_Student ss, Student *s);
