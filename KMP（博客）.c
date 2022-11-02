#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

void GetNext(char* sub,int *next)
{
	int sublen = strlen(sub);
	int i = 2; // i �������Ӵ�������Ԫ�ؿ�ʼ
	int k = 0; // ������˵�λ�ã�k��λ��ʼ��λ�ڣ�i - 1 ƥ��ʧ�ܵĻ���λ�õĶ�Ӧ�� k��
	           // ������ i - 1 λ����� �� k����� i λ�õ� k��
	next[0] = -1;
	next[1] = 0;
	while (i<sublen)
	{
		//�� k ���˵�ͷ��ʱ�� �� k==-1������Ҫ���˵� 0 ���±�λ�ã�
		//���� ��� �˻�λ���ַ���ƥ��ʧ�ܵ��ַ���ͬ
		if (k == -1 || sub[i - 1] == sub[k])
		{
			next[i] = k + 1;
			//�Ѿ���� i ���˻�λ�ã�i ����������
			i++;
			// k Ҫ����µ� i-1 λ�õ��˻�λ�á�
			k++;
		}
		//��� �˻�λ���ַ���ƥ��ʧ�ܵ��ַ�����ͬ
		else
		{
			// k �ڵ�ǰλ�ü�������
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
	//���� next ����
    int * next = (int*)malloc(sizeof(int)*SubLen);
	
	int i = pos; //����
	int j = 0;   //�Ӵ�

	//����next����
	GetNext(sub,next);

	//�������Ӵ�ƥ��
	while (i < StrLen && j < SubLen)
	{
		//���ƥ����ַ���ͬ�ͼ�������ƥ��
		if (j==-1 || str[i] == sub[j])
		{
			i++;
			j++;
		}
		//����
		else
		{
			j = next[j];
		}
	}
	//�� j ���������ʱ��Ҳ���� �Ӵ�ȫ��ƥ��ɹ�
	if (j >= SubLen)
	{
		return i - j;
	}
	//ģʽ�����Ӵ�ƥ��ʧ��
	return -1;
}


int main()
{


	printf("%d ", KMP("abcgaghudoihsdoi", "abc", 0));
	printf("%d ", KMP("abcgaghudoihsdoi", "sdoi", 0));
	printf("%d ", KMP("abcgaghudoihsdoi", "gagh", 0));

	
	return 0;
}