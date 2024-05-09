#pragma once

#define STACK_MAX 50

//LIFO
typedef struct
{
	char *buf[STACK_MAX];
	int top;

} Stack_string; 

//Get the last inserted element in the Stack
char* peek(const Stack_string* Ss);

//Push an element buf into the Stack
int push(Stack_string* Ss, const char buf[]);

//Pop the last inserted element out of the Stack
char* pop(Stack_string *Ss);

//Print all the elements of the Stack
void printAll(const Stack_string* Ss);

//Initialize top to 0
void initStack(Stack_string *Ss);
