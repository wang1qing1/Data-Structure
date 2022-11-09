#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

struct Node {
	int val;
	struct Node* next;
	struct Node* random;
};


//复制带随机指针的链表  时间复杂度是O(n^2)
struct Node* copyRandomList(struct Node* head) {
    //哨兵位头节点
    struct Node* phead = (struct Node*)malloc(sizeof(struct Node));
    struct Node* ptail = phead;
    struct Node* cur = head;
    //创建复制链表
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
        //如果随机结点不是空，通过比较地址，用count记录相对第一个节点的位置
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
        //原链表随机结点为空，那么复杂链表的随机结点也为空
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