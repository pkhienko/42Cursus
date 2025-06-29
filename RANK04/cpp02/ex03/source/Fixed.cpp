#include "Fixed.hpp"

const int	Fixed::_fractional_bits = 8;

Fixed::Fixed( void ) : _fixed_point(0) {}

Fixed::Fixed( const int fp )
{
	_fixed_point = fp << _fractional_bits;
}

Fixed::Fixed( const float fp )
{
	_fixed_point = roundf(fp * (1 << _fractional_bits));
}

Fixed::Fixed( const Fixed &other )
{
	*this = other;
}

Fixed	&Fixed::operator++( void )
{
	++this->_fixed_point;
	return (*this);
}

Fixed	&Fixed::operator--( void )
{
	--this->_fixed_point;
	return (*this);
}

Fixed	Fixed::operator++( int )
{
	Fixed	tmp = *this;
	this->_fixed_point++;
	return (tmp);
}

Fixed	Fixed::operator--( int )
{
	Fixed	tmp = *this;
	this->_fixed_point--;
	return (tmp);
}

Fixed	&Fixed::operator=( const Fixed &other )
{
	if (this != &other)
		this->_fixed_point = other._fixed_point;
	return (*this);
}

bool	Fixed::operator==( const Fixed &other ) const
{
	return (this->_fixed_point == other._fixed_point);
}

bool	Fixed::operator!=( const Fixed &other ) const
{
	return (this->_fixed_point != other._fixed_point);
}

bool	Fixed::operator>( const Fixed &other ) const
{
	return (this->_fixed_point > other._fixed_point);
}

bool	Fixed::operator<( const Fixed &other ) const
{
	return (this->_fixed_point < other._fixed_point);
}

bool	Fixed::operator>=( const Fixed &other ) const
{
	return (this->_fixed_point >= other._fixed_point);
}

bool	Fixed::operator<=( const Fixed &other ) const
{
	return (this->_fixed_point <= other._fixed_point);
}

Fixed	Fixed::operator+( const Fixed &a )
{
	return (Fixed(this->toFloat() + a.toFloat()));
}

Fixed	Fixed::operator-( const Fixed &a )
{
	return (Fixed(this->toFloat() - a.toFloat()));
}

Fixed	Fixed::operator*( const Fixed &a )
{
	return (Fixed(this->toFloat() * a.toFloat()));
}

Fixed	Fixed::operator/( const Fixed &a )
{
	if (a._fixed_point == 0)
	{
		std::cerr << "Error: Division by zero!" << std::endl;
		return (Fixed(0));
	}
	return (Fixed(this->toFloat() / a.toFloat()));
}

std::ostream	&operator<<( std::ostream &os, const Fixed &other)
{
	os << other.toFloat();
	return (os);
}

Fixed::~Fixed( void ) {}

int	Fixed::getRawBits( void ) const
{
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

Fixed	&Fixed::min( Fixed &a, Fixed &b )
{
	return (a._fixed_point < b._fixed_point ? a : b);
}

Fixed	&Fixed::max( Fixed &a, Fixed &b )
{
	return (a._fixed_point > b._fixed_point ? a : b);
}

const Fixed	&Fixed::min( const Fixed &a, const Fixed &b )
{
	return (a._fixed_point < b._fixed_point ? a : b);
}

const Fixed	&Fixed::max( const Fixed &a, const Fixed &b )
{
	return (a._fixed_point > b._fixed_point ? a : b);
}
