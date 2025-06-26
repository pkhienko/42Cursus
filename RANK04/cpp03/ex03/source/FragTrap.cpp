#include "FragTrap.hpp"

const unsigned int	FragTrap::DEFAULT_HIT_POINTS = 100;
const unsigned int	FragTrap::DEFAULT_ENERGY_POINTS = 100;
const unsigned int	FragTrap::DEFAULT_DAMAGE_POINTS = 30;

FragTrap::FragTrap( void ) : ClapTrap()
{
	_hitPoints = DEFAULT_HIT_POINTS;
	_energyPoints = DEFAULT_ENERGY_POINTS;
	_damagePoints = DEFAULT_DAMAGE_POINTS;
	std::cout << GREEN << " -> " RESET << "FragTrap " << YELLOW << _name << RESET << " has been created.\n" << std::endl;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
	_hitPoints = DEFAULT_HIT_POINTS;
	_energyPoints = DEFAULT_ENERGY_POINTS;
	_damagePoints = DEFAULT_DAMAGE_POINTS;
	std::cout << GREEN << " -> " RESET << "FragTrap " << YELLOW << _name << RESET << " has been created.\n" << std::endl;
}

FragTrap::FragTrap( const FragTrap &other ) : ClapTrap(other)
{
	std::cout << GREEN << " -> " RESET << "FragTrap " << YELLOW << _name << RESET << " has been copied.\n" << std::endl;
}

FragTrap	&FragTrap::operator=( const FragTrap &other )
{
	std::cout << MAGENTA << "Copy assignment operator called " << RESET << std::endl;
	std::cout << GREEN << " -> " RESET << "FragTrap " << YELLOW << _name << RESET << " has been copied.\n" << std::endl;
	if (this == &other)
		return (*this);
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_damagePoints = other._damagePoints;
	return (*this);
}

FragTrap::~FragTrap( void )
{
	std::cout << MAGENTA << "Destructor called" << RESET << std::endl;
	std::cout << GREEN << " -> " RESET << "FragTrap " << YELLOW << _name << RESET << " has been destroyed.\n" << std::endl;
}

void	FragTrap::highFivesGuys( void )
{
	std::cout << "FragTrap " << YELLOW << _name << RESET << std::endl;
	if (_hitPoints > 0 && _energyPoints > 0)
		std::cout << "FragTrap is giving high five!" << std::endl;
	else if (_energyPoints <= 0)
		std::cout << "FragTrap tries to give high five!, but has no more energy points!" << std::endl;
	else
		std::cout << "FragTrap tries to give high five!, but it's already dead!" << std::endl;
	showStatus();
}

void	FragTrap::showStatus( void )
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
