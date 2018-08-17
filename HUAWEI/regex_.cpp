#include "regex_.h"

void main_regex()
{
	if ( std::regex_match( "subject", std::regex( "(sub)(.*)" ) ) )
		std::cout << "string literal matched\n";//字符串匹配
	const char cstr[] = "subject";
	std::string s( "subject" );
	std::regex e( "(sub)(.*)" );
	if ( std::regex_match( s, e ) )
		std::cout << "string object matched\n";//字符对象匹配
	if ( std::regex_match( s.begin(), s.end(), e ) )
		std::cout << "range matched\n";//选择特定的位置进行匹配
	std::cmatch cm;    // same as std::match_results<const char*> cm;
	std::regex_match( cstr, cm, e );
	std::cout << "string literal with " << cm.size() << " matches\n";
	std::smatch sm;    // same as std::match_results<string::const_iterator> sm;
	std::regex_match( s, sm, e );
	std::cout << "string object with " << sm.size() << " matches\n";
	std::regex_match( s.cbegin(), s.cend(), sm, e );
	std::cout << "range with " << sm.size() << " matches\n";
	// using explicit flags:
	std::regex_match( cstr, cm, e, std::regex_constants::match_default );
	std::cout << "the matches were: ";
	for ( unsigned i = 0; i < sm.size(); ++i )
	{
		std::cout << "[" << sm[ i ] << "] ";
	}
	std::cout << std::endl;
	return ;
}

int main_regex2()
{
	string str = "sigalhu233";

	regex r( "[a-z0-9]+" );
	cout << "正则表达式：[a-z0-9]+" << endl;
	if ( regex_match( str, r ) )
		cout << "字符串：" << str << " 匹配成功！" << endl;
	else
		cout << "字符串：" << str << " 匹配失败！" << endl;

	cout << endl << "正则表达式：\\d+" << endl;
	if ( regex_match( str, regex( "\\d+" ) ) )
		cout << "字符串：" << str << " 匹配成功！" << endl;
	else
		cout << "字符串：" << str << " 匹配失败！" << endl;

	cout << endl << "正则表达式：\\d+" << endl;
	if ( regex_match( str.begin() + 7, str.end(), regex( "\\d+" ) ) )
		cout << "字符串：" << &str[ 7 ] << " 匹配成功！" << endl;
	else
		cout << "字符串：" << &str[ 7 ] << " 匹配失败！" << endl;

	smatch sm;//保存string类型的结果
	cout << endl << "正则表达式：([a-z]+)(\\d+)" << endl;
	if ( regex_match( str.cbegin()+5 , str.cend(), sm, regex( "([a-z]+)(\\d+)" ) ) )
	{
		cout << "字符串：" << &str[ 5 ] << " 匹配成功！" << endl;
		cout << "匹配字符串个数：" << sm.size() << endl;
		cout << "分别为：";
		for ( auto aa : sm )
			cout << aa.str() << " ";
		cout << endl;
	}
	else
		cout << "字符串：" << &str[ 5 ] << " 匹配失败！" << endl;

	cmatch cm;//保存char类型的结果
	//smatch cm;
	cout << endl << "正则表达式：([a-z]+)(\\d+)" << endl;
	if ( regex_match( str.c_str(), cm, regex( "([a-z]+)(\\d+)" ) ) )
	{
		cout << "字符串：" << str << " 匹配成功！" << endl;
		cout << "匹配字符串个数：" << cm.size() << endl;
		cout << "分别为：";
		for ( auto aa : cm )
			cout << aa.str() << " ";
		cout << endl;
	}
	else
		cout << "字符串：" << str << " 匹配失败！" << endl;
	return 0;
}
