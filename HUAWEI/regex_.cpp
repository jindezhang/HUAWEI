#include "regex_.h"

void main_regex()
{
	if ( std::regex_match( "subject", std::regex( "(sub)(.*)" ) ) )
		std::cout << "string literal matched\n";//�ַ���ƥ��
	const char cstr[] = "subject";
	std::string s( "subject" );
	std::regex e( "(sub)(.*)" );
	if ( std::regex_match( s, e ) )
		std::cout << "string object matched\n";//�ַ�����ƥ��
	if ( std::regex_match( s.begin(), s.end(), e ) )
		std::cout << "range matched\n";//ѡ���ض���λ�ý���ƥ��
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
	cout << "������ʽ��[a-z0-9]+" << endl;
	if ( regex_match( str, r ) )
		cout << "�ַ�����" << str << " ƥ��ɹ���" << endl;
	else
		cout << "�ַ�����" << str << " ƥ��ʧ�ܣ�" << endl;

	cout << endl << "������ʽ��\\d+" << endl;
	if ( regex_match( str, regex( "\\d+" ) ) )
		cout << "�ַ�����" << str << " ƥ��ɹ���" << endl;
	else
		cout << "�ַ�����" << str << " ƥ��ʧ�ܣ�" << endl;

	cout << endl << "������ʽ��\\d+" << endl;
	if ( regex_match( str.begin() + 7, str.end(), regex( "\\d+" ) ) )
		cout << "�ַ�����" << &str[ 7 ] << " ƥ��ɹ���" << endl;
	else
		cout << "�ַ�����" << &str[ 7 ] << " ƥ��ʧ�ܣ�" << endl;

	smatch sm;//����string���͵Ľ��
	cout << endl << "������ʽ��([a-z]+)(\\d+)" << endl;
	if ( regex_match( str.cbegin()+5 , str.cend(), sm, regex( "([a-z]+)(\\d+)" ) ) )
	{
		cout << "�ַ�����" << &str[ 5 ] << " ƥ��ɹ���" << endl;
		cout << "ƥ���ַ���������" << sm.size() << endl;
		cout << "�ֱ�Ϊ��";
		for ( auto aa : sm )
			cout << aa.str() << " ";
		cout << endl;
	}
	else
		cout << "�ַ�����" << &str[ 5 ] << " ƥ��ʧ�ܣ�" << endl;

	cmatch cm;//����char���͵Ľ��
	//smatch cm;
	cout << endl << "������ʽ��([a-z]+)(\\d+)" << endl;
	if ( regex_match( str.c_str(), cm, regex( "([a-z]+)(\\d+)" ) ) )
	{
		cout << "�ַ�����" << str << " ƥ��ɹ���" << endl;
		cout << "ƥ���ַ���������" << cm.size() << endl;
		cout << "�ֱ�Ϊ��";
		for ( auto aa : cm )
			cout << aa.str() << " ";
		cout << endl;
	}
	else
		cout << "�ַ�����" << str << " ƥ��ʧ�ܣ�" << endl;
	return 0;
}
