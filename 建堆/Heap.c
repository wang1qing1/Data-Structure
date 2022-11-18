#include"Heap.h"

void HeapInit(Heap* php)
{
	assert(php);
	php->a = NULL;
	php->capacity = php->size = 0;
}

void HeapPush(Heap* php, int x)
{
	assert(php);
	if (php->capacity == php->size)
	{
		int newcapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDataType* tmp = realloc(php->a, sizeof(HPDataType)*newcapacity);
		if (tmp == NULL)
		{
			perror("realloc");
			exit(-1);
		}
		php->a = tmp;
		php->capacity = newcapacity;
	}
	php->a[php->size++] = x;
	Adjust(php->a, php->size - 1);
}

void Swap(int* n1, int* n2)
{
	int tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}

void Adjust(HPDataType* a, int child)
{
	assert(a);
	while (child>0)
	{
		int parent = (child - 1) / 2;
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
		}
		else
		{
			break;
		}
	}
}

void Print(Heap* php,int n)
{
	assert(php);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", php->a[i]);
	}
	printf("\n");
}