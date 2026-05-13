#include "ScalarConverter.hpp"

static void	handleChar( long l )
{
	std::cout << "char: ";
	if (l < 0 || l > 127)
		std::cout << "impossible" << std::endl;
	else if (std::isprint(static_cast<int>(l)))
		std::cout << "'" << static_cast<char>(l) << "'" << std::endl;
	else 
		std::cout << "Non displayable" << std::endl;
}

static void	handleInt( long l )
{
	std::cout << "int: ";
	if (l < INT_MIN || l > INT_MAX)
        std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(l) << std::endl;
}

static void	handleFloat( double d, float f )
{
	std::cout << "float: ";
	if (d < -FLT_MAX || d > FLT_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << f << 'f' << std::endl;
}

void	printUnknown( const std::string &s )
{
	(void)s;
	std::cout << RED "Error: " YELLOW "Invalid type of {Char, Integer, Float, Double}" RESET << std::endl;
}

void	printSpecial( const std::string &s )
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	if (s == "+inf" || s == "+inff" || s == "-inf" || s == "-inff")
	{
		char	c = static_cast<char>(s[0]);
		std::cout << "float: " << (c == '-' ? '-' : '+') << "inff" << std::endl;
		std::cout << "double: " << (c == '-' ? '-' : '+') << "inf" << std::endl;
	}
	else if (s == "nan" || s == "nanf")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
}

void	printChar( const std::string &s )
{
	char	c = static_cast<char>(s[0]);
	
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << 'f' << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void	printInt( const std::string &s )
{
	long	l = strtol(s.c_str(), NULL, 10);

	handleChar(l);
	handleInt(l);
	std::cout << "float: " << static_cast<float>(l) << 'f' << std::endl;
	std::cout << "double: " << static_cast<double>(l) << std::endl;
}

void	printFloat( const std::string &s )
{
	double	d = strtod(s.c_str(), NULL);
	float	f = static_cast<float>(d);
	long	l = static_cast<long>(f);

	handleChar(l);
	handleInt(l);
	handleFloat(d, f);
	std::cout << "double: " << d << std::endl;
}

void	printDouble( const std::string &s )
{
	double				d = strtod(s.c_str(), NULL);
	float				f = static_cast<float>(d);
	long				l = static_cast<long>(f);

	handleChar(l);
	handleInt(l);
	handleFloat(d, f);
	std::cout << "double: ";
	if (d < -DBL_MAX || d > DBL_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << d << std::endl;
}
