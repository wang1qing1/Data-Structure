
#include"SeqList.h"

void menu()
{
	printf("****************************************\n");
	printf("***** 1.Ìí¼ÓÓ¢ÐÛ  2.ÅÅÐòÓ¢ÐÛ  **********\n");
	printf("***** 3.ÁÐ³öÓ¢ÐÛ  0.ÍË³ö      **********\n");
	printf("****************************************\n");
}

int main()
{
	HeroPond* heropond= InitHeroPond();
	int input = 0;
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:AddHero(heropond);
			break;
		case 2:Hero_Sort(heropond);
			break;
		case 3:Print(heropond->HeroAll);
			break;
		case 0:break;
		}

	} while (input);

	return 0;

}