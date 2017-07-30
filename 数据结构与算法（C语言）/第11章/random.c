#include "global.h"
#include "random.h"
#include <stdlib.h>
#include <time.h>

static BOOL bIsInit = FALSE;	// �޶����ļ���ʹ��
//��ʼ�������ϵͳ����ʱ��Ϊ����
void InitRandomSystem()
{
	if (!bIsInit)
	{
		time_t t;
		bIsInit = TRUE;
		srand((unsigned)time(&t));
	}
}
//��ȡһ�������
int GetRandomNumber(int leftVal, int rightVal)
{
	return rand() % (rightVal - leftVal + 1) + leftVal;
}
