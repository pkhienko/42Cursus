#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

# define RESET "\033[0m"
# define RED "\033[1;31m"
# define BLUE "\033[1;34m"
# define WHITE "\033[1;0m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define MAGENTA "\033[1;35m"

class ClapTrap {
	private :
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_damagePoints;

	public :
		static const unsigned int	DEFAULT_HIT_POINTS;
		static const unsigned int	DEFAULT_ENERGY_POINTS;
		static const unsigned int	DEFAULT_DAMAGE_POINTS;
	
	private :
		void	showStatus( void );

	public :
		ClapTrap( void );
		ClapTrap( std::string name );
		ClapTrap( const ClapTrap &other);
		
		ClapTrap	&operator=( const ClapTrap &other );

		~ClapTrap( void );

		void	attack( const std::string &target );
		void	takeDamage( unsigned int amount );
		void	beRepaired( unsigned int amount );

		std::string	getName( void ) const;
};

#endif
