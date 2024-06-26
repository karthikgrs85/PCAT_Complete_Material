#include "LinkedListDouble.h"
#include <stdio.h>


#define BUF_LEN 60

int main()
{
	
	struct LinkedList_DLL dll;
	dll.head = NULL;
	
	char buf[BUF_LEN];
	int option= 0, pos= 1;
	do
	{
		printf("\n Enter an option for Singly LinkedList with Char Buffer "
			"\n 1. To display the LinkedList "
			"\n 2. To get a node by value in the LinkedList "
			"\n 3. To insert an element to the LinkedList "
			"\n 4. To delete an element in the LinkedList "
			"\n 5. To exit :\n");
			
		scanf("%d",&option);
		if(option<1||option>5)
		{
			printf("\n Invalid option ....Please try again!..\n");
			continue;
		
		}
		switch(option)
		{
			case 1: printAllElementsinDLL(&dll);
				break;
				
			case 2: getchar();
				printf("\n Enter string buffer of Node to be searched :");
				fgets(buf, BUF_LEN, stdin);
				getNodeByElementinDLL(&dll,buf);
				break;
				
			case 3: getchar();
				printf("\n Enter some string to store in the Node :");
				fgets(buf, BUF_LEN, stdin);
				if(dll.head!=NULL)
				{ 
					printf("\n Enter position to store in the LinkedList :");
					scanf("%d",&pos);
				}
				else
				   pos = 1;
				insertNode_DLL(&dll, buf, pos);
								
				break;
			case 4: getchar();
				printf("\n Enter string buffer of Node to be deleted :");
				fgets(buf, BUF_LEN, stdin);
				deleteNodeInDLL(&dll, buf);
				break;
			case 5:
				break;
				
		
		
		
		
		}
	
	
	
	}while(option!=5);

	if(dll.head!=NULL)
		deleteAllNodesInDLL(&dll);

}
