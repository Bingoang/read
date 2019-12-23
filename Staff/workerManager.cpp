#include"workerManager.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

WorkerManager::WorkerManager()
{
	/******初始化属性******/

	//初始化职工人数
	this->m_StaffNum = 0;
	//初始化数组指针
	this->m_StaffArray = NULL;

	/******检查文件是否存在******/
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	//情况1：文件不存在
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		//初始化人数、数组指针、文件空标志
		this->m_StaffNum = 0;
		this->m_StaffArray = NULL;
		this->m_fileIsEmpty = true;
		ifs.close();
		return;
	}

	//情况2：如果文件存在但数据为空
	
	//法1：(如果只含有空格，也认为文件为空)
	//char ch;
	//ifs >> ch;//读取这个字符，若字符为空，则文件为空
	//if (ifs.eof())
	//{
	//	cout << "文件存在，为空" << endl;
	//	this->m_StaffNum = 0;
	//	this->m_StaffArray = NULL;
	//	this->m_fileIsEmpty = true;
	//	ifs.close();
	//	return;
	//}

	//法2：(如果只含有空格，认为文件非空)
	ifs.seekg(0, ios::end); //将文件指针指向文件末端 
	streampos fp = ifs.tellg(); //fp为文件指针的偏移量 
	if (int(fp) == 0) // 偏移量为0，证明文件为空，为首次进入系统
	{
		cout << "文件存在，为空" << endl;
		this->m_StaffNum = 0;
		this->m_StaffArray = NULL;
		this->m_fileIsEmpty = true;
		ifs.close();
		return;
	}

	/******文件存在，读取文件中已有信息条数******/
	int num = this->get_StaffNum();
	cout << "已有职工人数为：" << num << endl;
	//更新成员属性
	this->m_StaffNum = num;

	/******文件存在，读取文件中已有的每条信息******/

	//根据已有职工数创建数组
	this->m_StaffArray = new Worker *[this->m_StaffNum];

	//初始化职工
	init_Staff();

	////测试代码
	//for (int i = 0;i < this->m_StaffNum;i++)
	//{
	//	cout << "职工编号：" << this->m_StaffArray[i]->m_id << " "
	//		<< "职工姓名：" << this->m_StaffArray[i]->m_Name << " "
	//		<< "职工部门：" << this->m_StaffArray[i]->m_DeptId << endl;
	//}




}

void WorkerManager::show_Menu()
{
	cout << "******************************************" << endl;
	cout << "********* 欢迎使用职工管理系统！ *********" << endl;
	cout << "************* 0.退出管理程序 *************" << endl;
	cout << "************* 1.增加职工信息 *************" << endl;
	cout << "************* 2.显示职工信息 *************" << endl;
	cout << "************* 3.删除离职职工 *************" << endl;
	cout << "************* 4.修改职工信息 *************" << endl;
	cout << "************* 5.查找职工信息 *************" << endl;
	cout << "************* 6.按照编号排序 *************" << endl;
	cout << "************* 7.清空所有文档 *************" << endl;
	cout << "******************************************" << endl;
	cout << endl;
}

void WorkerManager::exitSystem()
{
	cout << "欢迎下次使用！" << endl;
	//system("pause");
	exit(0);
}

void WorkerManager::addStaff()
{
	int addNum=0;
	cout << "请输入需添加的职工数量：" << endl;
	cin >> addNum;

	if (addNum > 0)
	{
		//计算新空间的大小
		int newSize = this->m_StaffNum + addNum;
		//开辟新的空间
		Worker** newSpace = new Worker* [newSize];

		//将原空间的数据存到新空间里
		if (this->m_StaffArray != NULL)//  或者写成(this->m_StaffNum != 0)
		{
			for (int i = 0; i < this->m_StaffNum; i++)
			{
				newSpace[i] = this->m_StaffArray[i];
			}
		}

		//输入新的职工信息
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int deptid;

			//提示信息
			cout << "******第" << i+1 << "名新职工信息录入******" << endl;

			cout << "请输入职工编号：" << endl;
			cin >> id;

			cout << "请输入职工姓名："<< endl;
			cin >> name;

			cout << "请输入职工岗位：" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理"<< endl;
			cout << "3.总裁"<< endl;
			cin >> deptid;

			//用指针*worker指向存放新职工数据的堆区
			Worker * worker = NULL;
			switch (deptid)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			defualt:
				break;

			}

			//将 指向新添加的职工信息的指针 接着旧的数据 存到新空间中
			newSpace[this->m_StaffNum + i] = worker;
			
			//提示信息
			cout << "成功添加第" << i+1 << "名新职工！" << endl;

		}
		//释放原来旧数据的空间
		if(this->m_StaffArray!= NULL)
			delete[] this->m_StaffArray;

		//更新：指向新的空间
		this->m_StaffArray = newSpace;

		//更新数组长度（职工总人数）
		this->m_StaffNum = newSize;

		//提示信息
		cout << "******成功添加" <<addNum << "名新职工！******" << endl;
		
		//保存到文件中
		this->save();

		this->m_fileIsEmpty = false;

		//if (newSpace != NULL)
		//	delete[] newSpace;
	}

	else
	{
		cout << "输入有误！" << endl;
	}
	system("pause");
	system("cls");

}

int WorkerManager::get_StaffNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int deptid;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> deptid)
	{
		num++;
	}

	ifs.close();

	return num;
}

void WorkerManager::init_Staff()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	
	int id;
	string name;
	int deptid;
	 
	int index=0;

	while (ifs >> id && ifs >> name && ifs >> deptid)
	{
		Worker *worker = NULL;

		if (deptid == 1)
		{
			worker = new Employee(id, name, deptid);
		}
		else if (deptid == 2)
		{
			worker = new Manager(id, name, deptid);
		}
		else
		{
			worker = new Boss(id, name, deptid);
		}

		this->m_StaffArray[index++] = worker;
	}
}

void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0;i < this->m_StaffNum; i++)
	{
		ofs << this->m_StaffArray[i]->m_id<<" "
			<< this->m_StaffArray[i]->m_Name<<" "
			<< this->m_StaffArray[i]->m_DeptId << endl;
	}

	ofs.close();
}

//显示职工
void WorkerManager::show_Staff()
{
	if (m_fileIsEmpty)
	{
		cout << "文件不存在或为空！" << endl;
	}
	else 
	{
		for (int i = 0;i < m_StaffNum;++i)
		{
			//利用多态调用接口
			this->m_StaffArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");

}

//删除职工
void WorkerManager::del_Staff()
{
	if(this->m_fileIsEmpty)
	{
		cout << "文件不存在或为空!" << endl;
	}
	else
	{
		//按职工编号删除
		cout << "请输入需要删除的职工编号：" << endl;
		int id;
		cin >> id;

		int index = this->isExist(id);
		//index位置上职工删除，此后数组位置上的逐一前移，填补空位
		if (index != -1)
		{
			for (int i = index;i < this->m_StaffNum-1;++i)
			{
				this->m_StaffArray[i] = this->m_StaffArray[i + 1];
			}
			this->m_StaffNum--;

			//删除后数据同步保存在文件中
			this->save();

			cout << "删除职工成功！" << endl;
		}
		else
		{
			cout << "删除失败，未找到该职工！" << endl;
		}
		system("pause");
		system("cls");
	}
}

//判断职工是否存在
int WorkerManager::isExist(int id)
{
	int index = -1;
	for (int i = 0;i < this->m_StaffNum;++i)
	{
		if (this->m_StaffArray[i]->m_id == id)
		{
			index = i;
			break;
		}

	}
	return index;

}

//修改职工信息
void WorkerManager::mod_Staff()
{
	if (this->m_fileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请输入需要修改的职工编号" << endl;
		int id;
		cin >> id;

		int ret = this->isExist(id);
		//查找到编号的职工
		if (ret != -1)
		{
			delete this->m_StaffArray[ret];
			
			int new_id = 0;
			string new_name = "";
			int new_deptid = 0;

			cout << "查找到：编号为" << id << "的职工" << endl;
			cout << "请输入新的职工编号：";
			cin >> new_id;

			cout << "请输入新的职工姓名：";
			cin >> new_name;

			cout << "请输入新的职工部门编号：" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.总裁" << endl;
			cin >> new_deptid;

			Worker *worker = NULL;
			switch (new_deptid)
			{
			case 1:
				worker = new Employee(new_id, new_name, new_deptid);
				break;
			case 2:
				worker = new Manager(new_id, new_name, new_deptid);
				break;
			case 3:
				worker = new Boss(new_id, new_name, new_deptid);
				break;
			default:
				break;
			}
			
			//将新数据的指针存到数组中
			this->m_StaffArray[ret] = worker;

			cout << "修改成功！" << endl;

			//保存到文件中
			this->save();
			
		}
		else
		{
			cout << "修改失败，查无此人！" << endl;
		}
	}
	system("pause");
	system("cls");
}

//查找职工
void WorkerManager::find_Staff()
{
	if (this->m_fileIsEmpty)
	{
		cout << "文件不存在或为空！" << endl;
	}
	else
	{
		cout << "请输入查找方式：" << endl;
		cout << "1.按职工编号查找" << endl;
		cout << "2.按职工姓名查找" << endl;

		int select = 0;
		cin >> select;

		//选择1：按照职工编号查找
		if (select == 1)
		{
			cout << "请输入待查找的职工编号：";
			int id;
			cin >> id;

			int ret = this->isExist(id);
			if (ret != -1)
			{
				this->m_StaffArray[ret]->showInfo();
			}
			else
			{
				cout << "查找失败，查无此人！" << endl;
			}
		}
		//选择2：按职工姓名查找
		else if(select==2)
		{
			cout << "请输入待查找职工的姓名：";
			string name;
			cin >> name;

			bool flag = false;
			for (int i = 0; i < this->m_StaffNum; i++)
			{
				if (this->m_StaffArray[i]->m_Name == name)
				{
					cout << "查找成功，职工编号为" << this->m_StaffArray[i]->m_id
						<< "信息如下：" << endl;
					this->m_StaffArray[i]->showInfo();

					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "查找失败，查无此人！" << endl;
			}
		}
		else
		{
			cout << "输入选项有误！" << endl;
		}
	}
	system("pause");
	system("cls");
}

//职工排序
void WorkerManager::sort_Staff()
{
	if (this->m_fileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式：" << endl;
		cout << "1.按职工编号升序" << endl;
		cout << "2.按职工编号降序" << endl;

		int select = 0;
		cin >> select;
		
		for (int i = 0; i < this->m_StaffNum; i++)
		{
			int minORmax = i;
			for(int j=i+1; j<this->m_StaffNum; j++)
			{ 

			//升序
			if (select == 1)
			{
				if (this->m_StaffArray[j]->m_id < this->m_StaffArray[minORmax]->m_id)
				{
					minORmax = j;
				}
			}
			//降序
			else
			{
				if (this->m_StaffArray[j]->m_id > this->m_StaffArray[minORmax]->m_id)
				{
					minORmax = j;
				}
			}
			}

			if (i != minORmax)
			{
				Worker *temp = this->m_StaffArray[i];
				this->m_StaffArray[i] = this->m_StaffArray[minORmax];
				this->m_StaffArray[minORmax] = temp;
			}
		}
		cout << "排序成功，排序后结果为：" << endl;
		this->show_Staff();
		this->save();


	}
}

//清空文件
void WorkerManager::cleam_File()
{
	cout << "确认清空？" << endl;
	cout << "1.清空" << endl;
	cout << "2.返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//打开模式ios::trunc如果存在文件则删除重建
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if(this->m_StaffArray!=NULL)
		{ 
		for (int i = 0; i < this->m_StaffNum; i++)
		{
			if(this->m_StaffArray[i]!=NULL)
			{
				delete this->m_StaffArray[i];
				//this->m_StaffArray[i] = NULL;
			}
		}

		delete[] this->m_StaffArray;
		this->m_StaffArray = NULL;
		this->m_StaffNum = 0;
		this->m_fileIsEmpty = true;
		}
		cout << "清空成功！" << endl;
	}
	system("pause");
	system("cls");
}

//析构函数
WorkerManager::~WorkerManager()
{
	//释放堆取数据
	if (this->m_StaffArray != NULL)
		delete[] this->m_StaffArray;
}