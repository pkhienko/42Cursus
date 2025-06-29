#include "Point.hpp"

Point::Point( void ) : _x(Fixed(0)), _y(Fixed(0)) {}

Point::Point( const Point &other ) : _x(Fixed(other._x)), _y(Fixed(other._y)) {}

Point::Point( const float x, const float y ) : _x(Fixed(x)), _y(Fixed(y)) {}

Point   &Point::operator=( const Point &other )
{
    (void)other;
    return (*this);
}

Point::~Point( void ) {}

Fixed   Point::getX( void ) const { return (_x); }

Fixed   Point::getY( void ) const { return (_y); }
