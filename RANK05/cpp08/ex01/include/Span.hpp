#ifndef SPAN_HPP
# define SPAN_HPP

# include <ctime>
# include <vector>
# include <limits>
# include <cstdlib>
# include <iostream>
# include <algorithm>
# include <exception>

# define RESET "\033[0m"
# define RED "\033[1;31m"
# define BLUE "\033[1;34m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define MAGENTA "\033[1;35m"

# define MIN_INT std::numeric_limits<int>::min()
# define MAX_INT std::numeric_limits<int>::max()
# define MIN_LONG std::numeric_limits<long>::min()
# define MAX_LONG std::numeric_limits<long>::max()

typedef	std::vector<int> t_vector;
typedef	std::vector<int>::iterator t_vector_iter;

class Span  {
	private :
		unsigned int	_N;
		t_vector		_vector;

	public :
		// Constructors
		Span( void );
		Span( unsigned int n );
		Span( const Span &other );

		// Operators Overload
		Span	&operator=( const Span &other );

		// Destructor
		~Span( void );

		// Methods
		void	addNumber( int n );
		long	longestSpan( void );
		long	shortestSpan( void );
		void	addNumber( t_vector_iter begin, t_vector_iter end );

		// Exception
		class NoSpanFoundException : public std::exception {
			virtual const char	*what( void ) const throw();
		};
		class ContainerIsFullException : public std::exception {
			virtual const char	*what( void ) const throw();
		};
};

#endif
