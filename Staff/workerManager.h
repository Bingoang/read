#pragma once //��ֹͷ�ļ��ظ�����
#include <iostream>
#include <fstream>
#include"worker.h"

#define FILENAME "staffFile.txt"
using namespace std;


class WorkerManager
{
public:
	//���캯��
	WorkerManager();


	//չʾ�˵�
	void show_Menu();
	//�˳�����
	void exitSystem();
	//���ְ��
	void addStaff();
	//д�ļ�
	void save();
	//ͳ������
	int get_StaffNum();
	//��ʼ��Ա��ָ��
	void init_Staff();
	//��ʾְ��
	void show_Staff();
	//ɾ��ְ��
	void del_Staff();
	//�ж�ְ���Ƿ����
	int isExist(int id);
	//�޸�ְ����Ϣ
	void mod_Staff();
	//����ְ��
	void find_Staff();
	//ְ������
	void sort_Staff();
	//����ļ�
	void cleam_File();



	//��������
	~WorkerManager();

	//��¼�ļ���ְ������
	int m_StaffNum;
	//ְ������ָ�루��Ϊ�����ŵ�Ҳ��ָ�룬����**m_StaffArray��ָ��ָ���ָ�룬������**�ͣ�
	Worker** m_StaffArray;

	//�ļ��Ƿ�Ϊ��
	bool m_fileIsEmpty;
};
