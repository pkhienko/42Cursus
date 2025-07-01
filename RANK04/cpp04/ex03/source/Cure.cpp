#include "Cure.hpp"

Cure::Cure( void ) : AMateria()
{
	_type = "cure";
	// std::cout << MAGENTA "Default constructor called : " GREEN "Derived Class" RESET << std::endl;
	// std::cout << GREEN " -> " MAGENTA "AMateria " YELLOW << _type << RESET " has been created.\n" << std::endl;
}

Cure::Cure( std::string const &type ) : AMateria(type)
{
	// std::cout << MAGENTA "Constructor called : " GREEN "Derived Class" RESET << std::endl;
	// std::cout << GREEN " -> " MAGENTA "AMateria " YELLOW << _type << RESET " has been created.\n" << std::endl;
}

Cure::Cure( const Cure &other ) : AMateria(other)
{
	// std::cout << MAGENTA "Copy constructor called : " GREEN "Derived Class" RESET << std::endl;
	// std::cout << GREEN " -> " MAGENTA "AMateria " YELLOW << _type << RESET << " has been copied.\n" << std::endl;
	*this = other;
}

Cure	&Cure::operator=( const Cure &other )
{
	// std::cout << MAGENTA "Copy assignment operator called : " GREEN "Derived Class" RESET << std::endl;
	// std::cout << GREEN " -> " MAGENTA "AMateria " YELLOW << _type << RESET " has been copied.\n" << std::endl;
	if (this == &other)
		return (*this);
	this->_type = other._type;
	return (*this);
}

Cure::~Cure( void )
{
	// std::cout << MAGENTA "Destructor called : " GREEN "Derived Class" RESET << std::endl;
	// std::cout << GREEN " -> " MAGENTA "AMateria " YELLOW << _type << RESET " has been destroyed.\n" << std::endl;
}

Cure	*Cure::clone( void ) const { return (new Cure()); }

void	Cure::use( ICharacter &target )
{
	std:: cout << MAGENTA "Cure" RESET ": \"* heals " YELLOW << target.getName() << RESET "’s wounds *" << std::endl;
}
