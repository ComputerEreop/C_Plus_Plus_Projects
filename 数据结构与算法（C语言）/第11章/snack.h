//��
#pragma once

enum EDirection
{
	
	SNACK_UP,		// W
	SNACK_LEFT,		// A
	SNACK_DOWN,	// S
	SNACK_RIGHT	// D
};
// type declaration
typedef struct Snack
{
	int x;
	int y;
	struct Snack *pNext;
}Snack;

enum ESnakeStutas //�߳���ʳ����״̬
{
	SnakeNormal = 1,
	SnakeShorten,
	SnakeAccelerate
};
int snackLength;					// �ߵĳ���
Snack *pHeader, *pTail;				// ��ͷ����β
enum EDirection direction;	        // �ߵ��ƶ�����
enum ESnakeStutas SnakeStutas;		//�߳���ʳ����״̬

// ��ʼ����
Snack* SnackInit();
// �������ƶ������̣߳�
void SnackMove();
// ͷ�巨��������
Snack* SnackInsert();
// ĳ������ؿ��е���Ϸ����
void SnackDestroy();

void  SnackNormalFn();//��������ʳ��
Snack*  SnackShorten();//�����ж�ʳ�������
void SnackAccelerate();//�����»�ʳ��߼����ƶ�
