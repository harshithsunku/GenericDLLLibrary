#ifndef __DLL_LIB_H__
#define __DLL_LIB_H__

typedef struct DLL_NODE DLL_NODE;

struct DLL_NODE{
	DLL_NODE *prev;
	DLL_NODE *next;
};

int InitDllLib(DLL_NODE *head);

int InsertIntoDLL(DLL_NODE *head , DLL_NODE *node);

int DeleteFromDLL(DLL_NODE *head , DLL_NODE *node);

#define GETOFFSET(node,dll) \
	 (unsigned long) &(((node *)0)->dll);

#define DLL_TRAVERSE_START(head, temp)  \
{                                       \
	if(!head) {  \
		printf("Head is null");  \
		return 1; \
	} \
	temp = head; \
	while (temp->next != head) { \
		temp = temp->next;


#define DLL_TRAVERSE_END \
	} \
} \


#endif

