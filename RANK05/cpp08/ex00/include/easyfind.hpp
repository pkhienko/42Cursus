#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <list>
# include <deque>
# include <vector>
# include <string>
# include <iostream>
# include <algorithm>
# include <exception>

# define RESET "\033[0m"
# define RED "\033[1;31m"
# define BLUE "\033[1;34m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define MAGENTA "\033[1;35m"

template <typename T>
typename T::iterator	easyfind( T &container, int n );

template <typename T>
typename T::const_iterator	easyfind( const T &container, int n );

class NotFoundException : public std::exception {
	public :
		virtual const char	*what( void ) const throw();
};

# include "../source/easyfind.tpp"

#endif
