#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <cmath>
# include <string>
# include <cctype>
# include <cfloat>
# include <climits>
# include <iomanip>
# include <iostream>

# define RESET "\033[0m"
# define RED "\033[1;31m"
# define BLUE "\033[1;34m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define MAGENTA "\033[1;35m"

enum e_type {
	E_SPECIAL = 0,
	E_CHAR = 1,
	E_INT = 2,
	E_FLOAT = 3,
	E_DOUBLE = 4,
	E_UNKNOWN = 5
};

class ScalarConverter {
	private :
		// Constructors
		ScalarConverter( void );
		ScalarConverter( const ScalarConverter &other );

		// Operator Overload
		ScalarConverter	&operator=( const ScalarConverter &other );

		// Destructor
		~ScalarConverter( void );

	public :
		// Static Method
		static void	convert( const std::string &s );
};

// Print Function
void		printSpecial( const std::string &s );
void		printChar( const std::string &s );
void		printInt( const std::string &s );
void		printFloat( const std::string &s );
void		printDouble( const std::string &s );
void		printUnknown( const std::string &s );

// Additional Function
e_type		detectType( const std::string &s );
std::string	trim( const std::string &s );

#endif
