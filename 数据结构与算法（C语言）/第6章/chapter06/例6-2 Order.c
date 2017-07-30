#include <stdio.h>
#include <stdlib.h>

typedef struct BitNode
{
	char data;
	struct BitNode* lchild, *rchild;
}BitNode;


//1���������
void preOrder(BitNode* T)
{
	if (T == NULL)
		return;
	printf("%c", T->data); //��ӡ���ڵ��ֵ

	//��������ڵ��ٱ���������
	if (T->lchild != NULL)
		preOrder(T->lchild); //�ݹ����
	//�������������ٱ���������
	if (T->rchild != NULL)
		preOrder(T->rchild);
}

//2���������
void inOrder(BitNode* T)
{
	if (T == NULL)
		return;
	//�ȱ���������
	if (T->lchild != NULL)
		inOrder(T->lchild); //�ݹ����

	printf("%c", T->data); //�ٱ������ڵ�

	//������������
	if (T->rchild != NULL)
		inOrder(T->rchild);
}

//3���������
void lastOrder(BitNode* T)
{
	if (T == NULL)
		return;
	//�ȱ���������
	if (T->lchild != NULL)
		lastOrder(T->lchild); //�ݹ����
	//�ٱ���������
	if (T->rchild != NULL)
		lastOrder(T->rchild);
	printf("%c", T->data); //���������ڵ�
}

int main()
{
	BitNode nodeA, nodeB, nodeD, nodeF, nodeI, nodeL; //����6���ڵ�
	//���ڵ㶼��ʼ���������Ա�֤û�к��ӵĽڵ���Ӧָ�������
	memset(&nodeA, 0, sizeof(BitNode));
	memset(&nodeB, 0, sizeof(BitNode));
	memset(&nodeD, 0, sizeof(BitNode));
	memset(&nodeF, 0, sizeof(BitNode));
	memset(&nodeI, 0, sizeof(BitNode));
	memset(&nodeL, 0, sizeof(BitNode));
	//���ڵ㸳ֵ
	nodeA.data = 'A';
	nodeB.data = 'B';
	nodeD.data = 'D';
	nodeF.data = 'F';
	nodeI.data = 'I';
	nodeL.data = 'L';
	//�洢�ڵ�֮����߼���ϵ
	nodeA.lchild = &nodeB; //A�ڵ�������B
	nodeA.rchild = &nodeD; //A�ڵ���Һ�����D
	nodeB.rchild = &nodeF; //B�ڵ���Һ�����F
	nodeF.lchild = &nodeL; //F�ڵ��������L
	nodeD.lchild = &nodeI; //D�ڵ��������I

	printf("�����������ɹ���\n");

	printf("���������");
	preOrder(&nodeA);

	printf("\n���������");
	inOrder(&nodeA);

	printf("\n���������");
	lastOrder(&nodeA);
	printf("\n");
	system("pause");
	return 0;
}