#ifndef _SQQUEUE_H
#define _SQQUEUE_H

#define MAXSIZE 50
typedef struct Queue* SeqQueue;
struct Queue
{
	int front; // ��ͷ
	int rear; // ��β
	int data[MAXSIZE]; // ����
};

SeqQueue Create(); // ��ʼ������������һ���ն���Sq
int getLength(SeqQueue Sq); // ���ض���Sq��Ԫ�ظ���(���ȣ�
int IsEmpty(SeqQueue Sq); // �ж϶����Ƿ�Ϊ��
void Insert(SeqQueue Sq, int val);// ���
int Del(SeqQueue Sq);// ����
int GetHead(SeqQueue Sq);// ��ȡ��ͷԪ��
void Clear(SeqQueue Sq);// ������Sq���
void Destory(SeqQueue Sq); //���ٶ���

#endif	//_SQQUEUE_H
