#include "ClapTrap.hpp"

const unsigned int	ClapTrap::DEFAULT_HIT_POINTS = 10;
const unsigned int	ClapTrap::DEFAULT_ENERGY_POINTS = 10;
const unsigned int	ClapTrap::DEFAULT_DAMAGE_POINTS = 0;

ClapTrap::ClapTrap( void ) : _name("NONE"), _hitPoints(DEFAULT_HIT_POINTS), _energyPoints(DEFAULT_ENERGY_POINTS), _damagePoints(DEFAULT_DAMAGE_POINTS)
{
	std::cout << MAGENTA << "Default constructor called" << RESET << std::endl;
	std::cout << GREEN << " -> " RESET << "ClapTrap " << YELLOW << _name << RESET << " has been created.\n" << std::endl;
}

ClapTrap::ClapTrap( std::string name ) : _name(name), _hitPoints(DEFAULT_HIT_POINTS), _energyPoints(DEFAULT_ENERGY_POINTS), _damagePoints(DEFAULT_DAMAGE_POINTS)
{
	std::cout << MAGENTA << "Constructor called" << RESET << std::endl;
	std::cout << GREEN << " -> " RESET << "ClapTrap " << YELLOW << _name << RESET << " has been created.\n" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &other )
{
	std::cout << MAGENTA << "Copy constructor called" << RESET << std::endl;
	std::cout << GREEN << " -> " RESET << "ClapTrap " << YELLOW << _name << RESET << " has been copied.\n" << std::endl;
	*this = other;
}

ClapTrap	&ClapTrap::operator=( const ClapTrap &other )
{
	std::cout << MAGENTA << "Copy assignment operator called " << RESET << std::endl;
	std::cout << GREEN << " -> " RESET << "ClapTrap " << YELLOW << _name << RESET << " has been copied.\n" << std::endl;
	if (this == &other)
		return (*this);
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_damagePoints = other._damagePoints;
	return (*this);
}

ClapTrap::~ClapTrap( void )
{
	std::cout << MAGENTA << "Destructor called" << RESET << std::endl;
	std::cout << GREEN << " -> " RESET << "ClapTrap " << YELLOW << _name << RESET << " has been destroyed.\n" << std::endl;
}

void	ClapTrap::attack( const std::string &target )
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		_energyPoints--;
		std::cout << "ClapTrap " << YELLOW << _name << RESET << " attacks " << YELLOW << target << RESET <<
			", causing " << RED << _damagePoints << RESET << " points of damage!" << std::endl;
	}
	else if (_energyPoints <= 0)
		std::cout << "ClapTrap " << YELLOW << _name << RESET << " tries to attack " << YELLOW << target << RESET <<
			", but has no more energy points left!" << std::endl;
	else
		std::cout << "ClapTrap " << YELLOW << _name << RESET << " tries to attack " << YELLOW << target << RESET <<
			", but it's already dead!" << std::endl;
	showStatus();
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	if (_hitPoints > 0)
	{
		if (_hitPoints >= amount)
			_hitPoints -= amount;
		else
			_hitPoints = 0;
		std::cout << "ClapTrap " << YELLOW << _name << RESET << " has taken " <<
			RED << amount << RESET << " damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << YELLOW << _name << RESET <<
			" can't take damage because it's already dead!" << std::endl;
	showStatus();
}	

void	ClapTrap::beRepaired( unsigned int amount )
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		_energyPoints--;
		if (_hitPoints + amount > DEFAULT_HIT_POINTS)
			_hitPoints = DEFAULT_HIT_POINTS;
		else
			_hitPoints += amount;
		std::cout << "ClapTrap " << YELLOW << _name << RESET << " regains " <<
			GREEN << amount << RESET << " hit points!" << std::endl;
	}
	else if (_energyPoints <= 0)
		std::cout << "ClapTrap " << YELLOW << _name << RESET << 
			" tries to regain hit points, but has no more energy points left!" << std::endl;
	else
		std::cout << "ClapTrap " << YELLOW << _name << RESET <<
			" can't regain hit points because it's already dead!" << std::endl;
	showStatus();
}

void	ClapTrap::showStatus( void )
{
	std::string	color;

	color = _hitPoints > DEFAULT_HIT_POINTS / 2 ? GREEN : YELLOW;
	std::cout << GREEN << " -> " RESET << "HP: " << (_hitPoints == 0 ? RED : color) << _hitPoints << 
		WHITE"/" << GREEN << DEFAULT_HIT_POINTS << RESET << (_hitPoints == 0 ? RED"\t{DEAD}" : GREEN"\t{ALIVE}") << RESET << std::endl;
	color = _energyPoints > DEFAULT_ENERGY_POINTS / 2 ? GREEN : YELLOW;
	std::cout << GREEN << " -> " RESET << "EP: " << (_energyPoints == 0 ? RED : color) << _energyPoints << 
		WHITE"/" << GREEN << DEFAULT_ENERGY_POINTS << RESET << std::endl;
	std::cout << GREEN << " -> " RESET << "DM: " << (_damagePoints == 0 ? RED : GREEN) << _damagePoints << RESET << "\n" << std::endl;
}

std::string	ClapTrap::getName( void ) const { return (_name); }
