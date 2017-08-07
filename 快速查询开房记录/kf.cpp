#include "kf.h"

KaiFang::KaiFang(string path)
{
	filepath = path;
	dwFileSize = 0;
	hFileMap = nullptr;
	pvFile = nullptr;
	fileline = 0;
	pfilestart = nullptr;
	pfileend = nullptr;
	pos = nullptr;
}

KaiFang::~KaiFang()
{
	delete []pos;
}

bool KaiFang::myFileMap()
{
	LPCTSTR pszPathName = filepath.c_str();//ֻ����C�������͵��ַ���

	HANDLE hFile = CreateFile(pszPathName, GENERIC_WRITE | GENERIC_READ, 0, NULL
		, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hFile == INVALID_HANDLE_VALUE)
	{
		cout << "�ļ�������" << endl;
		return FALSE;
	}

	dwFileSize = GetFileSize(hFile, NULL);//����ļ��Ĵ�С
	cout << "�ļ���С��" << dwFileSize << "�ֽ�"<<endl;

	HANDLE hFileMap = CreateFileMapping(hFile, NULL, PAGE_READWRITE, 0,
		dwFileSize + sizeof(char), NULL);//�����ļ�ӳ��

	if (hFileMap == NULL){
		CloseHandle(hFile);//�����ļ�ӳ��ʧ�ܣ��ر��ļ�
		return FALSE;
	}

	SYSTEM_INFO sinf;
	GetSystemInfo(&sinf);
	DWORD dwAllocationGranularity = sinf.dwAllocationGranularity;
	//cout << "������С��λΪ" << dwAllocationGranularity << endl;
	//��ȡ��С��ӳ�䵥λ��65536

	PVOID pvFile = MapViewOfFile(hFileMap, FILE_MAP_WRITE, 0, 0, 0);

	if (pvFile == NULL){
		CloseHandle(hFileMap);
		CloseHandle(hFile);
		cout << "�ڴ�ӳ��ʧ�ܣ�������" << endl;
		return FALSE;
	}

	cout << "�ڴ�ӳ��ɹ�" << endl;

	PSTR pchAnsi = (PSTR)pvFile;

	pfilestart = (char *)pchAnsi;//ת��ָ��,�����ļ�ͷ

	pfileend = pfilestart + dwFileSize;//�����ļ�β

	pos = new int[n];//�����ļ�ƫ��ָ������
	for (int i = 0; i < n; i++)
		pos[i] = 0;

	int line = 0;//����
	int ipos = 0;//�ļ�ƫ��ָ���Ԫ��λ��
	int index = 0;

	char *p = pfilestart;
	while (index < dwFileSize)//ȫ��ɨ�裬��¼�߳�������ʼ��ַ
	{
		if (p[index++] == '\n')
		{
			line++;//�ҵ����з�����������1
			if ((line % 65535) == 0)//�жϵ�ǰ�����Ƿ��ܱ�65535������
			{
				pos[++ipos] = index;//����ܣ����¼��ǰ���ļ�ƫ��ָ��
			}
		}
	}

	fileline = line;//��¼�ļ�������
	//cout << "�ļ�������Ϊ��" << line << endl;
	//cout << "ɨ�����" << endl;
	cout << "===========�������==========" << endl;
	return true;
}


bool  KaiFang::SearchInFile(string &strfind)
{

	FindNode fd[n];
	thread *pth[n] = { 0 };

	int i = 0;
	char *pst = pfilestart;

	cout << "============������============" << endl;
	for (i = 0; i < n - 1; i++)
	{
		fd[i].key = strfind;
		fd[i].len = 65535;
		fd[i].pstart = pst + pos[i];
		fd[i].end = 0;
		fd[i].count = 0;
		pth[i] = new thread(&KaiFang::FindInFile,this, &fd[i]);
		pth[i]->join();
	}

	//������������
	fd[i].key = strfind;
	fd[i].len = fileline - 65535 * (n - 1);
	fd[i].pstart = pst + pos[i];
	fd[i].end = 0;
	fd[i].count = 0;
	pth[i] = new thread(&KaiFang::FindInFile, this, &fd[i]);
	pth[i]->join();

	int finish = 0;
	int total = 0;

	while (1){
		Sleep(10);//��ʱ��������־

		for (int i = 0; i < n; i++)
		{
			finish += fd[i].end;
			total += fd[i].count;
		}
		if (finish == n)
		{
			cout << "�������" << endl;
			cout << "���ҵ�" << total << "����¼" << endl;
			break;
		}
	}

	//cout << "game over" << endl;

	return true;
}

void KaiFang::FindInFile(fnode *fd)
{
	char *pstart = fd->pstart;
	char *p = fd->pstart;
	int length = fd->len;
	int line = 0;
	string str;
	while (line < length) //��ȡָ���ĳ���
	{
		str += *p;
		if (*p++ == '\n')
			line++;
	}

	int pos = 0;
	int count = 0;

	while ((pos = str.find(fd->key, pos)) != -1)
	{
		int pe = pos;
		while (pos != 0 && str[pos--] != '\n');
		while (str[pe++] != '\n');
		while (pos < pe - 2)
		{
			cout << str[pos];
			pos++;
		}
		count++;
		cout << endl;
		pos = pe;
	}

	fd->end = 1;//�����߳̽�����־
	fd->count = count;//ͳ�ƽ��
}