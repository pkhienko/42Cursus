#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource( void )
{
	// std::cout << MAGENTA "Default constructor called : " GREEN "Base Class" RESET << std::endl;
	// std::cout << GREEN " -> " MAGENTA "IMateriaSource" RESET " has been created.\n" << std::endl;
}

IMateriaSource::IMateriaSource( const IMateriaSource &other )
{
	// std::cout << MAGENTA "Copy constructor called : " GREEN "Base Class" RESET << std::endl;
	// std::cout << GREEN " -> " MAGENTA "IMateriaSource" RESET " has been copied.\n" << std::endl;
	*this = other;
}

IMateriaSource	&IMateriaSource::operator=( const IMateriaSource &other )
{
	// std::cout << MAGENTA "Copy assignment operator called : " GREEN "Base Class" RESET << std::endl;
	// std::cout << GREEN " -> " MAGENTA "IMateriaSource" RESET " has been copied.\n" << std::endl;
	(void)other;
	return (*this);
}

IMateriaSource::~IMateriaSource( void )
{
	// std::cout << MAGENTA "Destructor called : " GREEN "Base Class" RESET << std::endl;
	// std::cout << GREEN " -> " MAGENTA "IMateriaSource" RESET " has been destroyed.\n" << std::endl;
}
