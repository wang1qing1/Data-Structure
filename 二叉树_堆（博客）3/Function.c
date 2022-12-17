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
//向上调整算法(小堆)
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

//向下调整算法(大堆)
void AdjustDown_big(HPDateType* arr,int n, int parent)
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

//向下调整算法(小堆)
void AdjustDown_samll(HPDateType* arr, int n, int parent)
{
	int child = parent * 2 + 1;

	while (child < n)
	{
		if (child + 1 < n && arr[child] > arr[child + 1])
		{
			child++;
		}
		if (arr[child] < arr[parent])
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
		AdjustDown_big (php->a, n, i);
	}
}

//堆的删除，删除堆顶数据，并保证删除以后仍是堆
void HeapPop(Heap* php)
{
	assert(php);
	assert(php->size > 0);
	Swap(&php->a[0], &php->a[php->size]-1);
	php->size--;

	AdjustDown_big(php->a, php->size, 0);
}

//拿到堆顶数据
HPDateType HeapTop(Heap* php)
{
	assert(php);
	assert(php->size > 0);

	return php->a[0];
}

//堆的数据个数
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

//堆的销毁
void HeapDestroy(Heap* php)
{
	assert(php);
	free(php->a);
	php->capacity = php->size = 0;
}

//topk问题
void HeapTopK(Heap* php, int k)
{
	assert(php);
	assert(k > 0);

	for (int i = 0; i < k; i++)
	{
		printf("%d ", HeapTop(php));
		HeapPop(php);
	}

	printf("\n");
}


//topk 文件大数据量

void TopK_File(int k)
{
	//造数据
	FILE* pfile = fopen("test.txt", "w");
	srand(time(0));
	for (int i = 0; i < 1000; i++)
	{
		fprintf(pfile, "%d\n", rand() % 10000);
	}

	//建堆
	Heap hp;
	HeapInit(&hp);
	int* arr = (int*)malloc(sizeof(arr[0]) * k);
	for (int i = 0; i < k; i++)
	{
		arr[i] = INT_MIN;
	}
	HeapCreate(&hp, arr, k);
	fclose(pfile);


	//topK 选数
	FILE* pfile_ = fopen("test.txt", "r");	
	for (int i = 0; i < 1000; i++)
	{
		int tmp = 0;
		fscanf(pfile,"%d", &tmp);
		int hptop = HeapTop(&hp);
		if (tmp > hptop)
		{
			hp.a[0] = tmp;
			AdjustDown_samll(hp.a, k, 0);
		}
	}
	fclose(pfile_);
	Print(&hp);
	HeapDestroy(&hp);
}

void HeapSort(int *arr,int n)
{
	//建大堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown_big(arr, n, i);
	}

	//选数
	int end = n - 1;
	while (end)
	{
		Swap(&arr[0], &arr[end]);
		AdjustDown_big(arr, end, 0);
		end--;
	}
}