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

int getSize(LinkStack lstack) 
{
	return lstack->size; //��ȡջ�Ĵ�С
}

int Push(LinkStack lstack, int val)
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


void Destory(LinkStack lstack) //����ջ
{
	if (IsEmpty(lstack))
	{
		free(lstack);
		printf("ջ��Ϊ�գ������������٣�\n");
		return;
	}
	//���ջ��Ϊ�գ���Ҫ��ջ�еĽ�㶼ɾ���ͷ�
	do
	{
		pNode pTmp;
		pTmp = Pop(lstack);
		free(pTmp);
	}while (lstack->size > 0);
	printf("ջ���ٳɹ���\n");
}
