#pragma once
#include<algorithm>
#include<iostream>
#include<vector>
#include<stack>
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

//���������һ���
int Hall(vector<int>&arr,int left,int right)
{
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
	return left;
}

int Hole(vector<int>& arr, int left, int right)
{
	int key = arr[left];
	//�������Ϊ��
	int Holei = left;
	while (left < right)
	{
		//�����Ϊ�ӣ����ұ߿�ʼ�ң���keyС��
		while (left < right && arr[right] > key)
		{
			right--;
		}
		//����keyС��Ų��ȥ����ʱ�����λ�ñ���µĿ�
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

//˫ָ��
int DoublePointer(vector<int>& arr, int left, int right)
{
	int key = arr[left];
	int prev = left;
	int cur = prev + 1;
	while (cur <= right)
	{			
		//cur������keyС��ͣ�£���++prev����
		if (arr[cur] < key&&++prev!=cur)
		{
			swap(arr[prev], arr[cur]);
		}
		cur++;
	}
	//��curԽ��ʱ��prev��left����
	swap(arr[left], arr[prev]);
	return prev;
}

void _RQuickSort(vector<int>& arr, int begin, int end)
{
	//С�����Ż�
	if (end - begin<=3)
	{
		InsertSort(arr, begin, end);
		return;
	}
	//��������
	int left = begin;
	int right = end;
	//����ȡ��
	int mid = getmidnum(arr,begin, end);
	swap(arr[mid], arr[left]);

	int keyi = DoublePointer(arr, left, right);

	//�ָ����䣬[begin,left-1]---[key]---[left+1,end]
	_RQuickSort(arr, begin, keyi - 1);
	_RQuickSort(arr, keyi + 1, end);
}

void _QuickSort(vector<int>& arr, int begin, int end)
{
	stack<int> st;
	//��������
	int left = begin;
	int right = end;

	st.push(begin);
	st.push(end);

	while (!st.empty())
	{
		int right = st.top();
		st.pop();
		int left = st.top();
		st.pop();

		//����ȡ��
		int mid = getmidnum(arr, left, right);
		swap(arr[mid], arr[left]);

		int keyi = DoublePointer(arr, left, right);

		//key���ұ�
		if (keyi < right)
		{
			st.push(keyi + 1);
			st.push(right);
		}

		//key�����
		if (keyi > left)
		{
			st.push(left);
			st.push(keyi - 1);
		}
	}
}

void QuickSort(vector<int>& arr)
{
	_QuickSort(arr, 0, arr.size() - 1);
}

void _RMergeSort(int* a, int begin, int end, int* tmp)
{
	if (begin > end)
		return;

	int mid = (begin + end) / 2;
	// [begin, mid] [mid+1, end] �ݹ�������������
	_RMergeSort(a, begin, mid, tmp);
	_RMergeSort(a, mid + 1, end, tmp);

	// �鲢[begin, mid] [mid+1, end]
	//...

	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int i = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] <= a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}

	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}

	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}

	memcpy(a + begin, tmp + begin, sizeof(int) * (end - begin + 1));
}

void MergeSort(int* arr,int n)
{
	int* tmp = new int[n];
	_RMergeSort(arr, 0, n-1,tmp);
}





