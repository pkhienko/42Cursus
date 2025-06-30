#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ScavTrap.hpp"

class FragTrap : public ClapTrap {
	public :
		static const unsigned int	DEFAULT_HIT_POINTS;
		static const unsigned int	DEFAULT_ENERGY_POINTS;
		static const unsigned int	DEFAULT_DAMAGE_POINTS;

	private :
		void	showStatus( void );

	public :
		FragTrap( void );
		FragTrap( std::string name );
		FragTrap( const FragTrap &other );

		FragTrap	&operator=( const FragTrap &other );

		~FragTrap( void );

		void	highFivesGuys( void );
};

#endif
