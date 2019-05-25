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
	string _name;				//玩家对象
	vector<int> Card_pile;		//系统牌堆
	vector<int> Card_hand;		//当前手牌

public:
/*方法区*/
	//初始化扑克
	void Init_poker();
	//显示个人信息
	void Show_info();
	//显示扑克牌数组
	void Show_card(const vector<int>&);
	//玩家摸牌
	void Touch_Card(int Card_count);
	//卡牌的花色
//	string Colors_card(int card);
	//卡牌的值
	string Value_card(int card);
	//卡牌的排序
	void Sort_card(vector<int>&);
	//卡牌的对比
	int Contrast_card(int&, int&);
	//玩家出牌
	int Deal_card();
	//游戏实现
	void Game();
/*基本函数区*/
	//构造函数：初始化对象i
	Size_contrast();
	Size_contrast(string name) { Setname(name);};
	//析构函数：释放对象
	~Size_contrast();
	//-----------------------------------------------
	/**
	 *get直接return你想要的那个变量
	 *set带参数，然后给你想要赋值的成员变量
	 **/
	void Setname(string name) { this->_name = name; };
	string Getname() { return this->_name; }
	//+++++++++++++++++++++++++++++++++++++++++++++++
};

