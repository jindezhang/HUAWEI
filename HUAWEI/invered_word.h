#ifndef INV_H
#define  INV_H


#include<string>
#include <algorithm>
#include<vector>
#include<iostream>

/*
��Ŀ����
���ַ����е����е��ʽ��е��š�

˵����

1��ÿ����������26����д��СдӢ����ĸ���ɣ�

2���ǹ��ɵ��ʵ��ַ�����Ϊ���ʼ������

3��Ҫ���ź�ĵ��ʼ������һ���ո��ʾ�����ԭ�ַ��������ڵ��ʼ��ж�������ʱ������ת����Ҳֻ�������һ���ո�������

4��ÿ�������20����ĸ��*/
void splitWord( std::string str, std::vector<std::string> &word );
void printResult( std::vector<std::string> &vec_line );//�������vector��
void main_invered();

#endif
#pragma once

