#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter {
	private :
		std::string	_name;
		AMateria	*_inventory[4];
		AMateria	*_tmpInventory[100];
		int		_tmpCnt;
		
	public :
		Character( void );
		Character( const Character &other );
		Character( std::string const &name );

		Character	&operator=( const Character &other );

		~Character( void );

		std::string const &getName( void ) const;
		void equip( AMateria *m );
		void unequip( int idx );
		void use( int idx, ICharacter &target );
};

#endif
