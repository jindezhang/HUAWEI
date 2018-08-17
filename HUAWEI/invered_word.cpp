#include "invered_word.h"

void splitWord( std::string str, std::vector<std::string>& word )
{
	int start = 0;
	int i = 0;
	std::string str_temp;
	for ( ; i < str.size(); i++ )
	{
		//查找
		/*isalpha 字母（包括大写、小写）islower（小写字母）isupper（大写字母）
		isalnum（字母大写小写 + 数字）isblank（space和\t）isspace（space、\t、\r、\n）*/
		if ( !isalpha( str[ i ] ) )
		{
			//截取[start,i]范围的句子部分
			if ( isalpha( str[ start ] ) )
			{
				str_temp = str.substr( start, i - start );
				word.push_back( str_temp );
			}
			start = i+1;//截取i之后的句子部分。
		}
	}
	//当line只有一个单词时候，
	if ( start != i )
		word.push_back( str.substr( start, i - start ) );
}

void printResult( std::vector<std::string>& vec_line )
{
	auto item = vec_line.end(); //vec.end()//指向迭代器中末端元素的下一个，指向一个不存在元素。
	item--;
	while ( item != vec_line.begin() )
	{
		std::cout << *item << " ";
		item--;
	}
	std::cout << *item << "\n";
}

void main_invered()
{
	std::string str_line;
	std::vector<std::string> vec_line;

	getline( std::cin, str_line );//从cin中获取一行文本
	splitWord( str_line, vec_line );
	printResult( vec_line );


}
