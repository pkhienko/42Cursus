#include "RPN.hpp"

int	main( int ac, char **av )
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./RPN [Input File]"  << std::endl;
		return (1);
	}
	
	try
	{
		RPN	rpn;
		rpn.execute(av[1]);
	}
	catch(const std::exception &e)
	{
		std::cerr << RED << "Error" RESET ": " << e.what() << std::endl;
	}
	
	return (0);
}
