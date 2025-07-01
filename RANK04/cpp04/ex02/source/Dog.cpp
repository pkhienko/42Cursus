#include "Dog.hpp"

Dog::Dog( void ) : Animal()
{
	_type = "Dog";
	std::cout << MAGENTA "Default constructor called : " GREEN "Derived Class" RESET << std::endl;
	std::cout << GREEN " -> " YELLOW << _type << RESET " has been created.\n" << std::endl;
	_brain = new Brain();
}

Dog::Dog( const Dog &other ) : Animal(other)
{
	std::cout << MAGENTA "Copy constructor called : " GREEN "Derived Class" RESET << std::endl;
	std::cout << GREEN " -> " YELLOW << _type << RESET << " has been copied.\n" << std::endl;
	this->_brain = new Brain(*other._brain);
}

Dog	&Dog::operator=( const Dog &other )
{
	std::cout << MAGENTA "Copy assignment operator called : " GREEN "Derived Class" RESET << std::endl;
	std::cout << GREEN " -> " YELLOW << _type << RESET " has been copied.\n" << std::endl;
	if (this == &other)
		return (*this);
	Animal::operator=(other);
	delete _brain;
	this->_brain = new Brain(*other._brain);
	return (*this);
}

Dog::~Dog( void )
{
	std::cout << MAGENTA "Destructor called : " GREEN "Derived Class" RESET << std::endl;
	std::cout << GREEN " -> " YELLOW << _type << RESET " has been destroyed.\n" << std::endl;
	delete _brain;
}

void	Dog::makeSound( void ) const
{
	std::cout << YELLOW << _type << RESET " says: woof woof!" << std::endl;
}

void	Dog::getIdea( int n )
{
	std::string	&idea = _brain->getIdea(n);

	if (n >= 0 && n <= 99)
		std::cout << YELLOW "Dog " RESET "idea[" GREEN << n << RESET "]: " << idea << GREEN " | " RESET "Address: " RED << &idea << RESET << std::endl;
	else
		std::cout << YELLOW "Dog " RESET "idea[" GREEN "0" RESET"]: " << idea << GREEN " | " RESET "Address: " RED << &idea << RESET << std::endl;
}

void	Dog::setIdea( std::string idea, int n ) { _brain->setIdea(idea, n); }
