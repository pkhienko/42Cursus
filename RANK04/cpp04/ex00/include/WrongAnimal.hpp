#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string.h>

# define RESET "\033[0m"
# define RED "\033[1;31m"
# define BLUE "\033[1;34m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define MAGENTA "\033[1;35m"

class WrongAnimal {
	protected :
		std::string	_type;

	public :
		WrongAnimal( void );
		WrongAnimal( const WrongAnimal &other );

		WrongAnimal	&operator=( const WrongAnimal &other );

		~WrongAnimal( void );

		std::string	getType( void ) const;
		void		makeSound( void ) const;
};

#endif
