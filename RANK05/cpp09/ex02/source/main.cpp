#include "PmergeMe.hpp"

int	main( int ac, char **av )
{
	try
	{
		PmergeMe	pMergeMe;

		pMergeMe.execute(ac, av);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
