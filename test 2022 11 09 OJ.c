#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

struct Node {
	int val;
	struct Node* next;
	struct Node* random;
};


//���ƴ����ָ�������  ʱ�临�Ӷ���O(n^2)
struct Node* copyRandomList(struct Node* head) {
    //�ڱ�λͷ�ڵ�
    struct Node* phead = (struct Node*)malloc(sizeof(struct Node));
    struct Node* ptail = phead;
    struct Node* cur = head;
    //������������
    while (cur)
    {
        struct Node* new = (struct Node*)malloc(sizeof(struct Node));
        new->val = cur->val;
        ptail->next = new;
        ptail = new;
        cur = cur->next;
    }
    ptail->next = NULL;
    cur = head;
    struct Node* curcopy = phead->next;
    while (curcopy)
    {
        //��������㲻�ǿգ�ͨ���Ƚϵ�ַ����count��¼��Ե�һ���ڵ��λ��
        if (cur->random)
        {
            int count = 0;
            struct Node* findrandom = head;
            struct Node* findnode = phead->next;
            while (findrandom != cur->random)
            {
                count++;
                findrandom = findrandom->next;
            }
            while (count--)
            {
                findnode = findnode->next;
            }
            curcopy->random = findnode;
        }
        //ԭ����������Ϊ�գ���ô���������������ҲΪ��
        else
        {
            curcopy->random = NULL;
        }
        cur = cur->next;
        curcopy = curcopy->next;
    }
    struct Node* pp = phead->next;
    free(phead);
    return pp;
}