#include "seqstack.h"

void InitStack(SeqStack* stack) //��ʼ��ջ
{
	stack->top = -1; 
}

int IsEmpty(SeqStack* stack) //�ж�ջ�Ƿ�Ϊ��
{
	if (stack->top == -1)
		return 1;
	return 0;
}

int SeqStack_Top(SeqStack* stack) //����ջ��Ԫ��
{
	if (!IsEmpty(stack))
		return stack->data[stack->top];
	return INFINITY; //ֻ�������򵥱�ʶ���п���ջ��Ԫ��ҲΪ-1��
}

int SeqStack_Pop(SeqStack* stack) //����ջ��Ԫ��
{
	if (!IsEmpty(stack))
		return stack->data[stack->top--]; //����һ��Ԫ�غ�topҪ��1
	return INFINITY;
}

void SeqStack_Push(SeqStack* stack, int val) //��Ԫ��valѹ��ջ��
{
	if (stack->top >= MAXSIZE - 1) //ջ����
		return;
	stack->top++; //����Ԫ�غ�topҪ��1
	stack->data[stack->top] = val; //��valԪ�ش浽������
}

void SeqStack_Destory(SeqStack* stack) //����ջ
{
	if (!IsEmpty(stack))
		free(stack);
}
