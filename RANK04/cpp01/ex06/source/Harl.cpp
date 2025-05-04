#include "Harl.hpp"

Harl::Harl( void ) {}

Harl::~Harl( void ) {}

void	Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!\n" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money.\nYou didn’t putenough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming foryears, whereas you started working here just last month.\n" << std::endl;
}

void Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void	Harl::complain( std::string level )
{
	std::string	harl[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i = -1;

	while (++i < 4)
		if (harl[i] == level)
			break ;

	switch (i)
	{
		case DEBUG:
			debug();
			info();
			warning();
			error();
			break;
		case INFO:
			info();
			warning();
			error();
			break;
		case WARNING:
			warning();
			error();
			break;
		case ERROR:
			error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}