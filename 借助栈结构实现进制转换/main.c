#include"ST.h"
int main()
{
	ST stact = { 0 };
	StactInit(&stact);
	int N = 0;  //����
	int K = 0;  //��Ҫת���Ľ���

	scanf("%d %d", &N, &K);

	ScaleChange(&stact,N,K);
	while (!StactEmpty(&stact))
	{
		printf("%c", GetStactData(&stact));
	}

	return 0;
}

