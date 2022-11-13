#include"Queue.h"

int main()
{
	Queue Q;
	QueueInit(&Q);
	QueuePush(&Q, 100);
	QueuePush(&Q, 200);
	QueuePush(&Q, 300);
	QueuePush(&Q, 400);

	QueuePop(&Q);
	QueuePop(&Q);
	QueuePop(&Q);
	QueuePop(&Q);

	printf("%d ", QueueFront(&Q));

	printf("%d ", QueueBack(&Q));

	printf("%d ", QueueSize(&Q));
	QueueDestroy(&Q);
	return 0;
}