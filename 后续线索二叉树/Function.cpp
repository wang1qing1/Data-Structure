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

TreeNode* GetFrist(TreeNode*T)//因为是后序遍历顺序，即左右跟访问，先找到第一个左子树为空的结点
							  //再判断右子树上有没有树，如果右子树上有树，那么就在右子树上找第一个结点；
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
	if (node->rtag == 1)//如果其右孩子就是下一个遍历结点就将其返回
	{
		return node->rchild;
	}
	else
	{//如果其右孩子不是下一个需要遍历的结点，就有如下三种情况；
		if (node->parent == NULL)//1.这个结点就是整颗树的根结点；也就是所需遍历的最后一个结点，就返回NULL；
		{
			return NULL;
		}
		else if (node->parent->rchild == node)//2.如果该节点是在一个右子树上，
											  //又因为他的右孩子还不是下一个所需遍历的结点；
											  //那么他所需遍历的下一个结点，即使就是他的双亲结点，
		{
			return node->parent;
		}
		else //3.如果该节点是在一个左子树上，
			 //又因为他的右孩子还不是下一个所需遍历的结点；
		{    //他下一个遍历的就是他的双亲的右子树，在他双亲的右子树去寻找左子树第一个为空的结点；
			if (node->parent->rtag == 0)
			{
				return GetFrist(node->parent->rchild);
			}
			else//如果他的双亲没有右子树，那下一个访问的就是他的双亲；
			{
				return node->parent;
			}
		}
	}
}


