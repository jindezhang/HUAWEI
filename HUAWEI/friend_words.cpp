#include "friend_words.h"
#include <string>

bool is_friends( std::string des, std::string str )
{
	if(!des.compare(str))//尽量不使用“==”来比较字符串
		return false;
	std::sort( des.begin(), des.end() );
	std::sort( str.begin(), str.end() );
	return !des.compare( str );
}

void main_word()
{

	int count_w, num = 0;
	std::vector<std::string> word_list;
	std::string str_target;
	std::string str_temp;
	
	std::cout << "please input number and words,input number = -1 is exit ,number = 0 is clear dict.\n";

	std::cin >> count_w;
	int i;
	while ( -1 != count_w )
	{
		
		if ( 0 == count_w )
		{
			word_list.clear();
			goto END_W;
		}
		num = 0;
		for ( i = 0; i < count_w; i++ )
		{
			std::cin >> str_temp;
			word_list.push_back( str_temp );
		}
		std::sort( word_list.begin(), word_list.end() );
		std::cout << "\n";
		std::cin >> str_target;
		/*for ( i = 0; i < word_list.size(); i++ )
		{
			if ( is_friends( str_target, word_list[ i ] ) )
			{
				num++;
				std::cout << "the friends:"<<word_list[ i ]<<"\n";
			}

		}*/
		for ( auto item : word_list )
		{
			if ( is_friends( str_target, item ) )
			{
				num++;
				std::cout << "the friends:" << item << "\n";
			}
		}
		std::cout << num << "\n";

		END_W:
		std::cin >> count_w;
	}

}
