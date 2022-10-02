#include"List.h"
void menu()
{
	printf("******************************************\n");
	printf("*****   1.HeadAdd     2.TailAdd      *****\n");
	printf("*****   3.MidAdd      4.DeleteNode   *****\n");
	printf("*****   5.Seek        6.Modify       *****\n");
	printf("*****   7.PrintList   0.exit         *****\n");
	printf("******************************************\n");
}
int main()
{
	ListNode* Head = InitListNode();
	int input = 0;
	do
	{
		menu();
		printf("������ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case headadd:HeadAdd(Head);
			break;
		case tailadd:TailAdd(Head);
			break;
		case midadd:MidAdd(Head);
			break;
		case deletenode:DeleteNode(Head);
			break;
		case seek:Seek(Head);
			break;
		case modify:Modify(Head);
			break;
		case printlist:PrintList(Head);
			break;
		case exit_:
			Destroy(Head);
			printf("�˳���\n");
			return 0;
		}
	}while (input);
}