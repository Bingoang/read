#pragma once
#include<iostream>
#include<string>

using namespace std;

class Worker
{
public:
	//纯虚函数：显示个人信息
	virtual void showInfo()=0;
	//纯虚函数：显示部门名称
	virtual string getDeptName()=0;

	int m_id;//职工编号
	string m_Name;//职工姓名
	int m_DeptId;//职工所在部门编号
};
