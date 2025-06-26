#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed {
	private:
		int					_fixed_point;
		static const int	_fractional_bits;

	public:
		Fixed( void );
		Fixed( const Fixed &other );
		Fixed &operator=( const Fixed &other );
		~Fixed( void );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif