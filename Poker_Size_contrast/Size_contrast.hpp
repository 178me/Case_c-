#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <functional>
using namespace std;
class Size_contrast 
{
private:
	string _name;				//��Ҷ���
	vector<int> Card_pile;		//ϵͳ�ƶ�
	vector<int> Card_hand;		//��ǰ����

public:
/*������*/
	//��ʼ���˿�
	void Init_poker();
	//��ʾ������Ϣ
	void Show_info();
	//��ʾ�˿�������
	void Show_card(const vector<int>&);
	//�������
	void Touch_Card(int Card_count);
	//���ƵĻ�ɫ
//	string Colors_card(int card);
	//���Ƶ�ֵ
	string Value_card(int card);
	//���Ƶ�����
	void Sort_card(vector<int>&);
	//���ƵĶԱ�
	int Contrast_card(int&, int&);
	//��ҳ���
	int Deal_card();
	//��Ϸʵ��
	void Game();
/*����������*/
	//���캯������ʼ������i
	Size_contrast();
	Size_contrast(string name) { Setname(name);};
	//�����������ͷŶ���
	~Size_contrast();
	//-----------------------------------------------
	/**
	 *getֱ��return����Ҫ���Ǹ�����
	 *set��������Ȼ�������Ҫ��ֵ�ĳ�Ա����
	 **/
	void Setname(string name) { this->_name = name; };
	string Getname() { return this->_name; }
	//+++++++++++++++++++++++++++++++++++++++++++++++
};

