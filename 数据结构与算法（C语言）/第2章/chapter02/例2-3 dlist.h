#ifndef _DLIST_H_
#define _DLIST_H_

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
	pNode pre; //ָ��ǰ������ָ��
	pNode next; //ָ���̽���ָ��
};

pHead DlistCreate();  //����˫������
int getLength(pHead ph); //��ȡ˫������ĳ���
int IsEmpty(pHead ph); //�ж������Ƿ�Ϊ��
int DlistInsert(pHead ph, int pos, int val); //�������posλ�ò���Ԫ��val
pNode DlistDelete(pHead ph, int val); //ɾ��˫������ph�е�Ԫ��val
pNode DlistFind(pHead ph, int val); //����˫���������Ƿ���ֵΪval��Ԫ��
void DlistDestory(pHead ph); //��������
void printFront(pHead ph); //��ӡ˫�������е�Ԫ��
void printLast(pHead ph);
#endif
