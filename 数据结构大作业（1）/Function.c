#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

void _InitHeroPond(SL* p)
{
	assert(p);
	p = (SL*)malloc(sizeof(SL));
	p->a = NULL;
	p->capacity = 0;
	p->size = 0;
}

HeroPond* InitHeroPond()
{
	HeroPond* heropond = (HeroPond*)malloc(sizeof(HeroPond));
	_InitHeroPond(heropond->Assassin);
	_InitHeroPond(heropond->HeroAll);
	_InitHeroPond(heropond->Master);
	_InitHeroPond(heropond->Shooter);
	_InitHeroPond(heropond->Soldier);
	return heropond;
}

void AddHero(HeroPond*pHero)
{
	Figure x;
	scanf("%s%s%d%d%d%d%d", x.name, x.identity, &x.physical_attact, &x.physical_defend, &x.spell_attack, &x.spell_defend);
	if(!strcmp(x.identity, "·¨Ê¦"))
	{
		SLPushBack()
	}
}


