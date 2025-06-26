#include "Cat.hpp"

Cat::Cat( void ) : Animal()
{
	_type = "Cat";
	std::cout << MAGENTA "Default constructor called : " GREEN "Derived Class" RESET << std::endl;
	std::cout << GREEN " -> " YELLOW << _type << RESET " has been created.\n" << std::endl;
}

Cat::Cat( const Cat &other ) : Animal(other)
{
	std::cout << MAGENTA "Copy constructor called : " GREEN "Derived Class" RESET << std::endl;
	std::cout << GREEN " -> " YELLOW << _type << RESET << " has been copied.\n" << std::endl;
	*this = other;
}

Cat	&Cat::operator=( const Cat &other )
{
	std::cout << MAGENTA "Copy assignment operator called : " GREEN "Derived Class" RESET << std::endl;
	std::cout << GREEN " -> " YELLOW << _type << RESET " has been copied.\n" << std::endl;
	if (this == &other)
		return (*this);
	_type = other._type;
	return (*this);
}

Cat::~Cat( void )
{
	std::cout << MAGENTA "Destructor called : " GREEN "Derived Class" RESET << std::endl;
	std::cout << GREEN " -> " YELLOW << _type << RESET " has been destroyed.\n" << std::endl;
}

void	Cat::makeSound( void ) const
{
	std::cout << YELLOW << _type << RESET " says: meow meow!" << std::endl;
}
