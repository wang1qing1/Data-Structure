#include"ST.h"

void StactPrin(ST*stact)//打印
{
	assert(stact);
	for (int i = 0; i < stact->top; i++)
	{
		printf("%d ", stact->a[i]);
	}

}

void StactInit(ST* stact)//初始化
{
	assert(stact);
	stact->a = NULL;
	stact->capacity = 0;
	stact->top = 0;
}

void StactDestry(ST* stact)//销毁
{
	assert(stact);
	free(stact->a);
	stact->a = NULL;
	stact->capacity = 0;
	stact->top = 0;
}

void StactPush(ST* stact, STDATATYPE x)//增加数据
{
	assert(stact);
	 
	if (stact->capacity == stact->top)
	{
		int newcapacity = stact->capacity == 0 ? 4 : stact->capacity * 2;
		STDATATYPE* aa = /*(STDATATYPE*)*/realloc(stact->a, sizeof(STDATATYPE) * newcapacity);
		if (aa == NULL)
		{
			printf("realloc false!!!\n");
			exit(-1);
		}
		stact->a = aa;
		stact->capacity = newcapacity;
	}
	stact->a[stact->top] = x;
	stact->top++;
}

void StactPop(ST*stact)//删除数据
{
	assert(stact);
	assert(stact->top > 0);
	stact->top--;
}

STDATATYPE ReadStactData(ST*stact)//读数据
{
	assert(stact);
	assert(stact->top > 0);
	return stact->a[stact->top-1];
}

STDATATYPE GetStactData(ST* stact)//拿数据
{
	assert(stact);
	assert(stact->top > 0);
	return stact->a[--stact->top];
}

int Stactsize(ST* stact)//栈数据个数查询；
{
	assert(stact);
	return stact->top;
}

bool StactEmpty(ST* stact)//栈判空；
{
	assert(stact);
	/*if (stact->top == 0)
	{
		return false;
	}
	else
	{
		return true;
	}*/
	return stact->top == 0;
}
