#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include"list.h"

int main()
{
	int ret;
	pHead *ph = createList(); //��������
	if (ph == NULL)
	{
		printf("��������ʧ�ܣ�\n");
	}
	int arr[10] = { 1, 2, 3, 4, 56, 76, 7, 4, 36, 34 }; //����һ��int��������

	for (int i = 0; i <= 6; i++)
	{
		Insert(ph, 0, arr[i]); //������Ԫ�ز��뵽�����У�ÿ�ζ���ͷ������
	}

	printf("�����ȣ�%d\n", Size(ph));

	printf("��ӡ�����е�Ԫ�أ�\n");
	print(ph);
	printf("ɾ�������е�Ԫ�أ�������Ҫɾ����Ԫ�أ�\n");
	int num;
	scanf("%d", &num); //������Ϊ���Գ���Ϊ�����쳣�����������������е�Ԫ��
	Delete(ph, num);
	printf("Ԫ��ɾ���ɹ���ɾ��Ԫ��%d��������Ԫ��Ϊ��\n", num);
	print(ph);

	ret = find(ph, 3); //����������ĳһ��Ԫ��
	if (ret)
		printf("get!\n");
	else
		printf("NO!\n");

	system("pause");
	return 0;
}
