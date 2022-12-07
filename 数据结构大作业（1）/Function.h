#pragma once
typedef struct Figure
{
	char name[30];    //����
	char identity[20];//ְλ
	int spell_attack; //��������
	int physical_attact; //������
	int spell_defend;   //��������
	int physical_defend;//�������
}Figure;

typedef Figure SLDataType;
typedef struct SeqList
{
	SLDataType* a;
	int size;       // ��¼�洢���ٸ���Ч����
	int capacity;   // �ռ�������С 
}SL;

typedef struct HeroPond
{
	SL* Master; //��ʦ
	SL* Shooter; //����
	SL* Soldier; //սʿ
	SL* Assassin; //�̿�
	SL* HeroAll;//Ӣ���ܺ�
}HeroPond;
