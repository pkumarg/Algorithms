#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node *next;
}Node;

Node *head_ref = NULL;

void pushNode(Node **pList, int val)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->val = val;
    p->next = NULL;

    if(!(*pList))
    {
	*pList = p;
	return;
    }

    while((*pList)->next)
    {
	pList = &(*pList)->next;
    }

    (*pList)->next = p;
}

void printList(Node *pList)
{
    while(pList)
    {
	printf("%d ", pList->val);
	pList = pList->next;
    }

    printf("\n");
}

int addNumToList(Node *pList, int val)
{
    int carry = 0;

    if(pList->next != NULL)
    {
	carry = addNumToList(pList->next, val);
    }
    else if(pList->next == NULL)
    {
	pList->val += val;
	carry = pList->val / 10;
	pList->val %= 10;

	return carry;
    }

    pList->val += carry;
    carry = pList->val / 10;
    pList->val %= 10;

    return carry;
}

#if 0
int main()
{
    pushNode(&head_ref, 9);
    pushNode(&head_ref, 9);
    pushNode(&head_ref, 9);
    pushNode(&head_ref, 9);

    printList(head_ref);
    int carry = addNumToList(head_ref, 1);

    if(carry)
    {
	Node *p = NULL;
	pushNode(&p, carry);
	p->next = head_ref;
	head_ref = p;
    }

    printList(head_ref);

    return 0;
}
#endif
