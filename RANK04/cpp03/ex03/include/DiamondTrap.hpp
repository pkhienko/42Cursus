#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	private :
		std::string	_name;
	
	private :
		void	showStatus( void );

	public :
		DiamondTrap( void );
		DiamondTrap( std::string name );
		DiamondTrap( const DiamondTrap &other );

		DiamondTrap	&operator=( const DiamondTrap &other );

		~DiamondTrap( void );

		void	whoAmI( void );
};

#endif
