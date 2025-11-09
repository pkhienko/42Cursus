#ifndef ARRAY_TPP
# define ARRAY_TPP

template <typename T>
Array<T>::Array( void ) : _arr(NULL), _size(0) {}

template <typename T>
Array<T>::Array( unsigned int n ) : _arr(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array( const Array<T> &other ) : _arr(new T[other._size]), _size(other._size)
{
	for (unsigned int i = 0; i < _size; i++)
		_arr[i] = other._arr[i];
}

template <typename T>
Array<T>	&Array<T>::operator=( const Array<T> &other )
{
	if (this != &other)
	{
		delete [] _arr;
		_size = other._size;
		_arr = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_arr[i] = other._arr[i];
	}
	return (*this);
}

template <typename T>
T	&Array<T>::operator[]( unsigned int n ) { return (n < _size ? _arr[n] : throw Array<T>::OutOfBoundsException()); }

template <typename T>
const T	&Array<T>::operator[]( unsigned int n ) const { return (n < _size ? _arr[n] : throw Array<T>::OutOfBoundsException()); }

template <typename T>
Array<T>::~Array( void ) { delete [] _arr; }

template <typename T>
unsigned int	Array<T>::size( void ) const { return (_size); }

template <typename T>
const char	*Array<T>::OutOfBoundsException::what( void ) const throw()
{
	return ("Index is out of bounds");
}

#endif
