#define _CRT_SECURE_NO_WARNINGS
#include "clist.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int m, n;
	printf("������Լɪ�򻷵���������\n");
	scanf("%d", &m);
	if (m <= 0)
	{
		printf("��������ȷ�����֣�\n");
		return 0;
	}
	printf("����������ߵı�����\n");
	scanf("%d", &n);
	if (n <= 0)
	{
		printf("��������ȷ�����֣�\n");
		return 0;
	}

	//���������m��������
	pHead ph = NULL;
	ph = ClistCreate();
	if (ph == NULL)
	{
		printf("����ѭ������ʧ�ܣ�\n");
		return 0;
	}

	//����Ԫ��
	for (int i = m; i > 0; i--)
	{
		ClistInsert(ph, 0, i); //ʹ��ͷ�巨��m��1�������
	}

	print(ph);
	printf("����˳��\n");
	//����Ԫ�غ󣬾�ѭ����������
	pNode node = ph->next; //nodeָ��ָ���һ�����
	while (node->next != node) //ѭ���������������ָ����������ʱʣ���һ�����
	{
		for (int i = 1; i < n - 1; i++) //i < n - 1������n�����¿�ʼ
		{
			node = node->next; 
		}
		//forѭ��������nodeָ��ָ������ֵĽ���ǰ�����
		pNode pTmp = node->next; //pTmpָ��Ҫ���߳��Ľ��
		
		//��������Ҫ�ж���������0��λ�õĽ�㻹������λ�õĽ��
		if (pTmp == ph->next) //����˽����0��λ��
		{
			ph->next = pTmp->next; //ͷ���ҲҪ������
			node->next = pTmp->next;
			printf("%d  ", pTmp->data);
			free(pTmp);
			ph->length--;
		}
		else  //����˽��������λ��
		{
			node->next = pTmp->next;
			printf("%d  ", pTmp->data);
			free(pTmp);
			ph->length--;
		}
		node = node->next;
	}
	node->next = node;  //ѭ��������ֻʣ��nodeһ����㣬����ָ������
	printf("\n");

	printf("������������µ��� ");
	print(ph);

	system("pause");
	return 0;
}
