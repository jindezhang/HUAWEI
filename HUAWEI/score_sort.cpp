#include "score_sort.h"
#include <iostream>
#include <vector>
#include <time.h>

bool compare_score_asc( STU a, STU b )
{

	return a.score > b.score;
}

bool compare_score_des( STU a, STU b )
{

	return a.score < b.score;
}

void score_sort()
{

	int num;
	int mode;
	std::vector<STU> stu;
	STU tmp;

	std::cin >> num;
	std::cin >> mode;
	while (num--)
	{
		std::cin >> tmp.name >> tmp.score;
		stu.push_back( tmp );
	}
	clock_t start_t = clock();

	if ( 0 == mode )
		std::stable_sort( stu.begin(), stu.end(), compare_score_asc );
	else
		std::stable_sort( stu.begin(), stu.end(), compare_score_des );
	//sort  «≤ªŒ»∂®≈≈–Ú°£
	
	
	std::cout <<"\n ** the time cost:"<<(double)(clock()-start_t)/ CLOCKS_PER_SEC << " s \n";
	for ( auto item : stu )
	{
		std::cout << item.name << "  " << item.score << std::endl;

	}
}
