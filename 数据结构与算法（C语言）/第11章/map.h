#pragma once

enum EMap
{
	MAP_ROAD = 1,
	MAP_BODY,
	MAP_HEAD,
	MAP_FOOD_NORMAL,
	MAP_OBSTACLE,
	MAP_FOOD_ACCELERATE,
	MAP_FOOD_SHORTEN
};

enum EGameStatus //��Ϸ״̬
{
	GAME_LOOP,
	GAME_VICTORY,
	GAME_FAILURE
};

int width, height;					 // ��ͼ�ĳ��Ϳ�
volatile enum EGameStatus status;	 // ��Ϸ״̬
int map[MAX_LENGTH][MAX_LENGTH];	 // ��ͼ�������Ϊ 32 * 32
int mapTemp[MAX_LENGTH][MAX_LENGTH]; // ��ͼ�������Ϊ 32 * 32
int selectNum;						 // ��ѡ�ؿ�

// ��ͼԤ����
void PreviewMap();
// �����ͼ
void LoadMap(int scene);
// ��ͼ��ʾ�����̣߳�
void DisplayMap();
