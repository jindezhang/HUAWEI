#include "all24point.h"

void All24::show()
{
	

	/*std::string po[13];
	memcpy( po, poker,13 );*/

	
	int num[ 4 ];

	int i, j, k, l;
	int num1[ 4 ];
	bool legal;
	int allcount = 0;
	int mycount = 0 ;
	std::cout << "start..." << std::endl;
	for ( i = 1; i < 14; i++ )
	{
		num[ 0 ] = i;
		for ( j = 0; j < 13; j++ )
		{
			num[ 1 ] = j+1;
			for ( k = 0; k < 13; k++ )
			{
				num[ 2 ] = k + 1;
				for (l=0;l<13;l++)
				{
					allcount++;
					legal = false;
					//最多28561次
					num[ 3 ] = l + 1;

					/*if ( num[ 0 ] * num[ 1 ] * num[ 2 ] * num[ 3 ] < 24 )
					{
						std::cout << poker[ num[ 0 ] - 1 ]   <<","<< poker[ num[ 1 ] - 1 ] << ","
							<< poker[ num[ 2 ] - 1 ] << "," << poker[ num[ 3 ] - 1 ] << " is NONE" <<  std::endl;
						continue;

					}*/
					
					memcpy( num1, num, sizeof(num) );
					do
					{
						if ( Count24( num1[ 0 ], num1[ 1 ], num1[ 2 ], num1[ 3 ] ) )
						{
							std::cout << poker[ num1[ 0 ] - 1 ] << C[ 0 ] << poker[ num1[ 1 ] - 1 ] << C[ 1 ]
								<< poker[ num1[ 2 ] - 1 ] << C[ 2 ] << poker[ num1[ 3 ] - 1 ] << "= 24" << std::endl;
							legal = true;
							mycount++;
							break;
						}
					} while ( std::next_permutation( num1, num1 + 4 ) );
					
					if ( !legal )
					{
						std::cout << poker[ num[ 0 ] - 1 ] << "," << poker[ num[ 1 ] - 1 ] << ","
							<< poker[ num[ 2 ] - 1 ] << "," << poker[ num[ 3 ] - 1 ] << " is NONE ***" << std::endl;
					}

				}
				
				
			}
		}
	}
	std::cout << "mycount:" << mycount <<" all="<<allcount<< std::endl;

	/*
	//数字会重复出现，因为52个数排序，前面四个可能很多时候不会变。
	int allpoker[ 52 ];
	for ( int i = 0; i < 52; i++ )
	{
		allpoker[ i ] = i  % 13+1;
		std::cout << allpoker[ i ] << " " << std::endl;

	}
	int num[ 4 ];
	std::cout << "start...." << std::endl;
	int mycount = 0;
	do 
	{
		memcpy( num, allpoker, sizeof(num) );
		mycount++;
		std::cout << "**:" << mycount << " " << std::endl;
		std::cout << num[ 0 ] << "#";
		std::cout << num[ 1 ] << "#";
		std::cout << num[ 2 ] << "#";
		std::cout << num[ 3 ] << "#" << std::endl;

		if (num[0]*num[1]*num[2]*num[3] < 24)
		{
			continue;
		}
		do
		{
			if ( Count24( num[ 0 ], num[ 1 ], num[ 2 ], num[ 3 ] ) )
			{
				std::cout << poker[ num[ 0 ] - 1 ] << C[ 0 ] << poker[ num[ 1 ] - 1 ] << C[ 1 ]
					<< poker[ num[ 2 ] - 1 ] << C[ 2 ] << poker[ num[ 3 ] - 1 ] << "= 24" << std::endl;
				
			}
		} while ( std::next_permutation( num, num + 4 ) );

	} while (std::next_permutation(allpoker,allpoker+52));
	std::cout << "NONE" << std::endl;
	/*/
}
