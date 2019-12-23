#pragma once
#include"worker.h"
//using namespace std;

class Employee:public Worker
{
public:
	//重载构造函数
	Employee(int id, string name, int deptid);
	//声明：重写父类Worker中的2个纯虚函数
	virtual void showInfo();
	virtual string getDeptName();

};
