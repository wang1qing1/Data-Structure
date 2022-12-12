
#include"SeqList.h"

SL* _InitHeroPond()
{
	SL* p = (SL*)malloc(sizeof(SL));
	if (p == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	p->a = NULL;
	p->capacity = 0;
	p->size = 0;
	return p;
}

HeroPond* InitHeroPond()
{
	HeroPond* heropond = (HeroPond*)malloc(sizeof(HeroPond));
	if (heropond == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	heropond->Assassin = _InitHeroPond();
	heropond->HeroAll = _InitHeroPond();
	heropond->Master = _InitHeroPond();
	heropond->Shooter = _InitHeroPond();
	heropond->Soldier = _InitHeroPond();
	return heropond;
}

void AddHero(HeroPond*pHero)
{
	Figure x;
	while (1)
	{
		printf("请输入英雄信息，名称，类型，生命值，物理攻击，物理防御，法术攻击，法术防御\n:>");
		scanf("%s%s%d%d%d%d%d", x.name, x.identity, &x.life_val, &x.physical_attact, &x.physical_defend, &x.spell_attack, &x.spell_defend);
		if (!strcmp(x.identity, "法师"))
		{
			SLPushBack(pHero->Master, x);
			break;
		}
		else if (!strcmp(x.identity, "射手"))
		{
			SLPushBack(pHero->Shooter, x);
			break;
		}
		else if (!strcmp(x.identity, "战士"))
		{
			SLPushBack(pHero->Soldier, x);
			break;
		}
		else if (!strcmp(x.identity, "刺客"))
		{
			SLPushBack(pHero->Assassin, x);
			break;
		}
		else
		{
			printf("没有该类型英雄,请重新输入:>");
		}
	}
	
	SLPushBack(pHero->HeroAll, x);
}



int comper_life_val(void* e1, void* e2)
{
	return (((SLDataType*)e1)->life_val) - (((SLDataType*)e2)->life_val);
}

int comper_spell_attack(void* e1, void* e2)
{
	return (((SLDataType*)e1)->spell_attack) - (((SLDataType*)e2)->spell_attack);

}
int comper_physical_attact(void* e1, void* e2)
{
	return (((SLDataType*)e1)->physical_attact) - (((SLDataType*)e2)->physical_attact);
}

void menu_Hero()
{
	printf("*******************************************\n");
	printf("*******    1.Master   2.Shooter     *******\n");
	printf("*******    3.Soldier  4.Assassin    *******\n");
	printf("*******    5.HeroAll  0.exit        *******\n");
	printf("*******************************************\n");
}

void Hero_Sort(HeroPond* p)
{
	int input = 0;
	do
	{
		menu_Hero();
		scanf("%d", &input);
		switch (input)
		{
		case 1:Hero_Sort_attribute(p->Master);
			break;
		case 2:Hero_Sort_attribute(p->Shooter);
			break;
		case 3:Hero_Sort_attribute(p->Soldier);
			break;
		case 4:Hero_Sort_attribute(p->Assassin);
			break;
		case 0:break;
		default:
			printf("输入有误！！！\n");
		}

	} while (input);
}

void menu_Sort_attribute()
{
	printf("***************************************************\n");
	printf("*******    1.life_val   2.spell_attack      *******\n");
	printf("*******    3.physical_attact  0.exit        *******\n");
	printf("***************************************************\n");
}

void Hero_Sort_attribute(SL* p)
{
	int input = 0;
	do
	{
		menu_Sort_attribute();
		scanf("%d", &input);
		switch (input)
		{
		case 1:qsort(p->a, p->size, sizeof(p->a[0]), comper_life_val);
			break;
		case 2:qsort(p->a, p->size, sizeof(p->a[0]), comper_spell_attack);
			break;
		case 3:qsort(p->a, p->size, sizeof(p->a[0]), comper_physical_attact);
			break;
		case 0:break;
		default:
			printf("输入有误！！！\n");
		}
	} while (input);
}

void Print(SL* p)
{

	for (int i = 0; i < p->size; i++)
	{
		printf("英雄名称:%s 英雄分类:%s 生命值:%d 物理攻击:%d 法术攻击:%d 物理防御:%d 法术防御:%d\n",
			p->a[i].name, p->a[i].identity, p->a[i].life_val, p->a[i].physical_attact, p->a[i].physical_defend, p->a[i].physical_defend,
			p->a[i].spell_attack, p->a[i].spell_defend);
	}
}

void Print_attribute(HeroPond*p)
{
	int input = 0;
	do
	{
		void menu_Hero();
		menu_Sort_attribute();
		scanf("%d", &input);
		switch (input)
		{
		case 1:Print(p->Master);
			break;
		case 2:Print(p->Shooter);
			break;
		case 3:Print(p->Soldier);
			break; 
		case 4:Print(p->Assassin);
			break; 
		case 5:Print(p->HeroAll);
			break;
		case 0:break;
		default:
			printf("输入有误！！！\n");
		}
	} while (input);
}


