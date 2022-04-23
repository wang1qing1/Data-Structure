#pragma once
#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#define SEQ_INIT_SUZE 10//初始容量
#define SEQ_INC_SIZE 2  //
typedef int ElemType;
typedef struct
{
	ElemType* data;
	int capacity;//容量；
	int cursize;//元素个数；
}Seqlist;
int re_capacity(Seqlist* plist);//返回容量；

int re_cursize(Seqlist* plist);//返回现存元素个数；

int add_capacity(Seqlist* plist);//判断是否增容；

void Judge_add_capacity(Seqlist* plist);//判断是否增容；

void Init(Seqlist* plist);//结构体初始化；

void Depo_data(Seqlist* plist);//顺序表填充数据；

int Insert_data(Seqlist* plist,int n,int num);//插入一个数据；

void Insert_data_head(Seqlist* plist,int num);//首行插入；

void Insert_data_back(Seqlist* plist,int num);//末尾插入；

void print(Seqlist* plist);

int dele_data(Seqlist* plist,int pos);//删除指定坐标的数据；

int dele_data_data(Seqlist* plist,int val);//删除指定数据；

int seek_data(Seqlist* plist,int num);//查找一个数据；

int change_data(Seqlist* plist);//改动指定的数据；

void destroy_data(Seqlist* plist);//销毁顺序表

void delete_duplicaate_all(Seqlist* plist,int val);
