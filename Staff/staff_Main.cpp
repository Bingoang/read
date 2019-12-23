#include "workerManager.h"
//#include<iostream>

#include"worker.h"
#include"employee.h"
#include"manager.h"
#include "boss.h"

using namespace std;

int main()
{
	////多态测试代码
	//Worker *w = NULL;
	//w = new Employee(1, "张三", 1);
	//w->showInfo();
	//delete w;

	//w = new Manager(2, "张三", 2);
	//w->showInfo();
	//delete w;

	//w = new Boss(3, "张三", 3);
	//w->showInfo();
	//delete w;
	
	WorkerManager wm;
	int choice = 0;

	while (true)
	{
		wm.show_Menu();
		cout << "请输入您的选择：" << endl;
		cin >> choice;
		switch (choice)
		{
			//0.退出管理程序
		case 0:
			wm.exitSystem();
			break;
			//1.增加职工信息
		case 1:
			wm.addStaff();
			break;
			//2.显示职工信息
		case 2:
			wm.show_Staff();
			break;
			//3.删除离职职工
		case 3:
		//{
		//	//测试代码
		//	cout << "请输入职工编号：" << endl;
		//	int id;
		//	cin >> id;
		//	int ret=wm.isExist(id);
		//	if (ret == -1)
		//	{
		//		cout << "该职工不存在！" << endl;
		//	}
		//	else
		//	{
		//		cout << "职工存在！" << endl;
		//	}
		//	break;
		//}
			wm.del_Staff();
			break;

			//4.修改职工信息
		case 4:
			wm.mod_Staff();
			break;
			//5.查找职工信息
		case 5:
			wm.find_Staff();
			break;
			//6.按照编号排序
		case 6:
			wm.sort_Staff();
			break;
			//7.清空所有文档
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