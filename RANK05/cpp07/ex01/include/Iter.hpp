#ifndef ITER_HPP
# define ITER_HPP

# include <string>
# include <iostream>

# define RESET "\033[0m"
# define RED "\033[1;31m"
# define BLUE "\033[1;34m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define MAGENTA "\033[1;35m"

template <typename T_Array, typename T_Function>
void	iter( T_Array *arr, const size_t length, T_Function func )
{
	for (size_t i = 0; i < length; i++)
		func(arr[i]);
}

#endif
