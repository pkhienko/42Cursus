#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : _type("WrongAnimal")
{
	std::cout << MAGENTA "Default constructor called : " GREEN "Base Class" RESET << std::endl;
	std::cout << GREEN " -> " YELLOW << _type << RESET " has been created.\n" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal &other ) : _type("WrongAnimal")
{
	std::cout << MAGENTA "Copy constructor called : " GREEN "Base Class" RESET << std::endl;
	std::cout << GREEN " -> " YELLOW << _type << RESET << " has been copied.\n" << std::endl;
	*this = other;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &other )
{
	std::cout << MAGENTA "Copy assignment operator called : " GREEN "Base Class" RESET << std::endl;
	std::cout << GREEN " -> " YELLOW << _type << RESET " has been copied.\n" << std::endl;
	if (this == &other)
		return (*this);
	this->_type = other._type;
	return (*this);
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout << MAGENTA "Destructor called : " GREEN "Base Class" RESET << std::endl;
	std::cout << GREEN " -> " YELLOW << _type << RESET " has been destroyed.\n" << std::endl;
}

void	WrongAnimal::makeSound( void ) const
{
	std::cout << YELLOW << _type << RESET " says: no sound!" << std::endl;
}

std::string	WrongAnimal::getType( void ) const { return (_type); }
