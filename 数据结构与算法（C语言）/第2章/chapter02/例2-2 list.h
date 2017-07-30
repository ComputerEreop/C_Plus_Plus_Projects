#ifndef _LIST_H_
#define _LIST_H_

struct Node;
typedef struct Node  List;
typedef struct Header pHead;

pHead * createList(); //��������
int isEmpty(pHead* l);  //�ж������Ƿ�Ϊ��
int Insert(pHead* l, int pos, int val); //����Ԫ�أ�����ɹ�����1��
List* Delete(pHead* l, int ele);  //ɾ��Ԫ�أ�ɾ���ɹ�������ɾ����Ԫ��
List* find(pHead* l, int ele);  //����ĳ��Ԫ���Ƿ����
int Size(pHead* l);  //��ȡ�����С
void Destory(pHead* l); //��������
void print(pHead *l); //��ӡ����

struct Node  //���
{
	int data; //������
	struct Node* next;  //ָ����һ������ָ��
};

struct Header  //ͷ���
{
	int length; //��¼�����С
	struct Node* next;
};
#endif
