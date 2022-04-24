#include"ST.h"

void StactPrin(ST*stact)//��ӡ
{
	assert(stact);
	for (int i = 0; i < stact->top; i++)
	{
		printf("%d ", stact->a[i]);
	}

}

void StactInit(ST* stact)//��ʼ��
{
	assert(stact);
	stact->a = NULL;
	stact->capacity = 0;
	stact->top = 0;
}

void StactDestry(ST* stact)//����
{
	assert(stact);
	free(stact->a);
	stact->a = NULL;
	stact->capacity = 0;
	stact->top = 0;
}

void StactPush(ST* stact, STDATATYPE x)//��������
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

void StactPop(ST*stact)//ɾ������
{
	assert(stact);
	assert(stact->top > 0);
	stact->top--;
}

STDATATYPE ReadStactData(ST*stact)//������
{
	assert(stact);
	assert(stact->top > 0);
	return stact->a[stact->top-1];
}

STDATATYPE GetStactData(ST* stact)//������
{
	assert(stact);
	assert(stact->top > 0);
	return stact->a[--stact->top];
}

int Stactsize(ST* stact)//ջ���ݸ�����ѯ��
{
	assert(stact);
	return stact->top;
}

bool StactEmpty(ST* stact)//ջ�пգ�
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
