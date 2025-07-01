#include "ICharacter.hpp"

ICharacter::ICharacter( void )
{
	// std::cout << MAGENTA "Default constructor called : " GREEN "Base Class" RESET << std::endl;
	// std::cout << GREEN " -> " MAGENTA "ICharacter" RESET " has been created.\n" << std::endl;
}

ICharacter::ICharacter( const ICharacter &other )
{
	// std::cout << MAGENTA "Copy constructor called : " GREEN "Base Class" RESET << std::endl;
	// std::cout << GREEN " -> " MAGENTA "ICharacter" RESET " has been copied.\n" << std::endl;
	*this = other;
}

ICharacter	&ICharacter::operator=( const ICharacter &other )
{
	// std::cout << MAGENTA "Copy assignment operator called : " GREEN "Base Class" RESET << std::endl;
	// std::cout << GREEN " -> " MAGENTA "ICharacter" RESET " has been copied.\n" << std::endl;
	(void)other;
	return (*this);
}

ICharacter::~ICharacter( void )
{
	// std::cout << MAGENTA "Destructor called : " GREEN "Base Class" RESET << std::endl;
	// std::cout << GREEN " -> " MAGENTA "ICharacter" RESET " has been destroyed.\n" << std::endl;
}
