#include "manager.h"

Manager::Manager(int id, string name, int deptid)
{
	this->m_id = id;
	this->m_Name = name;
	this->m_DeptId = deptid;
}

void Manager::showInfo()
{
	cout << "ְ����ţ�" << this->m_id
		<< "\tְ��������" << this->m_Name
		<< "\tְ����λ��" << this->getDeptName()
		<< "\tְ����λְ������ܲý��������񣬲��·������Ա����" << endl;
}

string Manager::getDeptName()
{
	return string("����");
}
