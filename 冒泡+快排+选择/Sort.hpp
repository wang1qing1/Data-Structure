#pragma once
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

//直接选择排序
void SelectSort(vector<int>& arr)
{
	int begin = 0;
	int end = arr.size() - 1;
	//每找到一对max和min，begin和end就会缩小，直到区间没有数
	while (begin < end)
	{
		//每次从中间的区间找最大值和最小值
		int maxi = begin; int mini = begin;
		for (int i = begin + 1; i <= end; i++)
		{
			if (arr[maxi] < arr[i])
			{
				maxi = i;
			}
			if (arr[mini] > arr[i])
			{
				mini = i;
			}
		}
		swap(arr[begin], arr[mini]);
		//如果我们找到的maxi就是我们的begin，当我们swap(arr[begin], arr[mini])之后
		//max存储的就不是原来的begin位置的值，现在的max应该是mini的位置的值
		if (begin == maxi)
		{
			maxi = mini;
		}
		swap(arr[end], arr[maxi]);
		begin++;
		end--;
	}
}

void BubbleSort(vector<int>& arr)
{
	//趟数
	for (int j = 0; j < arr.size(); j++)
	{
		//每排号一趟就会有一个数据有序，所以每一趟需要比较的次数：
		//数据个数-当前的趟数-1:arr.size(0-j-1;

		//定义一个flag
		int flag = 0;
		for (int i = 0; i < arr.size() - j - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(arr[i], arr[i + 1]);
				flag = 1;
			}
		}
		//如果某一中没有发生交换，即flag还是0，意味着接下来的已经有序了
		if (flag == 0)
		{
			break;
		}
	}
}
void _QuickSort(vector<int>& arr, int begin, int end)
{
	//
	if (begin > end)
	{
		return;
	}
	//单趟排序
	int left = begin;
	int right = end;
	int keyi = left;
	while (left < right)//left==right时退出
	{
		//这里的left < right，如果
		while (left < right && arr[right] >= arr[keyi])
		{
			right--;
		}
		while (left < right && arr[left] <= arr[keyi])
		{
			left++;
		}
		swap(arr[left], arr[right]);
	}
	swap(arr[keyi], arr[left]);

	//分割区间，[begin,left-1]---[key]---[left+1,end]
	_QuickSort(arr, begin, left - 1);
	_QuickSort(arr, left + 1, end);

}


void QuickSort(vector<int>& arr)
{
	_QuickSort(arr, 0, arr.size() - 1);
}

