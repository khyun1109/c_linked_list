#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

  
typedef struct _listnode {
	void *data;
	unsigned long sz;

	struct _listnode *next;
} listnode;

typedef struct _list {
	listnode *head;
	listnode *tail;
} list;

listnode *AddNode(list *l, void *data, unsigned long size)
{
	listnode *node;

	if (!(l))
		return NULL;

	if (!(l->head)){
		l->head = malloc(sizeof(listnode));
		if(!(l->head))
			return NULL;
		l->tail = l->head;
		node = l->tail;
	} else {
		l->tail->next = malloc(sizeof(listnode));
		if (!(l->tail->next))
			return NULL;
		l->tail = l->tail->next;
		node = l->tail;
	}
	memset(node, 0x00, sizeof(listnode));

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

	del = l->head;
	while(del != NULL && del->next != node)
		del = del->next;

	if(!(del))
		return;

	if(del->next == l->tail)
		l->tail = del;

	del->next = del->next->next;

	free(node->data);
	free(node);	
}

listnode *FindNodeByValue(list *l, void *data)
{
	listnode *node;

	if(!(l))
		return NULL;

	node = l->head;
	while((node)) {
		if(!strcmp(node->data,data))
			return node;

		node = node->next;
	}
	printf("I can't find!!\n");
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
	if(FreeParameterAsWell) free(l);


	return;
}

void FreeList(list *l)
{
	FreeNodes(l, 0);
	return;
}


void PrintList(list *l)
{
	unsigned int i;
	listnode *node;
	
	i = 0;
	node = l->head;

	while ((node)) {
		printf("[*] node[%u]\n", i);
		printf("    sz:\t%lu\n", node->sz);
		printf("    data:\t%s\n",(char *) node->data);
		/*printf("    data:\t%x\n",*(int *)(node->data));*/
		node = node->next; i++;
	}
}



int main()
{
	listnode *target;
	list *l;
	int i;
	char *p;

	l = malloc(sizeof(list));
	memset(l, 0x00, sizeof(list));

	char input[100];
	char value[100];
	while(1){
	//Input your code here
	//
	//
	}

	PrintList(l);
	FreeList(l);

	free(l);
	return 0;
}

