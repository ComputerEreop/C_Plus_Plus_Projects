#define _CRT_SECURE_NO_WARNINGS
#include "head.h"

int main()
{
	char s[1024], t[100];
	int next[100]; //�洢t����ģʽֵ
	printf("����������s��\n");
	scanf("%s", s);
	printf("������ģʽt:\n");
	scanf("%s", t);
	printf("s���ȣ�%d\n", strlen(s));
	printf("t���ȣ�%d\n", strlen(t));

	printf("ģʽ��t��nextֵ��");
	get_Next(t, next);

	int ret = KMP(s, t, next);
	if (ret == -1)
		printf("ƥ��ʧ�ܣ�\n");
	else
		printf("ƥ��ɹ���t����s���е�һ�γ��ֵ�λ����%d\n", ret);

	system("pause");
	return 0;
}
