#include "Zombie.hpp"

int	main( void )
{
	Zombie	*zHorde;
	int		N = 4;

	zHorde = zombieHorde(N, "Horde");
	for (int i = 0; i < N; i++)
	{
		std::cout << "[" << i << "] [" << &zHorde[i] << "] -> ";
		zHorde[i].announce();
	}
	delete[] zHorde;
	return (0);
}