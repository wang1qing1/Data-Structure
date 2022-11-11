#include"Stact.h"

int main()
{
	ST* Stact= StactInit();
	StactPushBank(Stact, 100);
	StactPushBank(Stact, 200); 
	StactPushBank(Stact, 300);
	StactPushBank(Stact, 400);
	StactPopBank(Stact);
	Print(Stact);
	StactDestory(Stact);
	return 0;
}