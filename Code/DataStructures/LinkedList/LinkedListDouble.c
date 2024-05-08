#include "LinkedListDouble.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void initNode_Double(struct Node_Doubly **node, const char buf[])
{
	*node = (struct Node_Doubly*)malloc(sizeof(struct Node_Doubly));
	if((*node)->buf!=NULL)
		free((*node)->buf);
	(*node)->buf = (char*)calloc(strlen(buf)+1, sizeof(char));
	
	strcpy((*node)->buf, buf);
	(*node)->next = (*node)->prev = NULL;
	printf("\n Node with buffer %s intialized successfully \n",buf);
}


int deleteNode_Double(struct Node_Doubly *node)
{
	if(node==NULL || node->buf==NULL)
	{
		printf("\n Node does not contain valid data and cannot be deleted ....\n");
		return -1;
	}
	printf("\n Freeing Doubly Linked Node with buffer %s \n",node->buf);
	free(node->buf);
	node->buf = NULL;
	node->next = node->prev = NULL;
	free(node);
	return 1;
}

int insertNode_DLL(struct LinkedList_DLL *dll, const char buf[], int pos)
{
	if(pos<1)
	{
		printf("\n Not a valid position \n");
		return -1;
	
	}
	int count = 1;
	
	struct Node_Doubly *newNode = NULL;
	
	//Initialize New Node
	initNode_Double(&newNode, buf);
	
	//If pos = 1,
	//Insert the node at the beginning of SLL
	if(pos==1)
	{
		newNode->next = dll->head;
		dll->head = newNode;
		printf("\n New Node inserted at head successfully !..");
		return 1;
	}
	



	//Insert new Node between cur node and next node
	struct Node_Doubly *cur;
	cur = dll->head; 
	
	while(count <pos-1 && cur->next!= NULL)
	{
		cur = cur->next;
		count++;
	
	}
	
	newNode->prev = cur;
	newNode->next = cur->next;
	
	if(cur->next!=NULL)
		cur->next->prev = newNode;
	
	cur->next = newNode;
	
		
	
	printf("\n New Node inserted at position %d successfully !..", count);
	return 1;

}


void printAllElementsinDLL(const struct LinkedList_DLL *dll)
{
	if(dll==NULL || dll->head==NULL)
	{
		printf("\n LinkedList Empty or Not Initialized !....\n");
		return;
	}
	
	struct Node_Doubly *cur = dll->head;
	
	printf("\n Elements in Doubly Linked List :\n");
	printf("\n---------------------------------\n");
	while(cur!=NULL)
	{
		printf(" %s\n",cur->buf);
		cur = cur->next; 
	
	}
	printf("\n---------------------------------\n");

}


int getNodeByElementinDLL(const struct LinkedList_DLL *dll, const char buf[])
{

	struct Node_Doubly *cur = dll->head;
	int index = 0;
	while(cur!=NULL && strcmp(cur->buf,buf))
	{
		cur = cur->next;
		index++;
	}
	if(cur==NULL)
	{
		printf("\n Element with %s not found ",buf);
		return -1;
	}
	printf("\n Element with %s found at position %d",buf,index+1);
		return index;

}


int deleteNodeInDLL(struct LinkedList_DLL *dll, const char buf[])
{
	struct Node_Doubly *cur = dll->head;
	
	while(cur!=NULL && (cur->next!=NULL) && strcmp(cur->buf,buf))
	{
		cur = cur->next;
	}
	
	if(!strcmp(cur->buf,buf))
	{
		if(cur == dll->head)
			dll->head = cur->next;
		
		if(cur->prev)
			cur->prev->next = cur->next;
		if(cur->next)
			cur->next->prev  = cur->prev;
		deleteNode_Double(cur);
		printf("\n Element with buffer %s deleted successfully \n",buf);
		return 1;
	
	}
	else 
	{
		printf("\n Element with buffer %s not found !... \n",buf);
		return -1;
	}

}

int deleteAllNodesInDLL(struct LinkedList_DLL *dll)
{
	struct Node_Doubly *cur = dll->head, *next = cur->next;
	
	int numDeleted = 0;
	while(next!=NULL)
	{
		deleteNode_Double(cur);
		numDeleted++;
		cur = next;
		next = cur->next;
	}

	if(cur!=NULL)
	{
		deleteNode_Double(cur);
		numDeleted++;
	}
		
	printf("\n %d elements deleted successfully....\n", numDeleted);



}
