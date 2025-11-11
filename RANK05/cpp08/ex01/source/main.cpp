#include "Span.hpp"

int	main( void )
{
	std::cout << std::endl << MAGENTA "--- Subject Test: Small Container (Size: 5) ---" RESET << std::endl;
	Span	sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << YELLOW "Shortest Span" RESET ": " << sp.shortestSpan() << std::endl;
	std::cout << YELLOW "Longest Span" RESET ": " << sp.longestSpan() << std::endl;

	std::cout << std::endl << MAGENTA "--- Test 1: Container is full ---" RESET << std::endl;
	try
	{
		sp.addNumber(99);
	}
	catch(const std::exception &e)
	{
		std::cerr << RED << e.what() << std::endl;
	}

	std::cout << std::endl << MAGENTA "--- Test 2: No span (Distance) ---" RESET << std::endl;
	Span	sp2 = Span(0);
	Span	sp3 = Span(1);

	try
	{
		sp3.addNumber(9999);
		std::cout << YELLOW "Shortest Span" RESET ": " << sp2.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << std::endl;
	}
	try
	{
		std::cout << YELLOW "Longest Span" RESET ": " << sp3.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << std::endl;
	}
	
	std::cout << std::endl << MAGENTA "--- Test 3: Small Container (Size: 2) - (MIN, MAX) ---" RESET << std::endl;
	Span	sp4 = Span(2);

	try
	{
		sp4.addNumber(MIN_INT);
		sp4.addNumber(MAX_INT);
		std::cout << YELLOW "Shortest Span" RESET ": " << sp4.shortestSpan() << std::endl;
		std::cout << YELLOW "Longest Span" RESET ": " << sp4.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << std::endl;
	}

	std::cout << std::endl << MAGENTA "--- Test 4: Large Container (Size: 1_000_000) ---" RESET << std::endl;
	Span	sp5 = Span(1000000);
	std::vector<int> vec;

	std::srand(static_cast<unsigned int>(std::time(NULL)));
	for (int i = 0; i < 1000000; i++)
		vec.push_back(std::rand() % MAX_INT);
	try
	{
		sp5.addNumber(vec.begin(), vec.end());
		std::cout << YELLOW "Shortest Span" RESET ": " << sp5.shortestSpan() << std::endl;
		std::cout << YELLOW "Longest Span" RESET ": " << sp5.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << std::endl;
	}

	return (0);
}
