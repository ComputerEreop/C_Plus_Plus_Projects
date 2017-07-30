#include <stdio.h>
#include <stdlib.h>
#include "seqstack.h"

int main()
{
	srand((unsigned)time(0)); //��ʱ��Ϊ���Ӳ������
	SeqStack stack; //����һ��˳��ջ
	InitStack(&stack); //��ʼ��ջ
	
	//��ջ�����Ԫ��
	for (int i = 0; i < 50; i++)
	{
		SeqStack_Push(&stack, rand() % 1000); //��ӵ��������������
	}

	//��ȡջ��Ԫ��
	printf("ջ��Ԫ�أ�%d\n", SeqStack_Top(&stack));

	//��ӡջ��Ԫ��
	printf("ջ�е�Ԫ��:");
	for (int i = 0; i < 50; i++)
	{
		if (i % 5 == 0)
			printf("\n"); //ÿ5��Ԫ��һ��
		printf("%d  ", SeqStack_Pop(&stack));  //���ν�ջ��Ԫ�ص���	
	}

	printf("\n");

	system("pause");
	return 0;
}
