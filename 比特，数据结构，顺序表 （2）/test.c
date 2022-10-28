#include"SeqList.h"
int main()
{

	SeqList SL;
	SeqListInit(&SL);
	//SeqListPushBank(&SL, 100);
	SeqListPushBank(&SL, 200);
	SeqListPushBank(&SL, 300); 
	SeqListPushBank(&SL, 400); 
	SeqListPushBank(&SL, 500);
	//SeqListPopbank(&SL);
	//SeqListPrintf(&SL);
	//SeqListPushFront(&SL, 100);
	//SeqListPopFront(&SL);
	//SeqListPrintf(&SL);
	int index=SeqListFind(&SL, 200);
	if (index < 0)
	{
		printf("Not Find!!!\n");
	}
	else
	{
		printf("200 index is £º%d\n", index);
	}
	//SeqListInsert(&SL, 0, 100);
	SeqListPrintf(&SL);
	SeqListDestroy(&SL);


	/*size_t pos = 0;
	int i = -1;
	if (i >= pos)
	{
		printf("hahah");
	}
	else
	{
		printf("XXXXX");
	}*/
	return 0;
}

