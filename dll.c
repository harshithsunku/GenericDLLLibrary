



#include<stdio.h>
#include"dll.h"


int InitDllLib(DLL_NODE *head) {
	
	if(!head){
		printf("Node is NULL\n");
		return 0;
	}

	head->prev = head;
	head->next = head;
	return 1;
}

int InsertIntoDLL(DLL_NODE *head , DLL_NODE *node){
	if(!head){
		printf("Head is NILL\n");
		return 0;
	}

	if(!node){
		printf("Node is NULL\n");
		return 0;
	}

	node->next = head->next;
	head->next = node;
	node->prev = head;
	node->next->prev = node;

	return 1;
}


int DeleteFromDLL(DLL_NODE *head, DLL_NODE *node){
	if(!node){
		printf("Node is NULL\n");
		return 0;
	}
	
	if(!head){
		printf("Head is NULL\n");
		return 0;
	}

	if(head == node){
		printf("Head Delete not allowed\n");
		return 0;
	}
	
	node->prev->next = node->next;
	node->next->prev = node->prev;
		
	return 1;
}


