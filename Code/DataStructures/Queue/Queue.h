#pragma once

#define QUEUE_MAX 50

//FIFO 
typedef struct
{
	char* buf[QUEUE_MAX];
	int start, end;

} Queue_String;

//Initialize start and end to -1
void initQueue(Queue_String *Qs);

//Add an element buf to the beginning of the Queue
int enqueue(Queue_String *Qs, const char buf[]);

//Remove the first inserted element from the Queue
char* dequeue(Queue_String *Qs);

//Print the elements in the Queue
int printQueue(const Queue_String *Qs);
