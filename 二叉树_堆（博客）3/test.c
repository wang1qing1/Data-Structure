#include"function.h"

void Print(Heap* php)
{
	for (int i = 0; i < php->size; i++)
	{
		printf("%d ", php->a[i]);
	}
	printf("\n");
}

int main()
{
	int array[] = { 27,15,19,18,28,34,65,49,25,37 };
	int n = sizeof(array) / sizeof(array[0]);

	HeapSort(array, n);

	for (int i = 0; i < n; i++)
	{
		printf("%d ", array[i]);
	}
}


////ǰ5���5������
	//TopK_File(5);
//TopK_File(&hp, 5);


////��������һ�β������
	//for (int i = 0; i < n; i++)
	//{
	//	HeapPush(&hp, array[i]);
	//}

	/*Print(&hp);
	HeapPop(&hp);
	Print(&hp);
	HeapPop(&hp);
	Print(&hp);*/


	//����
//Heap hp;
////��ʼ��
//HeapInit(&hp);

/*int array[] = { 27,15,19,18,28,34,65,49,25,37 };
int n = sizeof(array) / sizeof(array[0]);
HeapCreate(&hp, array, n);*/

//ѡ��ǰ3���3������
/*HeapTopK(&hp, 3);*/

//���ٶ�
//HeapDestroy(&hp);
//return 0;
