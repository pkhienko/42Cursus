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
		
		Fixed	&operator=( const Fixed &other );

		~Fixed( void );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

	std::ostream	&operator<<( std::ostream &os, const Fixed &other);

#endif