#pragma once

#define BUF_MAX 60

//Node for Singly Linked List containing char buffer buf
struct Node_Singly
{
	char *buf;
	struct Node_Singly *next;

};


void initNode_Single(struct Node_Singly **node, const char buf[]);
int deleteNode_Single(struct Node_Singly *node);


struct LinkedList_SLL
{
	struct Node_Singly *head;

};

int insertNode_SLL(struct LinkedList_SLL *sll, const char buf[], int pos);
void printAllElementsinSLL(const struct LinkedList_SLL *sll);
int getNodeByElementinSLL(const struct LinkedList_SLL *sll, const char buf[]);
int deleteNodeInSLL(struct LinkedList_SLL *sll, const char buf[]);
int deleteAllNodesInSLL(struct LinkedList_SLL *sll);



