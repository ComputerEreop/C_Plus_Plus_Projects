#include <stdio.h>
#include <stdlib.h>

void get_Next(char* t, int* next)
{
	//��ģʽ��t��nextֵ����������next��
	int i = 0, j = -1;
	next[0] = -1;
	while (t[i] != '\0') //ѭ������
	{
		if (j == -1 || t[i] == t[j])
		{
			i++, j++;
			if (t[i] != t[j])
				next[i] = j;
			else
				next[i] = next[j];
		}
		else
			j = next[j];
	}

	//��nextֵ��ӡ��ʾ
	for (int n = 0; n < i; n++)
		printf("%d  ", next[n]);
	printf("\n");
}
int KMP(char* s, char* t, int next[])
{
	if (s == NULL || t == NULL)
		return -1;
	//�����������s��ģʽ��t�ĳ���
	int len = 0;
	char* temp = t;
	while (*temp++ != '\0') //��t�ĳ���
		len++;

	//��ʼģʽƥ��
	int i = 0, j = 0;
	while (s[i] != '\0' && t[j] != '\0') //ѭ������
	{
		if (j == -1 || s[i] == t[j]) //���j=-1���������ַ���ȣ��ͱȶԺ�����ַ�
			i++, j++;
		else
			j = next[j]; //i���䣬j�ı䣬�����������Ļ���

		//���j��ֵ����ģʽt�Ĵ�С����֤��t�Ѿ�ƥ�䵽ĩβ
		if (j == len)
			return i - len;
	}
	return -1;
}