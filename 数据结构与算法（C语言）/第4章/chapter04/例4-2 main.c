#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find(char* s, char* t) //ģʽƥ���㷨
{
	int i = 0, j = 0;
	while (i < strlen(s) && j < strlen(t))
	{
		if (s[i] == t[j]) //��������ַ���ȣ���ȶԺ����ַ�
		{
			i++;
			j++;
		}
		else //��������ַ������
		{
			i = i - j + 1; //��������һ��λ�ÿ�ʼ
              j = 0; //ģʽt��ͷ��ʼ
		}
	}
	//ѭ��������Ҫ�鿴i��j��λ��
	if (j == strlen(t)) //���j��ֵ����ģʽt�ĳ��ȣ���˵��t����ȫƥ��
		return i - strlen(t); 
	else
		return -1;
}


int main()
{
	char s[1024], t[100];
	printf("����������s��\n");
	scanf("%s", s);
	printf("������ģʽt:\n");
	scanf("%s", t);
	printf("s���ȣ�%d\n", strlen(s));
	printf("t���ȣ�%d\n", strlen(t));

	int ret = find(s, t);
	if (ret == -1)
		printf("ƥ��ʧ�ܣ�\n");
	else
		printf("ƥ��ɹ���t����s���е�һ�γ��ֵ�λ����%d\n", ret);

	system("pause");
	return 0;
}
