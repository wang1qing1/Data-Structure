#include"HFM.h"

HaffTree* hafTree_Init(int* weight, int num)
{
	HaffTree* T = (HaffTree*)malloc(sizeof(HaffTree));
	T->height = num;
	T->data = (TreeNode*)malloc(sizeof(TreeNode) * (2 * num - 1));
	for (int i = 0; i <num; i++)
	{
		T->data[i].weight = weight[i];
		T->data[i].parent = 0;
		T->data[i].lchild = -1;
		T->data[i].rchild = -1;
	}
	for (int i = num; i < 2 * num - 1; i++)
	{
		T->data[i].weight = 0;
		T->data[i].parent = 0;
		T->data[i].lchild = -1;
		T->data[i].rchild = -1;
	}
	return T;
}

int* SelectMin(HaffTree* T)
{
	int min=10000;
	int secondmin=10000;
	int min_index;
	int secondmin_index;
	
	for ( int i = 0; i < T->height; i++)
	{
		if (T->data[i].parent == 0)
		{
			if (T->data[i].weight < min)
			{
				min = T->data[i].weight;
				min_index = i;
			}
		}
	}

	for (int i = 0; i < T->height; i++)
	{
		if (T->data[i].parent == 0&& i !=min_index)
		{
			if (T->data[i].weight < secondmin)
			{
				secondmin = T->data[i].weight;
				secondmin_index = i;
			}
		}
	}
	int* arr = (int*)malloc(sizeof(int) * 2);
	arr[0] = min_index;
	arr[1] = secondmin_index;
	return arr;
}

void CreateHafmTree(HaffTree* T,  int num)
{
	int leight = 2 * num - 1;
	for (int i = T->height; i < leight; i++)
	{
		int* arr = SelectMin(T);
		int min = arr[0];
		int secondmin = arr[1];
		T->data[i].weight = T->data[min].weight+T->data[secondmin].weight;
		T->data[i].lchild = min;
		T->data[i].rchild = secondmin;
		T->data[min].parent = i;
		T->data[secondmin].parent = i;
		T->height++;
	}
}

void PrevClue(HaffTree* T ,int index )
{
	if (index != -1)
	{
		printf("%d ", T->data[index].weight);
		PrevClue(T, T->data[index].lchild);
		PrevClue(T, T->data[index].rchild);
	}
}

