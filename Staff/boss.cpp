#include "boss.h"

Boss::Boss(int id, string name, int deptid)
{
	this->m_id = id;
	this->m_Name = name;
	this->m_DeptId = deptid;
}
void Boss::showInfo()
{
	cout << "ְ����ţ�" << this->m_id
		<< "\tְ��������" << this->m_Name
		<< "\tְ����λ��" << this->getDeptName()
		<< "\tְ����λְ�𣺹���˾��������" << endl;
}
string Boss::getDeptName()
{
	return string("�ܲ�");
}
