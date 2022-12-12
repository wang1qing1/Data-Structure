#include"SeqList.h"

void SLCheckCapacity(SL* ps)
{
	assert(ps);

	if (ps->size == ps->capacity)
	{
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, newCapacity*sizeof(SLDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newCapacity;
	}
}

//void SLInit(SL* ps)
//{
//	assert(ps);
//
//	ps->a = NULL;
//	ps->size = 0;
//	ps->capacity = 0;
//}

void SLDestroy(SL* ps)
{
	assert(ps);

	//if (ps->a != NULL)
	if (ps->a)
	{
		free(ps->a);
		ps->a = NULL;
		ps->size = ps->capacity = 0;
	}
}


void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	SLCheckCapacity(ps);
	
	ps->a[ps->size] = x;
	ps->size++;

	//SLInsert(ps, ps->size, x);
}

void SLPopBack(SL* ps)
{
	assert(ps);
	ps->size--;

	//SLErase(ps, ps->size-1);
}


void SLPushFront(SL* ps)
{
	assert(ps);
	SLCheckCapacity(ps);

	Figure x;
	scanf("%s%s%d%d%d%d%d", x.name, x.identity, &x.physical_attact, &x.physical_defend, &x.spell_attack, &x.spell_defend);
	// 挪动数据
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}

	ps->a[0] = x;
	ps->size++;

}

void SLPopFront(SL* ps)
{
	assert(ps);
	assert(ps->size > 0);

	int begin = 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		begin++;
	}

	ps->size--;
}

// 在pos位置插入数据
void SLInsert(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0);
	assert(pos <= ps->size);

	SLCheckCapacity(ps);
	Figure x;
	scanf("%s%s%d%d%d%d%d", x.name, x.identity, &x.physical_attact, &x.physical_defend, &x.spell_attack, &x.spell_defend);
	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}

	ps->a[pos] = x;
	ps->size++;
}

// 删除pos位置数据
void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0);
	assert(pos < ps->size);
	//assert(ps->size > 0);
	
	// 挪动数据覆盖
	int begin = pos + 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		begin++;
	}

	ps->size--;
}

int SLFind(SL* ps)
{
	assert(ps);
	char n[30];
	scanf("%s", n);
	for (int i = 0; i < ps->size; ++i)
	{
		if (ps->a[i].name == n)
		{
			return i;
		}
	}

	return -1;
}

