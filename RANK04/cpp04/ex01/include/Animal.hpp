#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

# define RESET "\033[0m"
# define RED "\033[1;31m"
# define BLUE "\033[1;34m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define MAGENTA "\033[1;35m"

class Animal {
	protected :
		std::string	_type;

	public :
		Animal( void );
		Animal( const Animal &other );

		Animal	&operator=( const Animal &other );

		virtual ~Animal( void );

		std::string		getType( void ) const;
		virtual void	makeSound ( void ) const;
};

#endif
