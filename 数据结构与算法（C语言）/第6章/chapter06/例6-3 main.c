#include <stdio.h>
#include <stdlib.h>
#include "linkstack.h"

//Ѱ�ұ�����ʼ���
BitNode*  GoFarLeft(BitNode* T, LinkStack ls)
{
	if (T == NULL)
		return NULL;
	while (T->lchild != NULL) //��������Ϊ�գ���һֱ����Ѱ��
	{
		Push(ls, T);
		T = T->lchild;
	}
	return T;
}

//�ǵݹ������������
void MyOrder(BitNode* T)
{
	LinkStack ls = Create(); //����ջ
	BitNode* t = GoFarLeft(T, ls);//Ѱ�ұ�����ʼ���
	while (t != NULL)
	{
		printf("%c", t->data); //��ӡ��ʼ����ֵ
		//����������������ظ����裨1��
		if (t->rchild != NULL)
			t = GoFarLeft(t->rchild, ls); //Ѱ���������е���ʼ���
		else if (!IsEmpty(ls)) //���ջ��Ϊ��
		{
			t = getTop(ls)->data; //���˵�ջ��Ԫ�ؽ��
			Pop(ls); //ջ��Ԫ�ص���
		}
		else
			t = NULL;
	}
}
int main()
{
	BitNode nodeA, nodeB, nodeD, nodeF, nodeI, nodeL; //����6�����
	//����㶼��ʼ���������Ա�֤û�к��ӵĽ����Ӧָ�������
	memset(&nodeA, 0, sizeof(BitNode));
	memset(&nodeB, 0, sizeof(BitNode));
	memset(&nodeD, 0, sizeof(BitNode));
	memset(&nodeF, 0, sizeof(BitNode));
	memset(&nodeI, 0, sizeof(BitNode));
	memset(&nodeL, 0, sizeof(BitNode));
	//����㸳ֵ
	nodeA.data = 'A';
	nodeB.data = 'B';
	nodeD.data = 'D';
	nodeF.data = 'F';
	nodeI.data = 'I';
	nodeL.data = 'L';
	//�洢���֮����߼���ϵ
	nodeA.lchild = &nodeB; //A���������B
	nodeA.rchild = &nodeD; //A�����Һ�����D
	nodeB.rchild = &nodeF; //B�����Һ�����F
	nodeF.lchild = &nodeL; //F����������L
	nodeD.lchild = &nodeI; //D����������I

	printf("�����������ɹ���\n");

	printf("�ǵݹ����������");
	MyOrder(&nodeA);

	printf("\n");
	system("pause");
	return 0;
}
