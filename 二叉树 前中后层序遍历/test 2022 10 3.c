#include"Tree.h"

//²ãÐò±éÀú
void SequenTrave(BTnode* root)
{
	Queue* head = InitQueue();
	InputQueue(head, root);
	while (Judge(head))
	{
		Queue*frist = head->next;
		if (frist->pdata->left != NULL)
		{
			InputQueue(head, frist->pdata->left);
		}
		if (frist->pdata->right != NULL)
		{
			InputQueue(head, frist->pdata->right);
		}
		PutQueue(head);
		DeleQueue(head);
	}
}

int main()
{
	BTnode* A = malloc(sizeof(BTnode));
	A->data = 'A';
	A->left = NULL;
	A->right = NULL;

	BTnode* B = malloc(sizeof(BTnode));
	B->data = 'B';
	B->left = NULL;
	B->right = NULL;

	BTnode* C = malloc(sizeof(BTnode));
	C->data = 'C';
	C->left = NULL;
	C->right = NULL;

	BTnode* D = malloc(sizeof(BTnode));
	D->data = 'D';
	D->left = NULL;
	D->right = NULL;

	BTnode* E = malloc(sizeof(BTnode));
	E->data = 'E';
	E->left = NULL;
	E->right = NULL;

	A->left = B;
	A->right = C;
	B->left = D;
	B->right = E;

	/*int size = 0;
	NodeSize1(A, &size);
	printf("%d\n", size);

	printf("%d\n", NodeSize(A));
	printf("%d\n", LeafNodeSize(A));*/

	/*ProTrave(A);
	printf("\n");
	MidTrave(A);
	printf("\n");
	AfTrave(A);*/

	//InputQueue(head,A);
	//InputQueue(head,B);
	//PutQueue(head);
	//DeleQueue(head);
	//PutQueue(head);

	SequenTrave(A);

	
	


	return 0;
}