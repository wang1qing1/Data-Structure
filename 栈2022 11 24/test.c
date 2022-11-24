#include"Stact.h"

void Print(ST* Stact)
{
	assert(Stact);
	for (int i = 0; i < Stact->top; i++)
	{
		printf("%d ", Stact->date[i]);
	}
	printf("\n");
}
int main()
{
	ST* Stact= StactInit();
	StactPushBank(Stact, 100); 
	StactPushBank(Stact, 200); 
	StactPushBank(Stact, 300); 
	StactPushBank(Stact, 400); 
	Print(Stact);
	printf("StactSize:%d\n",StactSize(Stact));
	//Pop“ª¥Œ
	StactPopBank(Stact);
	Print(Stact);
	printf("StactSize:%d\n", StactSize(Stact));
	StactDestory(Stact);
	return 0;
}