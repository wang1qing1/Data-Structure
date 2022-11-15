#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>


typedef int STDateType;

typedef struct Stact
{
	STDateType* date;
	int capacity;
	int top;
}ST;

ST* StactInit()
{
	ST* Stact = (ST*)malloc(sizeof(ST));
	Stact->capacity = 4;
	Stact->top = 0;
	Stact->date = (STDateType*)malloc(sizeof(STDateType) * Stact->capacity);
	return Stact;
}

void StactPushBank(ST* Stact, STDateType x)
{
	assert(Stact);
	if (Stact->capacity == Stact->top)
	{
		STDateType* tmp = (STDateType*)realloc(Stact->date, Stact->capacity * 2 * sizeof(STDateType));
		if (tmp == NULL)
		{
			perror("realloc");
			exit(-1);
		}
		Stact->date = tmp;
		Stact->capacity *= 2;
	}
	Stact->date[Stact->top++] = x;
}

bool StactEmpty(ST* stact)
{
	assert(stact);

	return stact->top == 0;
}

STDateType StactTop(ST* Stact)
{
	assert(Stact);
	assert(!StactEmpty(Stact));

	return Stact->date[Stact->top - 1];
}

void StactPopBank(ST* Stact)
{
	assert(Stact);
	assert(!StactEmpty(Stact));

	Stact->top--;
}

void StactDestory(ST* Stact)
{
	assert(Stact);

	free(Stact->date);
	Stact->date = NULL;
	Stact->capacity = 0;
	Stact->top = 0;
	free(Stact);
}

int StactSize(ST* Stact)
{
	assert(Stact);
	return Stact->top;
}

typedef struct {
	ST* push;
	ST* top;
} MyQueue;


MyQueue* myQueueCreate() {
	MyQueue* Q = (MyQueue*)malloc(sizeof(MyQueue));
	Q->push = StactInit();
	Q->top = StactInit();
	return Q;
}

void myQueuePush(MyQueue* obj, int x) {
	assert(obj);
	StactPushBank(obj->push, x);
}

int myQueuePop(MyQueue* obj) {
	assert(obj);
	if (StactEmpty(obj->top))
	{
		while (!StactEmpty(obj->push))
		{
			StactPushBank(obj->top, StactTop(obj->push));
			StactPopBank(obj->push);
		}
	}
	int ret = StactTop(obj->top);
	StactPopBank(obj->top);
	return ret;
}

int myQueuePeek(MyQueue* obj) {
	assert(obj);
	if (StactEmpty(obj->top))
	{
		while (!StactEmpty(obj->push))
		{
			StactPushBank(obj->top, StactTop(obj->push));
			StactPopBank(obj->push);
		}
	}
	return StactTop(obj->top);
}

bool myQueueEmpty(MyQueue* obj) {
	assert(obj);
	return StactEmpty(obj->top) && StactEmpty(obj->push);
}

void myQueueFree(MyQueue* obj) {
	assert(obj);
	StactDestory(obj->push);
	StactDestory(obj->top);
	free(obj);
}

int main()
{

	return 0;
}
