#ifndef SORT_H_H
#define SORT_H_H

#include <algorithm>
#include <string>

typedef struct student
{
	int score;
	std::string name;
}STU;
bool compare_score( STU a, STU b );
void score_sort();
#endif


#pragma once
