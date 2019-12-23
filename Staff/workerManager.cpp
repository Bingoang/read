#include"workerManager.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

WorkerManager::WorkerManager()
{
	/******��ʼ������******/

	//��ʼ��ְ������
	this->m_StaffNum = 0;
	//��ʼ������ָ��
	this->m_StaffArray = NULL;

	/******����ļ��Ƿ����******/
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	//���1���ļ�������
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		//��ʼ������������ָ�롢�ļ��ձ�־
		this->m_StaffNum = 0;
		this->m_StaffArray = NULL;
		this->m_fileIsEmpty = true;
		ifs.close();
		return;
	}

	//���2������ļ����ڵ�����Ϊ��
	
	//��1��(���ֻ���пո�Ҳ��Ϊ�ļ�Ϊ��)
	//char ch;
	//ifs >> ch;//��ȡ����ַ������ַ�Ϊ�գ����ļ�Ϊ��
	//if (ifs.eof())
	//{
	//	cout << "�ļ����ڣ�Ϊ��" << endl;
	//	this->m_StaffNum = 0;
	//	this->m_StaffArray = NULL;
	//	this->m_fileIsEmpty = true;
	//	ifs.close();
	//	return;
	//}

	//��2��(���ֻ���пո���Ϊ�ļ��ǿ�)
	ifs.seekg(0, ios::end); //���ļ�ָ��ָ���ļ�ĩ�� 
	streampos fp = ifs.tellg(); //fpΪ�ļ�ָ���ƫ���� 
	if (int(fp) == 0) // ƫ����Ϊ0��֤���ļ�Ϊ�գ�Ϊ�״ν���ϵͳ
	{
		cout << "�ļ����ڣ�Ϊ��" << endl;
		this->m_StaffNum = 0;
		this->m_StaffArray = NULL;
		this->m_fileIsEmpty = true;
		ifs.close();
		return;
	}

	/******�ļ����ڣ���ȡ�ļ���������Ϣ����******/
	int num = this->get_StaffNum();
	cout << "����ְ������Ϊ��" << num << endl;
	//���³�Ա����
	this->m_StaffNum = num;

	/******�ļ����ڣ���ȡ�ļ������е�ÿ����Ϣ******/

	//��������ְ������������
	this->m_StaffArray = new Worker *[this->m_StaffNum];

	//��ʼ��ְ��
	init_Staff();

	////���Դ���
	//for (int i = 0;i < this->m_StaffNum;i++)
	//{
	//	cout << "ְ����ţ�" << this->m_StaffArray[i]->m_id << " "
	//		<< "ְ��������" << this->m_StaffArray[i]->m_Name << " "
	//		<< "ְ�����ţ�" << this->m_StaffArray[i]->m_DeptId << endl;
	//}




}

void WorkerManager::show_Menu()
{
	cout << "******************************************" << endl;
	cout << "********* ��ӭʹ��ְ������ϵͳ�� *********" << endl;
	cout << "************* 0.�˳�������� *************" << endl;
	cout << "************* 1.����ְ����Ϣ *************" << endl;
	cout << "************* 2.��ʾְ����Ϣ *************" << endl;
	cout << "************* 3.ɾ����ְְ�� *************" << endl;
	cout << "************* 4.�޸�ְ����Ϣ *************" << endl;
	cout << "************* 5.����ְ����Ϣ *************" << endl;
	cout << "************* 6.���ձ������ *************" << endl;
	cout << "************* 7.��������ĵ� *************" << endl;
	cout << "******************************************" << endl;
	cout << endl;
}

void WorkerManager::exitSystem()
{
	cout << "��ӭ�´�ʹ�ã�" << endl;
	//system("pause");
	exit(0);
}

void WorkerManager::addStaff()
{
	int addNum=0;
	cout << "����������ӵ�ְ��������" << endl;
	cin >> addNum;

	if (addNum > 0)
	{
		//�����¿ռ�Ĵ�С
		int newSize = this->m_StaffNum + addNum;
		//�����µĿռ�
		Worker** newSpace = new Worker* [newSize];

		//��ԭ�ռ�����ݴ浽�¿ռ���
		if (this->m_StaffArray != NULL)//  ����д��(this->m_StaffNum != 0)
		{
			for (int i = 0; i < this->m_StaffNum; i++)
			{
				newSpace[i] = this->m_StaffArray[i];
			}
		}

		//�����µ�ְ����Ϣ
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int deptid;

			//��ʾ��Ϣ
			cout << "******��" << i+1 << "����ְ����Ϣ¼��******" << endl;

			cout << "������ְ����ţ�" << endl;
			cin >> id;

			cout << "������ְ��������"<< endl;
			cin >> name;

			cout << "������ְ����λ��" << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����"<< endl;
			cout << "3.�ܲ�"<< endl;
			cin >> deptid;

			//��ָ��*workerָ������ְ�����ݵĶ���
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

			//�� ָ������ӵ�ְ����Ϣ��ָ�� ���žɵ����� �浽�¿ռ���
			newSpace[this->m_StaffNum + i] = worker;
			
			//��ʾ��Ϣ
			cout << "�ɹ���ӵ�" << i+1 << "����ְ����" << endl;

		}
		//�ͷ�ԭ�������ݵĿռ�
		if(this->m_StaffArray!= NULL)
			delete[] this->m_StaffArray;

		//���£�ָ���µĿռ�
		this->m_StaffArray = newSpace;

		//�������鳤�ȣ�ְ����������
		this->m_StaffNum = newSize;

		//��ʾ��Ϣ
		cout << "******�ɹ����" <<addNum << "����ְ����******" << endl;
		
		//���浽�ļ���
		this->save();

		this->m_fileIsEmpty = false;

		//if (newSpace != NULL)
		//	delete[] newSpace;
	}

	else
	{
		cout << "��������" << endl;
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

//��ʾְ��
void WorkerManager::show_Staff()
{
	if (m_fileIsEmpty)
	{
		cout << "�ļ������ڻ�Ϊ�գ�" << endl;
	}
	else 
	{
		for (int i = 0;i < m_StaffNum;++i)
		{
			//���ö�̬���ýӿ�
			this->m_StaffArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");

}

//ɾ��ְ��
void WorkerManager::del_Staff()
{
	if(this->m_fileIsEmpty)
	{
		cout << "�ļ������ڻ�Ϊ��!" << endl;
	}
	else
	{
		//��ְ�����ɾ��
		cout << "��������Ҫɾ����ְ����ţ�" << endl;
		int id;
		cin >> id;

		int index = this->isExist(id);
		//indexλ����ְ��ɾ�����˺�����λ���ϵ���һǰ�ƣ����λ
		if (index != -1)
		{
			for (int i = index;i < this->m_StaffNum-1;++i)
			{
				this->m_StaffArray[i] = this->m_StaffArray[i + 1];
			}
			this->m_StaffNum--;

			//ɾ��������ͬ���������ļ���
			this->save();

			cout << "ɾ��ְ���ɹ���" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ����" << endl;
		}
		system("pause");
		system("cls");
	}
}

//�ж�ְ���Ƿ����
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

//�޸�ְ����Ϣ
void WorkerManager::mod_Staff()
{
	if (this->m_fileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "��������Ҫ�޸ĵ�ְ�����" << endl;
		int id;
		cin >> id;

		int ret = this->isExist(id);
		//���ҵ���ŵ�ְ��
		if (ret != -1)
		{
			delete this->m_StaffArray[ret];
			
			int new_id = 0;
			string new_name = "";
			int new_deptid = 0;

			cout << "���ҵ������Ϊ" << id << "��ְ��" << endl;
			cout << "�������µ�ְ����ţ�";
			cin >> new_id;

			cout << "�������µ�ְ��������";
			cin >> new_name;

			cout << "�������µ�ְ�����ű�ţ�" << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ܲ�" << endl;
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
			
			//�������ݵ�ָ��浽������
			this->m_StaffArray[ret] = worker;

			cout << "�޸ĳɹ���" << endl;

			//���浽�ļ���
			this->save();
			
		}
		else
		{
			cout << "�޸�ʧ�ܣ����޴��ˣ�" << endl;
		}
	}
	system("pause");
	system("cls");
}

//����ְ��
void WorkerManager::find_Staff()
{
	if (this->m_fileIsEmpty)
	{
		cout << "�ļ������ڻ�Ϊ�գ�" << endl;
	}
	else
	{
		cout << "��������ҷ�ʽ��" << endl;
		cout << "1.��ְ����Ų���" << endl;
		cout << "2.��ְ����������" << endl;

		int select = 0;
		cin >> select;

		//ѡ��1������ְ����Ų���
		if (select == 1)
		{
			cout << "����������ҵ�ְ����ţ�";
			int id;
			cin >> id;

			int ret = this->isExist(id);
			if (ret != -1)
			{
				this->m_StaffArray[ret]->showInfo();
			}
			else
			{
				cout << "����ʧ�ܣ����޴��ˣ�" << endl;
			}
		}
		//ѡ��2����ְ����������
		else if(select==2)
		{
			cout << "�����������ְ����������";
			string name;
			cin >> name;

			bool flag = false;
			for (int i = 0; i < this->m_StaffNum; i++)
			{
				if (this->m_StaffArray[i]->m_Name == name)
				{
					cout << "���ҳɹ���ְ�����Ϊ" << this->m_StaffArray[i]->m_id
						<< "��Ϣ���£�" << endl;
					this->m_StaffArray[i]->showInfo();

					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "����ʧ�ܣ����޴��ˣ�" << endl;
			}
		}
		else
		{
			cout << "����ѡ������" << endl;
		}
	}
	system("pause");
	system("cls");
}

//ְ������
void WorkerManager::sort_Staff()
{
	if (this->m_fileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ��" << endl;
		cout << "1.��ְ���������" << endl;
		cout << "2.��ְ����Ž���" << endl;

		int select = 0;
		cin >> select;
		
		for (int i = 0; i < this->m_StaffNum; i++)
		{
			int minORmax = i;
			for(int j=i+1; j<this->m_StaffNum; j++)
			{ 

			//����
			if (select == 1)
			{
				if (this->m_StaffArray[j]->m_id < this->m_StaffArray[minORmax]->m_id)
				{
					minORmax = j;
				}
			}
			//����
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
		cout << "����ɹ����������Ϊ��" << endl;
		this->show_Staff();
		this->save();


	}
}

//����ļ�
void WorkerManager::cleam_File()
{
	cout << "ȷ����գ�" << endl;
	cout << "1.���" << endl;
	cout << "2.����" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//��ģʽios::trunc��������ļ���ɾ���ؽ�
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
		cout << "��ճɹ���" << endl;
	}
	system("pause");
	system("cls");
}

//��������
WorkerManager::~WorkerManager()
{
	//�ͷŶ�ȡ����
	if (this->m_StaffArray != NULL)
		delete[] this->m_StaffArray;
}