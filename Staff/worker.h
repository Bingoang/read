#pragma once
#include<iostream>
#include<string>

using namespace std;

class Worker
{
public:
	//���麯������ʾ������Ϣ
	virtual void showInfo()=0;
	//���麯������ʾ��������
	virtual string getDeptName()=0;

	int m_id;//ְ�����
	string m_Name;//ְ������
	int m_DeptId;//ְ�����ڲ��ű��
};
