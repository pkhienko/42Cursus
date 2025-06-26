#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {
	private:
		const Fixed	_x;
		const Fixed	_y;

	public:
		Point( void );
		Point( const Point &other );
		Point( const float x, const float y );

		Point	&operator=( const Point &other );
		
		~Point( void );
};

#endif