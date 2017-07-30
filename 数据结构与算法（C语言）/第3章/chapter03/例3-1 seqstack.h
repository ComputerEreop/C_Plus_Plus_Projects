#ifndef _SEQSTACK_H_
#define _SEQSTACK_H_

#define MAXSIZE 1024
#define INFINITY 65535
typedef struct
{
	int data[MAXSIZE]; //�ڽṹ�ж���һ������
	int top;  //ָʾջ��Ԫ��,���������൱������
}SeqStack;

void InitStack(SeqStack* stack); //��ʼ��ջ
int IsEmpty(SeqStack* stack); //�ж�ջ�Ƿ�Ϊ��
int SeqStack_Top(SeqStack* stack); //����ջ��Ԫ��
int SeqStack_Pop(SeqStack* stack); //����ջ��Ԫ��
void SeqStack_Push(SeqStack* stack, int val); //��Ԫ��valѹ��ջ��
void SeqStack_Destory(SeqStack* stack); //����ջ

#endif
