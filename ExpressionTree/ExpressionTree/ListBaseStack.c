#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

void StackInit(Stack * pstack)
{
	pstack->head = NULL;
}

int SIsEmpty(Stack * pstack)
{
	if (pstack->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack * pstack, Data data)
{
	Node * newNode = (Node *)malloc(sizeof(Node));

	newNode->data = data;
	newNode->next = pstack->head;

	pstack->head = newNode;
}

Data SPop(Stack * pstack)
{
	Data rdata;
	Node * rnode;

	if (SIsEmpty(pstack))
	{
		printf("There is No data.\n");
		exit(-1);
	}

	rdata = pstack->head->data;
	rnode = pstack->head;

	pstack->head = rnode->next;
	free(rnode);

	return rdata;
}

Data SPeek(Stack * pstack)
{
	if (SIsEmpty(pstack))
	{
		printf("There is No data.\n");
		exit(-1);
	}

	return pstack->head->data;
}