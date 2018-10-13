#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
	struct NODE *fwd;
	struct NODE *bwd;
	int value;
} Node;

int dll_insert(Node *rootp,int new_value)
{
	Node *this;
	Node *next;
	Node *newnode;

	for (this = rootp ; (next = this->fwd)!=NULL ; this = next)
	{
		if (next->value == new_value) return 0;//不插入重复的值
		if (next->value > new_value) break;
	}
	newnode = (Node*)malloc(sizeof(Node));
	if (newnode == NULL) return -1;
	newnode->value = new_value;

	newnode->fwd = next;
	if (this != rootp)
	{
		this->fwd = newnode;
		newnode->bwd = this;
	}
	else
	{
		rootp->fwd = newnode;
		newnode->bwd = NULL;
	}
	if (next != NULL)
		next->bwd = newnode;
	else
		rootp->bwd = newnode;
	return 1;
}

int dll_remove(Node *rootp,Node *node)
{
	register Node *current,*last;
	current = rootp;

	while(current != NULL)
	{
		if(current != node)
		{
			last = current;
			current = current->fwd;
		}
		else
		{
			last->fwd = current->fwd;
			return 1;
		}
	}
	return 0;
}

int main(){
	int i=0;
	Node *head;
	Node *current;
	Node *end;
	Node *removep;

	head = (Node*)malloc(sizeof(Node));
	if (head == NULL) return 0;
	head->fwd = NULL;
	head->bwd = NULL;
	end = head;

	for (i=1;i<=10;i++)
	{
		current = (Node*)malloc(sizeof(Node));
		current->value = 5*i;
		current->fwd = NULL;
		end->fwd = current;
		current->bwd = end;
		end = current;
	}
	head->bwd = end;

	removep = head;
	for(i=0;i<5;i++) removep = removep->fwd;
	printf("%d ",dll_remove(head,removep));
	
	printf("HEAD--->");
	i=0;
	current = head->fwd;
	while (current != NULL)
	{
		printf("%d--->",current->value);
		current = current->fwd;
	}
	printf("END");
	return 0;
}
