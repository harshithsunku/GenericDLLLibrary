#include <stdio.h>
#include "dll.h"
#include <stdlib.h>

DLL_NODE head;

typedef struct Node Node;

struct Node{
	int data;
	DLL_NODE dll;
};

unsigned long offset = GETOFFSET(Node,dll)

int main()
{
	if(!InitDllLib(&head)){
		printf("DLL Library init failed\n");
		return 1;
	}

	DLL_NODE *head_ptr = &head;

	Node *node = (Node*)malloc(sizeof(Node));
	node->data = 10;	

	InsertIntoDLL(head_ptr, (DLL_NODE*)&node->dll);

    Node *node1 = (Node*)malloc(sizeof(Node));
    node1->data = 555;

    InsertIntoDLL(head_ptr, (DLL_NODE*)&node1->dll);

    Node *node2 = (Node*)malloc(sizeof(Node));
    node2->data = 11;

    InsertIntoDLL(head_ptr, (DLL_NODE*)&node2->dll);

    Node *node3 = (Node*)malloc(sizeof(Node));
    node3->data = 5155;

    InsertIntoDLL(head_ptr, (DLL_NODE*)&node3->dll);


	DLL_NODE *temp = NULL;

	DLL_TRAVERSE_START(head_ptr, temp) 
	{										\
		printf("\n node data = %d \n", (int) ((Node*)(((char*)temp) - offset))->data );
	}
	DLL_TRAVERSE_END 
	
	DeleteFromDLL(head_ptr, &node1->dll);
	free(node1);

	DeleteFromDLL(head_ptr, head_ptr);

	DeleteFromDLL(head_ptr, &node3->dll);
	free(node3);

	DeleteFromDLL(head_ptr, &node->dll);
	free(node);

	DeleteFromDLL(head_ptr, &node2->dll);
	free(node2);

	DLL_TRAVERSE_START(head_ptr, temp)
    {                                       \
        printf("\n node data = %d \n", (int) ((Node*)(((char*)temp) - offset))->data );
    }
    DLL_TRAVERSE_END
	

	return 0;
}
