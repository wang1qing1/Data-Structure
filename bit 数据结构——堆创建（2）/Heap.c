#include"Heap.h"

void HeapInit(Heap* php)
{
	assert(php);
	php->a = NULL;
	php->capacity = php->size = 0;
}


//堆插入数据
void HeapPush(Heap* php, HPDataType x)
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
	AdjustUp(php->a, php->size - 1);
}

//数据交换
void Swap(HPDataType* n1, HPDataType* n2)
{
	int tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}

//向上调整
void AdjustUp(HPDataType* a, int child)
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

//得到堆定
HPDataType HeapTop(Heap* php)
{
	assert(php);
	return php->a[0];
}

//向下调整
void AdjustDown(Heap*php,int parent)
{
	assert(php);
	assert(parent >= 0);
	int child = parent * 2 + 1;
	while (child<php->size)
	{
		
		if (child + 1 < php->size && php->a[child] > php->a[child + 1])
		{
			child++;
		}
		if (php->a[child] < php->a[parent])
		{
			Swap(&php->a[child], &php->a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

//删除堆顶数据，不改变堆结构
void HeapPop(Heap*php)
{
	assert(php);
	Swap(&php->a[0], &php->a[php->size-1]);
	php->size--;
	AdjustDown(php,0);
}

//创建一个堆
void HeapCreate(Heap* php, HPDataType* arr, int n)
{
	assert(php && arr);
	HPDataType* tmp = (HPDataType*)malloc(sizeof(HPDataType) * n);
	if (tmp == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	php->a = tmp;
	memcpy(php->a, arr, sizeof(HPDataType) * n);
	php->capacity = php->size = n;
	for (int i = (php->size - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(php, i);
	}
}
int HeapSize(Heap* php)
{
	assert(php);
	return php->size;
}

bool HeapEmpty(Heap* php)
{
	assert(php);
	return php->size == 0;
}

void HeapDestroy(Heap* php)
{
	assert(php);
	free(php->a);
	php->capacity = php->capacity = 0;
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

