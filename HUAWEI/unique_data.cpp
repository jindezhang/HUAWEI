#include "unique_data.h"
#include <list>
#include <vector>
#include <time.h>


//new thinking
#include <iostream>
#include <vector>

int unique_dat( int d ){
	int N, n;
	clock_t start_t;
	std::cin >> N;
	//while ( std::cin >> N )
	{
		
		std::vector<int> a( 1000, 0 );
		while ( N-- )
		{
			std::cin >> n;
			a[ n ] = 1;
		}
		start_t = clock();
		for ( int i = 0; i < 1000; i++ )
		{
			if ( a[ i ] )
				std::cout << i << "  ";
		}
	}
	std::cout << "\n";
	std::cout << "cost time:" << ( double )( clock() - start_t ) << std::endl;
	return 0;
}

void unique_data()
{
	std::vector<int> stu;
	
	int tem = 0;
	int count;
	std::cout << "please input students id:" << std::endl;
	std::cin >> count;
	clock_t start_t;
	while ( count -- )
	{
		std::cin >> tem;
		
		stu.push_back( tem );
	}
	start_t = clock();
	if ( stu.empty() )
	{
		std::cout << "no data" << std::endl;
		return;
	}

	std::sort(stu.begin(), stu.end());
	std::cout << std::endl;
	for ( auto item : stu )
	{
		if(tem == item || 0 == item)
			continue;

		std::cout << item << "  ";
		tem = item;
	}
	std::cout << "cost time:" << ( double )( clock() - start_t ) << std::endl;

}
