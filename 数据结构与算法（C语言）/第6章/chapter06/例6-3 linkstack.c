#include "linkstack.h"
#include <stdio.h>
#include <stdlib.h>

LinkStack Create() //����ջ
{
	LinkStack lstack = (LinkStack)malloc(sizeof(struct Stack));
	if (lstack != NULL)
	{
		lstack->top = NULL;
		lstack->size = 0;
	}
	return lstack;
}

int IsEmpty(LinkStack lstack) //�ж�ջ�Ƿ�Ϊ��
{
	if (lstack->top == NULL || lstack->size == 0)
		return 1;
	return 0;
}

int Push(LinkStack lstack, BitNode* val)
{
	pNode node = (pNode)malloc(sizeof(struct Node)); //ΪԪ��val������
	if (node != NULL)
	{
		node->data = val;
		node->next = getTop(lstack); //��Ԫ�ؽ��ָ����һ�����,��ʽʵ��
		lstack->top = node; //topָ���½��
		lstack->size++;
	}
	return 1;
}

pNode getTop(LinkStack lstack) //��ȡջ��Ԫ��
{
	if (lstack->size != 0)
		return lstack->top;
	return NULL;
}

pNode Pop(LinkStack lstack) //����ջ��Ԫ��
{
	if (IsEmpty(lstack))
	{
		return NULL;
	}
	pNode node = lstack->top; //nodeָ��ջ��Ԫ��
	lstack->top = lstack->top->next; //topָ����һ��Ԫ��
	lstack->size--;
	return node;
}
