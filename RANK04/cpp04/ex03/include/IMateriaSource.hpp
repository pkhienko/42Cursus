#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include "AMateria.hpp"

class AMateria;
class IMateriaSource;

class IMateriaSource {
	public :
		IMateriaSource( void );
		IMateriaSource( const IMateriaSource &other );

		IMateriaSource	&operator=( const IMateriaSource &other );

		virtual	~IMateriaSource( void );

		virtual void	learnMateria( AMateria * ) = 0;
		virtual AMateria	*createMateria( std::string const &type ) = 0;
};

#endif
