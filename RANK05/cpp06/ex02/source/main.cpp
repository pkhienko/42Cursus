#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate( void )
{
	int	random = std::rand() % 3;

	if (random == 0)
	{
		std::cout << GREEN "Generated: " YELLOW "A" << std::endl;
		return (new A());
	}
	else if (random == 1)
	{
		std::cout << GREEN "Generated: " YELLOW "B" << std::endl;
		return (new B());
	}
	else if (random == 2)
	{
		std::cout << GREEN "Generated: " YELLOW "C" << std::endl;
		return (new C());
	}
	return (NULL);
}

void	identify(Base *p)
{
	std::cout << MAGENTA "  Identify" RESET " (Pointer): " YELLOW;

	if (dynamic_cast<A *>(p))
		std::cout << "A" RESET << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" RESET << std::endl;		
	else if (dynamic_cast<C *>(p))
		std::cout << "C" RESET << std::endl;
}

void	identify(Base &p)
{
	std::cout << MAGENTA "  Identify" RESET " (Referenced): " YELLOW;

	try
	{
		dynamic_cast<A &>(p);
		std::cout << "A" RESET << std::endl;
		return ;
	}
	catch(const std::exception &e) {}
	try
	{
		dynamic_cast<B &>(p);
		std::cout << "B" RESET << std::endl;
		return ;
	}
	catch(const std::exception &e) {}
	try
	{
		dynamic_cast<C &>(p);
		std::cout << "C" RESET << std::endl;
	}
	catch(const std::exception &e) {}
}

int	main( void )
{
	std::cout << MAGENTA << std::endl << "========= Test Identify Real Type =========" << RESET << std::endl;

	std::srand(static_cast<unsigned int>(std::time(NULL)));
	std::cout << BLUE << std::endl << "Random Loop 5 Times" << RESET << std::endl;
	for (int i = 0; i < 5; i++)
	{
		Base	*ptr = generate();
		identify(ptr);
		identify(*ptr);
		delete ptr;
	}

	std::cout << MAGENTA << std::endl << "========= End of Tests =========" << RESET << std::endl;
	return (0);
}
