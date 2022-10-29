#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

void Getnext(char* sub, int* next)
{
	int sublen = (int)strlen(sub);
	next[0] = -1;
	next[1] = 0;
	int i = 2;
	int k = 0;
	
	while (i < sublen)
	{
		if (k == -1 || sub[i - 1] == sub[k])
		{
			next[i] = k + 1;
			i++;
			k++;
		}
		else
		{
			k = next[k];
		}
	}
}

int KMP(char* str,char* sub, int pos)
{
	assert(str && sub);
	int Strlen = (int)strlen(str);
	int Sublen = (int)strlen(sub);
	assert(pos>=0 && pos<Strlen);

	int* next = (int*)malloc(sizeof(int) * Sublen);
	assert(next);

	Getnext(sub, next);

	int i = pos;  //遍历主串
	int j = 0;    //遍历子串

	while (i < Strlen && j < Sublen)
	{
		if (j == -1 || str[i] == sub[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	if (j >= Sublen)
	{
		return i - j;
	}
	return -1;
}

int main()
{
	printf("%d ", KMP("abcgaghudoihsdoi", "abc", 0));
	printf("%d ", KMP("abcgaghudoihsdoi", "sdoi", 0));
	printf("%d ", KMP("abcgaghudoihsdoi", "gagh", 0));
	return 0;
}