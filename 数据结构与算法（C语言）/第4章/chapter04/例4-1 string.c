#include <stdio.h>

typedef struct string
{
	char * str; //ָ�򴮵�ָ��
	int length; //���ĳ���
}String;
void strAssign(String* s, char* p) //��ֵ
{
	//�ȼ���p���ĳ��ȣ�Ȼ�����������Ϊs�е�str���ٿռ�
	int i = 0;
	while (p[i] != '\0')
		i++;
	s->str = (char*)malloc((i + 1)*sizeof(char));
	//Ȼ��p����ֵ��s��
	int j = 0;
	for (j = 0; j <= i; j++)
		s->str[j] = p[j];
	s->str[j + 1] = '\0'; //ĩβ��ֵ\0
	s->length = i; //�����ȼ�¼
}
int strLength(String* s) //�󴮵ĳ���
{
	return s->length;
}
void strCopy(String* s, String* t) //����t���Ƶ���s��
{
	//����Ϊs�������ڴ棬��С����t��
	s->str = (char*)malloc((t->length)*sizeof(char));
	memset(s->str, '\0', t->length + 1);
	for (int i = 0; i <= t->length; i++)
		s->str[i] = t->str[i];
}
int strEqual(String* s, String* t) //�ж������Ƿ����
{
	if (s->length == t->length)
	{
		while (*(s->str++) != *(t->str++))
		{
			printf("����������ȣ�\n");
			return 0;
		}
		printf("��������ȣ�\n");
		return 1;
	}
	printf("����������ȣ�\n");
	return 0;
}
void strConnect(String* s, String* t) //����������
{
	int len = s->length + t->length;
	char* temp = (char*)malloc((s->length + t->length)*sizeof(char)); //���뻺��
	memset(temp, '\0', s->length);
	int i, j;
	for (i = 0; i < s->length; i++) //��s���ȴ��뻺����
		temp[i] = s->str[i];
	for (j = 0; j < t->length; j++, i++) //�ٽ�t���������
		temp[i] = t->str[j];
	temp[i] = '\0';
	s->str = temp; //��s��ָ��temp
	s->length = s->length + t->length;
}

int strCompete(String* s, String* t) //�Ƚϴ���С
{
	if (s && t) //���������������Ϊ�գ���׳���жϣ�
	{
		int sl = s->length, tl = t->length; //��¼�������ĳ���
		while (*(s->str) != '\0' && *(t->str) != '\0')
		{
			if (*(s->str) < *(t->str))
				return -1;
			if (*(s->str) == *(t->str))
			{
				s->str++;
				t->str++;
			}
			if (*(s->str) > *(t->str))
				return 1;
			s->str++;
			t->str++;
		}
		//���ѭ������������һ�����Ѿ���β��
		//��ô�������������һ�����Ӵ�һ��������
		//��ʱ�Ƚ��������ĳ��ȴ�С
		if (sl < tl)
			return -1;
		if (sl == tl)
			return 0;
		if (sl > tl)
			return 1;
	}
}
void Insert(String *s, int pos, char* p) //���봮
{
	if (pos < 0 || pos > s->length)
		return;
	//�������p�ĳ���
	int plen = 0;
	while (p[plen] != '\0')
	{
		plen++;
	}
	//ѭ��������plen�ͼ�¼�˴�p�ĳ���
	//����һ����ʱ���棬����s�봮p�������
	char* temp = (char*)malloc((plen + s->length)*sizeof(char));
	int i;
	for (i = 0; i < pos; i++) //��s��posλ��ǰ�Ĵ������
	{
		temp[i] = s->str[i];
	}
	//Ȼ��p�����뵽posλ�ú�
	int j = 0;
	while (p[j] != '\0')
	{
		temp[i] = p[j];
		i++, j++;
	}
	//��p����������󣬽��Ž�ʣ�µ�s����������
	for (; pos < s->length; pos++)
	{
		temp[i] = s->str[pos];
		i++;
	}
	temp[i] = '\0';
	s->str = temp;
	s->length = s->length + plen;
	printf("����֮��%s\n", temp);
}
void Delete(String* s, int pos, int len) //ɾ��ĳһ���Ӵ�
{
	if (pos < 0 || pos > s->length || len > s->length - pos)
		return;
	//�ȴ���һ�����棬��СΪs->length - len
	char* temp = (char*)malloc((s->length - len)*sizeof(char));
	int i;
	for (i = 0; i < pos; i++) //��s����posλ��ǰ�Ĵ����Ƶ�temp������
	{
		temp[i] = s->str[i];
	}

	int j = pos + len;
	for (; j < s->length; j++)//��ȥ���Ӵ�����ʣ��Ĵ����Ƶ�temp��
	{
		temp[i] = s->str[j];
		i++;
	}
	temp[i] = '\0';
	s->str = temp;
	s->length = s->length - len;
	printf("ɾ���Ӵ���%s\n", temp);
}
void print(String* s)
{
	if (s)
		printf("%s\n", s->str);
}
