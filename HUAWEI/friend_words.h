#ifndef WORDS_H_
#define WORD_H_

#include<string>
#include <algorithm>
#include<vector>
#include<iostream>
/*

查找兄弟单词

输入描述 :
先输入字典中单词的个数，再输入n个单词作为字典单词。
输入一个单词，查找其在字典中兄弟单词的个数
再输入数字n

输出描述 :
根据输入，输出查找到的兄弟单词的个数*/
bool is_friends( std::string des, std::string str );
void main_word();

#endif

#pragma once
