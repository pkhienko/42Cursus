#ifndef EASYFIND_TPP
# define EASYFIND_TPP

template <typename T>
typename T::iterator	easyfind( T &container, int n )
{
	typename T::iterator	iter = std::find(container.begin(), container.end(), n);
	
	if (iter == container.end())
		throw NotFoundException();
	return (iter);
}

template <typename T>
typename T::const_iterator	easyfind( const T &container, int n )
{
	typename T::const_iterator	iter = std::find(container.begin(), container.end(), n);
	
	if (iter == container.end())
		throw NotFoundException();
	return (iter);
}

#endif
