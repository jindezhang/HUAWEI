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
	void show();//������


	//�������ԭ��
	//����ͨ����ַ����Ӽ����ɻ�ö�Ӧ����ֵ�����Խ���ѭ�����ж����������Ƿ�����
	//����ʹ��STL�㷨��sort() next_permutation();������ϡ�
	//std::vector<std::string> poker = { "A","2","3","4","5","6","7","8","9","10","J","Q","K" };
	std::string poker[ 13 ] = { "A","2","3","4","5","6","7","8","9","10","J","Q","K" };
	char C[ 12 ] = { '+', '+', '+', '-', '-', '-', '*', '*', '*', '/', '/', '/'};
	int Cal( int a, int b, char c );//����
	bool Count24( int a, int b, int c, int d );//������Ƿ��ܵõ�24
	int Cal24( int a, int b, int c, int d, char c1, char c2, char c3 );//���������㡣
};


#endif
#pragma once
