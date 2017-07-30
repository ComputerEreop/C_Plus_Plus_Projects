#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "linkstack.h"

char buffer[256] = { 0 }; //��ʱ����������ջ�е�����Ԫ�ؿ����ȴ��������
void Put(char ch)
{
	static int index = 0;
	buffer[index++] = ch; //���ַ����������Ȼ������index����
}

//���ȼ��ȽϺ���
int Priority(char ch)
{
	int ret = 0;
	switch (ch)
	{
	case '+':
	case '-':
		ret = 1;
		break;
	case '*':
	case '/':
		ret = 2;
		break;
	default:
		break;
	}
	return ret;
}

//�ж��ַ��Ƿ�������
int isNumber(char ch)
{
	return (ch >= '0' && ch <= '9'); //�����ַ���1�����򷵻�0
}

//�ж��ַ��Ƿ��������
int isOperator(char ch)
{
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

//�ж��ַ��Ƿ���������
int isLeft(char ch)
{
	return (ch == '(');
}

//�ж��ַ��Ƿ���������
int isRight(char ch)
{
	return (ch == ')');
}

//�������ܣ���׺ת��׺���ʽ
//��������ֵ����ȷ����0�����󷵻�-1
int  Transform(const char* str)
{
//��ת���ַ���ʱ���ȴ���һ��ջ
LinkStack lstack = Create(); //����ջ

//������ջ֮�󣬾ͱ����ַ����е��ַ�������������������ջ...
int i = 0;
while (str[i] != '\0')
{
	//�ж��Ƿ�������
	if (isNumber(str[i])) //��������֣���ֱ�����
	{
		Put(str[i]);  //���뵽buffer��
	}
	//�ж��Ƿ��������
	else if (isOperator(str[i])) 
	{
		//�����������������ж�ջ�Ƿ�Ϊ��
		if (!IsEmpty(lstack)) //���ջ��Ϊ��
		{
			//Ҫ�Ƚϴ˷�����ջ�����ŵ����ȼ�
			while (!IsEmpty(lstack) && Priority(*((char*)getTop(lstack))) 
                                                          >= Priority(str[i]))
			{ //���ջ���������ȼ��ߣ��ͽ�ջ�����ŵ����������ֱ��ջ�����ŵ����ȼ�
			  //С�ڴ˷��Ż���ջ�ѵ���
				Put(Pop(lstack)->data); //��������ջ�����Ŵ��뵽buffer��
			}
		}
		Push(lstack, str[i]); //���ջΪ�գ�����ֱ����ջ
	}
	//����������ţ�ֱ����ջ
	else if (isLeft(str[i]))
	{
		Push(lstack, str[i]);
	}
	//�����������
	else if (isRight(str[i]))
	{
		//�ж�ջ���ǲ��������ţ�������ǣ��͵�����ֱ��ƥ�䵽������
		while (!isLeft(*((char*)getTop(lstack)))) 
		{	
				//����ջ�����Ų����뵽buffer��
				Put(Pop(lstack)->data);
				if (IsEmpty(lstack)) //�������Ԫ�غ�ջ�Ѿ����ˣ���ƥ�����
				{
					printf("û��ƥ�䵽�����ţ�\n");
					return -1; //���ջ��Ϊ�գ���������
				}
			}

			Pop(lstack); //whileѭ����������ƥ�䵽�������ţ��������ŵ�����ע�ⲻ����
		}
		else
		{
			printf("�в���ʶ���ַ���\n");
			return -1;
		}
		i++;
	}
	
	//����������
	if (str[i] == '\0')
	{
		//���������󣬽�ջ�����з������ε���
		while (!IsEmpty(lstack))
		{
			if (getTop(lstack)->data == '(') //���ջ�л��С�(����֤��ȱ��������
			{
				printf("��û��ƥ��ġ�������ȱ�١�����\n");
				return -1;
			}
			Put(Pop(lstack)->data);
		}
	}
	else
	{
		printf("����û����ɣ�\n");
	}
	return 1;
}

int main()
{
	char str[1024] = {0};//"1325+*+";
	printf("����������������ʽ��\n");
	scanf("%s", str);
	
	if(Transform(str) == -1)
		printf("�����г��ִ����޷����ת����\n"); //ת��
	else
		printf("ת����ı��ʽ�ǣ� %s\n",buffer);
	system("pause");
	return 0;
}
