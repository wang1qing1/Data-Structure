#include"TREE.h"

void CreateTree(TreeNode** T,TreeNode*par)
{
	char ch;
	scanf("%c", & ch);
	if (ch == ' ')
	{
		*T = NULL;
	}
	else
	{
		*T = (TreeNode*)malloc(sizeof(TreeNode));
		(*T)->data = ch;
		(*T)->ltag = 0;
		(*T)->rtag = 0;
		(*T)->parent = par;
		CreateTree(&(*T)->lchild,*T);
		CreateTree(&(*T)->rchild,*T);
	}
}

void AfteClue(TreeNode* T, TreeNode** prev)
{
	if (T != NULL)
	{
		AfteClue(T->lchild, prev);
		AfteClue(T->rchild, prev);
		if (T->lchild == NULL)
		{
			T->ltag = 1;
			T->lchild = *prev;
		}
		if (*prev != NULL && (*prev)->rchild == NULL)
		{
			(* prev)->rtag = 1;
			(* prev)->rchild = T;
		}
		*prev = T;
	} 
}

TreeNode* GetFrist(TreeNode*T)//��Ϊ�Ǻ������˳�򣬼����Ҹ����ʣ����ҵ���һ��������Ϊ�յĽ��
							  //���ж�����������û�������������������������ô�������������ҵ�һ����㣻
{
	while (T->ltag!=1)
	{
		T = T->lchild;
	}
	if (T->rtag == 0)
	{
		return GetFrist(T->rchild);
	}
	return T;
}

TreeNode* GetNext(TreeNode* node)
{
	if (node->rtag == 1)//������Һ��Ӿ�����һ���������ͽ��䷵��
	{
		return node->rchild;
	}
	else
	{//������Һ��Ӳ�����һ����Ҫ�����Ľ�㣬�����������������
		if (node->parent == NULL)//1.����������������ĸ���㣻Ҳ����������������һ����㣬�ͷ���NULL��
		{
			return NULL;
		}
		else if (node->parent->rchild == node)//2.����ýڵ�����һ���������ϣ�
											  //����Ϊ�����Һ��ӻ�������һ����������Ľ�㣻
											  //��ô�������������һ����㣬��ʹ��������˫�׽�㣬
		{
			return node->parent;
		}
		else //3.����ýڵ�����һ���������ϣ�
			 //����Ϊ�����Һ��ӻ�������һ����������Ľ�㣻
		{    //����һ�������ľ�������˫�׵�������������˫�׵�������ȥѰ����������һ��Ϊ�յĽ�㣻
			if (node->parent->rtag == 0)
			{
				return GetFrist(node->parent->rchild);
			}
			else//�������˫��û��������������һ�����ʵľ�������˫�ף�
			{
				return node->parent;
			}
		}
	}
}


