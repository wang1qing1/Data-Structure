
#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS
#include"QUEUE.h"
int main()
{
	Queue queue = { 0 };
	QInit(&queue);
	QueuePush(&queue, 100);
	QueuePush(&queue, 200);
	QueuePush(&queue, 300);
	QueuePop(&queue);
	printf("%d ", ReadQueueBank(&queue));
	printf("\n");
	printf("%d ", ReadQueueFront(&queue));
	printf("%d ", QueueSize(&queue));
	printf("\n");
	QueuePrintf(&queue);
	QueueDestoy(&queue);


	return 0;
}