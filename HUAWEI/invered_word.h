#ifndef INV_H
#define  INV_H


#include<string>
#include <algorithm>
#include<vector>
#include<iostream>

/*
题目描述
对字符串中的所有单词进行倒排。

说明：

1、每个单词是以26个大写或小写英文字母构成；

2、非构成单词的字符均视为单词间隔符；

3、要求倒排后的单词间隔符以一个空格表示；如果原字符串中相邻单词间有多个间隔符时，倒排转换后也只允许出现一个空格间隔符；

4、每个单词最长20个字母；*/
void splitWord( std::string str, std::vector<std::string> &word );
void printResult( std::vector<std::string> &vec_line );//逆向输出vector；
void main_invered();

#endif
#pragma once

