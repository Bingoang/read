#include"employee.h"

Employee::Employee(int id,string name,int deptid)
{
	this->m_id = id;
	this->m_Name = name;
	this->m_DeptId = deptid;
}

void Employee::showInfo()
{
	cout << "职工编号：" << this->m_id
		<< "\t职工姓名：" << this->m_Name
		<< "\t职工岗位：" << this->getDeptName()
		<< "\t职工岗位职责：完成经理交给的任务。" << endl;

}

string  Employee::getDeptName()
{
	return string("员工");//直接写“员工”也行，编译器会把“员工”这个const char *强转成string
}

