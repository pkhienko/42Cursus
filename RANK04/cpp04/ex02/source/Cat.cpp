#include "Cat.hpp"

Cat::Cat( void ) : Animal()
{
	_type = "Cat";
	std::cout << MAGENTA "Default constructor called : " GREEN "Derived Class" RESET << std::endl;
	std::cout << GREEN " -> " YELLOW << _type << RESET " has been created.\n" << std::endl;
	_brain = new Brain();
}

Cat::Cat( const Cat &other ) : Animal(other)
{
	std::cout << MAGENTA "Copy constructor called : " GREEN "Derived Class" RESET << std::endl;
	std::cout << GREEN " -> " YELLOW << _type << RESET << " has been copied.\n" << std::endl;
	this->_brain = new Brain(*other._brain);
}

Cat	&Cat::operator=( const Cat &other )
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

Cat::~Cat( void )
{
	std::cout << MAGENTA "Destructor called : " GREEN "Derived Class" RESET << std::endl;
	std::cout << GREEN " -> " YELLOW << _type << RESET " has been destroyed.\n" << std::endl;
	delete _brain;
}

void	Cat::makeSound( void ) const
{
	std::cout << YELLOW << _type << RESET " says: meow meow!" << std::endl;
}

void	Cat::getIdea( int n )
{
	std::string	&idea = _brain->getIdea(n);

	if (n >= 0 && n <= 99)
		std::cout << YELLOW "Cat " RESET "idea[" GREEN << n << RESET "]: " << idea << GREEN " | " RESET "Address: "  RED << &idea << RESET << std::endl;
	else
		std::cout << YELLOW "Cat " RESET "idea[" GREEN "0" RESET "]: " << idea << GREEN " | " RESET "Address: " RED << &idea << RESET<< std::endl;
}

void	Cat::setIdea( std::string idea, int n ) { _brain->setIdea(idea, n); }
