#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <sstream>
# include <iostream>
# include <algorithm>
# include <stdexcept>

# define RESET "\033[0m"
# define RED "\033[1;31m"
# define BLUE "\033[1;34m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define MAGENTA "\033[1;35m"

class RPN {
	private :
		std::stack<int>	_stack;

		// Methods
		bool	isOperator( const char &op ) const;
		int		calculate( int a, int b, char op) const;

	public :
		// Constructors
		RPN( void );
		RPN( const RPN &other );

		// Operators Overload
		RPN	&operator=( const RPN &other );

		// Destructor
		~RPN( void );

		// Method
		void	execute( const std::string &expression );
};

#endif
