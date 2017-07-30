#ifndef _LINKQUEUE_H
#define _LINKQUEUE_H

typedef struct Node * pNode;
typedef struct Queue * LQueue; //�൱�ڶ���ͷ���pHead
struct Node
{
int data; //������
pNode next; //ָ����
};

struct Queue //ͷ���
{
	pNode front; //ָ��ͷ��㣬�൱��������ͷ������nextָ��
	pNode rear;  //ָ��β���
	int length; //���г���
};

LQueue Create(); //��������
int getLength(LQueue Lq); //��ȡ����
int IsEmpty(LQueue Lq); //�ж��Ƿ�Ϊ��
void Insert(LQueue Lq, int val);// valԪ�����
int GetHead(LQueue Lq);// ��ȡ��ͷԪ��
pNode Del(LQueue Lq);// ����
void Clear(LQueue Lq);// ������Lq���
#endif	//_LINKQUEUE_H
