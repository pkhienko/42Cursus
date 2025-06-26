#include "ScavTrap.hpp"

const unsigned int	ScavTrap::DEFAULT_HIT_POINTS = 100;
const unsigned int	ScavTrap::DEFAULT_ENERGY_POINTS = 50;
const unsigned int	ScavTrap::DEFAULT_DAMAGE_POINTS = 20;

ScavTrap::ScavTrap( void ) : ClapTrap()
{
	_hitPoints = DEFAULT_HIT_POINTS;
	_energyPoints = DEFAULT_ENERGY_POINTS;
	_damagePoints = DEFAULT_DAMAGE_POINTS;
	std::cout << GREEN << " -> " RESET << "ScavTrap " << YELLOW << _name << RESET << " has been created.\n" << std::endl;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name)
{
	_hitPoints = DEFAULT_HIT_POINTS;
	_energyPoints = DEFAULT_ENERGY_POINTS;
	_damagePoints = DEFAULT_DAMAGE_POINTS;
	std::cout << GREEN << " -> " RESET << "ScavTrap " << YELLOW << _name << RESET << " has been created.\n" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap &other ) : ClapTrap(other)
{
	std::cout << GREEN << " -> " RESET << "ScavTrap " << YELLOW << _name << RESET << " has been copied.\n" << std::endl;
}

ScavTrap	&ScavTrap::operator=( const ScavTrap &other )
{
	std::cout << MAGENTA << "Copy assignment operator called " << RESET << std::endl;
	std::cout << GREEN << " -> " RESET << "ScavTrap " << YELLOW << _name << RESET << " has been copied.\n" << std::endl;
	if (this == &other)
		return (*this);
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_damagePoints = other._damagePoints;
	return (*this);
}

void	ScavTrap::attack( const std::string &target )
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		_energyPoints--;
		std::cout << "ScavTrap " << YELLOW << _name << RESET << " attacks " << YELLOW << target << RESET <<
			", causing " << RED << _damagePoints << RESET << " points of damage!" << std::endl;
	}
	else if (_energyPoints <= 0)
		std::cout << "ScavTrap " << YELLOW << _name << RESET << " tries to attack " << YELLOW << target << RESET <<
			", but has no more energy points left!" << std::endl;
	else
		std::cout << "ScavTrap " << YELLOW << _name << RESET << " tries to attack " << YELLOW << target << RESET <<
			", but it's already dead!" << std::endl;
	showStatus();
}

void	ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap " << YELLOW << _name << RESET << std::endl;
	if (_hitPoints > 0 && _energyPoints > 0)
		std::cout << "ScavTrap is now in Gatekeeper mode." << std::endl;
	else if (_energyPoints <= 0)
		std::cout << "ScavTrap tries to change to Gatekeeper mode, but has no more energy points!" << std::endl;
	else
		std::cout << "ScavTrap tries to change to Gatekeeper mode, but it's already dead!" << std::endl;
	showStatus();
}

ScavTrap::~ScavTrap( void )
{
	std::cout << MAGENTA << "Destructor called" << RESET << std::endl;
	std::cout << GREEN << " -> " RESET << "ScavTrap " << YELLOW << _name << RESET << " has been destroyed.\n" << std::endl;
}

void	ScavTrap::showStatus( void )
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
