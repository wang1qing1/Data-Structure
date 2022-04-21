#include"TREE.h"

bool JaEmpty(Stact* phead)//栈判空
{
	assert(phead);
	return phead->next == phead;
}

void CreatTree(TreeNode** T)//创建二叉树
{
	char x;
	scanf("%c", &x);
	if (x == ' ')
	{
		*T = NULL;
	}
	else
	{
		*T = (TreeNode*)malloc(sizeof(TreeNode));
		(*T)->data = x;
		CreatTree(&(*T)->lchild);
		CreatTree(&(*T)->rchild);
	}
}

void PrevTra(TreeNode* T)//递归前序遍历
{
	if (T == NULL)
	{
		return;
	}
	else
	{
		printf("%c ", T->data);
		PrevTra(T->lchild);
		PrevTra(T->rchild);
	}
}

void InitStact(Stact** pphead)//初始化栈头结点
{
	*pphead = (Stact*)malloc(sizeof(Stact));
	(*pphead)->next = *pphead;
	(*pphead)->prev = *pphead;
	(*pphead)->Data = NULL;
}

void Printf(Stact* phead)//打印栈
{
	Stact* cur = phead->next;
	while (cur!=phead)
	{
		printf("%d ", cur->Data);
		cur = cur->next;
	}
}


void PushStact(Stact* phead, TreeNode* X)//入栈
{
	Stact* tail = (phead)->prev;
	Stact* newnode = (Stact*)malloc(sizeof(Stact));
	if (newnode == NULL)
	{
		printf("栈增加空间失败！！");
		exit(-1);
	}
	newnode->Data = X;
	newnode->next = phead;
	newnode->prev = tail;
	tail->next = newnode;
	(phead)->prev = newnode;
}

Stact* GetStactNode(Stact* phead)//出栈
{
	assert(phead);
	Stact* Retu = (phead)->prev;
	Stact* tail = (phead)->prev;
	Stact* pre_tail = tail->prev;
	pre_tail->next = phead;
	(phead)->prev = pre_tail;
	return Retu;
}

void MyMidTra(Stact* phead, TreeNode* T)//非递归中序遍历
{
	TreeNode* TR = T;
	while (TR!=NULL||!JaEmpty(phead))
	{
		if(TR)
		{
			PushStact(phead, TR);
			TR = TR->lchild;
		}
		else
		{
			TreeNode*Snode = GetStactNode(phead)->Data;
			printf("%c ", Snode->data);
			TR = Snode->rchild;
		}
	}
	
}

void MyPreTra(Stact* phead, TreeNode* T)//非递归前序遍历
{
	TreeNode* TR = T;
	while (TR != NULL || !JaEmpty(phead))
	{
		if (TR)
		{
			PushStact(phead, TR);
			printf("%c ", TR->data);
			TR = TR->lchild;
		}
		else
		{
			TreeNode* Snode = GetStactNode(phead)->Data;
			TR = Snode->rchild;
		}
	}

}







