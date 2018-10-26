typedef struct BITREE{
	int data;
	BITREE *lchild;
	BITREE *rchild;
}BiTree;

int Traverse1(BiTree *t)
{
	BiTree *tmp = t;
	if (tmp == NULL) return 0;
	while (tmp != NULL || (IsEmpty(&s)!= 1))
	{
		while (tmp != NULL)
		{
			Push(&s,tmp);
			printf("%d ",tmp->data);
			tmp = tmp->lchild;
		}
		if (IsEmpty(&s) != 1)
		{
			Pop(&s,&tmp);
			tmp = tmp->rchild;
		}
	}
	return 1;
}

void Traverse2(BiTree *t)
{
	if (t != NULL)
	{
		printf("%d ",t->data);
		Traverse2(t->lchild);
		Traverse2(t->rchild);
	}
}

void Traverse3(BiTree *t)
{
	BiTree *p = t;
	BiTree *s[100];
	int top = -1;
	do
	{
		while (p!=NULL)
		{
			printf("%d ",p->data);
			if(p->rchild != NULL)
			{
				s[++top] = p->rchild;
			}
			p = p->lchild;
		}
		if (top != -1)
		{
			p = s[top--];
		}
	}
	while(p != NULL ||top != -1)
}
void Traverse4(BiTree *t)
{
	BiTree *p = t;
	BiTree *s[100];
	int top = -1;

	while (p!=NULL || top != -1)
	{
		while(p!=NULL)
		{
			s[++top] = p;
			printf("%d",p->data);
			p = p->lchild;
		}
		if (top != -1)
		{
			p = s[top--];
			p = p->rchild;
		}
	}

}