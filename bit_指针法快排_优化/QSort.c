#include"QSort.h"

//插入排序
void InsertSort(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = arr[end + 1];
		while (end >= 0)
		{
			if (arr[end] > tmp)
			{
				arr[end + 1] = arr[end];
				end--;
			}
			else
			{
				break;
			}
		}
		arr[end + 1] = tmp;
	}
}
void Swap(int* n, int* m)
{
	int tmp = *m;
	*m = *n;
	*n = tmp;
}

int MidArr(int* arr, int begin, int end)
{
	int mid = (begin + end) / 2;
	if (arr[begin] > arr[end])
	{
		if (arr[end] > arr[mid])
		{
			return end;
		}
		else if(arr[mid]>arr[begin])
		{
			return begin;
		}
		else if (arr[mid] > arr[end] && arr[mid] < arr[begin])
		{
			return mid;
		}
	}
	else //arr[begin] < arr[end]
	{
		if (arr[mid] < arr[begin])
		{
			return begin;
		}
		else if (arr[end] < arr[mid])
		{
			return end;
		}
		else if (arr[mid] > arr[begin] && arr[mid] < arr[begin])
		{
			return mid;
		}
	}
}

//指针法
int NeedleQuick(int* a, int begin, int end)
{

	int mid = MidArr(a,begin,end);
	Swap(&a[mid], &a[begin]);
	int prev = begin;
	int cur = prev + 1;
	int key = begin;
	while (cur <= end)
	{
		if (a[cur] < a[key] && ++prev != cur)
		{
			Swap(&a[prev], &a[cur]);
		}
		cur++;
	}
	Swap(&a[prev], &a[key]);
	return prev;
}

//挖坑法
int HoleQuick(int* arr, int begin, int end)
{

}
void QuickSort(int* arr, int begin, int end)
{
	if (end - begin + 1 <= 15)
	{
		InsertSort(arr + begin, end - begin + 1);
		return;
	}
	int key= NeedleQuick(arr, begin, end);
	QuickSort(arr, begin, key - 1);
	QuickSort(arr, key + 1, end);
}