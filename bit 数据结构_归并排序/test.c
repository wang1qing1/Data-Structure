#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}

		a[end + 1] = tmp;
	}
}

void Print(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void _MergeSort(int* arr, int begin, int end, int* tmp)
{
	if (begin >= end)
	{
		return;
	}
	int mid = (begin + end) / 2;
	int begin1 = begin; int end1 = mid;
	int begin2 = mid + 1; int end2 = end;
	_MergeSort(arr, begin1, end1, tmp);
	_MergeSort(arr, begin2, end2, tmp);
	int j = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] <= arr[begin2])
		{
			tmp[j++] = arr[begin1++];
		}
		if(arr[begin2]<arr[begin1] )
		{
			tmp[j++] = arr[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		tmp[j++] = arr[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[j++] = arr[begin2++];
	}
	memcpy(arr+begin, tmp+begin, sizeof(int) * (end - begin+1));
}
void MergeSort(int* arr, int n)
{
	int* tmp = (int*)malloc(n*sizeof(int));
	if (tmp == NULL)
	{
		perror("malloc ");
		exit(-1);
	}
	_MergeSort(arr, 0, n - 1, tmp);
	free(tmp);
	tmp = NULL;
}

int main()
{
	int arr[100];
	srand(time(0));
	for (int i = 0; i < 100; i++)
	{
		arr[i] = rand() % 1000;
	}
	//int arr[] = { 2,1,5,6,9,8,7,4,3 };
	int n = sizeof(arr) / sizeof(int);
	MergeSort(arr, n);
	//InsertSort(arr, n);
	Print(arr, n);

}