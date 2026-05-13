#include "ScalarConverter.hpp"

std::string	trim( const std::string &s )
{
	size_t	start = 0, end = s.size();

	if (end == 1 && std::isspace(static_cast<int>(s[start])))
		return (s);
	while (start < end && std::isspace(static_cast<int>(s[start])))
		start++;
	while (end > start && std::isspace(static_cast<int>(s[end - 1])))
		end--;
	return (s.substr(start, end - start));
}
