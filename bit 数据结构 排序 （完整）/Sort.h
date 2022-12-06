#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Swap(int* n, int* m);

//��������
void InsertSort(int* arr, int n);

//ϣ������
void ShellSort(int* a, int n);

// ѡ������ 
void SelectSort(int* a, int n);

//���µ����㷨 
void AdjustDwon(int* a, int n, int root);

// ð������ 
void BubbleSort(int* a, int n);

//����
void QuickSort(int* arr, int begin, int end);

//����ָ�뷨
int NeedleQuick(int* a, int begin, int end);

//����ȡ��
int MidArr(int* arr, int begin, int end);

//�ڿӷ�
int HoleQuick(int* arr, int begin, int end);

//������
int HoareQuick(int* arr, int begin, int end);

//���ŷǵݹ�
void QuickSortNoR(int* arr, int begin, int end);

//��������ȡ��
void ThreewayQuickSort(int* arr, int begin, int end);

//�鲢����
void MergeSort(int* arr, int n);
void _MergeSort(int* arr, int begin, int end, int* tmp);

//�ǵݹ�鲢����
void MergeSortNoR(int* arr, int n);