#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void )
{
	for (int i = 0; i < 4; i++)
		_templates[i] = NULL;
	// std::cout << MAGENTA "Default constructor called : " GREEN "Derived Class" RESET << std::endl;
	// std::cout << GREEN " -> " MAGENTA "MateriaSource " RESET " has been created.\n" << std::endl;
}

MateriaSource::MateriaSource( const MateriaSource &other ) : IMateriaSource(other)
{
	for (int i = 0; i < 4; i++)
		_templates[i] = NULL;
	// std::cout << MAGENTA "Copy constructor called : " GREEN "Derived Class" RESET << std::endl;
	// std::cout << GREEN " -> " MAGENTA "MateriaSource " RESET " has been copied.\n" << std::endl;
	*this = other;
}

MateriaSource	&MateriaSource::operator=( const MateriaSource &other )
{
	// std::cout << MAGENTA "Copy assignment operator called : " GREEN "Derived Class" RESET << std::endl;
	// std::cout << GREEN " -> " MAGENTA "MateriaSource " RESET " has been copied.\n" << std::endl;
	if (this == &other)
		return (*this);
	for (int i = 0; i < 4; i++)
		_templates[i] = other._templates[i];
	return (*this);
}

MateriaSource::~MateriaSource( void )
{
	for (int i = 0; i < 4; i++)
		delete _templates[i];
	// std::cout << MAGENTA "Destructor called : " GREEN "Derived Class" RESET << std::endl;
	// std::cout << GREEN " -> " MAGENTA "MateriaSource " RESET " has been destroyed.\n" << std::endl;
}

void	MateriaSource::learnMateria( AMateria *m )
{
	if (!m)
	{
		std::cout << RED "ERROR" RESET ": Invalid materia" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!_templates[i])
		{
			_templates[i] = m->clone();
			delete m;
			return ;
		}
	}
	std::cout << YELLOW "WARNING" RESET <<": Inventory is full!" << std::endl;
}

AMateria	*MateriaSource::createMateria( std::string const &type )
{
	for (int i = 0; i < 4; i++)
	{
		if (_templates[i] && _templates[i]->getType() == type)
			return (_templates[i]->clone());
	}
	std::cout << YELLOW "WARNING" RESET << ": Can't create materia " YELLOW << type << RESET << std::endl;
	return (0);
}
