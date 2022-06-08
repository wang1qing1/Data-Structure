#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

typedef struct Her
{
	int time;
	int vail;
}Her;

int Max(int x, int y)
{
	return x > y ? x : y;
}

int main()
{
	int T=0, n=0;
	scanf("%d %d", &T,&n);
	Her* her = (Her*)malloc(sizeof(Her)* (n+1));
	her[0].time = 0; her[0].vail = 0;
	for (int i = 1; i < n+1; i++)
	{
		scanf("%d %d", &her[i].time,&her[i].vail);
	}
	int**dp = (int**)malloc(sizeof(int*) * (n+1));
	for (int i = 0; i < n+1; i++)
	{
		dp[i] = (int*)malloc(sizeof(int) * (T + 1));
	}
	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < T+ 1; j++)
		{
			if (i==0||j==0)
			{
				dp[i][j] = 0;
			}
			else if (her[i].time > j)
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				dp[i][j] = Max(dp[i - 1][j - her[i].time] + her[i].vail, dp[i - 1][j]);
			}
		}
	}
	printf("%d", dp[n][T]);
	return 0;
}