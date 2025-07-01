#include "Character.hpp"

Character::Character( void )
{
	_tmpCnt = 0;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
		_tmpInventory[i] = NULL;
	// std::cout << MAGENTA "Default constructor called : " GREEN "Derived Class" RESET << std::endl;
	// std::cout << GREEN " -> " MAGENTA "Character " YELLOW << _name << RESET " has been created.\n" << std::endl;
}

Character::Character( std::string const &name )
{
	_name = name;
	_tmpCnt = 0;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
		_tmpInventory[i] = NULL;
	// std::cout << MAGENTA "Constructor called : " GREEN "Derived Class" RESET << std::endl;
	// std::cout << GREEN " -> " MAGENTA "Character " YELLOW << _name << RESET " has been created.\n" << std::endl;
}

Character::Character( const Character &other ) : ICharacter(other)
{
	_name = other._name;
	_tmpCnt = 0;
	for (int i = 0; i < 4; i++)
		_inventory[i] = other._inventory[i] ? other._inventory[i]->clone() : NULL;
	for (int i = 0; i < 100; i++)
		_tmpInventory[i] = NULL;
	// std::cout << MAGENTA "Copy constructor called : " GREEN "Derived Class" RESET << std::endl;
	// std::cout << GREEN " -> " MAGENTA "Character " YELLOW << _name << RESET " has been copied.\n" << std::endl;
}

Character	&Character::operator=( const Character &other )
{
	// std::cout << MAGENTA "Copy assignment operator called : " GREEN "Derived Class" RESET << std::endl;
	// std::cout << GREEN " -> " MAGENTA "Character " YELLOW << _name << RESET " has been copied.\n" << std::endl;
	if (this == &other)
		return (*this);
	for (int i = 0; i < 4; i++)
	{
		delete _inventory[i];
		_inventory[i] = other._inventory[i] ? other._inventory[i]->clone() : NULL;
	}
	for (int i = 0; i < 100; i++)
		delete _tmpInventory[i]; 
	this->_name = other._name;
	this->_tmpCnt = 0;
	return (*this);
}

Character::~Character( void )
{
	for (int i = 0; i < 4; i++)
		delete _inventory[i];
	for (int i = 0; i < 100; i++)
		delete _tmpInventory[i]; 
	// std::cout << MAGENTA "Destructor called : " GREEN "Derived Class" RESET << std::endl;
	// std::cout << GREEN " -> " MAGENTA "Character " YELLOW << _name << RESET " has been destroyed.\n" << std::endl;
}

std::string const	&Character::getName( void ) const { return (_name); }

void	Character::equip( AMateria *m )
{
	if (!m)
	{
		std::cout << RED "ERROR" RESET ": Invalid materia" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m->clone();
			return ;
		}
	}
	std::cout << YELLOW "WARNING" RESET <<": Inventory is full!" << std::endl;
}

void	Character::unequip( int idx )
{
	if (idx >= 0 && idx <= 3 && _inventory[idx])
	{
		if (_tmpCnt < 100)
		{
			_tmpInventory[_tmpCnt++] = _inventory[idx];
			_inventory[idx] = NULL;
		}
		else
			std::cout << YELLOW "WARNING" RESET ": Floor is full!" << std::endl;
	}
	else if (idx < 0 || idx >= 4)
		std::cout << RED "ERROR" RESET ": Invalid index " GREEN << idx << RESET << std::endl;
	else
		std::cout << YELLOW "WARNING" RESET ": Index[" GREEN << idx << RESET "] is empty!" << std::endl;
}

void	Character::use( int idx, ICharacter &target )
{
	if (idx >= 0 && idx <= 3 && _inventory[idx])
		_inventory[idx]->use(target);
	else if (idx < 0 || idx >= 4)
		std::cout << RED "ERROR" RESET ": Invalid index " GREEN << idx << RESET << std::endl;
	else
		std::cout << YELLOW "WARNING" RESET ": Index[" GREEN << idx << RESET "] is empty!" << std::endl;

}
