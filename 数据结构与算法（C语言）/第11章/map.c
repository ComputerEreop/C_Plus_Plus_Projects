#define _CRT_SECURE_NO_WARNINGS
#include "global.h"
#include "snack.h"
#include "food.h"
#include "map.h"
#include <stdio.h>
#include <stdlib.h>

static FILE *fp = NULL;
volatile enum EGameStatus status = GAME_LOOP;

void LoadMap(int scene)
{
	int i, j;
	char str[MAX_LENGTH] = "";

	sprintf(str, "Map\\%d.map", scene);
	fp = fopen(str, "r");
	fscanf(fp, "%d%d", &width, &height);

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			fscanf(fp, "%d", &map[j][i]);
			mapTemp[j][i] = map[j][i];
		}
	}
	fclose(fp);
	fp = NULL;
}


void PreviewMap()
{
	int i, j;
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			map[i][j] = mapTemp[i][j];
		}
	}

	Snack *pSnack = pHeader;
	map[pSnack->x][pSnack->y] = MAP_HEAD;
	pSnack = pSnack->pNext;
	while (pSnack)
	{
		map[pSnack->x][pSnack->y] = MAP_BODY;
		pSnack = pSnack->pNext;
	}
	map[food.x][food.y] = food.foodKind;
}

void DisplayMap()
{
	int i, j;

	system("cls");
	printf("                 ���ǰ���\n\n");
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			if (i==0||j==0)
			{
				printf("��");
				continue;
			}
			switch (map[j][i])
			{
			case MAP_ROAD:
				printf("��");
				break;
			case MAP_BODY:
				printf("��");
				break;
			case MAP_HEAD:
				printf("��");
				break;
			case MAP_FOOD_NORMAL:
				printf("��");
				break;

			case MAP_FOOD_ACCELERATE:
				printf("��");
				break;
			case MAP_FOOD_SHORTEN:
				printf("��");
				break;
			case MAP_OBSTACLE:
				printf("�p");
				break;
			}
		}
		printf("��");

		switch (i)
		{
		case 3:
			printf("\t���ĵ÷��ǣ�%d", snackLength);
			break;


		case 7:
			printf("\t���ع����߳���Ҫ10");
			break;
		case 8:
			printf("\tĿǰ�߳����ǣ�%d", snackLength);
			break;
		case 9:
			printf("\t����ػ���ĳ��ȣ�%d", 10 - snackLength);
			break;

		case 13:
			switch (food.foodKind)
			{
			case MAP_FOOD_NORMAL:
				printf("\t���ֵ�ʳ��Ϊ������ʳ�");
				break;
			case MAP_FOOD_ACCELERATE:
				printf("\t���ֵ�ʳ��Ϊ���ж�ʳ�");
				break;
			case MAP_FOOD_SHORTEN:
				printf("\t���ֵ�ʳ��Ϊ���»�ʳ�");
				break;
			default:
				break;
			}
			break;

		case 14:
			switch (food.foodKind)
			{
			case MAP_FOOD_NORMAL:
				printf("  Ч�����Ժ�����1���������ֳɳ���");
				break;
			case MAP_FOOD_ACCELERATE:
				printf("  Ч�����Ժ�����1���������ٱ�죡");
				break;
			case MAP_FOOD_SHORTEN:
				printf("  Ч�����Ժ����1���������ٱ�����");
				break;
			default:
				break;
			}
			break;

		default:
			break;
		}
		
		printf("\n");
	}
	for (j = 0; j <= width; j++)
		printf("��");
	printf("\n");
}
