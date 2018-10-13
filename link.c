#include<stdio.h>
#include <stdlib.h>
typedef struct NODE {
	struct NODE *link;
	int value;
} Node;

int sll_insert(Node **linkp,int new_value)//12
{
	register Node *current;
	register Node *new;
	register Node *head;
	
	head = *linkp;
	linkp = &head->link;
	
	while((current = *linkp)!= NULL && current->value < new_value)
		linkp = &current->link;

	new = (Node*)malloc(sizeof(Node));
	if (new == NULL) return 0;
	new->value = new_value;

	new->link = current;
	*linkp = new;
	
	return 1;
}

Node* sll_reverse(Node *first)//12.8.4
{
	register Node *current;
	register Node *next1;
	register Node *next2;

	if (first == NULL||first->link == NULL) return NULL;
	
	current = first;
	next1 = current->link;
	current->link = NULL;
	
	while (next1 != NULL)
	{
		next2 = next1->link;
		next1->link = current;
		current = next1;
		next1 = next2;
	}
	first = NULL;

	return current;
}

int sll_remove(Node **rootp,Node *node)//12.8.5
{
	register Node *current;
	register Node *last;

	current = *rootp;
	last = current;
	while(current != NULL)
	{
		if (current != node) 
		{
			last = current;
			current = current->link;
		}
		else 
		{
			last->link = current->link;
			return 1;
		}
	}
	return 0;
}

Node *search_list(Node *node,void const *value,int(*compare)(void const *,void const *))
{
	while (node != NULL)
	{
		if (compare( &node->value,value) == 0)
			break;
		node = node->link;
	}
	return node;
}

int compare_ints(void const *a,void const* b)
{
	if (*(int*)a == *(int*)b)
		return 0;
	return 1;
}

int main(){
	Node *head,*node,*end,*removep;
	int i,y=30,remove = 35;
	
	head = (Node*)malloc(sizeof(Node));
	if(head == NULL) return 0;
	end = head;

	for (i = 1;i<11;i++)
	{
		node = (Node*)malloc(sizeof(Node));
		node->value = 5*i;
		end->link = node;
		end = node;
	}
	end->link = NULL;

	node = search_list(head,&y,compare_ints);

	removep = search_list(head,&remove,compare_ints);
	printf("%d HEAD--->",sll_remove(&head,removep));
	

	while(node!=NULL)
	{
		printf("%d--->",node->value);
		node = node->link;
	}
	printf("END");

	return 0;
}
