#pragma once

#define QUEUE_MAX 50

//FIFO 
typedef struct
{
	char* buf[QUEUE_MAX];
	int end;

} Queue_String;

//Initialize start and end to -1
void initQueue(Queue_String *Qs);

//Add an element buf to the beginning of the Queue
//Move remaining elements 1 step above and increment end
//Newly inserted element should be copied to buf[0]
int enqueue(Queue_String *Qs, const char buf[]);

//Remove the first inserted element from the Queue
char* dequeue(Queue_String *Qs);

//Print the elements in the Queue
int printQueue(const Queue_String *Qs);
