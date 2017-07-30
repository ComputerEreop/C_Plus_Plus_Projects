#include "global.h"
#include "map.h"
#include "food.h"
#include "snack.h"
#include "random.h"
#include <stdio.h>
#include <conio.h>
#include <process.h>//windows�߳�ͷ�ļ�
#include <windows.h>//��ȡ���������ͷ�ļ�

void InitGame(int n)
{
	LoadMap(n); //���ص�ͼ
	SnackInit(); //�߳�ʼ��
	PreviewMap();
	FoodCreate(); //����ʳ��
	PreviewMap(); //Ԥ�����ͼ
	DisplayMap(); //��ʾ��ͼ
}

void MainLoop(void *param)//��Ϸ����ѭ������ȡ��������
{
	char ch;
	while (status == GAME_LOOP)//���߳�ִ�ж�ȡ�û����빦��
	{
		ch = _getch(); //��ȡ��������
		switch (ch)
		{
		case 'w': 
		case 'W':
			direction = SNACK_UP; //�����ƶ�
			break;
		case 'a':
		case 'A':
			direction = SNACK_LEFT; //�����ƶ�
			break;
		case 's':
		case 'S':
			direction = SNACK_DOWN; //�����ƶ�
			break;
		case 'd':
		case 'D':
			direction = SNACK_RIGHT; //�����ƶ�
			break;
		default: 
			break;
		}
	}
}

void Failure() //����ʧ�ܣ���ӡ��Ϸ��������
{
	int i, tmp;
	system("cls");
	printf("\n\n\n\n");
	for (i = 0; i < CONSOLE_MAX_WIDTH; i++) //��ӡ��һ�š�#������
		printf("#"); 

	tmp = CONSOLE_MAX_WIDTH - 30;
	for (i = 0; i < tmp / 2; i++)
		printf(" ");
	printf("�ܱ�Ǹ����ʧ���ˣ����ٴο�����Ϸ\n"); //��ӡ������ʾ

	for (i = 0; i < CONSOLE_MAX_WIDTH; i++) //��ӡ�ڶ��š�#������
		printf("#");
	system("pause");
}

void VictoryFn() //��ӡʤ�����ؽ���
{
	int i, tmp;
	system("cls");
	printf("\n\n\n\n");
	for (i = 0; i < CONSOLE_MAX_WIDTH; i++)
		printf("#");

	tmp = CONSOLE_MAX_WIDTH - 30;
	for (i = 0; i < tmp / 2; i++)
		printf(" ");
	printf("��ϲ����˳�������%d��,����������ˣ\n", snackLength);

	for (i = 0; i < CONSOLE_MAX_WIDTH; i++)
		printf("#");
	Sleep(500);
}


int main()
{	
	HANDLE hThread;
	hThread = (HANDLE)_beginthread(MainLoop, 0, NULL);//����һ�����߳�
	int selectNum = 1;
	InitRandomSystem();//��ʼ�������ϵͳ
AA:
	InitGame(selectNum);//�������ѡ�Ĺؿ�����ʼ����Ϸ
	
	while (status == GAME_LOOP)//״̬һֱ��GAME_LOOPʱ��һֱִ��
	{
		switch (SnakeStutas)
		{
		case SnakeShorten:
			Sleep(DELAY_TIME_SHORTEN);//��ʾ���ͼ��ͣ��DELAY_TIMEʱ��
			SnackMove();//�������ƶ���Ϊ����Ϸ�Ľ�׳�ԣ�
			break;
		case SnakeNormal:
			Sleep(DELAY_TIME);//��ʾ���ͼ��ͣ��DELAY_TIMEʱ��	
			SnackMove();//�������ƶ���Ϊ����Ϸ�Ľ�׳�ԣ�
			break;
		case SnakeAccelerate:
			Sleep(DELAY_TIME_ACCELERATE);//��ʾ���ͼ��ͣ��DELAY_TIMEʱ��
			SnackMove();//�������ƶ���Ϊ����Ϸ�Ľ�׳�ԣ�
			break;
		default:
			SnackMove();//�������ƶ���Ϊ����Ϸ�Ľ�׳�ԣ�
			break;
		}

		PreviewMap();//Ԥ�����ͼ
		DisplayMap();//��ʾ��ͼ

	}
	
	if (status == GAME_FAILURE)//��Ϸʧ��
	{
		Failure();//�˳�
		SnackDestroy();

	}
	else if (status == GAME_VICTORY)
	{
		VictoryFn();
		status = GAME_LOOP;
		selectNum = selectNum % 3+1;
 		goto AA;
	}
	
}
