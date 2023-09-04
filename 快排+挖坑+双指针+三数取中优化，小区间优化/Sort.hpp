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

int getmidnum(vector<int>& arr,int begin,int end)
{
	int mid = (begin + end) / 2;
	if (arr[begin] < arr[end])
	{
		if (arr[end] < arr[mid])
		{
			return end;
		}
		else if (arr[mid] < arr[begin])
		{
			return begin;
		}
		else
		{
			return mid;
		}
	}
	else //arr[begin] > arr[end]
	{
		if (arr[mid] > arr[begin])
		{
			return begin;
		}
		else if (arr[end] > arr[mid])
		{
			return end;
		}
		else
		{
			return mid;
		}
	}
}

//void InsertSort(std::vector<int>& arr)
//{
//	for (int i = 0; i < arr.size() - 1; i++)
//	{
//		int end = i;
//		int tmp = arr[end + 1];
//		while (end >= 0)
//		{
//			if (arr[end] < tmp)
//			{
//				break;
//			}
//			else
//			{
//				arr[end + 1] = arr[end];
//				end--;
//			}
//		}
//		arr[end + 1] = tmp;
//	}
//}

void InsertSort(vector<int>& arr,int begin,int end)
{
	for (int i = begin; i < end; i++)
	{
		int End = i;
		int tmp = arr[End + 1];
		while (End >= begin)
		{
			if (tmp < arr[End])
			{
				arr[End + 1] = arr[End];
				End--;
			}
			else
			{
				break;
			}
		}
		arr[End + 1] = tmp;
	}
}

//霍尔法左右划分
int Hall(vector<int>&arr,int left,int right)
{
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
	return left;
}

int Hole(vector<int>& arr, int left, int right)
{
	int key = arr[left];
	//最左边作为坑
	int Holei = left;
	while (left < right)
	{
		//左边作为坑，从右边开始找，比key小的
		while (left < right && arr[right] > key)
		{
			right--;
		}
		//将比key小的挪过去，此时的这个位置变成新的坑
		arr[Holei] = arr[right];
		Holei = right;

		while (left < right && arr[left] < key)
		{
			left++;
		}
		arr[Holei] = arr[left];
		Holei = left;
	}
	arr[Holei] = key;
	return Holei;
}

int DoublePointer(vector<int>& arr, int left, int right)
{
	int key = arr[left];
	int prev = left;
	int cur = prev + 1;
	while (cur <= right)
	{
		if (arr[cur] < key&&++prev!=cur)
		{
			swap(arr[prev], arr[cur]);
		}
		cur++;
	}
	swap(arr[left], arr[prev]);
	return prev;
}

void _QuickSort(vector<int>& arr, int begin, int end)
{
	//小区间优化
	if (end - begin<=3)
	{
		InsertSort(arr, begin, end);
		return;
	}
	//单趟排序
	int left = begin;
	int right = end;
	//三数取中
	int mid = getmidnum(arr,begin, end);
	swap(arr[mid], arr[left]);

	int keyi = DoublePointer(arr, left, right);

	//分割区间，[begin,left-1]---[key]---[left+1,end]
	_QuickSort(arr, begin, keyi - 1);
	_QuickSort(arr, keyi + 1, end);
}


void QuickSort(vector<int>& arr)
{
	_QuickSort(arr, 0, arr.size() - 1);
}

