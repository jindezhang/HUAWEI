#include "invered_word.h"

void splitWord( std::string str, std::vector<std::string>& word )
{
	int start = 0;
	int i = 0;
	std::string str_temp;
	for ( ; i < str.size(); i++ )
	{
		//����
		/*isalpha ��ĸ��������д��Сд��islower��Сд��ĸ��isupper����д��ĸ��
		isalnum����ĸ��дСд + ���֣�isblank��space��\t��isspace��space��\t��\r��\n��*/
		if ( !isalpha( str[ i ] ) )
		{
			//��ȡ[start,i]��Χ�ľ��Ӳ���
			if ( isalpha( str[ start ] ) )
			{
				str_temp = str.substr( start, i - start );
				word.push_back( str_temp );
			}
			start = i+1;//��ȡi֮��ľ��Ӳ��֡�
		}
	}
	//��lineֻ��һ������ʱ��
	if ( start != i )
		word.push_back( str.substr( start, i - start ) );
}

void printResult( std::vector<std::string>& vec_line )
{
	auto item = vec_line.end(); //vec.end()//ָ���������ĩ��Ԫ�ص���һ����ָ��һ��������Ԫ�ء�
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

	getline( std::cin, str_line );//��cin�л�ȡһ���ı�
	splitWord( str_line, vec_line );
	printResult( vec_line );


}
