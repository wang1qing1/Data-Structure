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


////前5大的5个数据
	//TopK_File(5);
//TopK_File(&hp, 5);


////数组数据一次插入堆中
	//for (int i = 0; i < n; i++)
	//{
	//	HeapPush(&hp, array[i]);
	//}

	/*Print(&hp);
	HeapPop(&hp);
	Print(&hp);
	HeapPop(&hp);
	Print(&hp);*/


	//定义
//Heap hp;
////初始化
//HeapInit(&hp);

/*int array[] = { 27,15,19,18,28,34,65,49,25,37 };
int n = sizeof(array) / sizeof(array[0]);
HeapCreate(&hp, array, n);*/

//选出前3大的3个数据
/*HeapTopK(&hp, 3);*/

//销毁堆
//HeapDestroy(&hp);
//return 0;
