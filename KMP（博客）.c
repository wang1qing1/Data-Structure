#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

void GetNext(char* sub,int *next)
{
	int sublen = strlen(sub);
	int i = 2; // i 从数组子串第三个元素开始
	int k = 0; // 代表回退的位置，k的位置始终位于，i - 1 匹配失败的回退位置的对应的 k，
	           // 即可由 i - 1 位置求出 的 k，求出 i 位置的 k。
	next[0] = -1;
	next[1] = 0;
	while (i<sublen)
	{
		//当 k 回退到头的时候 即 k==-1，就需要回退到 0 号下标位置，
		//或者 如果 退回位置字符和匹配失败的字符相同
		if (k == -1 || sub[i - 1] == sub[k])
		{
			next[i] = k + 1;
			//已经求出 i 的退回位置，i 继续往后走
			i++;
			// k 要变成新的 i-1 位置的退回位置。
			k++;
		}
		//如果 退回位置字符和匹配失败的字符不相同
		else
		{
			// k 在当前位置继续回退
			k = next[k];
		}
	}
}

int KMP(char* str, char* sub, int pos)
{
	assert(str && sub);
	int StrLen = strlen(str);
	int SubLen = strlen(sub);
	assert(pos >= 0&&pos<StrLen);
	//创建 next 数组
    int * next = (int*)malloc(sizeof(int)*SubLen);
	
	int i = pos; //主串
	int j = 0;   //子串

	//构建next数组
	GetNext(sub,next);

	//主串和子串匹配
	while (i < StrLen && j < SubLen)
	{
		//如果匹配的字符相同就继续往后匹配
		if (j==-1 || str[i] == sub[j])
		{
			i++;
			j++;
		}
		//回退
		else
		{
			j = next[j];
		}
	}
	//当 j 遍历到最后时，也就是 子串全部匹配成功
	if (j >= SubLen)
	{
		return i - j;
	}
	//模式串与子串匹配失败
	return -1;
}


int main()
{


	printf("%d ", KMP("abcgaghudoihsdoi", "abc", 0));
	printf("%d ", KMP("abcgaghudoihsdoi", "sdoi", 0));
	printf("%d ", KMP("abcgaghudoihsdoi", "gagh", 0));

	
	return 0;
}