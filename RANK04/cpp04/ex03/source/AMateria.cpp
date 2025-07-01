#include "AMateria.hpp"

AMateria::AMateria( void ) : _type("")
{
	// std::cout << MAGENTA "Default constructor called : " GREEN "Base Class" RESET << std::endl;
	// std::cout << GREEN " -> " MAGENTA "AMateria " YELLOW << _type << RESET " has been created.\n" << std::endl;
}

AMateria::AMateria( std::string const &type ) : _type(type)
{
	// std::cout << MAGENTA "Constructor called : " GREEN "Base Class" RESET << std::endl;
	// std::cout << GREEN " -> " MAGENTA "AMateria " YELLOW << _type << RESET " has been created.\n" << std::endl;
}

AMateria::AMateria( const AMateria &other )
{
	// std::cout << MAGENTA "Copy constructor called : " GREEN "Base Class" RESET << std::endl;
	// std::cout << GREEN " -> " MAGENTA "AMateria " YELLOW << _type << RESET << " has been copied.\n" << std::endl;
	*this = other;
}

AMateria	&AMateria::operator=( const AMateria &other )
{
	// std::cout << MAGENTA "Copy assignment operator called : " GREEN "Base Class" RESET << std::endl;
	// std::cout << GREEN " -> " MAGENTA "AMateria " YELLOW << _type << RESET " has been copied.\n" << std::endl;
	if (this == &other)
		return (*this);
	this->_type = other._type;
	return (*this);
}

AMateria::~AMateria( void )
{
	// std::cout << MAGENTA "Destructor called : " GREEN "Base Class" RESET << std::endl;
	// std::cout << GREEN " -> " MAGENTA "AMateria " YELLOW << _type << RESET " has been destroyed.\n" << std::endl;
}

std::string const	&AMateria::getType( void ) const { return (_type); }

void	AMateria::use( ICharacter &target ) { (void)target; }
