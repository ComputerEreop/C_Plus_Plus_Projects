#include <stdio.h>
#include <stdlib.h>
#include "LinkQueue.h"

int main()
{
	LQueue Lq = Create();
	srand((unsigned)time(0));
	for (int i = 0; i < 10; i++)
		Insert(Lq, rand() % 100);
	printf("���г��ȣ�%d\n", getLength(Lq));
	printf("��ͷԪ�أ�%d\n", GetHead(Lq));
	printf("��ͷԪ��  ����Ԫ��\n");
 	while (getLength(Lq) > 0) //�����У�ѭ�������Ƕ��в�Ϊ��
 	{
 		int ret = GetHead(Lq);//��ȡ��ͷԪ��
 		printf("  %d          ", ret);
 		ret = Del(Lq)->data; //������
 		printf("%d\n", ret);
 	}

	Clear(Lq); //��ն���
	system("pause");
	return 0;
}
