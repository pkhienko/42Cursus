#include "BitcoinExchange.hpp"

int	main( int ac, char **av )
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./btc [Input File]"  << std::endl;
		return (1);
	}
	
	try
	{
		BitcoinExchange	btc;
		btc.run(av[1]);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}
