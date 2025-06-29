#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed {
	private:
		int					_fixed_point;
		static const int	_fractional_bits;

	public:
		Fixed( void );
		Fixed( const int fp );
		Fixed( const float fp );
		Fixed( const Fixed &other );

		Fixed	operator++( int );
		Fixed	operator--( int );
		Fixed	&operator++( void );
		Fixed	&operator--( void );

		Fixed	&operator=( const Fixed &other );
		Fixed	operator+( const Fixed &other );
		Fixed	operator-( const Fixed &other );
		Fixed	operator*( const Fixed &other );
		Fixed	operator/( const Fixed &other );

		bool	operator>( const Fixed &other ) const;
		bool	operator<( const Fixed &other ) const;
		bool	operator==( const Fixed &other ) const;
		bool	operator!=( const Fixed &other ) const;
		bool	operator>=( const Fixed &other ) const;
		bool	operator<=( const Fixed &other ) const;

		~Fixed( void );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		int		toInt( void ) const;
		float	toFloat( void ) const;

		static Fixed	&min( Fixed &a, Fixed &b );
		static Fixed	&max( Fixed &a, Fixed &b );
		static const Fixed	&min( const Fixed &a, const Fixed &b );
		static const Fixed	&max( const Fixed &a, const Fixed &b );
};

	std::ostream	&operator<<( std::ostream &os, const Fixed &other);

#endif
