#include"Sort.h"
#include"Stact.h"
// ��������
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

// ϣ������ 
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

void Swap(int* n, int* m)
{
	int tmp = *n;
	*n = *m;
	*m = tmp;
}

// ѡ������ 
void SelectSort(int* a, int n)
{
	int end = n - 1;
	int begin = 0;
	while (begin <= end)
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

//���µ����㷨 
void AdjustDwon(int* a, int n, int root)
{
	int child = root * 2 + 1;
	while (child < n)
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

// ������ 
void HeapSort(int* a, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDwon(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDwon(a, end, 0);
		end--;
	}
}

// ð������ 
void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
			}
		}
	}
}

//����ȡ��
int MidArr(int* arr, int begin, int end)
{
	int mid = (begin + end) / 2;
	if (arr[begin] > arr[end])
	{
		if (arr[end] > arr[mid])
		{
			return end;
		}
		else if (arr[mid] > arr[begin])
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

//ָ�뷨
int NeedleQuick(int* a, int begin, int end)
{

	int mid = MidArr(a, begin, end);
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

//�ڿӷ�
int HoleQuick(int* arr, int begin, int end)
{
	//����ȡ��
	int mid = MidArr(arr, begin, end);
	Swap(&arr[mid], &arr[begin]);

	int left = begin;
	int right = end;

	int key = arr[left];
	int hole = left;
	while (left < right)
	{
		//������ arr[right] >= key ,ֻ�����ϸ��keyС�ģ����ڻ��ߵ��ھͱ�������
		while (left < right && arr[right] >= key)
		{
			right--;
		}
		arr[hole] = arr[right];
		hole = right;
		while (left < right && arr[left] <= key)
		{
			left++;
		}
		arr[hole] = arr[left];
		hole = left;
	}

	arr[hole] = key;
	return hole;
}
//������
int HoareQuick(int* arr, int begin, int end)
{
	//����ȡ��
	int mid = MidArr(arr, begin, end);
	Swap(&arr[mid], &arr[begin]);

	int left = begin;
	int right = end;
	int key = left;
	while (left < right)
	{
		while (left < right && arr[right] >= arr[key])
		{
			right--;
		}
		while (left < right && arr[left] <= arr[key])
		{
			left++;
		}
		Swap(&arr[left], &arr[right]);
	}
	Swap(&arr[left], &arr[key]);
	//��left right ����λ�ã�����key��λ��
	return left;
}

//����
void QuickSort(int* arr, int begin, int end)
{
	//С����ǵݹ��Ż���С�������ֱ�Ӳ�������
	if (end - begin + 1 <= 15)
	{
		InsertSort(arr + begin, end - begin + 1);
		return;
	}
	int key = HoareQuick(arr, begin, end);
	QuickSort(arr, begin, key - 1);
	QuickSort(arr, key + 1, end);
}

//���ŷǵݹ�
void QuickSortNoR(int* arr, int begin, int end)
{
	//����ջ�ṹ
	ST* st = StactInit();
	//����һ��ͷβ��ջ
	StactPushBank(st, begin);
	StactPushBank(st, end);
	//������ջ��ֱ��ջ��
	while (!StactEmpty(st))
	{
		//��ջ
		int stactend = StactTop(st);
		StactPopBank(st);
		int stactbegin = StactTop(st);
		StactPopBank(st);
		//����ջ�ģ�ͷβ���� ָ�뷨 key ��λ
		int keyi = HoleQuick(arr, stactbegin, stactend);

		//�ָ�����,��ջ [stactbegin]-[keyi],[keyi+1]-[stactend].
		if (stactbegin < keyi - 1)
		{
			StactPushBank(st, stactbegin);
			StactPushBank(st, keyi - 1);
		}
		if (keyi + 1 < stactend)
		{
			StactPushBank(st, keyi + 1);
			StactPushBank(st, stactend);
		}
	}
}

//������·����
void ThreewayQuickSort(int* arr, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}
	if ((end - begin + 1) < 15)
	{
		InsertSort(arr + begin, end - begin + 1);
	}
	else
	{
		int mid = MidArr(arr, begin, end);
		Swap(&arr[mid], &arr[begin]);

		int key = arr[begin];
		int left = begin; int right = end;
		int cur = left + 1;
		while (cur <= right)
		{
			if (arr[cur] < key)
			{
				Swap(&arr[cur], &arr[left]);
				left++;
				cur++;
			}
			else if (arr[cur] > key)
			{
				Swap(&arr[cur], &arr[right]);
				right--;
			}
			else //arr[cur]==arr[keyi]
			{
				cur++;
			}
		}
		//[begin]-[left-1]С��key
		//[left]-[right] ����key
		//[cur]-[end] ����key
		ThreewayQuickSort(arr, begin, left - 1);
		ThreewayQuickSort(arr, right + 1, end);
	}
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
		if (arr[begin2] < arr[begin1])
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
	memcpy(arr + begin, tmp + begin, sizeof(int) * (end - begin + 1));
}


//�鲢����
void MergeSort(int* arr, int n)
{
	int* tmp = (int*)malloc(n * sizeof(int));
	if (tmp == NULL)
	{
		perror("malloc ");
		exit(-1);
	}
	_MergeSort(arr, 0, n - 1, tmp);
	free(tmp);
	tmp = NULL;
}

//�ǵݹ�鲢����
void MergeSortNoR(int* arr, int n)
{
	int* tmp = malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc ");
		exit(-1);
	}
	int rangeN = 1;
	while (rangeN < n)
	{
		for (int i = 0; i < n; i += 2 * rangeN)
		{
			int begin1 = i; int end1 = begin1 + rangeN - 1;
			int begin2 = i + rangeN; int end2 = begin2 + rangeN - 1;
			int j = begin1;
			//���[begin2]-[end2]�Ѿ�ȫ��Խ�磬����ʣ�µ�[begin1]-[n]����[begin1]-[end1]
			//�������ٹ鲢
			if (end1 >= n)
			{
				break;
			}
			else if (begin2 >= n)
			{
				break;
			}
			else if (end2 >= n)
			{
				end2 = n - 1;
			}

			while (begin1 <= end1 && begin2 <= end2)
			{
				if (arr[begin1] <= arr[begin2])
				{
					tmp[j++] = arr[begin1++];
				}
				if (arr[begin2] < arr[begin1])
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
			memcpy(arr + i, tmp + i, sizeof(int) * (end2 - i + 1));
		}
		rangeN *= 2;
	}
	free(tmp);
	tmp = NULL;
}

//�ǵݹ�鲢����
void MergeSortNoR2(int* arr, int n)
{
	int* tmp = malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc ");
		exit(-1);
	}
	int rangeN = 1;
	while (rangeN < n)
	{
		for (int i = 0; i < n; i += 2 * rangeN)
		{

			int begin1 = i; int end1 = begin1 + rangeN - 1;
			int begin2 = i + rangeN; int end2 = begin2 + rangeN - 1;
			int j = begin1;



			//��end1��ʼԽ��
			if (end1 >= n)
			{
				//��֤[begin1]-[n-1]֮��������
				end1 = n - 1;
				//��������ʱ�����뱣֤[begin2]-[end2]������Ч
				begin2 = 1;
				end2 = -1;
			}//��begin2 ��ʼԽ�磬
			else if (begin2 >= n)
			{
				//[begin2]-[end2]������Ч
				begin2 = 1;
				end2 = -1;
			}
			else if (end2 >= n)
			{
				end2 = n - 1;
			}
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (arr[begin1] <= arr[begin2])
				{
					tmp[j++] = arr[begin1++];
				}
				if (arr[begin2] < arr[begin1])
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

		}
		memcpy(arr, tmp, sizeof(int) * n);
		rangeN *= 2;
	}
	free(tmp);
	tmp = NULL;
}
