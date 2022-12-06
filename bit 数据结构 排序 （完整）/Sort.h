#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Swap(int* n, int* m);

//插如排序
void InsertSort(int* arr, int n);

//希尔排序
void ShellSort(int* a, int n);

// 选择排序 
void SelectSort(int* a, int n);

//向下调整算法 
void AdjustDwon(int* a, int n, int root);

// 冒泡排序 
void BubbleSort(int* a, int n);

//快排
void QuickSort(int* arr, int begin, int end);

//快排指针法
int NeedleQuick(int* a, int begin, int end);

//三数取中
int MidArr(int* arr, int begin, int end);

//挖坑法
int HoleQuick(int* arr, int begin, int end);

//霍尔法
int HoareQuick(int* arr, int begin, int end);

//快排非递归
void QuickSortNoR(int* arr, int begin, int end);

//快排三数取中
void ThreewayQuickSort(int* arr, int begin, int end);

//归并排序
void MergeSort(int* arr, int n);
void _MergeSort(int* arr, int begin, int end, int* tmp);

//非递归归并排序
void MergeSortNoR(int* arr, int n);