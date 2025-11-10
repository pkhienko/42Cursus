#ifndef WHATEVER__HPP
# define WHATEVER__HPP

# include <string>
# include <iostream>

# define RESET "\033[0m"
# define RED "\033[1;31m"
# define BLUE "\033[1;34m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define MAGENTA "\033[1;35m"

template <typename T>
void	swap( T &a, T &b )
{
	T c = a;
	a = b;
	b = c;
}

template <typename T>
T	min( const T &a, const T &b )
{
	if (a == b)
		return (b);
	return (a < b ? a : b);
}

template <typename T>
T	max( const T &a, const T &b)
{
	if (a == b)
		return (b);
	return (a > b ? a : b);
}

#endif
