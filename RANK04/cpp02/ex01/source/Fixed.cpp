#include "Fixed.hpp"

const int	Fixed::_fractional_bits = 8;

Fixed::Fixed( void ) : _fixed_point(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int fp )
{
	std::cout << "Int constructor called" << std::endl;
	_fixed_point = fp << _fractional_bits;
}

Fixed::Fixed( const float fp )
{
	std::cout << "Float constructor called" << std::endl;
	_fixed_point = roundf(fp * (1 << _fractional_bits));
}

Fixed::Fixed( const Fixed &other )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed	&Fixed::operator=( const Fixed &other )
{
	std::cout << "Copy assignment operator called " << std::endl;
	if (this != &other)
		this->_fixed_point = other._fixed_point;
	return (*this);
}

std::ostream	&operator<<( std::ostream &os, const Fixed &other)
{
	os << other.toFloat();
	return (os);
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixed_point);
}

void	Fixed::setRawBits( int const raw )
{
	_fixed_point = raw;
}

int	Fixed::toInt( void ) const
{
	return (_fixed_point >> _fractional_bits);
}

float	Fixed::toFloat( void ) const
{
	return ((float)_fixed_point / (1 << _fractional_bits));
}