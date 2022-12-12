#pragma once
typedef struct Figure
{
	char name[30];    //名字
	char identity[20];//职位
	int life_val;
	int spell_attack; //法术攻击
	int physical_attact; //物理攻击
	int spell_defend;   //法术防御
	int physical_defend;//物理防御
}Figure;

typedef Figure SLDataType;
typedef struct SeqList
{
	SLDataType* a;
	int size;       // 记录存储多少个有效数据
	int capacity;   // 空间容量大小 
}SL;

typedef struct HeroPond
{
	SL* Master; //法师
	SL* Shooter; //射手
	SL* Soldier; //战士
	SL* Assassin; //刺客
	SL* HeroAll;//英雄总和
}HeroPond;

HeroPond* InitHeroPond();

void AddHero(HeroPond* pHero);

void Print(SL* p);

void Hero_Sort(HeroPond* p);

void Hero_Sort_attribute(SL* p);