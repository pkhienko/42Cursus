#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <string>
# include <cstdlib>
# include <iostream>
# include <exception>

# define RESET "\033[0m"
# define RED "\033[1;31m"
# define BLUE "\033[1;34m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define MAGENTA "\033[1;35m"

template <typename T>
class Array {
	private :
		T				*_arr;
		unsigned int	_size;

	public :
		// Constructors
		Array( void );
		Array( unsigned int n );
		Array( const Array &other );

		// Operators Overload
		Array			&operator=( const Array &other );
		T				&operator[]( unsigned int n );
		const T			&operator[]( unsigned int n ) const;

		// Destructor
		~Array( void );

		// Method
		unsigned int	size( void ) const;

		// Exceptions
		class OutOfBoundsException : public std::exception {
			public :
				virtual const char	*what( void ) const throw();
		};
};

# include "../source/Array.tpp"

#endif
