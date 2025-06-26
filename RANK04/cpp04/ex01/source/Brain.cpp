#include "Brain.hpp"

Brain::Brain( void )
{
	std::cout << MAGENTA "Default constructor called : " GREEN "Base Class" RESET << std::endl;
	std::cout << GREEN " -> " YELLOW "Brain" RESET " has been created.\n" << std::endl;
	std::srand(std::time(NULL));
	for (int i = 0; i < IDEAS; i++)
		_ideas[i] = generateString();
}

Brain::Brain( const Brain &other )
{
		std::cout << MAGENTA "Copy constructor called : " GREEN "Base Class" RESET << std::endl;
	std::cout << GREEN " -> " YELLOW "Brain" RESET << " has been copied.\n" << std::endl;
	*this = other;
}

Brain	&Brain::operator=( const Brain &other )
{
	std::cout << MAGENTA "Copy assignment operator called : " GREEN "Base Class" RESET << std::endl;
	std::cout << GREEN " -> " YELLOW "Brain" RESET " has been copied.\n" << std::endl;
	if (this == &other)
		return (*this);
	for (int i = 0; i < IDEAS; i++)
		this->_ideas[i] = other._ideas[i];
	return (*this);
}

Brain::~Brain( void )
{
	std::cout << MAGENTA "Destructor called : " GREEN "Base Class" RESET << std::endl;
	std::cout << GREEN " -> " YELLOW "Brain" RESET " has been destroyed.\n" << std::endl;
}

std::string	&Brain::getIdea( int n )
{
	if (n >= 0 && n <= 99)
		return (_ideas[n]);
	std::cout << RED "Error" RESET ": Number must be between 0 - 99, Forcing return index 0" << std::endl;
	return (_ideas[0]);
}

void	Brain::setIdea( std::string idea, int n )
{
	if (n >= 0 && n <= 99)
		_ideas[n] = idea;
	else
		std::cout << RED "ERROR" RESET ": Number must be between 0 -99" << std::endl;
} 

std::string	Brain::generateString( void )
{
	std::string	str;

	const std::string	set = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	for (int i = 0; i < 10; i++)
		str += set[rand() % set.length()];
	return (str);
}