#include "workerManager.h"
//#include<iostream>

#include"worker.h"
#include"employee.h"
#include"manager.h"
#include "boss.h"

using namespace std;

int main()
{
	////��̬���Դ���
	//Worker *w = NULL;
	//w = new Employee(1, "����", 1);
	//w->showInfo();
	//delete w;

	//w = new Manager(2, "����", 2);
	//w->showInfo();
	//delete w;

	//w = new Boss(3, "����", 3);
	//w->showInfo();
	//delete w;
	
	WorkerManager wm;
	int choice = 0;

	while (true)
	{
		wm.show_Menu();
		cout << "����������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
			//0.�˳��������
		case 0:
			wm.exitSystem();
			break;
			//1.����ְ����Ϣ
		case 1:
			wm.addStaff();
			break;
			//2.��ʾְ����Ϣ
		case 2:
			wm.show_Staff();
			break;
			//3.ɾ����ְְ��
		case 3:
		//{
		//	//���Դ���
		//	cout << "������ְ����ţ�" << endl;
		//	int id;
		//	cin >> id;
		//	int ret=wm.isExist(id);
		//	if (ret == -1)
		//	{
		//		cout << "��ְ�������ڣ�" << endl;
		//	}
		//	else
		//	{
		//		cout << "ְ�����ڣ�" << endl;
		//	}
		//	break;
		//}
			wm.del_Staff();
			break;

			//4.�޸�ְ����Ϣ
		case 4:
			wm.mod_Staff();
			break;
			//5.����ְ����Ϣ
		case 5:
			wm.find_Staff();
			break;
			//6.���ձ������
		case 6:
			wm.sort_Staff();
			break;
			//7.��������ĵ�
		case 7:
			wm.cleam_File();
			break;
		default:
			system("cls");
			break;
		}
	}
	

	system("pause");
	return 0;
}