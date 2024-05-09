#pragma once

#define BUF_MAX 60

//Node for Doubly Linked List
struct Node_Doubly
{
	char *buf;
	struct Node_Doubly *next, *prev;

};

void initNode_Double(struct Node_Doubly **node, const char buf[]);
int deleteNode_Double(struct Node_Doubly *node);

struct LinkedList_DLL
{
	struct Node_Doubly *head;

};


int insertNode_DLL(struct LinkedList_DLL *dll, const char buf[], int pos);
void printAllElementsinDLL(const struct LinkedList_DLL *dll);
int getNodeByElementinDLL(const struct LinkedList_DLL *dll, const char buf[]);
int deleteNodeInDLL(struct LinkedList_DLL *dll, const char buf[]);
int deleteAllNodesInDLL(struct LinkedList_DLL *dll);


