#include <stdio.h>
#include <stdlib.h>

struct Header  //ͷ���
{
	int length; //��¼�����С
	struct Node* next; //ָ���һ������ָ��
};
struct Node  //���
{
	int data; //������
	struct Node* next;  //ָ����һ������ָ��
};

typedef struct Header pHead; //��struct Header������ΪpHead
typedef struct Node  List;  //��struct Node������ΪList

//��������
pHead * createList()//pHead��struct Header�ı�������ͷ�������
{
	pHead* ph = (pHead*)malloc(sizeof(pHead)); //Ϊͷ�������ڴ�
	ph->length = 0; //Ϊͷ����ʼ��
	ph->next = NULL;
	return ph; //��ͷ����ַ����
}
//��ȡ�����С
int Size(pHead* ph)
{
	if (ph == NULL)
	{
		printf("������������");
		return 0;
	}

	return ph->length;
}
//����
int Insert(pHead* ph, int pos, int val) //��ĳһ��λ�ò���ĳһ��Ԫ�أ�����ɹ�����1��
{
	//������׳���ж�
	if (ph == NULL || pos < 0 || pos > ph->length)
	{
		printf("������������");
		return 0;
	}
	//���������в���Ԫ��ʱ����Ҫ�ҵ����λ��
	List* pval = (List*)malloc(sizeof(List)); //�ȷ���һ���ڴ����洢Ҫ���������
	pval->data = val;

	List *pCur = ph->next; //��ǰָ��ָ��ͷ����ĵ�һ�����
	if (pos == 0) //�����ڵ�һ��λ��
	{
		ph->next = pval; //ָ��Ͽ����ӹ���
		pval->next = pCur;
	}
	else
	{
		for (int i = 1; i < pos; i++) //�ҵ�Ҫ�����λ��
		{
			pCur = pCur->next;
		}

		pval->next = pCur->next; //ָ��Ͽ������ӹ���
		pCur->next = pval;
	}

	ph->length++; //����һ��Ԫ�أ�����Ҫ��1
	return 1;
}
//����
List* find(pHead* ph, int val)  //����ĳ��Ԫ��
{
	//������׳���ж�
	if (ph == NULL)
	{
		printf("������������");
		return NULL;
	}

	//��������������Ԫ��
	List *pTmp = ph->next;
	do
	{
		if (pTmp->data == val)
		{
			return pTmp;
		}
		pTmp = pTmp->next;
	} while (pTmp->next != NULL); //ѭ��������ֱ�������β

	printf("û��ֵΪ%d��Ԫ��!", val);
	return NULL;
}

//ɾ��
List* Delete(pHead* ph, int val)  //ɾ��ֵΪval��Ԫ�أ�ɾ���ɹ�������ɾ����Ԫ��
{
	//������׳���ж�
	if (ph == NULL)
	{
		printf("���������");
		return NULL;
	}

	//�ҵ�valֵ���ڽ��
	List* pval = find(ph, val);
	if (pval == NULL)
	{
		printf("û��ֵΪ%d��Ԫ��!", val);
		return NULL;
	}

	//��������ȥ�ҵ�Ҫɾ����㣬���ҳ���ǰ������̽��
	List *pRe = ph->next;  //��ǰ���
	List *pCur = NULL;
	if (pRe->data == val)  //���ɾ�����ǵ�һ�����
	{
		ph->next = pRe->next;
		ph->length--;
		return pRe;
	}
	else //���ɾ�������������
	{
		for (int i = 0; i < ph->length; i++)  //��������
		{
			pCur = pRe->next;
			if (pCur->data == val) //�ҵ�Ҫɾ����Ԫ��
			{
				pRe->next = pCur->next; //����ɾ��Ԫ�ص��������������������
				ph->length--; //���ȼ�1
				return pCur;  //����ɾ����Ԫ�ؽ�㷵��
			}
			pRe = pRe->next;
		}
	}
}

//��������
void Destory(pHead* ph)
{
	List *pCur = ph->next;
	List *pTmp;
	if (ph == NULL)
		printf("������������");

	while (pCur->next != NULL)
	{
		pTmp = pCur->next;
		free(pCur); //������ͷ�
		pCur = pTmp;
	}
	ph->length = 0; //�ص���ʼ��״̬
	ph->next = NULL;
}

//��������
void print(pHead *ph)
{
	if (ph == NULL)
	{
		printf("������������");
	}
	List *pTmp = ph->next;
	while (pTmp != NULL)
	{
		printf("%d  ", pTmp->data);
		pTmp = pTmp->next;
	}
	printf("\n");
}



