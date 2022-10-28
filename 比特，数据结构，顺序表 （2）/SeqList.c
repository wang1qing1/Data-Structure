#include"SeqList.h"

//�п�
static int JudgeEmpty(SeqList* pSL)
{
	assert(pSL);

	//���˷��� 1��û������ 0.
	return pSL->size == pSL->capacity;  
}

static void JudegCapacity(SeqList* pSL)
{
	//�����������ʱ������ǰ���ݸ������ڵ�ǰ����ʱ��������
	if (pSL->capacity == pSL->size)
	{
		//����ǵ�һ��������ݣ�������Ҫ��һ����ʼ�������Ժ���Ҫ���ݾ������ݵ���ǰ����������������
		pSL->capacity = (pSL->capacity) == 0 ? 4 : pSL->capacity * 2;
		SLDateType* pf = (SLDateType*)realloc(pSL->date, pSL->capacity * sizeof(SLDateType));
		assert(pf);
		pSL->date = pf;
		//pSL->capacity = newcapacity;
	}
}

//��ʼ��
void SeqListInit(SeqList* pSL)
{
	pSL->date = NULL;
	pSL->capacity = 0;
	pSL->size = 0;
}

//β��
void SeqListPushBank(SeqList *pSL, SLDateType date)
{
	assert(pSL);
	//�ж�����
	JudegCapacity(pSL);
	pSL->date[pSL->size] = date;
	pSL->size++;
}

//˳���Ĵ�ӡ
void SeqListPrintf(SeqList* pSL)
{
	assert(pSL);
	for (int i = 0; i < pSL->size; i++)
	{
		printf("%d ", pSL->date[i]);
	}
	printf("\n");
}

//˳��������
void SeqListDestroy(SeqList* pSL)
{
	//���ԣ���ֹ�������
	assert(pSL);
	//��˳�������ʱ�������͵�ǰ���ݸ�������Ҫ��Ϊ0.
	if (pSL->date != NULL)
	{
		free(pSL->date);
		pSL->date = NULL;
		pSL->date = 0;
		pSL->capacity = 0;
	}
}

//βɾ
void SeqListPopbank(SeqList* pSL)
{
	assert(pSL);
	//������飬ֻ�е�˳����е����ݴ��� 0 ʱ�����ܽ���ɾ������
	assert(pSL->size > 0);
	pSL->size--;
}

//ͷ��
void SeqListPushFront(SeqList* pSL, SLDateType* date)
{
	assert(pSL);
	JudegCapacity(pSL);
	//Ų������
	for (int i = pSL->size-1; i >=0; i--)
	{
		pSL->date[i + 1] = pSL->date[i];
	}
	//��������
	pSL->date[0] = date;
	pSL->size++;
}

//ͷɾ
void SeqListPopFront(SeqList* pSL)
{
	//�п�
	if (JudgeEmpty(pSL))
	{
		printf("���\n");
		exit(-1);
	}
	for (int i = 0; i < pSL->size - 1; i++)
	{
		pSL->date[i] = pSL->date[i + 1];
	}
	pSL->size--;
}

//˳������
int SeqListFind(SeqList* pSL, SLDateType date)
{
	assert(pSL);
	for (int i = 0; i < pSL->size; i++)
	{
		if (pSL->date[i] == date)
		{
			return i;
		}
	}
	
	return -1;
}

//˳�����posλ�ò���date
void SeqListInsert(SeqList* pSL, size_t pos, SLDateType date)
{
	assert(pSL);
	//������λ���Ƿ����
	assert(pos>=0 && pos<pSL->size);
	//�ж�����
	JudegCapacity(pSL);
	for (int i = pSL->size - 1; i >= pos; i--)
	{
		pSL->date[i + 1] = pSL->date[i];
	}
	pSL->date[pos] = date;
	pSL->size++;
}

//˳���ɾ��posλ�õ�ֵ



