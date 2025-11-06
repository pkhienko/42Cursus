#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

# include <stdint.h>
# include <iostream>
# include "Data.hpp"

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

class Serialization {
	private :
		// Constructors
		Serialization( void );
		Serialization( const Serialization &other );

		// Operator Overload
		Serialization	&operator=( const Serialization &other );

		// Destructor
		~Serialization( void );

	public :
		// Method
		static uintptr_t serialize( Data *ptr );
		static Data *deserialize( uintptr_t raw );
};

#endif
