#include "kf.h"

int main()
{
	string filepath = "kaifang_noBomb.txt";

	KaiFang kf(filepath);
		
	if (kf.myFileMap())
	{
		string findstr;
		string choice;
		while (1)
		{
			choice.clear();
			cout << "��ӭʹ�ÿ�����ѯ���ߣ���ѡ��Ҫ��ѯ�ķ�ʽ(exit�˳�)��1��ȷ���ң�0ģ�����ң�" << endl;
			cin >> choice;
			if (!choice.compare("exit"))
			{
				cout << "ллʹ��" << endl;
				choice.clear();
				break;
			}
			else
			{
				if (choice == "1")
				{
					choice.clear();
					while (findstr.empty())
					{

						cout << "��������Ҫ���ҵ�����(exit�˳�)��" << endl;
						cin >> findstr;
					}
					if (!findstr.compare("exit"))
					{
						cout << "ллʹ��" << endl;
						return 0;
					}
					findstr.push_back(',');
					//cout << "������������ǣ�" << findstr << endl;

					int starttime = GetTickCount();
					kf.SearchInFile(findstr);
					int endtime = GetTickCount();

					cout << "�ܺ�ʱ" << endtime - starttime << "ms" << endl;
					cout << endl;
					findstr.clear();
				}
				else if (choice == "0")
				{
					choice.clear();
					while (findstr.empty())
					{

						cout << "��������Ҫ���ҵ�����(exit�˳�)��" << endl;
						cin >> findstr;
					}
					if (!choice.compare("exit"))
					{
						cout << "ллʹ��" << endl;
						return 0;
					}
					//cout << "������������ǣ�" << findstr << endl;

					int starttime = GetTickCount();
					kf.SearchInFile(findstr);
					int endtime = GetTickCount();

					cout << "�ܺ�ʱ" << endtime - starttime << "ms" << endl;
					cout << endl;
					findstr.clear();
				}
				else
				{
					cout << endl;
					cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>������������������<<<<<<<<<<<<<<<<<<<<<<<" << endl;
					cout << endl;
					choice.clear();
					findstr.clear();
				}			
			}		

		}
				
	}

	system("pause");
	return 0;
}