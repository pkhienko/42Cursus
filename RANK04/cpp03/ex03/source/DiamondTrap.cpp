#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : ClapTrap(), ScavTrap(), FragTrap()
{
	this->_name = "NONE";
	this->_hitPoints = FragTrap::DEFAULT_HIT_POINTS;
	this->_energyPoints = ScavTrap::DEFAULT_ENERGY_POINTS;
	this->_damagePoints = FragTrap::DEFAULT_DAMAGE_POINTS;
	std::cout << GREEN << " -> " RESET << "DiamondTrap " << YELLOW << _name << RESET << " has been created.\n" << std::endl;
}

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name")
{
	this->_name = name;
	this->_hitPoints = FragTrap::DEFAULT_HIT_POINTS;
	this->_energyPoints = ScavTrap::DEFAULT_ENERGY_POINTS;
	this->_damagePoints = FragTrap::DEFAULT_DAMAGE_POINTS;
	std::cout << GREEN << " -> " RESET << "DiamondTrap " << YELLOW << _name << RESET << " has been created.\n" << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap &other ) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	this->_name = other._name;
	std::cout << GREEN << " -> " RESET << "DiamondTrap " << YELLOW << _name << RESET << " has been copied.\n" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=( const DiamondTrap &other )
{
	std::cout << MAGENTA << "Copy assignment operator called " << RESET << std::endl;
	std::cout << GREEN << " -> " RESET << "DiamondTrap " << YELLOW << _name << RESET << " has been copied.\n" << std::endl;
	if (this == &other)
		return (*this);
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_damagePoints = other._damagePoints;
	return (*this);
}

DiamondTrap::~DiamondTrap( void )
{
	std::cout << MAGENTA << "Destructor called" << RESET << std::endl;
	std::cout << GREEN << " -> " RESET << "DiamondTrap " << YELLOW << _name << RESET << " has been destroyed.\n" << std::endl;
}

void	DiamondTrap::whoAmI( void )
{
	std::cout << "DiamondTrap " << YELLOW << this->_name << RESET ": " MAGENTA "whoAmI" RESET << std::endl;
	std::cout << GREEN " -> " << RESET "DiamondTrap: " YELLOW << this->_name <<
		GREEN "\n -> " RESET "ClapTrap: " << YELLOW << ClapTrap::_name << RESET << "\n" << std::endl;
}

void	DiamondTrap::showStatus( void )
{
	std::string	color;

	color = _hitPoints > FragTrap::DEFAULT_HIT_POINTS / 2 ? GREEN : YELLOW;
	std::cout << GREEN << " -> " RESET << "HP: " << (_hitPoints == 0 ? RED : color) << _hitPoints << 
		WHITE"/" << GREEN << FragTrap::DEFAULT_HIT_POINTS << RESET << (_hitPoints == 0 ? RED"\t{DEAD}" : GREEN"\t{ALIVE}") << RESET << std::endl;
	color = _energyPoints > ScavTrap::DEFAULT_ENERGY_POINTS / 2 ? GREEN : YELLOW;
	std::cout << GREEN << " -> " RESET << "EP: " << (_energyPoints == 0 ? RED : color) << _energyPoints << 
		WHITE"/" << GREEN << ScavTrap::DEFAULT_ENERGY_POINTS << RESET << std::endl;
	std::cout << GREEN << " -> " RESET << "DM: " << (_damagePoints == 0 ? RED : GREEN) << _damagePoints << RESET << "\n" << std::endl;
}
