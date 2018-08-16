#ifndef MYPOINT_H
#define MYPOINT_H

#include <string>
#include <algorithm>
#include <iostream>
#include <time.h>
#include <algorithm>
#include <vector>

class MyPoint
{
public:
	MyPoint();
	~MyPoint();
	void show();//主程序


	//用数组的原因。
	//可以通过地址的相加减即可获得对应的数值；可以进行循环的判断输入条件是否满足
	//方便使用STL算法。sort() next_permutation();排列组合。
	//std::vector<std::string> poker = { "A","2","3","4","5","6","7","8","9","10","J","Q","K" };
	std::string poker[ 13 ] = { "A","2","3","4","5","6","7","8","9","10","J","Q","K" };
	char C[ 12 ] = { '+', '+', '+', '-', '-', '-', '*', '*', '*', '/', '/', '/'};
	int Cal( int a, int b, char c );//计算
	bool Count24( int a, int b, int c, int d );//计算出是否能得到24
	int Cal24( int a, int b, int c, int d, char c1, char c2, char c3 );//四则混合运算。
};


#endif
#pragma once
