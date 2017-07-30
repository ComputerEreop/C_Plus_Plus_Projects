#include "clist.h"
#include <stdio.h>
#include <stdlib.h>

pHead ClistCreate() //����ѭ������
{
	pHead ph = (pHead)malloc(sizeof(struct Head)); //Ϊͷ������ռ�
	if (ph == NULL)
		printf("����ͷ���ʧ�ܣ�"); //Ϊ�˷������н���鿴��������return����
	//������ͷ���󣬳�ʼ��ͷ���������
	ph->length = 0;
	ph->next = NULL;
	return ph; //��ͷ��㷵��
}

int IsEmpty(pHead ph) //�ж������Ƿ�Ϊ��
{
	if (ph == NULL)
		printf("�����˫��������");
	if (ph->length == 0) //�������Ϊ0��������Ϊ��
		return 1;
	else
		return 0;
}

int ClistInsert(pHead ph, int pos, int val) //�������posλ�ò���Ԫ��val
{

	if (ph == NULL || pos < 0 || pos > ph->length)
	{
		printf("����Ԫ��ʱ��������������\n");
	}

	pNode pval = NULL;
	//��������������Ϊ��Ԫ��val������
	pval = (pNode)malloc(sizeof(struct Node));
	pval->data = val; //��ֵval���浽�˽����

	//������Ҫ�ж����ĸ�λ�ò���Ԫ�أ����ж������Ƿ�Ϊ��
	if (IsEmpty(ph)) //�������Ϊ��
	{
		ph->next = pval;  //ֱ�ӽ������뵽ͷ����
		pval->next = pval; //����һ�����ָ�����Լ�
	}
	else //ѭ������Ϊ�գ����Ϊ��ͷ�����루��ͷ���󣩺���ͨλ�ò���
	{
		pNode pRear = ph->next;
		if (pos == 0) //�ڵ�һ��λ�ã�ͷ���󣩲���
		{
			//��0��λ�ò��룬��Ҫ���ҵ�β���
			while (pRear->next != ph->next) //ѭ������������
			{
				pRear = pRear->next; //pCurָ������ƶ�
			}
			//whileѭ��������pRearָ��β���
			//Ȼ�����Ԫ��
			pval->next = ph->next;
			ph->next = pval;
			pRear->next = pval; //����������˳���ܸ���
		}
		else //�������0��λ�ò��룬��͵�����������
		{
			pNode pCur = ph->next;
			for (int i = 1; i < pos; i++) //��Ҫ���������ҵ�Ҫ�����λ��
			{
				pCur = pCur->next; //pCurָ�������
			}
			//ѭ�������󣬴�ʱpCurָ�����Ҫ�����λ��
			pval->next = pCur->next; //ָ��Ͽ������ӵĹ���
			pCur->next = pval;
		}
	}
	ph->length++;
	return 1;
}

void print(pHead ph) //��ӡѭ�������е�Ԫ��
{
	if (ph == NULL || ph->length == 0)
	{
		printf("������������");
	}

	pNode pTmp = ph->next;

	for (int i = 0; i < ph->length; i++)
	{
		printf("%d ", pTmp->data);
		pTmp = pTmp->next;
	}
	printf("\n");
}
