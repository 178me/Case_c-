/**
 *Title:扑克牌游戏：比大小
 *Time:2019-5-23
 *writer:178me
 **/
#include <iostream>
#include "Size_contrast.hpp"
using namespace std;
int main()
{
	system("title 扑克牌之比大小");
	system("color 02");
	Size_contrast* Player1 = new Size_contrast();		//new一个类
	Player1->Game();		//一句话搞定
	delete Player1;		//回收类
}

