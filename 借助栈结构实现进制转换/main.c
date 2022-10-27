#include"ST.h"
int main()
{
	ST stact = { 0 };
	StactInit(&stact);
	int N = 0;  //数据
	int K = 0;  //需要转换的进制

	scanf("%d %d", &N, &K);

	ScaleChange(&stact,N,K);
	while (!StactEmpty(&stact))
	{
		printf("%c", GetStactData(&stact));
	}

	return 0;
}

