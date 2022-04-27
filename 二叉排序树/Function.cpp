#include"TREE.h"

void SortTree(TreeNode** T, int data)
{
	if (*T == NULL)//ֻ���ҵ���λ�����ǲ��ܲ��룻
	{
		*T = (TreeNode*)malloc(sizeof(TreeNode));//Ϊ�������׼������Ľ�㿪�ٿռ䣬
		(*T)->data = data;//����ת��
		(*T)->lchild = NULL;//�²���Ľ��һ����һ��Ҷ�ӽڵ㣬����������������ҪΪNULL��
		(*T)->rchild = NULL;
	}
	else if (data < (*T)->data)//�������ֵ�����д洢��ֵ���бȽϣ�����ȸýڵ�С��
							   //������������������Ѱ�ң�
	{
		SortTree(&(*T)->lchild, data);
	}
	else if (data == (*T)->data)//��Ϊ�����������޷�������ͬ��ֵ�����Ե������ֵ��ýڵ��ֵ��ȣ�
								//���ǾͲ�������
	{
		return;
	}
	else//����ȸýڵ��ֵ�����Ǿ����ýڵ��������Ѱ�ң�
	{
		SortTree(&(*T)->rchild, data);
	}
	//�����ݹ��Ե�Ѱ�ң������ֵ�ȸýڵ��ֵС����������������Ѱ�ң�
	//��Ȳ������������ֵ�ȸýڵ��ֵ������ýڵ��������Ѱ�ң�ֱ���ҵ����
	//ĳһ����������������������Ϊ�գ������λ�þ������Ǵ����ֵ׼���ŵ�λ�ã�
}

TreeNode* SeaTree(TreeNode* T, int key)
{
	if (key == T->data)
	{
		return T;
	}
	else if(key < T->data)
	{
		SeaTree(T->lchild, key);
	}
	else
	{
		SeaTree(T->lchild, key);
	}
}

void MidClue(TreeNode*T)//�������
{
	if (T)
	{
		MidClue(T->lchild);
		printf("%d ", T->data);
		MidClue(T->rchild);
	}
}

 