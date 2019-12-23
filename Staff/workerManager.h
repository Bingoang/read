#pragma once //防止头文件重复包含
#include <iostream>
#include <fstream>
#include"worker.h"

#define FILENAME "staffFile.txt"
using namespace std;


class WorkerManager
{
public:
	//构造函数
	WorkerManager();


	//展示菜单
	void show_Menu();
	//退出函数
	void exitSystem();
	//添加职工
	void addStaff();
	//写文件
	void save();
	//统计人数
	int get_StaffNum();
	//初始化员工指针
	void init_Staff();
	//显示职工
	void show_Staff();
	//删除职工
	void del_Staff();
	//判断职工是否存在
	int isExist(int id);
	//修改职工信息
	void mod_Staff();
	//查找职工
	void find_Staff();
	//职工排序
	void sort_Staff();
	//清空文件
	void cleam_File();



	//析构函数
	~WorkerManager();

	//记录文件中职工人数
	int m_StaffNum;
	//职工数组指针（因为数组存放的也是指针，所以**m_StaffArray是指向指针的指针，所以是**型）
	Worker** m_StaffArray;

	//文件是否为空
	bool m_fileIsEmpty;
};
