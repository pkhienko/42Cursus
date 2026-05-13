#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void ) {}

ScalarConverter::ScalarConverter( const ScalarConverter &other ) { (void)other; }

ScalarConverter	&ScalarConverter::operator=( const ScalarConverter &other )
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter( void ) {}

void ScalarConverter::convert( const std::string &s )
{
	std::string	str = trim(s);
	e_type		type = detectType(str);
	
	std::cout << std::fixed << std::setprecision(1);
	void	(*arr_type[])( const std::string & ) = {
		printSpecial,
		printChar,
		printInt,
		printFloat,
		printDouble,
		printUnknown
	};
	arr_type[type](str);
}
