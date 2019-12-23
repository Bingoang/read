#include "manager.h"

Manager::Manager(int id, string name, int deptid)
{
	this->m_id = id;
	this->m_Name = name;
	this->m_DeptId = deptid;
}

void Manager::showInfo()
{
	cout << "职工编号：" << this->m_id
		<< "\t职工姓名：" << this->m_Name
		<< "\t职工岗位：" << this->getDeptName()
		<< "\t职工岗位职责：完成总裁交给的任务，并下发任务给员工。" << endl;
}

string Manager::getDeptName()
{
	return string("经理");
}
