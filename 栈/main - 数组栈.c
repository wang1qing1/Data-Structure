#include"ST.h"
int main()
{
	ST stact = { 0 };
	StactInit(&stact);
	StactPush(&stact, 100);
	StactPush(&stact, 200);
	StactPush(&stact, 300);
	StactPush(&stact, 400);
	StactPush(&stact, 500);
	StactPush(&stact, 600);
	//StactPop(&stact);
	StactPrin(&stact);
	printf("\n");
	printf("%d ", ReadStactData(&stact));
	printf("%d ", GetStactData(&stact));
	if (StactEmpty(&stact) == true)
	{
		printf("栈空");
	}
	else
	{
		printf("栈数据个数=%d\n", Stactsize(&stact));
	}
	StactDestry(&stact);

	return 0;
}

