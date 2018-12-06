#include "24point.h"
#include "my24point.h"
#include <time.h>
#include "all24point.h"
#include "unique_data.h"
#include "score_sort.h"
#include "listNode.h"
#include "studyEnglish.h"
#include "friend_words.h"
#include "invered_word.h"
#include "regex_.h"


/*
int main(){
	//point24 t;
	//t.show();
	
	/ *clock_t start_t, end_t;
	start_t = clock();
	MyPoint mp;
	mp.show();
	end_t = clock();
	std::cout << "time cost :" << ( double )( end_t - start_t ) / CLOCKS_PER_SEC;
* /

	/ *All24 all;
	all.show();* /

	/ *unique_data();
	unique_dat( 0 );* /
	//score_sort();

	//输出单向链表中的倒数第k结点
	//tmain();

	//学英语
	//main_study();

	//dict
	//main_word();

	//单词倒排
	//main_invered();

	//正则表达式
	main_regex2();

}*/

// numeric_accum.cpp
// compile with: /EHsc
#include <vector>
#include <numeric>
#include <functional>
#include <iostream>

int main_t()
{
	using namespace std;

	vector <int> v1, v2( 20 );
	vector <int>::iterator iter1, iter2;

	int i;
	for ( i = 1; i < 21; i++ )
	{
		v1.push_back( i );
	}

	cout << "The original vector v1 is:\n ( ";
	for ( iter1 = v1.begin(); iter1 != v1.end(); iter1++ )
		cout << *iter1 << " ";
	cout << ")." << endl;

	// The first member function for the accumulated sum
	int total;
	total = accumulate( v1.begin(), v1.end(), 10 );

	cout << "The sum of the integers from 1 to 20 is: "
		<< total << "." << endl;

	// Constructing a vector of partial sums
	int j = 0, partotal;
	for ( iter1 = v1.begin(); iter1 != v1.end(); iter1++ )
	{
		partotal = accumulate( v1.begin(), iter1 + 1, 0 );
		v2[ j ] = partotal;
		j++;
	}

	cout << "The vector of partial sums is:\n ( ";
	for ( iter2 = v2.begin(); iter2 != v2.end(); iter2++ )
		cout << *iter2 << " ";
	cout << ")." << endl << endl;

	// The second member function for the accumulated product
	vector <int> v3, v4( 10 );
	vector <int>::iterator iter3, iter4;

	int s;
	for ( s = 1; s < 11; s++ )
	{
		v3.push_back( s );
	}

	cout << "The original vector v3 is:\n ( ";
	for ( iter3 = v3.begin(); iter3 != v3.end(); iter3++ )
		cout << *iter3 << " ";
	cout << ")." << endl;

	int ptotal;
	ptotal = accumulate( v3.begin(), v3.end(), 1, multiplies<int>() );

	cout << "The product of the integers from 1 to 10 is: "
		<< ptotal << "." << endl;

	// Constructing a vector of partial products
	int k = 0, ppartotal;
	for ( iter3 = v3.begin(); iter3 != v3.end(); iter3++ )
	{
		ppartotal = accumulate( v3.begin(), iter3 + 1, 1, multiplies<int>() );
		v4[ k ] = ppartotal;
		k++;
	}

	cout << "The vector of partial products is:\n ( ";
	for ( iter4 = v4.begin(); iter4 != v4.end(); iter4++ )
		cout << *iter4 << " ";
	cout << ")." << endl;

    return 0;
}


//  针对动态内存分配大小，做安全检查
//  <malloc.h>
//  new 通过 calloc, malloc, or realloc 实现的情况下可用
//  如果，operation new 被复写，要重新评估该函数的可行性
//【排序】
template<typename T>
size_t MEM_SIZE( T* ptr )
{
    return _msize( ptr ) / sizeof( T ); //  windows独有   
                                        //  return malloc_usable_size( ptr ) / sizeof( T ); //  linux
}

void f( int arr[] ) {

    int temp[ 21 ];
    int ii = MEM_SIZE( arr );
    for ( int i = 0; i < ii; i++ )
    {
        temp[ arr[ i ] ]++;
    }
    //顺序打印
    for ( int i = 0; i < 21; i++ )
    {
        for ( int j = 0; j < temp[ i ]; j++ )
        {
            std::cout << i<<std::endl;
        }
    }
}
void test_f(){
    int arr[] = { 1,3,4,2,5,9,6 };
    int temp[ 21 ] = { 0 };
    int ii = sizeof( arr ) / sizeof( arr[ 0 ] );
    for ( int i = 0; i < ii; i++ )
    {
        temp[ arr[ i ] ]++;
    }
    //顺序打印
    for ( int i = 0; i < 21; i++ )
    {
        for ( int j = 0; j < temp[ i ]; j++ )
        {
            std::cout << i << std::endl;
        }
    }
    f( arr );
    return;
}

#include <string>

/*
题目描述
计算字符串最后一个单词的长度，单词以空格隔开。
输入描述:
一行字符串，非空，长度小于5000。

输出描述:
整数N，最后一个单词的长度。
*/

void test_strLast(){
    
    std::string str;
    getline( std::cin, str );
    

    int count = 0;
    std::for_each( str.begin(), str.end(), [ &count ]( char c ){
        //char space = " ";
        if ( c != ' ' )
            count++;
        else
            count = 0;
    } );
    std::cout << count << std::endl;
    return;
}

/************************************************************************/
/* 题目描述
写出一个程序，接受一个由字母和数字组成的字符串，和一个字符，然后输出输入字符串中含有该字符的个数。不区分大小写。
思路：通过字符映射表转换
    1.先比较输入的字符的个数；
    2.再通过字符映射表转换，再比较得出的个数。
*/
/************************************************************************/
#include <algorithm>
char transForm( char a ){
    char b;
    if ( a > 0x40 && a < 0x5B ) //A = 0x41 Z = 0x5A --> ‘A'  'Z' 
        b = char( a + 0x20 );
    else if ( a > 0x60 && a < 0x7B )
        b = char( a - 0x20 );
    else
        b = a;
    return b;
}
void main_countChar(){
    std::string str;
    char c;
    char tmp;
    int count = 0;
    std::cin >> str;
    std::cin >> c;
    
    if ( str.empty() )
        std::cout << count << std::endl;

    tmp = transForm( c );
    std::for_each( str.begin(), str.end(), [ &count, &c, &tmp ]( char x){
        if ( c == x )
            count++;
        if (c != tmp && tmp == x){
            count++;
        }
    } );
    std::cout << count << std::endl;

}
#include "random.h"

//哈希表；拉链法
void show( char value ){
    std::cout << value << "\t";
}
#include "DataStruct.h"
int main()
{
    
    //test_strLast();

    //明明的随机数
    //main_random();
    //计算字符个数
    //main_countChar();

    //哈希表
    HashTable<char, char> hash(11);
    char a = 'a';
    for ( char i = 'z'; i >= 'a'; --i )
    {
        hash.install( i, a );
        ++a;
    }

    hash.display(show);
    char b = hash.get( 'z' );
    std::cout << b << std::endl;

    hash.del( 'z' );
    hash.display( show );
    system( "pause" );
    return 0;
}


