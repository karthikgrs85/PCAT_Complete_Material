#include "LinkedListSingle.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void initNode_Single(struct Node_Singly **node, const char buf[])
{
	*node = (struct Node_Singly*)malloc(sizeof(struct Node_Singly));
	if((*node)->buf!=NULL)
		free((*node)->buf);
	(*node)->buf = (char*)calloc(strlen(buf)+1, sizeof(char));
	strcpy((*node)->buf, buf);
	(*node)->next = NULL;
	printf("\n Node with buffer %s intialized successfully \n",buf);
}

int deleteNode_Single(struct Node_Singly *node)
{
	if(node==NULL || node->buf==NULL)
	{
		printf("\n Node does not contain valid data and cannot be deleted ....\n");
		return -1;
	}
	printf("\n Freeing Singly Linked Node with buffer %s \n",node->buf);
	free(node->buf);
	node->buf = NULL;
	node->next = NULL;
	free(node);
	return 1;

}


int insertNode_SLL(struct LinkedList_SLL *sll, const char buf[], int pos)
{
	if(pos<1)
	{
		printf("\n Not a valid position \n");
		return -1;
	
	}
	int count = 1;
	
	struct Node_Singly *newNode = NULL;
	
	//Initialize New Node
	initNode_Single(&newNode, buf);
	
	//If pos = 1,
	//Insert the node at the beginning of SLL
	if(pos==1)
	{
		newNode->next = sll->head;
		sll->head = newNode;
		printf("\n New Node inserted at head successfully !..");
		return 1;
	}
	



	//Insert new Node between cur node and next node
	struct Node_Singly *cur, *next;
	cur = sll->head; 
	next= cur->next;
	
	while(count <pos-1 && next!= NULL)
	{
		cur = cur->next;
		next = cur->next;
		count++;
	
	}
	cur->next = newNode;
	newNode->next = next;
	printf("\n New Node inserted at position %d successfully !..", count);
	return 1;

}
void printAllElementsinSLL(const struct LinkedList_SLL *sll)
{
	if(sll==NULL || sll->head==NULL)
	{
		printf("\n LinkedList Empty or Not Initialized !....\n");
		return;
	}
	
	struct Node_Singly *cur = sll->head;
	
	printf("\n Elements in Singly Linked List :\n");
	printf("\n---------------------------------\n");
	while(cur!=NULL)
	{
		printf(" %s\n",cur->buf);
		cur = cur->next; 
	
	}
	printf("\n---------------------------------\n");



}
int getNodeByElementinSLL(const struct LinkedList_SLL *sll, const char buf[])
{
	
	struct Node_Singly *cur = sll->head;
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
int deleteNodeInSLL(struct LinkedList_SLL *sll, const char buf[])
{
	struct Node_Singly *cur, *prev, *next;
	int pos = 1;
	cur = sll->head;
	prev = cur;
	next = cur->next;
	
	//If buf is located at head, update head and delete the first element
	if(!strcmp(sll->head->buf,buf))
	{
		sll->head = next;
		deleteNode_Single(cur);		
		printf("\n Node with buffer %s deleted at head successfully !....\n", buf);
		return 1;
	}
	while(cur!= NULL && strcmp(cur->buf,buf) && next!=NULL)
	{
		prev = cur;
		cur = cur->next;
		next = cur->next;
		pos++;
	}	
	if(!strcmp(cur->buf, buf))
	{
		prev->next = next;
		deleteNode_Single(cur);		
		printf("\n Node with buffer %s deleted at position %d successfully !....\n",buf, pos);
		return 1;
	
	}
	
	printf("\n Node with buffer %s not found \n",buf);
	return -1;

}
int deleteAllNodesInSLL(struct LinkedList_SLL *sll)
{
	struct Node_Singly *cur, *next;
	cur = sll->head;
	next = cur->next;
	int numDeleted = 0;
	while(next!=NULL)
	{
		deleteNode_Single(cur);
		numDeleted++;
		cur = next;
		next = cur->next;
	}

	if(cur!=NULL)
	{
		deleteNode_Single(cur);
		numDeleted++;
	}
		
	printf("\n %d elements deleted successfully....\n", numDeleted);
	return 1;
}

