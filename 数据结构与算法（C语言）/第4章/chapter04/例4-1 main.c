#define _CRT_SECURE_NO_WARNINGS
#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int main()
{
	String s;
	char arr[1024];
	printf("������Ҫ��ֵ��s�Ĵ���\n");
	scanf("%s", arr);
	strAssign(&s, arr);

	printf("s:");
	print(&s);

	printf("���ȣ�%d\n", strLength(&s));

	//�ٴ���һ����t�����Ƚ��������Ĵ�С
	String t;
	printf("������Ҫ��ֵ��t�Ĵ���\n");
	scanf("%s", arr);
	strAssign(&t, arr);
	printf("t:");
	print(&t);
	printf("���ȣ�%d\n", strLength(&t));

	printf("�ж��������Ƿ���ȣ�");
	strEqual(&s, &t);
	
	printf("�Ƚ���������С��");
	int ret = strCompete(&s, &t); //�Ƚϴ�С
	if (ret < 0)
		printf("��t�ϴ�\n");
	if (ret == 0)
		printf("������һ����\n");
	if (ret > 0)
		printf("��s�ϴ�\n");

	//����������������
	printf("����s��t����������");
	strConnect(&s, &t); //����ֵΪchar*����
	print(&s);
	printf("������������s�ĳ��ȣ�%d\n", strLength(&s));
	//����s���Ƶ���t��
	//strCopy(&s, &t); //����t���Ƶ���s��
	//printf("����t���Ƶ���s����s��ֵ��");
	//print(&s);

	//�ڴ�s�в���һ����
	printf("������Ҫ������Ӵ���\n");
	scanf("%s", arr);
	Insert(&s, 3, arr);
	printf("���봮��s�ĳ��ȣ�%d\n", strLength(&s));

	//ɾ����s�е�ĳһ���Ӵ�
	Delete(&s, 3, 5);
	printf("ɾ���Ӵ���s�ĳ��ȣ�%d\n", strLength(&s));

	system("pause");
	return 0;
}
