#include "LinkQueue.h"
#include <stdio.h>
#include <stdlib.h>

LQueue Create() //��������
{
	LQueue Lq = (LQueue)malloc(sizeof(struct Queue)); //Ϊͷ������ռ�
	Lq->front = NULL;
	Lq->rear = NULL;
	Lq->length = 0;
}

int getLength(LQueue Lq) //��ȡ����
{
	return Lq->length;
}

int IsEmpty(LQueue Lq) //�ж��Ƿ�Ϊ��
{
	if (Lq->length == 0)
		return 1;
	return 0;
}

void Insert(LQueue Lq, int val) //���
{
	pNode pn = (pNode)malloc(sizeof(struct Node)); //Ϊvalֵ������
	pn->data = val;
	pn->next = NULL;
		//�������Ϊ��,��pn�����뵽ͷ����
	if (IsEmpty(Lq)) 
	{
		//Lq->next = pn;
		Lq->front = pn; //frontָ��pn���
		Lq->rear = pn; //rearָ��pn���
	}
	else //������в�Ϊ��
	{
		Lq->rear->next = pn; //���뵽rearָ���
		Lq->rear = pn; //pn�����뵽rearλ�ô�
	}
	Lq->length++;
}

int GetHead(LQueue Lq) // ��ȡ��ͷԪ��
{
	if (IsEmpty(Lq))
	{
		printf("����Ϊ�գ���Ԫ�ؿ�ȡ��\n");
		return 10000;
	}
	return Lq->front->data;
}

pNode Del(LQueue Lq)  //����
{
	if (IsEmpty(Lq))
	{
		printf("����Ϊ�գ�ɾ������\n");
		return NULL;
	}
	pNode pTmp = Lq->front;
	Lq->front = pTmp->next;
	Lq->length--;
	return pTmp;
}

void Clear(LQueue Lq) // ������Lq���
{
	//�ص���ʼ״̬
	Lq->front = NULL;
	Lq->rear = NULL;
	Lq->length = 0;
	printf("�����Ѿ���գ�\n");
}
