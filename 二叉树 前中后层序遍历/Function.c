#include"Tree.h"
//前序遍历
void ProTrave(BTnode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->data);
	ProTrave(root->left);
	ProTrave(root->right);

}

//中序遍历
void MidTrave(BTnode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	ProTrave(root->left);
	printf("%c ", root->data);
	ProTrave(root->right);
}

//后序遍历
void AfTrave(BTnode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	ProTrave(root->left);
	ProTrave(root->right);
	printf("%c ", root->data);
}

//求节点数
void NodeSize1(BTnode* root, int* size)
{
	if (root == NULL)
	{
		return;
	}
	(*size)++;
	NodeSize1(root->left, size);
	NodeSize1(root->right, size);
}

//求节点数
int NodeSize(BTnode* root)
{
	return root == NULL ? 0 : NodeSize(root->left) + NodeSize(root->right) + 1;
}

//求叶子节点数
int LeafNodeSize(BTnode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	return LeafNodeSize(root->left) + LeafNodeSize(root->right);
}

Queue* InitQueue()
{
	Queue* head = (Queue*)malloc(sizeof(Queue));
	head->pdata = 0;
	head->next = head;
	head->prov = head;
	return head;
}

Queue* AddNode() 
{
	Queue* newnode = (Queue*)malloc(sizeof(Queue));
	newnode->pdata = NULL;
	newnode->next = NULL;
	newnode->prov = NULL;
	return newnode;
}

void InputQueue(Queue* head, DATA_TYPE* pdata)
{
	Queue* NewNode = AddNode();
	NewNode->pdata = pdata;
	Queue* tail = head->prov;
	NewNode->prov = tail;
	NewNode->next = head;
	head->prov = NewNode;
	tail->next = NewNode;
}

void PutQueue(Queue* head)
{
	Queue* frist = head->next;
	printf("%c ", frist->pdata->data);
}

void DeleQueue(Queue*head)
{
	Queue* frist = head->next;
	Queue* second = frist->next;
	head->next = second;
	second->prov = head;
	free(frist);

}

int Judge(Queue* head)
{
	if (head->next == head)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}