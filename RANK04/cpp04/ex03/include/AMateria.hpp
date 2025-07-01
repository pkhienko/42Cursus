#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <iostream>
# include "ICharacter.hpp"

# define RESET "\033[0m"
# define RED "\033[1;31m"
# define BLUE "\033[1;34m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define MAGENTA "\033[1;35m"

class ICharacter;

class AMateria {
	protected :
		std::string	_type;

	public :
		AMateria( void );
		AMateria( const AMateria &other );
		AMateria( std::string const &type );

		AMateria	&operator=( const AMateria &other );

		virtual ~AMateria( void );

		std::string const	&getType( void ) const;
		virtual AMateria	*clone( void ) const = 0;
		virtual void		use( ICharacter &target );
};

#endif
