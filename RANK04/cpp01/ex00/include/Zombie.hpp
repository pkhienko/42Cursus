#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie {
	private:
		std::string	_name;

	public:
		Zombie( void );
		Zombie( std::string name );
		~Zombie( void );
		
		void	announce( void );
};
	
void	randomChump( std::string name );
Zombie	*newZombie( std::string name );

#endif