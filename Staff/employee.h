#pragma once
#include"worker.h"
//using namespace std;

class Employee:public Worker
{
public:
	//���ع��캯��
	Employee(int id, string name, int deptid);
	//��������д����Worker�е�2�����麯��
	virtual void showInfo();
	virtual string getDeptName();

};
