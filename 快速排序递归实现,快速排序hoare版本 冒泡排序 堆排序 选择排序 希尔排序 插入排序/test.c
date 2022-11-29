#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

// 插入排序
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[i + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

// 希尔排序
void ShellSort(int* a, int n)
{
	int grap = n;
	while (grap)
	{
		grap = grap / 2;
		for (int i = 0; i < n - grap; i++)
		{
			int end = i;
			int tmp = a[i + grap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + grap] = a[end];
					end -= grap;
				}
				else
				{
					break;
				}
			}
			a[end + grap] = tmp;
		}
	}
}

void Swap(int* n,int* m)
{
	int tmp = *n;
	*n = *m;
	*m = tmp;
}

// 选择排序
void SelectSort(int* a, int n)
{
	int end = n-1 ;
	int begin = 0;
	while(begin<=end)
	{
		int imax = begin;
		int imin = begin;
		for (int j = begin; j <= end; j++)
		{
			if (a[j] < a[imin])
			{
				imin = j;
			}
			if (a[j] > a[imax])
			{
				imax = j;
			}
		}
		Swap(&a[begin], &a[imin]);
		if (begin == imax)
		{
			imax = imin;
		}
		Swap(&a[end], &a[imax]);
		end--;
		begin++;
	}
}


//向下调整算法
void AdjustDwon(int* a, int n, int root)
{
	int child = root * 2 + 1;
	while(child<n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			child++;
		}
		if (a[child] > a[root])
		{
			Swap(&a[child], &a[root]);
			root = child;
			child = root * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

// 堆排序
void HeapSort(int* a, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDwon(a, n, i);
	}
	int end = n-1;
	while (end>0)
	{
		Swap(&a[0], &a[end]);
		AdjustDwon(a, end, 0);
		end--;
	}
}

// 冒泡排序
void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i -1; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
			}
		}
	}
}


// 快速排序递归实现
// 快速排序hoare版本
void PartSort1(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int end = right;
	int begin = left;
	int ikey = left;
	while (left < right)
	{
		while (left<right && a[right] >= a[ikey])
		{
			right--;
		}
		while (left < right && a[left] <= a[ikey])
		{
			left++;
		}
		Swap(&a[left], &a[right]);
	}
	Swap(&a[ikey], &a[left]);
	ikey = left;
	PartSort1(a, begin, ikey-1);
	PartSort1(a, ikey + 1, end);
}


void Print(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}


int main()
{
	int arr[] = { 6,10,5,12,78,43,59,32,4,1,8,7,3,2,9 };
	//InsertSort(arr, sizeof(arr) / sizeof(int));
	//ShellSort(arr, sizeof(arr) / sizeof(int));
	//HeapSort(arr, sizeof(arr) / sizeof(int));
	//Print(arr, sizeof(arr) / sizeof(int));

	SelectSort(arr, sizeof(arr) / sizeof(int));
	Print(arr, sizeof(arr) / sizeof(int));
	BubbleSort(arr, sizeof(arr) / sizeof(int));
	//PartSort1(arr,0, sizeof(arr)/sizeof(int)-1);
	Print(arr, sizeof(arr) / sizeof(int));
}
