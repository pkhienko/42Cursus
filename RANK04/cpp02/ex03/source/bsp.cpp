#include "Point.hpp"

static bool isZero( float n )
{
    const float EPSILON = 0.0001f;
    return (n < EPSILON && n > -EPSILON);
}

static float   findArea( Point const a, Point const b, Point const c )
{
    float   area = (a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) -
                b.getX().toFloat() * (a.getY().toFloat() - c.getY().toFloat()) +
                c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())) / 2.0f;
    return (area >= 0 ? area : -area);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point )
{
    float   totalArea = findArea(a, b, c);
    float   area1 = findArea(point, a, b);
    float   area2 = findArea(point, a, c);
    float   area3 = findArea(point, b, c);
    
    if (isZero(area1) || isZero(area2) || isZero(area3))
        return (false);
    return (isZero((area1 + area2 + area3) - totalArea));
}
