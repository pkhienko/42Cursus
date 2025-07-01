#include "Ice.hpp"

Ice::Ice( void ) : AMateria()
{
	_type = "ice";
	// std::cout << MAGENTA "Default constructor called : " GREEN "Derived Class" RESET << std::endl;
	// std::cout << GREEN " -> " MAGENTA "AMateria " YELLOW  << _type << RESET " has been created.\n" << std::endl;
}

Ice::Ice( std::string const &type ) : AMateria(type)
{
	// std::cout << MAGENTA "Constructor called : " GREEN "Derived Class" RESET << std::endl;
	// std::cout << GREEN " -> " MAGENTA "AMateria " YELLOW << _type << RESET " has been created.\n" << std::endl;
}

Ice::Ice( const Ice &other ) : AMateria(other)
{
	// std::cout << MAGENTA "Copy constructor called : " GREEN "Derived Class" RESET << std::endl;
	// std::cout << GREEN " -> " MAGENTA "AMateria " YELLOW << _type << RESET << " has been copied.\n" << std::endl;
	*this = other;
}

Ice	&Ice::operator=( const Ice &other )
{
	// std::cout << MAGENTA "Copy assignment operator called : " GREEN "Derived Class" RESET << std::endl;
	// std::cout << GREEN " -> " MAGENTA "AMateria " YELLOW << _type << RESET " has been copied.\n" << std::endl;
	if (this == &other)
		return (*this);
	this->_type = other._type;
	return (*this);
}

Ice::~Ice( void )
{
	// std::cout << MAGENTA "Destructor called : " GREEN "Derived Class" RESET << std::endl;
	// std::cout << GREEN " -> " MAGENTA "AMateria " YELLOW << _type << RESET " has been destroyed.\n" << std::endl;
}

Ice	*Ice::clone( void ) const { return (new Ice()); }

void	Ice::use( ICharacter &target )
{
	
	std:: cout << MAGENTA "Ice" RESET ": \"* shoots an ice bolt at " YELLOW << target.getName() << RESET " *" << std::endl;
}
