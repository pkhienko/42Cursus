#include "easyfind.hpp"

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

template <typename T>
typename T::iterator	easyfind( T &container, int n )
{
	typename T::iterator	iter = std::find(container.begin(), container.end(), n);
	
	return (iter == container.end() ? throw NotFoundException() : iter);
}

template <typename T>
typename T::const_iterator	easyfind( const T &container, int n )
{
	typename T::const_iterator	iter = std::find(container.begin(), container.end(), n);
	
	return (iter == container.end() ? throw NotFoundException() : iter);
}

const char	*NotFoundException::what( void ) const throw() { return ("Number not found in container"); }

#endif
