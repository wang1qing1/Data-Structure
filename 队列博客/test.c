#include"Queue.h"

int main()
{
	Queue Q;
	QueueInit(&Q);
	//插如100 .200 300 ，400 ，
	QueuePush(&Q, 100);
	QueuePush(&Q, 200);
	QueuePush(&Q, 300);
	QueuePush(&Q, 400);

	//输出队头数据
	printf("%d ", QueueFront(&Q));
	//输出队尾数据
	printf("%d ", QueueBack(&Q));
	//输出队列数据个数
	printf("%d \n", QueueSize(&Q));
	//输出队列中的数据
	while (!QueueEmpty(&Q))
	{
		printf("%d ", Q.head->date);
		QueuePop(&Q);
	}
	//队列销毁
	QueueDestroy(&Q);

	return 0;
}