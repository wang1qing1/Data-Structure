#include"HFM.h"
int main()
{
	int weight[] = {1,2,3,4};
	int num = sizeof(weight) / sizeof(int);

	HaffTree*T= hafTree_Init(weight,num);
	/*int* arr = SelectMin(T);*/
	/*printf("%d %d", arr[0], arr[1]);*/
	CreateHafmTree(T, num);
	PrevClue(T, T->height-1);
	return 0;
}