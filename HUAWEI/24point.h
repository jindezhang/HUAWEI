#ifndef POINT_H
#define POINT_H

#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>

/*
https://www.nowcoder.com/practice/7e124483271e4c979a82eb2956544f9d?tpId=37&tqId=21312&tPage=1&rp=&ru=/ta/huawei&qru=/ta/huawei/question-ranking

*/

class point24
{
public:
	point24();
	~point24();
	void show();
private:
	std::string poker[13] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
	char C[ 12 ] = { '+', '+', '+', '-', '-', '-', '*', '*', '*', '/', '/', '/' };
	int Cal( int a, int b, char c );
	int Cal24( int a, int b, int c, int d, char c1, char c2, char c3 );
	bool Count24( int a, int b, int c, int d );
};



#endif // !24POINT


#pragma once
