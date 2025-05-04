#include "Zombie.hpp"

int	main( void )
{
	std::cout << "---------- Stack ----------" << std::endl;
	Zombie	z1("Zombie1");
	Zombie	z2;

	z1.announce();
	z2.announce();
	randomChump("random_Z");

	std::cout << "\n---------- Heap ---------" << std::endl;
	Zombie	*z3 = newZombie("Zombie3");

	z3->announce();
	delete(z3);
	return (0);
}