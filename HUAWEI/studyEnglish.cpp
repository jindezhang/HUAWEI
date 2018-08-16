#include "studyEnglish.h"

std::vector<std::string> unit = { "","one","two","three","four","five","six","seven","eight","nine" };
std::vector<std::string> decade = { "","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety" };
std::vector<std::string>decade1 = { "ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen" };

std::string translator( long num )
{
	std::string str = "";
	if ( num / 100 )
	{
		str = unit[ num / 100 ];
		str += " hunderd";
	}
	num %= 100;
	if ( 0 == num )
		return str;
	if ( !str.empty() )
		str += " and ";

	if ( num > 20 )
	{
		str += decade[ num / 10 ];
		str += "-";
		num %= 10;
		if ( 0 == num )
			return str;
		str += unit[ num ];
	}
	else if ( num > 10 )
	{
		str += decade1[ num / 10 ];
		str += " ";
	}
	else
	{
		num %= 10;
		if ( 0 == num )
			return str;
		str += unit[ num ];
	}
	
	return str;
	}

void main_study()
{
	long long num;
	std::string str;
	std::cin >> num;
	if ( num < 0 )
	{
		std::cout << "eorro\n";
		return;
	}
	if ( 0 == num )
	{
		std::cout << " zero \n";
		return;
	}

	if ( num / 1000000000 )
	{
		str = translator( num / 1000000000 );
		str += " billion ";
	}
	num %= 1000000000;

	if ( num/ 1000000 )
	{
		str += translator( num / 1000000 );
		str += " million ";
	}
	num %= 1000000;

	if ( num / 1000 )
	{
		str += translator( num / 1000 );
		str += " thousand ";
	}
	num %= 1000;

	str += translator( num );
	std::cout << str;
}
