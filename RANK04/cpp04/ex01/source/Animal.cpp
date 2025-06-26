#include "Animal.hpp"

Animal::Animal( void ) : _type("Animal")
{
	std::cout << MAGENTA "Default constructor called : " GREEN "Base Class" RESET << std::endl;
	std::cout << GREEN " -> " YELLOW << _type << RESET " has been created.\n" << std::endl;
}

Animal::Animal( const Animal &other ) : _type("Animal")
{
	std::cout << MAGENTA "Copy constructor called : " GREEN "Base Class" RESET << std::endl;
	std::cout << GREEN " -> " YELLOW << _type << RESET << " has been copied.\n" << std::endl;
	*this = other;
}

Animal	&Animal::operator=( const Animal &other )
{
	std::cout << MAGENTA "Copy assignment operator called : " GREEN "Base Class" RESET << std::endl;
	std::cout << GREEN " -> " YELLOW << _type << RESET " has been copied.\n" << std::endl;
	if (this == &other)
		return (*this);
	this->_type = other._type;
	return (*this);
}

Animal::~Animal( void )
{
	std::cout << MAGENTA "Destructor called : " GREEN "Base Class" RESET << std::endl;
	std::cout << GREEN " -> " YELLOW << _type << RESET " has been destroyed.\n" << std::endl;
}

void	Animal::makeSound( void ) const
{
	std::cout << YELLOW << _type << RESET " says: no sound!" << std::endl;
}

std::string	Animal::getType( void ) const { return (_type); }
