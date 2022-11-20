#include"HeapSort.h"

void Swap(int* n, int* m)
{
	int tmp = *n;
	*n = *m;
	*m = tmp;
}

//向下调整算法
void AdjustDown(int *arr,int size ,int parent)
{
	assert(arr);
	assert(parent <= size);
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && arr[child + 1] > arr[child])
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

//堆排序
void HeapSort(int* arr, int size)
{
	//建堆
	for (int i = (size - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(arr, size, i);
	}
	//选数
	while (size)
	{
		Swap(&arr[0], &arr[--size]);
		AdjustDown(arr, size, 0);
	}
}

