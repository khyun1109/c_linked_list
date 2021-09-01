typedef struct _listnode {
	void *data;
	unsigned long sz;

	struct _listnode *next;
} listnode;

typedef struct _list {
	LISTNODE *head;
	LISTNODE *tail;
} list;

listnode *AddNode(list *, void *, unsigned long);
void DeleteNode(list *, listnode *);
listnode *FindNodeByRef(list *,void *);
void FreeNodes(list *, int);
void FreeList(list *);
