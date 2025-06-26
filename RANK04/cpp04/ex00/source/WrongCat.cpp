#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal()
{
	_type = "WrongCat";
	std::cout << MAGENTA "Default constructor called : " GREEN "Derived Class" RESET << std::endl;
	std::cout << GREEN " -> " YELLOW << _type << RESET " has been created.\n" << std::endl;
}

WrongCat::WrongCat( const WrongCat &other ) : WrongAnimal(other)
{
	std::cout << MAGENTA "Copy constructor called : " GREEN "Derived Class" RESET << std::endl;
	std::cout << GREEN " -> " YELLOW << _type << RESET << " has been copied.\n" << std::endl;
	*this = other;
}

WrongCat	&WrongCat::operator=(const WrongCat &other )
{
	std::cout << MAGENTA "Copy assignment operator called : " GREEN "Derived Class" RESET << std::endl;
	std::cout << GREEN " -> " YELLOW << _type << RESET " has been copied.\n" << std::endl;
	if (this == &other)
		return (*this);
	this->_type = other._type;
	return (*this);
}

WrongCat::~WrongCat( void )
{
	std::cout << MAGENTA "Destructor called : " GREEN "Derived Class" RESET << std::endl;
	std::cout << GREEN " -> " YELLOW << _type << RESET " has been destroyed.\n" << std::endl;
}

void	WrongCat::makeSound( void ) const
{
	std::cout << YELLOW << _type << RESET " says: no sound!" << std::endl;
}

std::string	WrongCat::getType( void ) const { return (_type); }
