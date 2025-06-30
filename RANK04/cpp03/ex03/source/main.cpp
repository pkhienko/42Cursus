#include "DiamondTrap.hpp"

int	main( void )
{
	std::cout << MAGENTA "-------------------- CLAPTRAP --------------------\n" RESET << std::endl;
	{
		ClapTrap a("A");
		ClapTrap b("B");

		a.attack("B");
		a.takeDamage(4);
		a.beRepaired(30);
		a.takeDamage(10);
		a.attack("B");
		b.attack("A");
		b.attack("A");
		b.takeDamage(54);
		b.beRepaired(3);
	}
	std::cout << MAGENTA "--------------------------------------------------\n" RESET << std::endl;

	std::cout << MAGENTA "-------------------- SCAVTRAP --------------------\n" RESET << std::endl;
	{
		ScavTrap a("A");
		ScavTrap b("B");

		a.guardGate();
		a.attack("B");
		a.takeDamage(2);
		a.beRepaired(99);
		a.guardGate();
		b.attack("A");
		b.takeDamage(1024);
		b.takeDamage(2);
	}
	std::cout << MAGENTA "--------------------------------------------------\n" RESET << std::endl;

	std::cout << MAGENTA "-------------------- FRAGTRAP --------------------\n" RESET << std::endl;
	{
		FragTrap a("A");
		FragTrap b("B");

		a.highFivesGuys();
		a.attack("B");
		a.takeDamage(102);
		b.highFivesGuys();
		a.takeDamage(0);
		a.attack("B");

	}
	std::cout << MAGENTA "--------------------------------------------------\n" RESET << std::endl;

	std::cout << MAGENTA "------------------- DIAMONDTRAP ------------------\n" RESET << std::endl;
	{
		DiamondTrap a("A");
		DiamondTrap b("B");
		DiamondTrap c(a);

		a.whoAmI();
		a.beRepaired(23);
		a.attack("C");
		b.whoAmI();
		b.attack("A");
		b.takeDamage(74);
		c.whoAmI();
	}
	std::cout << MAGENTA "--------------------------------------------------\n" RESET << std::endl;
	return (0);
}
