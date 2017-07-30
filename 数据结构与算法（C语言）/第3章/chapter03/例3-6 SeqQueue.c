#include "SeqQueue.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

SeqQueue Create()
{
	SeqQueue Sq = (SeqQueue)malloc(sizeof(struct Queue)); //����ռ�
	Sq->front = Sq->rear = -1;
	memset(Sq->data, 0, MAXSIZE*sizeof(int));
	return Sq;
}

int getLength(SeqQueue Sq)
{
	return Sq->rear - Sq->front; //���г����Ƕ�ͷ��β֮��
}

int IsEmpty(SeqQueue Sq)
{
	if (Sq->front = Sq->rear)//�ж϶����Ƿ�Ϊ�յ�����
	{
		return 1;
	}
	return 0;
}

// ����ǰ���Ƕ�ͷ, ����Ƕ�β
void Insert(SeqQueue Sq, int val)
{
	// �����Ƿ�����
	if (Sq->rear == MAXSIZE - 1)
	{
		printf("�����������޷��ٲ���Ԫ�أ�\n");
		return;
	}
	//����ǿն���
	if (Sq->front == Sq->rear) 
	{
		Sq->front = Sq->rear = 0; 
		Sq->data[Sq->rear] = val;
		Sq->rear++;
	}
	else
	{
		Sq->data[Sq->rear] = val; //��������
		Sq->rear++;
	}
}

int Del(SeqQueue Sq)
{
	// �ն���
	if (Sq->front == Sq->rear) //����Ϊ�յ�����
	{
		printf("����Ϊ�գ���Ԫ�ؿɵ���\n");
		return 10000; //���ش����־
	}
	int temp = Sq->data[Sq->front];
	Sq->front++; //ɾ����ͷԪ�غ�front����ƶ�
	return temp;
}

int GetHead(SeqQueue Sq)
{
	// �ն���
	if (Sq->front == Sq->rear)
	{
		printf("����Ϊ�գ���Ԫ�ؿ�ȡ��\n");
		return 10000;
	}
	// ��ȡԪ��
	return  Sq->data[Sq->front];
}

void Clear(SeqQueue Sq)
{

	Sq->front = Sq->rear = -1;
	printf("��������գ�\n");
}

void Destory(SeqQueue Sq)
{
	free(Sq);
	printf("����������!\n");
}
