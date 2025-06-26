#include "ScavTrap.hpp"

int	main( void )
{
	ClapTrap	a("A");
	ScavTrap	b("B");
	ScavTrap	c;

	c.guardGate();
	a.attack(b.getName());
	b.takeDamage(20);
	b.attack(c.getName());
	c.takeDamage(5);
	a.takeDamage(2);
	a.beRepaired(1);
	b.attack(a.getName());
	a.takeDamage(8);
	c.attack(b.getName());
	b.takeDamage(40);
	a.beRepaired(15);
	b.guardGate();
	b.takeDamage(100);
	b.takeDamage(10);
	c.beRepaired(40);

	return (0);
}