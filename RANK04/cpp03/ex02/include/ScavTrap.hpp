#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public :
		static const unsigned int	DEFAULT_HIT_POINTS;
		static const unsigned int	DEFAULT_ENERGY_POINTS;
		static const unsigned int	DEFAULT_DAMAGE_POINTS;

	private :
		void	showStatus( void );

	public :
		ScavTrap( void );
		ScavTrap( std::string name );
		ScavTrap( const ScavTrap &other );

		ScavTrap	&operator=( const ScavTrap &other );

		~ScavTrap( void );

		void	guardGate( void );
		void	attack( const std::string &target );
};

#endif
