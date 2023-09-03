#pragma once
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

//ֱ��ѡ������
void SelectSort(vector<int>& arr)
{
	int begin = 0;
	int end = arr.size() - 1;
	//ÿ�ҵ�һ��max��min��begin��end�ͻ���С��ֱ������û����
	while (begin < end)
	{
		//ÿ�δ��м�����������ֵ����Сֵ
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
		//��������ҵ���maxi�������ǵ�begin��������swap(arr[begin], arr[mini])֮��
		//max�洢�ľͲ���ԭ����beginλ�õ�ֵ�����ڵ�maxӦ����mini��λ�õ�ֵ
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
	//����
	for (int j = 0; j < arr.size(); j++)
	{
		//ÿ�ź�һ�˾ͻ���һ��������������ÿһ����Ҫ�ȽϵĴ�����
		//���ݸ���-��ǰ������-1:arr.size(0-j-1;

		//����һ��flag
		int flag = 0;
		for (int i = 0; i < arr.size() - j - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(arr[i], arr[i + 1]);
				flag = 1;
			}
		}
		//���ĳһ��û�з�����������flag����0����ζ�Ž��������Ѿ�������
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
	//��������
	int left = begin;
	int right = end;
	int keyi = left;
	while (left < right)//left==rightʱ�˳�
	{
		//�����left < right�����
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

	//�ָ����䣬[begin,left-1]---[key]---[left+1,end]
	_QuickSort(arr, begin, left - 1);
	_QuickSort(arr, left + 1, end);

}


void QuickSort(vector<int>& arr)
{
	_QuickSort(arr, 0, arr.size() - 1);
}

