
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
	/*printf("����ǰ:");
	SlistPrintf(&plist);
	printf("\n");*/
	/*printf("βɾǰ:");
	SlistPrintf(plist);
	printf("\n");
	printf("βɾ��:");
	SListpophback(&plist);*/
	SlistNode* pos= FindList(plist, 300);
	//if (pos != NULL)//�ҵ����ݵĽ�㲢�ҸĶ��������ݣ�
	//{
	//	pos->data = 3000;
	//}
	/*SlistInserAfter(&pos, 350);
	printf("�����:");
	SlistPrintf(plist);
	SlistEraseAfter(&pos);
	printf("\n");
	printf("ɾ����:");*/
	SlistPrintf(plist);
	return 0;
}
