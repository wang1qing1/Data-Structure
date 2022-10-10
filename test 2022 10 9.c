#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void PrintSort(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void Swap(int* e1, int* e2)
{
	int tmp = *e1;
	*e1 = *e2;
	*e2 = tmp;
}

//选择排序
void SelectSort(int *arr,int n)
{
	int begin = 0;
	int end = n - 1;
	
	while (begin < end)
	{
		int min_index = begin;
		int max_index = end;
		for (int i = begin; i <= end; i++)
		{
			if (arr[min_index] > arr[i])
			{
				min_index = i;
			}
			if (arr[max_index] < arr[i])
			{
				max_index = i;
			}
		}
		Swap(&arr[begin], &arr[min_index]);
		// 如果begin跟maxi重叠，需要修正一下maxi的位置
		if (begin == max_index)
		{
			max_index = min_index;
		}
		Swap(&arr[max_index], &arr[end]);
		++begin;
		--end;
	}
}

//
//堆排序，
//建堆的时间复杂度是 O(N)
//选数的时间复杂度是 O(LogN)
//所以堆排序的时间复杂度是 O(N*LogN)
//
void AdjustDwon(int* arr, int n, int root)
{
	int child = root * 2 + 1;
	while (child < n)
	{
		if (child < n - 1 && arr[child] < arr[child + 1])
		{
			child++;
		}
		if (arr[child] > arr[root])
		{
			Swap(&arr[child], &arr[root]);
			root = child;
			child = root * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int* arr, int n)
{
	//排升序，建大堆
	//建大堆
	int end = n - 1;
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDwon(arr, n, i);
	}
	while (end>0)
	{
		Swap(&arr[0], &arr[end]);
		AdjustDwon(arr, end , 0);
		end--;
	}
}

void TestHeapSort()
{
	int arr[] = { 1,5,4,2,3,6,7,8,9 };
	HeapSort(arr, sizeof(arr) / sizeof(int));
	PrintSort(arr, sizeof(arr) / sizeof(int));
}

void TestSelectSort()
{
	int arr[] = { 1,5,4,2,3,6,7,8,9 };
	SelectSort(arr, sizeof(arr) / sizeof(int));
	PrintSort(arr, sizeof(arr) / sizeof(int));
}

int main()
{
	TestHeapSort();
	TestSelectSort();
	return 0;
}