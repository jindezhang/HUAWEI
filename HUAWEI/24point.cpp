#include "24point.h"


point24::point24()
{


}

point24::~point24()
{
}

void point24::show()
{
	std::string str[ 4 ];
	std::cout << "|please input 4 numbers(A~K):";
	std::cin >> str[ 0 ] >> str[ 1 ] >> str[ 2 ] >> str[ 3 ];

	int i, j;
	bool legal;
	for (  i = 0; i < 4; i++ )
	{
		legal = false;
		for (j=0;j<13;j++)
		{
			if ( str[ i ].compare( ( poker[ j ].c_str() )) == 0 )
				legal = true;

		}
		if ( legal == false )
		{
			std::cout << "EORROR" << std::endl;
			return;
		}
			
	}

	int a, b, c, d;
	std::string *p;
	p = std::find( poker, poker + 13, str[ 0 ] );
	a = p - poker + 1;
	p = std::find( poker, poker + 13, str[ 1 ] );
	b = p - poker + 1;
	p = std::find( poker, poker + 13, str[ 2 ] );
	c = p - poker + 1;
	p = std::find( poker, poker + 13, str[ 3 ] );
	d = p - poker + 1;

	int num[ 4 ];
	num[ 0 ] = a;
	num[ 1 ] = b;
	num[ 2 ] = c;
	num[ 3 ] = d;

	do
	{
		if ( Count24( num[ 0 ], num[ 1 ], num[ 2 ], num[ 3 ] ) )
		{
			std::cout << poker[ num[ 0 ] - 1 ] << C[ 0 ] << poker[ num[ 1 ] - 1 ] << C[ 1 ]
				<< poker[ num[ 2 ] - 1 ] << C[ 2 ] << poker[ num[ 3 ] - 1 ] << "= 24" << std::endl;
			return;
		}
	} while ( std::next_permutation( num, num + 4 ) );
	std::cout << "NONE" << std::endl;
	return;
}

int point24::Cal( int a, int b, char c )
{
	switch ( c)
	{
		case '+':return a + b;
		case '-':return a - b;
		case '*':return a*b;
		case '/':return a / b;
		default:
			break;
	}
	return -1;
}

int point24::Cal24( int a, int b, int c, int d, char c1, char c2, char c3 )
{

	return Cal( Cal( Cal( a, b, c1 ), c, c2 ), d, c3 );

}

bool point24::Count24( int a, int b, int c, int d )
{
	std::sort( C, C + 12 );

	do 
	{
		if ( Cal24( a, b, c, d, C[ 0 ], C[ 1 ], C[ 2 ] ) == 24 )
			return true;
	} while (std::next_permutation(C,C+12));
	
	return false;
}
