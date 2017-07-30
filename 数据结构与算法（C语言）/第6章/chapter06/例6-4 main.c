#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct BitNode
{
	char data;
	struct BitNode* lchild, *rchild;
}BitNode;

//�������
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

//#�ŷ�����������
BitNode* BitNode_Create()
{
	BitNode* temp = NULL;
	char ch;
	scanf("%c", &ch);
	if (ch == '#') //�������#�ţ��򷵻�NULL
	{
		temp = NULL;
		return temp;
	}
	else
	{
		temp = (BitNode*)malloc(sizeof(BitNode)); //Ϊ������ռ�
		if (temp == NULL)
			return NULL;
		temp->data = ch;
		temp->lchild = NULL;
		temp->rchild = NULL;
		//����������������
		temp->lchild = BitNode_Create();
		temp->rchild = BitNode_Create();
		return temp;
	}
}

//�ͷ���:���ͷ������������ͷ�������������ͷŸ����
void BitNode_Free(BitNode* T)
{
	if (T == NULL)
		return;
	if (T->lchild != NULL)
	{
		BitNode_Free(T->lchild); //�ͷ�������
		T->lchild = NULL;
	}
	if (T->rchild != NULL)
	{
		BitNode_Free(T->rchild); //�ͷ�������
		T->rchild = NULL;
	}
	free(T);
}

int main()
{
	BitNode* T = NULL;
	printf("���������Ľ��Ԫ��ֵ��\n");
	T = BitNode_Create(); //������

	inOrder(T); //�����������
	printf("\n");
	BitNode_Free(T);
	printf("�������ͷųɹ���\n");

	system("pause");
	return 0;
}
