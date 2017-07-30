#include "dlist.h"
#include <stdio.h>
#include <stdlib.h>

pHead DlistCreate()  //����˫������
{
	pHead ph = (pHead)malloc(sizeof(struct Head)); //Ϊͷ������ռ�
	if (ph == NULL)
		printf("����ͷ���ʧ�ܣ�"); //Ϊ�˷������н���鿴��������return����
	//������ͷ���󣬳�ʼ��ͷ���������
	ph->length = 0;
	ph->next = NULL;
	return ph; //��ͷ��㷵��
}
int getLength(pHead ph) //��ȡ˫������ĳ���
{
	//�ȶԴ����������������׳�Լ��
	if (ph == NULL)
		printf("�����˫��������");
	return ph->length;
}

int IsEmpty(pHead ph) //�ж�˫�����Ƿ�Ϊ��
{
	if (ph == NULL)
		printf("�����˫��������");
	if (ph->length == 0) //�������Ϊ0��������Ϊ��
		return 1;
	else
		return 0;
}

int DlistInsert(pHead ph, int pos, int val) //�������posλ�ò���Ԫ��val
{
	pNode pval = NULL;
	//������׳���ж�
	if (ph == NULL || pos < 0 || pos > ph->length)
		printf("����Ԫ��ʱ��������������");

	//����������󣬾�ҪΪԪ�ط�����ռ�
	pval = (pNode)malloc(sizeof(struct Node));
	pval->data = val; //��ֵval���浽�˽����

	//������Ҫ�ж����ĸ�λ�ò���Ԫ�أ����ж������Ƿ�Ϊ��
	if (IsEmpty(ph)) //�������Ϊ��
	{
		ph->next = pval; //ֱ�ӽ������뵽ͷ����
		pval->next = NULL;
		pval->pre = NULL; //��һ����㲻��ָͷ���
	}
	else //���˫����Ϊ�գ���Ҫ�ж��ǲ����ĸ�λ��
	{
		pNode pCur = ph->next;
		if (pos == 0) //�ڵ�һ��λ�ã�ͷ���󣩲���
		{
			ph->next = pval; //ͷ���ָ��pval
			pval->pre = NULL;
			pval->next = pCur; //pval�ĺ��ָ��ָ��pCur
			pCur->pre = pval; //pCurǰ��ָ��ָ��pval
		}
		else //������ǲ��뵽��һ��λ��
		{
			for (int i = 1; i < pos; i++) //��Ҫ���������ҵ�Ҫ�����λ��
			{
				pCur = pCur->next; //pCurָ�������
			}
			//ѭ�������󣬴�ʱpCurָ�����Ҫ�����λ��
			pval->next = pCur->next; //ָ��Ͽ������ӵĹ���
			pCur->next->pre = pval;
			pval->pre = pCur;
			pCur->next = pval;
		}
	}
	ph->length++;
	return 1;
}

pNode DlistDelete(pHead ph, int val) //ɾ��˫������ph�е�Ԫ��val
{
	if (ph == NULL || ph->length == 0)
	{
		printf("������������");
	}
	//�����������������ҵ�ֵΪval��Ԫ�أ�Ȼ����ɾ��
	pNode pval = DlistFind(ph, val); //�ҵ�ֵ���ڵĽ��
	if (pval == NULL)
	{
		return NULL;
	}
	printf("����ɾ��\n");
	//��Ϊ˫�����еĽ�����ǰ��������к�̽��
	pNode pRe = pval->pre; //pReָ��pval����ǰ�����
	pNode pNext = pval->next; //pNextָ��pval���ĺ�̽��

	pRe->next = pNext;
	pNext->pre = pRe;
	return pval;
}

pNode DlistFind(pHead ph, int val) //����ĳ��Ԫ��
{
	if (ph == NULL)
	{
		printf("������������");
	}
	//���������������Ҫ����˫��������Ҫ�ҵ�Ԫ��
	pNode pTmp = ph->next;  //�˹����뵥��������
	do
	{
		if (pTmp->data == val)
		{
			printf("�д�Ԫ�أ�\n");
			return pTmp;
		}
		pTmp = pTmp->next;
	} while (pTmp->next != NULL); //ѭ��������ֱ�������β

	printf("û��ֵΪ%d��Ԫ��!\n", val);
	return NULL;
}

void DlistDestory(pHead ph) //��������
{
	pNode pCur = ph->next;
	pNode pTmp;
	if (ph == NULL)
		printf("������������");

	while (pCur->next != NULL)
	{
		pTmp = pCur->next;
		free(pCur); //������ͷ�
		pCur = pTmp;
	}
	ph->length = 0; //�ص���ʼ��״̬
	ph->next = NULL;
}

void printFront(pHead ph) //��ӡ˫�������е�Ԫ�أ���ǰ�����ӡ
{
	if (ph == NULL)
	{
		printf("������������");
	}
	pNode pTmp = ph->next;
	while (pTmp != NULL)
	{
		printf("%d  ", pTmp->data);
		pTmp = pTmp->next;
	}
	printf("\n");
}

void printLast(pHead ph) //�����ӡ��������ĩβ��ʼ��ǰ��ӡ
{
	if (ph == NULL)
	{
		printf("������������");
	}
	pNode pTmp = ph->next;
	while (pTmp->next != NULL)
	{
		pTmp = pTmp->next;  //�Ƚ�ָ��pTmp�ƶ���ĩβ���
	}
	for (int i = --ph->length; i >= 0; i--) //��ĩβ�����ǰ��ӡԪ��
	{
		printf("%d  ", pTmp->data);
		pTmp = pTmp->pre;
	}
	printf("\n");
}
