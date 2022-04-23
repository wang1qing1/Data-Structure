#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS
#include"data.h"
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#define SEQ_INIT_SUZE 10//初始容量
#define SEQ_INC_SIZE 2  //
typedef int ElemType;
ElemType* data1 = NULL;
int re_capacity(Seqlist* plist)//返回容量；
{
	assert(plist);
	return plist->capacity;
}
int re_cursize(Seqlist* plist)//返回现存元素个数；
{
	assert(plist);
	return plist->cursize;
}
int add_capacity(Seqlist* plist)//判断是否增容；
{
	assert(plist);
	if (re_capacity(plist) == re_cursize(plist))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void Judge_add_capacity(Seqlist* plist)//判断是否增容；
{
	if (add_capacity(plist))
	{
		ElemType* data = (ElemType*)realloc(plist->data, plist->capacity * SEQ_INC_SIZE);
		plist->capacity *= SEQ_INC_SIZE;
		if (NULL == data)
		{
			printf("增容失败");
		}
		//free(plist->data);
		//plist->data = data1;
	}
}
void Init(Seqlist* plist)//结构体初始化；
{
	assert(plist);
	plist->capacity = SEQ_INIT_SUZE;//初始容量设置成10；
	plist->cursize = 0;//由于还没有存入数据，所以当前顺序表中数据为0；
	plist->data = (ElemType*)malloc(sizeof(ElemType) * plist->capacity);//动态为顺序表开辟可以容纳10个int类型的空间，
	if (plist->data == NULL) //如果开辟失败 ,malloc就会返回NULL（空指针）；                                         
	{                        //如果顺序表空间都没有开辟出来，后面就更不用操作，我们直接使用
		exit(-1);            //exit（-1）；暴力结束；
	}
}
void Depo_data(Seqlist* plist)//顺序表填充数据；
{
	assert(plist);
	for (int i = 0; i < 6; i++)
	{
		plist->data[i] = i;
		plist->cursize++;
	}
}
int Insert_data(Seqlist* plist,int n,int num)//插入一个数据；
{
	//n——插入数据的位置，num——需要插入数据的位置；
	assert(plist);
	if (n > plist->cursize - 1 || n < 0)
	{//判断，我们插入的位置是不是在我们的有效数据的范围里面；
		printf("插入位置错误\n");//如果插入错误，我们就提示出，并结束这个函数。
		return 0;
	}
	for (int i = plist->cursize - 1; i >= n; i--)
	{
		plist->data[i + 1] = plist->data[i];
	}
	plist->data[n] = num;
	plist->cursize++;
	Judge_add_capacity(plist);
}
void Insert_data_head(Seqlist* plist,int num)//首行插入；
{
	assert(plist);
	for (int i = plist->cursize - 1; i >= 0; i--)
	{
		plist->data[i + 1] = plist->data[i];
	}
	plist->data[0] = num;
	plist->cursize++;
	Judge_add_capacity(plist);
}
void Insert_data_back(Seqlist* plist,int num)//末尾插入；
{
	assert(plist);
	plist->data[plist->cursize] = num;
	plist->cursize++;
	Judge_add_capacity(plist);
}
void print(Seqlist* plist)
{
	assert(plist);
	for (int i = 0; i < plist->cursize; i++)
	{
		printf("%d ", plist->data[i]);
	}
	printf("\n");
	printf("现存元素数：%d\n", plist->cursize);
	printf("顺序表容量：%d\n", plist->capacity);
}
int dele_data(Seqlist* plist,int pos)//删除指定坐标的数据；
{
	assert(plist);
	if (pos > plist->cursize || pos < 0)
	{
		printf("删除错误\n");
		return 0;
	}
	for (int i = pos; i < plist->cursize - 1; i++)
	{
		plist->data[i] = plist->data[i + 1];
	}
	plist->cursize--;
}
int dele_data_data(Seqlist* plist,int val)//删除指定数据；
{
	assert(plist);
	if ((seek_data (plist,val))> plist->cursize || (seek_data(plist, val) < 0))
	{
		printf("删除错误\n");
		return 0;
	}
	for (int i = seek_data(plist, val); i < plist->cursize - 1; i++)
	{
		plist->data[i] = plist->data[i + 1];
	}
	plist->cursize--;
}
int seek_data(Seqlist* plist,int num)//查找一个数据；
{
	assert(plist);
	int i = 0;
	for (i = 0; i <= plist->cursize - 1; i++)
	{
		if (plist->data[i] == num)
		{
			return i;
		}
	}
	return -1;
}
int change_data(Seqlist* plist)//改动指定的数据；
{
	assert(plist);
	int pos = 0;
	ElemType num;
	printf("请输入需要修改的数据的下表 pos ,和改动后的数据 num \n");
	scanf("%d %d", &pos, &num);
	if (pos > plist->cursize || pos < 0)
	{
		printf("修改错误\n");
		return 0;
	}
	plist->data[pos] = num;
}
void destroy_data(Seqlist* plist)//销毁顺序表
{
	assert(plist);
	free(plist->data);
	plist->data = NULL;
}
//void delete_duplicaate_all(Seqlist*plist,int val)//错误示例；错误未知
//{
//	for (int i = 0; i < plist->cursize; i++)
//	{
//		if (plist->data[i] == val)
//		{
//			dele_data_data(plist, val);
//		}
//	}
//}
//void delete_duplicaate_all(Seqlist* plist, int val)//错误示例；错误未知
//{
//	assert(plist);
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < plist->cursize; i++)
//	{
//		if (plist->data[i] != val)
//		{
//			plist->data[j++] = plist->data[i];
//		}
//		else
//		{
//			plist->cursize--;
//		}
//	}
//	
//}

void delete_duplicaate_all(Seqlist* plist, int val)
{
	assert(plist);
	int i = 0;
	int j = 0;
	for (i = 0; i < plist->cursize ; i++)
	{
		if (plist->data[i] != val)
		{
			plist->data[j++] = plist->data[i];
		}
	}
	plist->cursize = j;
}
