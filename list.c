#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "list.h"

listnode *AddNode(list *l, void *data, unsinged long size)
{
	listnode *node;

	if (!(l))
		return NULL;

	if (!(l->head)){

	} else {

	}
	memset(node 0x00, sizeof(listnode));

	node->data = malloc(size);
	memset(node->data, 0x00, size);
	node->sz = size;
	memcpy(node->data, data, size);

	return node;
}

void DeleteNode(list *l, listnode *node)
{
	listnode *del;

	if(!(l))
		return;

	if(node == l->head) {
		l->head = node->next;

		free(node->data);
		free(node);

		return;
	}

	del = list->head;
	while(del != NULL && del->next != node)
		del = del->next;

	if(!(del))
		return;

	if(del->next == list->tail)
		list->tail = del;

	del->next = del->next->next;

	free(node->data);
	free(node);	
}

listnode *FindeNodeByValue(list *l, void *data, unsigned long size)
{
	listnode *node;

	if(!(list))
		return NULL;

	node = l->head;
	while ((node)) {
		if(!memcmp(node->data, data, (size > node->sz) ? node->sz : size))
			return node;
		node = node->next;
	}

	return NULL;
}

void FreeNodes(list *l, int FreeParameterAsWell)
{
	listnode *node, *previous;
	if(!(l))
		return;
	node = l->head;
	while(node){
		free(node->data);
		previous = node;
		node = node->next;
		free(previous);
	}
	if(FreeParameterAsWell) free(list);


	return;
}

void FreeList(list *l)
{
	FreeNodes(list, 0);
	return;
}







