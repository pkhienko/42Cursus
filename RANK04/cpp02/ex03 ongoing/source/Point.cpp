#include "Point.hpp"

Point::Point( void ) : _x(0), _y(0) {}

Point::Point( const Point &other )
{
    *this = other;
}

Point::Point( const float x, const float y ) : _x(x), _y(y) {}

Point   &Point::operator=( const Point &other )
{
    if (this != &other)
        *this = other;
    return (*this);
}

Point::~Point( void ) {}