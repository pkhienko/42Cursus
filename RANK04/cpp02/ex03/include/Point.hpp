#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {
	private:
		Fixed const	_x;
		Fixed const	_y;

	public:
		Point( void );
		Point( const Point &other );
		Point( const float x, const float y );

		Point	&operator=( const Point &other );
		
		~Point( void );

		Fixed	getX( void ) const;
		Fixed	getY( void ) const;
};

#endif
