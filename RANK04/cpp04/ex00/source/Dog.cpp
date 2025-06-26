#include "Dog.hpp"

Dog::Dog( void ) : Animal()
{
	_type = "Dog";
	std::cout << MAGENTA "Default constructor called : " GREEN "Derived Class" RESET << std::endl;
	std::cout << GREEN " -> " YELLOW << _type << RESET " has been created.\n" << std::endl;
}

Dog::Dog( const Dog &other ) : Animal(other)
{
	std::cout << MAGENTA "Copy constructor called : " GREEN "Derived Class" RESET << std::endl;
	std::cout << GREEN " -> " YELLOW << _type << RESET << " has been copied.\n" << std::endl;
	*this = other;
}

Dog	&Dog::operator=( const Dog &other )
{
	std::cout << MAGENTA "Copy assignment operator called : " GREEN "Derived Class" RESET << std::endl;
	std::cout << GREEN " -> " YELLOW << _type << RESET " has been copied.\n" << std::endl;
	if (this == &other)
		return (*this);
	_type = other._type;
	return (*this);
}

Dog::~Dog( void )
{
	std::cout << MAGENTA "Destructor called : " GREEN "Derived Class" RESET << std::endl;
	std::cout << GREEN " -> " YELLOW << _type << RESET " has been destroyed.\n" << std::endl;
}

void	Dog::makeSound( void ) const
{
	std::cout << YELLOW << _type << RESET " says: woof woof!" << std::endl;
}
