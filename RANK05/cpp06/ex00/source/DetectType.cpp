#include "ScalarConverter.hpp"

static bool	allDigits( const std::string &s, size_t start, size_t end )
{
	if (start >= end)
		return (false);
	while (start < end)
		if (!std::isdigit(static_cast<int>(s[start++])))
			return (false);
	return (true);
}

static bool	isInt( const std::string &s, size_t start, size_t end )	
{
	if (start >= end)
		return (false);
	if (s[start] == '+' || s[start] == '-')
		if (++start >= end)
			return (false);
	return (allDigits(s, start, end)); 
}

static bool	isFloat( const std::string &s, size_t point_pos, size_t end )	
{
	if (end < 2 || s[end - 1] != 'f')
		return (false);
	if (point_pos == std::string::npos)
		return (isInt(s, 0, end - 1));
	return (!(point_pos == 0 || point_pos + 1 >= end - 1 ||
			!isInt(s, 0, point_pos) || !allDigits(s, point_pos + 1, end - 1)));
}

static bool	isDouble( const std::string &s, size_t point_pos, size_t end )	
{
	return (!(end < 3 || point_pos == 0 || point_pos + 1 >= end || point_pos == std::string::npos ||
			!isInt(s, 0, point_pos) || !allDigits(s, point_pos + 1, end)));
}

e_type	detectType( const std::string &s )
{
	size_t	size = s.size();
	
	if (size == 0)
		return (E_UNKNOWN);
	if (s == "nan" || s == "nanf" ||
		s == "-inf" || s == "+inf" ||
		s == "-inff" || s == "+inff")
		return (E_SPECIAL);
	
	int	c = static_cast<int>(s[0]);
 	if (size == 1 && std::isprint(c) && !std::isdigit(c))
		return (E_CHAR);

	size_t	point_pos = s.find('.');
	if (point_pos == std::string::npos && isInt(s, 0, size))
		return (E_INT);
	if (isFloat(s, point_pos, size))
		return (E_FLOAT);
	if (isDouble(s, point_pos, size))
		return (E_DOUBLE);
	return (E_UNKNOWN);	
}
