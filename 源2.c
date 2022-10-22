#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student { //定义学生的结构体
	int number;
	char name[50];
	char sex[3];
	int age;
	int higher_mathematics, data_structure, english, PE;
	int average_score;
	int total_score;
	struct student* next;
} *LinkList, LNode;
LinkList L;
LinkList create(int n);
void output();
void insert(int i);
void delete();
void delete_i(int i);
void find();
int main()
{
	char c;
	int n, i;
	int j = 1;
	printf("创建结点的个数:");
	scanf("%d", &n);
	create(n); //调用create函数
	printf("\n以下是录入的学生：\n");
	output();
	while (j)
	{
		printf("\n1.查找学生记录\n2.插入学生记录\n3.删除学生记录\n4.删除学生记录(位置）\n5.输出学生记录\n6.退出系统\n");
		printf("请选择你想要执行的操作：\n");
		scanf(" %c", &c);
		if (c == '1') {
			find();//查找学生记录
		}

		else if (c == '2') { //查找学生记录
			printf("请输入要插入的位置：");
			scanf("%d", &i);
			insert(i);
			printf("以下是修改后的记录：\n");
			output();
		}
		else if (c == '3') { //删除学生记录
			delete();
			printf("以下是修改后的记录：\n");
			output();
		}
		else if (c == '4') {
			printf("请输入要删除的位置：");
			scanf("%d", &i);
			delete_i(i);
			printf("以下是修改后的记录：\n");
			output();
		}
		else if (c == '5') { //输出学生记录
			output();
		}
		else if (c == '6') { //退出系统
			printf("已退出");
			j = 0;
		}
	}
	getchar(); getchar();
	return 0;
}


LinkList create(int n) {
	LNode*node, *tail;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	tail = L;
	for (int i = 0; i < n; i++) {
		node = (LinkList)malloc(sizeof(LNode));
		printf("请输入第%d个同学的信息\n", i + 1);
		printf("学号：");
		scanf("%d", &node->number);
		printf("姓名：");
		scanf("%s", node->name);
		printf("性别：");
		scanf("%s", node->sex);
		printf("年龄：");
		scanf("%d", &node->age);
		printf("高等数学：");
		scanf("%d", &node->higher_mathematics);
		printf("数据结构：");
		scanf("%d", &node->data_structure);
		printf("英语：");
		scanf("%d", &node->english);
		printf("体育：");
		scanf("%d", &node->PE);
		node->average_score = (node->higher_mathematics + node->data_structure + node->english + node->PE) / 4;
		node->total_score = node->higher_mathematics + node->data_structure + node->english + node->PE;
		node->next = NULL;
		tail->next = node;
		tail = node;
	}
	return L; //返回头节点的地址
}


void output()
{

	LinkList p = L;
	printf("学号\t姓名\t性别\t年龄\t高数\tDS\t英语\t体育\t平均成绩\t总成绩\n");
	while (p->next != NULL) {
		p = p->next;
		printf("%-2d\t%s\t%s\t%d\t%-3d\t%-3d\t%-3d\t%-3d\t%-5d\t\t%-4d\n", p->number, p->name, p->sex, p->age, p->higher_mathematics, p->data_structure, p->english, p->PE, p->average_score, p->total_score);

	}
}

void insert(int i)
{
	LinkList p = L;
	LNode* node;
	int j = 0;
	while (p && j < i - 1)
	{
		p = p->next;
		++j;
	}

	node = (LinkList)malloc(sizeof(LNode));
	printf("请输入学生记录的值：\n");
	printf("学号：");
	scanf("%d", &node->number);
	printf("姓名：");
	scanf("%s", node->name);
	printf("性别：");
	scanf("%s", node->sex);
	printf("年龄：");
	scanf("%d", &node->age);
	printf("高等数学：");
	scanf("%d", &node->higher_mathematics);
	printf("数据结构：");
	scanf("%d", &node->data_structure);
	printf("英语：");
	scanf("%d", &node->english);
	printf("体育：");
	scanf("%d", &node->PE);
	node->average_score = (node->higher_mathematics + node->data_structure + node->english + node->PE) / 4;
	node->total_score = node->higher_mathematics + node->data_structure + node->english + node->PE;
	node->next = p->next;
	p->next = node;

}

void delete()
{
	char date[50] = { 0 };
	int num;
	LinkList p = L, pr = L;
	printf("删除学生记录（学号或姓名）：\n");
	scanf("%s", date);//输入需删除的数据，姓名或学号
	if (strspn(date, "0123456789") == strlen(date)) {
		num = atoi(date);
		while (num != (p->number) || (strcmp(date, p->name) == 0)) {
			pr = p;
			p = p->next;
			if (p == NULL) {
				break;
			}
		}
	}
	else {
		while (strcmp(date, p->name) != 0) {
			pr = p;
			p = p->next;
			if (p == NULL) {
				break;
			}
		}
	}
	if (p != NULL) {
		pr->next = p->next;
		free(p);
	}
	else {
		pr->next = NULL;
		free(p);
	}
}
void delete_i(int i)
{
	LinkList p = L, q;
	int j = 0;
	while (p && j < i - 1)
	{
		p = p->next;
		++j;
	}
	q = p->next;
	p->next = q->next;
	free(q);
}

void find()
{
	char str[50] = { 0 };
	int num;
	LinkList p = L;
	printf("查找哪位学生记录：\n");
	scanf("%s", str);//输入需查找的数据，姓名或学号
	if (strspn(str, "0123456789") == strlen(str)) {//判断是否为学号（数字）
		num = atoi(str);//是的话转换为数字
		while (num != (p->number) || (strcmp(str, p->name) == 0)) {
			p = p->next;
			if (p == NULL) {
				break;
			}
		}
	}
	else {
		while (strcmp(str, p->name) != 0) {//判断名字是否相同
			p = p->next;
			if (p == NULL) {
				break;
			}
		}
	}
	printf("%d\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p->number, p->name, p->sex, p->age, p->higher_mathematics, p->data_structure, p->english, p->PE, p->average_score, p->total_score);
}
