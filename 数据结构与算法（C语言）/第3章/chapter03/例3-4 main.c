#include "linkstack.h" //��ջ��ͷ�ļ���������
#include <stdio.h>

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

//����������������
int express(int left, int right, char op)
{
	switch (op)
	{
	case '+':
		return left + right;
	case '-':
		return left - right;
	case '*':
		return left * right;
	case '/':
		return left / right;
	default:
		break;
	}
	return -1;
}

//��׺���ʽ����
int Calculate(const char * str)
{
	LinkStack lstack = NULL;
	lstack = Create();

	int i = 0;
	while (str[i]) //�����ַ���
	{
		if (isNumber(str[i])) //��������֣�ֱ����ջ
			Push(lstack, str[i] - '0'); //�ڴ洢ʱ���ǰ��ַ���ASCII��洢�ģ�����Ҫ��ȥ��0��
		else if (isOperator(str[i])) //�������������͵������Ҳ�����
		{
			int left = Pop(lstack)->data;
			int right = Pop(lstack)->data;
			int ret = express(left, right, str[i]); //����
			Push(lstack, ret); //��������ջ
		}
		else
		{
			printf("error!\n");
			break;
		}
		i++;
	}

	if (str[i] == '\0' && getSize(lstack) == 1)
		return *((char*)getTop(lstack));
}

int main()
{
	char *str = "1325+*+";  //��ȷ�ĺ�׺���ʽ
	int num = Calculate(str);
	printf("%d\n", num);

	system("pause");
	return 0;
}
