#include"Stact.h"
ST* StactInit()
{
	ST* Stact = (ST*)malloc(sizeof(ST));
	Stact->capacity = 4;
	Stact->top = 0;
	Stact->date = (STDateType*)malloc(sizeof(STDateType)*Stact->capacity);
	return Stact;
}

void StactPushBank(ST* Stact, STDateType x)
{
	assert(Stact);
	if (Stact->capacity == Stact->top)
	{
		STDateType* tmp = (STDateType*)realloc(Stact->date, Stact->capacity * 2);
		if (tmp==NULL)
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

void Print(ST* Stact)
{
	assert(Stact);
	for (int i = 0; i < Stact->top; i++)
	{
		printf("%d ", Stact->date[i]);
	}
	printf("\n");
}





