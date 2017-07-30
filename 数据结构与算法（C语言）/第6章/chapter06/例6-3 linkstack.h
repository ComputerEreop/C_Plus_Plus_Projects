#ifndef _LINKSTACK_H_
#define _LINKSTACK_H_

//�������Ľ��ṹ
typedef struct BitNode
{
	char data; //��������Ϊchar
	struct BitNode* lchild, *rchild;
}BitNode;

//ջ�Ľ��ṹ
typedef struct Node * pNode;
typedef struct Stack * LinkStack;
struct Node //���ݽ��
{
	BitNode* data;  //���ݣ�BitNode�ṹ�����͵�ָ��
	pNode next; //ָ��
};

struct Stack  //�˽ṹ��¼ջ�Ĵ�С��ջ��Ԫ��ָ��
{
	pNode top; //ջ��Ԫ��ָ��
	int size; //ջ��С
};

LinkStack Create(); //����ջ
int IsEmpty(LinkStack lstack); //�ж�ջ�Ƿ�Ϊ��
int Push(LinkStack lstack, BitNode* val); //Ԫ����ջ
pNode getTop(LinkStack lstack); //��ȡջ��Ԫ��
pNode Pop(LinkStack lstack); //����ջ��Ԫ��

#endif
