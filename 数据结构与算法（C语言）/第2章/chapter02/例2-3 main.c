#define _CRT_SECURE_NO_WARNINGS
#include "dlist.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
	//����һ��˫������
	pHead ph = NULL;
	ph = DlistCreate();

	//�������в���Ԫ��
	int num;
	printf("������Ҫ�����Ԫ�أ�����0������\n");
	while (1)
	{
		scanf("%d", &num);
		if (num == 0)
			break;
		DlistInsert(ph, 0, num); //�����Գ����ͷ������
	}

	printf("˫�����ȣ�%d\n", getLength(ph));
	printFront(ph); //��ǰ�����ӡ˫�����Ԫ��
	DlistInsert(ph, 3, 99); //��3λ�ò�����Ԫ��99
	printFront(ph);//Ȼ���ٴ�ǰ�����ӡ˫�����Ԫ��
	printLast(ph); //�Ӻ���ǰ��ӡԪ��

	int val;
	printf("������Ҫ���ҵ�Ԫ�أ�\n");
	scanf("%d", &val);
	DlistFind(ph, val); //����Ԫ��

	int del;
	printf("������Ҫɾ����Ԫ�أ�\n");
	scanf("%d", &del);
	DlistDelete(ph, del); //ɾ��Ԫ��
	printFront(ph); //��ӡɾ��Ԫ�غ������

	DlistDestory(ph); //��������
	printf("˫�������ٳɹ���\n��ʱ������Ϊ��%d\n", ph->length);

	system("pause");
	return 0;
}
