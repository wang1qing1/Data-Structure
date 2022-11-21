#include"TopK.h"

void Swap(int* n, int* m)
{
	int tmp = *n;
	*n = *m;
	*m = tmp;
}

//���µ����㷨
void Adjustdow(int *arr,int size,int parent)
{
	assert(arr);
	assert(parent <= size);
	while (parent * 2 + 1 < size)
	{
		int child = parent * 2 + 1;
		if (child + 1 < size && arr[child + 1] < arr[child])
		{
			child++;
		}
		if (arr[child] < arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
			parent = child;
		}
		else
		{
			break;
		}
	}
}

//�������ļ�
void CreateFile(int n)
{
	int num = n;
	srand(time(0));
	FILE* pf = fopen("test.txt", "w");
	while (n--)
	{
		int val = rand() % num;
		fprintf(pf, "%d\n", val);
	}
	fclose(pf);
}

//topk 
//�����ݼ��࣬k ��Сʱ�������˽�����ȫ�����ص��ڴ棬
//ȥ�����ļ���ȡ���� ��С�ѶѶ����ݽ��бȽϣ�����ȶѶ�
//���ݴ��Ǿ�ֱ�Ӵ���Ѷ����ݣ������µ�����
int* Topk(int k)
{
	int* topk = (int*)malloc(sizeof(int)*k);
	if (topk == NULL)
	{
		perror("malloc");
	}
	FILE* pf = fopen("test.txt", "r");
	for (int i = 0; i < k; i++)
	{
		int val = 0;
		fscanf(pf, "%d", &val);
		topk[i] = val;
	}
	fclose(pf);
	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		Adjustdow(topk, k, i);
	}
	 pf = fopen("test.txt", "r");
	int value = 0;
	while (fscanf(pf, "%d", &value) != EOF)
	{
		if (value > topk[0])
		{
			topk[0] = value;
			Adjustdow(topk, k, 0);
		}
	}
	return topk;
}