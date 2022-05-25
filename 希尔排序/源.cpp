#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void Print(int* arr,int arrlength)
{
	for (int i = 0; i < arrlength; i++)
	{
		printf("%d ", arr[i]);
	}
}

void shellSort(int* arr, int arrlength, int step)
{
	for (int i = 0; i < arrlength; i++)
	{
		for (int j = i + step; j < arrlength; j+=step)
		{
			for (int k = i; i < j; i += step)
			{
				if (arr[j] < arr[i])
				{
					int tmp = arr[j];
					for (int t = j; j >= i; j -= step)
					{
						arr[t ] = arr[t - step];
					}
					arr[i] = tmp;
				}
			}
		}
	}
}

int main()
{
	int arr[] = { 1,3,2,4,6,5,9,7,8 };
	int step[3] = { 5,3,1 };
	int arrlengh = sizeof(arr) / sizeof(int);
	for (int i = 0; i < 3; i++)
	{
		shellSort(arr, arrlengh, step[i]);
	}
	Print(arr, arrlengh);

	return 0;
}