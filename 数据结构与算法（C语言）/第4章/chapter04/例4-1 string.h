#ifndef _STRING_H_
#define _STRING_H_

typedef struct string
{
	char * str;
	int length;
}String;

void strAssign(String* s, char* p); //��p����ֵ��ֵ��s
int strLength(String* s); //�󴮵ĳ���
int strEqual(String* s, String* t);//�ж��������Ƿ����
int strCompete(String* s, String* t); //�Ƚ�������С
void strConnect(String* s, String* t); //���������ַ���
void strCopy(String* s, String* t); //����t���Ƶ���s��
void Insert(String *s, int pos, char* p); //��posλ�ò��봮p
void Delete(String* s, int pos, int len); //ɾ��posλ�ü����泤��Ϊlen�Ĵ�

void print(String* s); //��ӡ��

#endif
