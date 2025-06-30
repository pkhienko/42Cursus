#include "ClapTrap.hpp"

int	main( void )
{
	ClapTrap	a;
	ClapTrap	b("B");

	b.attack(a.getName());
	a.takeDamage(6);
	b.beRepaired(1);
	a.takeDamage(100);
	a.attack(b.getName());
	b.takeDamage(2);
	
	return (0);
}
