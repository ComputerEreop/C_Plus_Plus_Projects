#pragma once

// type declaration
typedef struct Food
{
	int x;
	int y;
	enum EMap foodKind;
}Food;

Food food;		// ʳ��

// ����ʳ��
Food FoodCreate();
// ʳ�ﱻ�Ե�
void FoodRelease();