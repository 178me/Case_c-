#include "Size_contrast.hpp"

void Size_contrast::Show_info()
{
	/**
	 *显示玩家信息
	 *手牌排序和显示手牌
	 **/
	cout << "名称:" << _name << endl;
	Sort_card(this->Card_hand);
	Show_card(this->Card_hand);
}

void Size_contrast::Init_poker()
{
	/**
	 *初始化牌堆54张扑克牌
	 *当前手牌清零
	 **/
	int j = 1;
	this->Card_pile.clear();
	for (int i = 0; i != 54; ++i) {
		if (i == 52) { this->Card_pile.push_back(14); }
		else if (i == 53) { this->Card_pile.push_back(15); }
		else {
			if (i % 13 == 0 && i != 0)	j = 1;
			this->Card_pile.push_back(j);
			++j;
		}
	}
	this->Card_hand.clear();
}

void Size_contrast::Show_card(const vector<int>&temp_card)
{
	/**
	 *定义两个字符串变量接收花色和牌值
	 *循环显示出里面的元素，每行13个元素
	 **/
	string  t2;
	for (int i = 0; i != temp_card.size();++i) {
//		t1 = Colors_card(i);
	//	t1 = Colors_card(52);
		t2 = Value_card(temp_card[i]-1);
		if (i % 13 == 0 && i != 0) { cout << endl; }
		cout << left;
		cout << setw(6) << t2;
	}
	cout << endl;
}

void Size_contrast::Touch_Card(int Card_count)
{
	/**
	 *1、从牌堆里随机获得卡牌;这里需要随机函数
	 *2、把卡牌放进玩家手牌数组，并删除牌堆里的这张牌
	 **/
	srand((unsigned)time(NULL));
	int Pile_count = 54;
	for (int i = 0; i != Card_count; ++i) {
		int Card_Index = rand() % Pile_count;
		this->Card_hand.push_back(this->Card_pile[Card_Index]);
		this->Card_pile.erase(Card_pile.begin()+Card_Index);
		Pile_count--;
	}
}
/*
string Size_contrast::Colors_card(int card)
{
	/**
	 *定义一个字符串数组存储花色
	 *0~51的元素 % 4 得出花色
	 *52和53为王的花色，暂时用这个
	 *本来想显示符号，但是显示不出来，只好用中文了
	 *
//	string colors[6]{"♢","♧", "♡", "♤", "小", "大" };
	string colors[4]{"方块","梅花", "红桃", "黑桃"};
		return colors[card % 4];
}*/

string Size_contrast::Value_card(int card)
{
	/**
	 *定义一个字符串数组存储牌值
	 *0~51的元素 % 13 得出牌值
	 *52和53为王
	 *本来想显示符号，但是显示不出来，只好用中文了
	 **/
	string value[15]{"3","4","5","6","7" ,"8" ,"9" ,"10" ,"J" ,"Q" ,"K" ,"A" ,"2","小王","大王" };
	if (card < 0)	card = 0;
	if (card == 13) {
		return value[13];
	}
	if (card == 14) {
		return value[14];
	}
		return value[card % 13];
}

void Size_contrast::Sort_card(vector<int>&temp_card)
{
	/**
	 *使用排序方法进行降序排序
	 **/
	sort(temp_card.begin(),temp_card.end(),greater<int>());
}

int Size_contrast::Contrast_card(int&num1,int&num2)
{
/**
 *选择出牌
 *验证牌是否在手牌中
 *通过之后对比大小
 **/
	if (num1 > num2)		return 1;
	if (num1 < num2)		return 2;
	return 0;
}

int Size_contrast::Deal_card()
{
/**
 *提示出牌
 *验证出牌
 *true：返回这张牌 ; flase:重新输入
 **/
	int temp_card;
	do {
		cin >> temp_card;
		if (temp_card >= 1 && temp_card <= Card_hand.size()) {
			temp_card -= 1;
			break;
		}
		else {
			cout << "输入错误，请重新输入！";
		}
	} while (1);
	
	vector<int>::const_iterator it = find(this->Card_hand.cbegin(),this->Card_hand.cend(),Card_hand[temp_card]);
	if (it != Card_hand.end()) {
		return temp_card;
	}
}

void Size_contrast::Game()
{
	/**
	 *整个游戏的流程
	 *想作弊可以自己修改代码，(￣▽￣)"
	 **/
	string temp_name;		//存储玩家昵称的临时变量
	int choice,num1,num2,score1 = 0,score2 = 0;		//choice用来接收比大小的一个结果，num1,num2用来接收玩家和系统出的牌；后面两个记录分数
	int num1_Index;		//玩家出的牌下标
	char b = 'y';		//控制是否继续游戏的变量
	srand((unsigned)time(NULL));		//用时间做种子，生成随机数字
		cout << "游戏名:扑克牌比大小" << endl;
		cout << "游戏规则:一共有54张牌，玩家抽取十五张牌，系统取剩下的，然后各出一张牌比大小。" << endl;
		cout << "注意:出牌的下标是从左到右计算，最左边的一张牌为1，后面的以此类推。" << endl;
		system("pause");		//此方法暂停
		cout << "游戏开始" << endl;
		cout << "给自己起个名字吧";
		cin >> temp_name;		//接收玩家昵称
		Setname(temp_name);		//给玩家赋值
		Touch_Card(15);			//摸15张牌
		system("cls");			//清屏
	do {
		cout << "游戏名:扑克牌比大小" << endl << endl;
		cout << "游戏规则:一共有54张牌，玩家抽取十五张牌，系统取剩下的，然后各出一张牌比大小。" << endl << endl;
		cout << "注意:出牌的下标是从左到右计算，最左边的一张牌为1，后面的以此类推。" << endl << endl;
		Show_info();		//展示个人信息
		cout << endl;
		cout << "请输入你要出的牌的下标:";
		num1_Index = Deal_card();		//获取下标
		num1 = Card_hand[num1_Index];		//玩家出的牌
		num2 = this->Card_pile[rand() % Card_pile.size()];		//系统随机抽一张牌
		this->Card_hand.erase(Card_hand.begin()+num1_Index);		//删除玩家出的牌
		choice = Contrast_card(num1,num2);		//接受比较结果  有1，2，0三种结果  对应下面的三个if
		cout << endl;
		cout << "系统玩家的牌是：" << Value_card(num2) << endl;		//显示系统所出的牌
		if (choice == 1) {
			cout << this->_name << "获得一分" << endl;
			score1++;
		}
		if (choice == 2) {
			cout << "系统玩家" << "获得一分" << endl;
			score2++;
		}
		if (choice == 0) { cout << "双方一样大" << endl; }
		//游戏结果判定：当手牌数为0是，进入结局：分数大于系统，win，否则输
		if (this->Card_hand.empty()) {
			cout << "游戏结束！" << endl;
			cout << _name << "的分数是" << score1 << endl;
			cout << "系统玩家" << "的分数是" << score2 << endl;
			if (score1 > score2) { cout << _name << "获胜" << endl; }
			else {
				cout << "你输了,再接再厉吧！" << endl;
			}
			cout << "是否继续游戏(y/n)";		//提示是否继续游戏
			cin >> b;
			Init_poker();		//初始化扑克牌
			Touch_Card(15);		//摸15张牌
		}
		system("pause");
		system("cls");
	} while (b == 'y'||b == 'Y');
}


Size_contrast::Size_contrast()
{
	this->Setname("默认玩家");
	Init_poker();		//初始化扑克牌
}

Size_contrast::~Size_contrast()
{
}
