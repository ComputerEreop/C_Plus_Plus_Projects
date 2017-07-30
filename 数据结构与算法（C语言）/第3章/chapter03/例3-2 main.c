#include <stdio.h>
#include <stdlib.h>
#include "linkstack.h"

int main()
{
	srand((unsigned)time(0));
	LinkStack lstack = NULL;
	lstack = Create(); //����һ��ջ

	//�ж�ջ�Ƿ�Ϊ��
	int ret;
	ret = IsEmpty(lstack);
	if (ret)
		printf("ջΪ�գ�\n");
	else
		printf("ջ��Ϊ�գ�\n");

	//��ջ�в���Ԫ��
	for (int i = 0; i < 10; i++)
	{
		Push(lstack, rand() % 100); //������������������
	}

	//�ٴ��ж�ջ�Ƿ�Ϊ��
	ret = IsEmpty(lstack);
	if (ret)
		printf("ջΪ�գ�\n");
	else
		printf("ջ��Ϊ�գ�\n");

	//��ջ�ĳ���
	printf("ջ�ĳ��ȣ�%d\n", getSize(lstack));

	//��ȡջ��Ԫ��
    //���ص���pNode������ͣ�Ҫת��Ϊint����
	printf("ջ��Ԫ�أ�%d\n", *((int*)getTop(lstack))); 

	//��ӡջ�е�Ԫ��
	while (lstack->size > 0)
	{
         //Pop()���ص���pnode������ͣ�ҲҪת��Ϊint����
		printf("%d  ", *((int*)Pop(lstack))); 
	}
	printf("\n");

	//����ջ
	Destory(lstack);

	system("pause");
	return 0;
}
