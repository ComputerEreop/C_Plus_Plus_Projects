#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <string>
#include <thread>

using namespace std;

const int n = 306;

typedef struct FindNode
{
	string key;	//������Ŀ��
	char *pstart;//���
	int len;     //������Χ
	int end;	//�����Ƿ���ɽ��ָ��
	int count;  //ͳ�Ƽ�¼����

}fnode;

class KaiFang{
private:
	string filepath;//�ļ�·��
	DWORD dwFileSize;//�ļ���С
	HANDLE hFileMap;//ӳ����
	PVOID pvFile;//�ļ�ӳ����Ȩ

	int fileline;//�ļ�����
	char *pfilestart;//�ļ���ʼָ��
	char *pfileend;//�ļ�����ָ��
	int  *pos;//�ļ�ƫ�Ƶ�ַ
	
public:
	KaiFang(string path);
	~KaiFang();
	bool myFileMap();
	bool SearchInFile(string &strfind);
	void FindInFile(fnode *fd);
};