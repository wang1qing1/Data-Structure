#include"TREE.h"
void InitQueue(QueueNode** pphead)
{
	*pphead = (QueueNode*)malloc(sizeof(QueueNode));
	(*pphead)->Qdata = {0};
	(*pphead)->next = *pphead;
	(*pphead)->prev = *pphead;
}

void PushQeueNode(QueueNode** pphead, TreeNode* X)
{
	QueueNode* tail = (*pphead)->prev;
	QueueNode*newnode= (QueueNode*)malloc(sizeof(QueueNode));
	newnode->Qdata = X;
	newnode->prev = tail;
	tail->next = newnode;
	newnode->next = (*pphead);
	(*pphead)->prev = newnode;
}

void PrinQueue(QueueNode* phead)
{
	QueueNode* cur = phead->next;
	while (phead != cur)
	{
		printf("%c ", cur->Qdata->data);
		cur = cur->next;
	}
}

TreeNode* GetQueueNode(QueueNode*phead)
{
	QueueNode* frist = phead->next;
	QueueNode* second = frist->next;
	TreeNode* num = frist->Qdata;
	phead->next = second;
	second->prev = phead;
	return num;
}

bool JaEmpty(QueueNode* phead)
{
	return phead->next == phead;
}

void CreatTree(TreeNode** T)
{
	char a;
	scanf("%c", &a);
	if (a == ' ')
	{
		*T = NULL;
	}
	else
	{
		*T = (TreeNode*)malloc(sizeof(TreeNode));
		(*T)->data = a;
		CreatTree(&(*T)->lchild);
		CreatTree(&(*T)->rchild);
	}
}

void PrevPrinTree(TreeNode*T)
{
	if (T == NULL)
	{
		return;
	}
	else
	{
		printf("%c ", T->data);
		PrevPrinTree(T->lchild);
		PrevPrinTree(T->rchild);
	}
}

void LayerSequence(TreeNode* T, QueueNode* phead)
{
	TreeNode* cur = T;
	PushQeueNode(&phead, cur);
	while (!JaEmpty(phead))
	{
		TreeNode* Node = GetQueueNode(phead);
		printf("%c ",Node->data);
		if (Node->lchild != NULL)
		{
			PushQeueNode(&phead, Node->lchild);
		}
		if (Node->rchild != NULL)
		{
			PushQeueNode(&phead, Node->rchild);
		}
	}
}


