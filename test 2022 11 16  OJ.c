#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<assert.h>

typedef struct {
    int* date;
    int tail;
    int head;
    int k;
} MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* Q = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    Q->date = (int*)malloc(sizeof(int) * (k + 1));
    Q->tail = 0;
    Q->head = 0;
    Q->k = k;
    return Q;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {

    if (myCircularQueueIsFull(obj))
    {
        return false;
    }
    assert(obj);
    obj->date[obj->tail++] = value;
    if (obj->tail == (obj->k) + 1)
    {
        obj->tail = 0;
    }
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    assert(obj);
    if (myCircularQueueIsEmpty(obj))
    {
        return false;
    }
    obj->head++;
    if (obj->head == obj->k + 1)
    {
        obj->head = 0;
    }
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    assert(obj);
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    return obj->date[obj->head];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    assert(obj);
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    if (obj->tail - 1 < 0)
    {
        return obj->date[obj->k];
    }
    return obj->date[obj->tail - 1];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    assert(obj);
    return obj->tail == obj->head;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    assert(obj);
    return (obj->tail + 1) % (obj->k + 1) == obj->head;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    assert(obj);
    free(obj->date);
    free(obj);
}


int main()
{
	return 0;
}