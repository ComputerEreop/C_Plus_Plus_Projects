#include <stdio.h>
#include <stdlib.h>
#include "SeqQueue.h"

int main()
{
	SeqQueue Sq = Create(); //��������
	srand((unsigned)time(0));
	for (int i = 0; i < 10; ++i)
	{
		Insert(Sq, rand() % 100); //����У������������
	}
	printf("���г��ȣ�%d\n", getLength(Sq));
	printf("��ͷԪ��  ����Ԫ��\n");
	while (Sq->front != Sq->rear) //�����У�ѭ�������Ƕ��в�Ϊ��
	{
		int ret = GetHead(Sq);//��ȡ��ͷԪ��
		printf("  %d          ", ret);
		ret = Del(Sq); //������
		printf("%d\n", ret);
	}
	printf("���г��ȣ�%d\n", getLength(Sq));
	Clear(Sq);
	Destory(Sq);

	system("pause");
	return 0;
}
