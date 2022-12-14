#include"function.h"

void Swap(HPDateType* n1, HPDateType* n2)
{
	HPDateType tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}

void HeapInit(Heap* php)
{
	assert(php);
	php->a = NULL;
	php->capacity = php->size = 0;
}

void AdjustUp(HPDateType* a, int size, int child)
{
	int parent = (child - 1) / 2;
	while (child>0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void JudgeCapacity(Heap*php)
{
	assert(php);
	if (php->capacity == php->size)
	{
		int newcaprcity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDateType* tmp = realloc(php->a, sizeof(HPDateType) * newcaprcity);
		if (tmp == NULL)
		{
			perror("realloc");
			exit(-1);
		}
		php->a = tmp;
		php->capacity = newcaprcity;
	}
}
void HeapPush(Heap* php, HPDateType x)
{
	assert(php);
	JudgeCapacity(php);
	php->a[php->size++] = x;

	AdjustUp(php->a, php->size,php->size - 1);
}

void AdjustDown(HPDateType* arr,int n, int parent)
{
	int child = parent * 2 + 1;
	
	while (child < n)
	{
		if (child + 1 < n && arr[child] < arr[child + 1])
		{
			child++;
		}
		if (arr[child] > arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

//对已经给出的数组进行建堆
void HeapCreate(Heap* php, HPDateType* arr, int n)
{
	assert(php);
	php->a = (HPDateType*)malloc(sizeof(HPDateType) * n);
	php->capacity = n;
	php->size = n;
	memmove(php->a,arr,sizeof(arr[0]) * n);
	
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(php->a, n,i);
	}
}

//堆的销毁
void HeapDestroy(Heap* php)
{
	assert(php);
	free(php->a);
	php->capacity = php->size = 0;
}