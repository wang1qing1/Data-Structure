#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void PrintSort(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//²åÈçÅÅÐò¡ª¡ªÖ±½Ó²åÈçÅÅÐò
void InserSort(int *arr,int n)
{
	for (int end = 0; end < n - 1; end++)
	{
		int tmp = arr[end + 1];
		for (end; end >= 0; end--)
		{
			if (arr[end] > tmp)
			{
				arr[end + 1] = arr[end];
			}
			else
			{
				break;
			}
		}
		arr[end + 1] = tmp;
	}
}

//²åÈçÅÅÐò¡ª¡ªÏ£¶ûÅÅÐò
void ShellSort(int* arr, int n)
{
	int gap=6;
	while (gap)
	{
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = arr[end + gap];
			for (end; end >= 0; end -= gap)
			{
				if (arr[end] > tmp)
				{
					arr[end + gap] = arr[end];
				}
				else
				{
					break;
				}
			}
			arr[end + gap] = tmp;
		}
		gap /= 2;
	}
}

void TestShellSort()
{
	int arr[] = { 1,5,4,2,3,6,7,8,9 };
	ShellSort(arr, sizeof(arr) / sizeof(int));
	PrintSort(arr, sizeof(arr) / sizeof(int));
}

void TestInserSort()
{
	int arr[] = { 1,5,4,2,3,6,7,8,9 };
	InserSort(arr, sizeof(arr) / sizeof(int));
	PrintSort(arr, sizeof(arr) / sizeof(int));
}

int main()
{
	//TestInserSort();
	TestShellSort();

	return 0;
}



















