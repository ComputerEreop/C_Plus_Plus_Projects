#ifndef _LINKSTACK_H_
#define _LINKSTACK_H_

typedef struct Node * pNode;
typedef struct Stack * LinkStack;
struct Node //���ݽ��
{
	int data;  //����
	pNode next; //ָ��
};

struct Stack  //�˽ṹ��¼ջ�Ĵ�С��ջ��Ԫ��ָ��
{
	pNode top; //ջ��Ԫ��ָ��
	int size; //ջ��С
};

LinkStack Create(); //����ջ
int IsEmpty(LinkStack lstack); //�ж�ջ�Ƿ�Ϊ��
int getSize(LinkStack lstack); //��ȡջ�Ĵ�С
int Push(LinkStack lstack, int val); //Ԫ����ջ
pNode getTop(LinkStack lstack); //��ȡջ��Ԫ��
pNode Pop(LinkStack lstack); //����ջ��Ԫ��
void Destory(LinkStack lstack); //����ջ

#endif
