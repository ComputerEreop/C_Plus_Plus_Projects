#ifndef _CLIST_H_
#define _CLIST_H_

struct Node;
typedef struct Head*  pHead;  //ͷ�������
typedef struct Node*  pNode;  //���ݽ������
//����ͷ���
struct Head
{
	int length;
	pNode next; //ָ����һ������ָ��
};
//�������ݽ��
struct Node
{
	int data;
	pNode next; //ָ���̽���ָ��
};
pHead ClistCreate();  //����ѭ������
int getLength(pHead ph); //��ȡѭ������ĳ���
int IsEmpty(pHead ph); //�ж������Ƿ�Ϊ��
int ClistInsert(pHead ph, int pos, int val); //�������posλ�ò���Ԫ��val
void print(pHead ph); //��ӡѭ�������е�Ԫ��

#endif
