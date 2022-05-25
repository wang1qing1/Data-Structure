#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void InserSort(int* arr, int arrnum)
{
	for (int i = 1; i < arrnum; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[i])
			{
				int tmp = arr[i];
				for (int k = i-1; k >= j; k--)
				{
					arr[k+1] = arr[k];
				}
				arr[j] = tmp;
			}
		}
	}
}

int main()
{
	int arr[] = { 10,2,50,6,41,8,5,54,66 };
	int arrnum = sizeof(arr) / sizeof(int);
	InserSort(arr, arrnum);
	for (int i = 0; i < arrnum; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}