#include "easyfind.hpp"

template <typename T>
static void	testContainer( T &container, int n, std::string name )
{
	try
	{
		typename T::value_type	v = *easyfind(container, n);
		std::cout << YELLOW "[" BLUE << name << YELLOW "]" GREEN " FOUND" RESET ": " << v << std::endl; 
	}
	catch(const std::exception &e)
	{
		std::cout << YELLOW "[" BLUE << name << YELLOW "]" RESET ": " RED << e.what() << std::endl; 
	}

}

int	main( void )
{
	std::cout << std::endl << MAGENTA "--- List (Non-Const) ---" RESET << std::endl;
	std::list<int>	list_nc;
	for (int i = 0; i <= 5; i++)
		list_nc.push_back(i * 10);
	testContainer(list_nc, 50, "List");
	testContainer(list_nc, 99, "List");

	std::cout << std::endl << MAGENTA "--- Vector (Non-Const) ---" RESET << std::endl;
	std::vector<int>	vec_nc;
	for (int i = 0; i <= 10; i++)
		vec_nc.push_back(i * 2);
	testContainer(vec_nc, 10, "Vector");
	testContainer(vec_nc, 19, "Vector");

	std::cout << std::endl << MAGENTA "--- Deque (Non-Const) ---" RESET << std::endl;
	std::deque<int>	deque_nc;
	for (int i = 0; i <= 5; i++)
		deque_nc.push_back(-i);
	testContainer(deque_nc, -4, "Deque");
	testContainer(deque_nc, -9999, "Deque");

	std::cout << std::endl << MAGENTA "--- List (Const) ---" RESET << std::endl;
	const std::list<int>	list_c(list_nc);
	testContainer(list_c, 30, "List");
	testContainer(list_c, 49, "List");

	std::cout << std::endl << MAGENTA "--- Vector (Const) ---" RESET << std::endl;
	const std::vector<int>	vec_c(vec_nc);
	testContainer(vec_c, 18, "Vector");
	testContainer(vec_c, -1, "Vector");

	std::cout << std::endl << MAGENTA "--- Deque (Const) ---" RESET << std::endl;
	const std::deque<int>	deque_c(deque_nc);
	testContainer(deque_c, 0, "Deque");
	testContainer(deque_c, 123, "Deque");
	
	return (0);
}
