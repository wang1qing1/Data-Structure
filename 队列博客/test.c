#include"Queue.h"

int main()
{
	Queue Q;
	QueueInit(&Q);
	//����100 .200 300 ��400 ��
	QueuePush(&Q, 100);
	QueuePush(&Q, 200);
	QueuePush(&Q, 300);
	QueuePush(&Q, 400);

	//�����ͷ����
	printf("%d ", QueueFront(&Q));
	//�����β����
	printf("%d ", QueueBack(&Q));
	//����������ݸ���
	printf("%d \n", QueueSize(&Q));
	//��������е�����
	while (!QueueEmpty(&Q))
	{
		printf("%d ", Q.head->date);
		QueuePop(&Q);
	}
	//��������
	QueueDestroy(&Q);

	return 0;
}