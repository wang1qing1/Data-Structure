
#include"SEQ.h"

int main()
{
	SlistNode* plist = NULL;
	SListpushback(&plist, 100);
	SListpushback(&plist, 200);
	SListpushback(&plist, 300);
	SListpushback(&plist, 400);
	SListpushback(&plist, 500);
	SListpushback(&plist, 600);
	SListpushback(&plist, 700);
	/*printf("插入前:");
	SlistPrintf(&plist);
	printf("\n");*/
	/*printf("尾删前:");
	SlistPrintf(plist);
	printf("\n");
	printf("尾删后:");
	SListpophback(&plist);*/
	SlistNode* pos= FindList(plist, 300);
	//if (pos != NULL)//找到数据的结点并且改动数据内容；
	//{
	//	pos->data = 3000;
	//}
	/*SlistInserAfter(&pos, 350);
	printf("插入后:");
	SlistPrintf(plist);
	SlistEraseAfter(&pos);
	printf("\n");
	printf("删除后:");*/
	SlistPrintf(plist);
	return 0;
}
