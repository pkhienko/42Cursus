#include "Point.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point );

int main( void ) {
	Point	a(5, 5);
	Point	b(3, 3);
	Point	c(7, 3);

	Point	inside(5, 4);
	Point	edge(4, 4);
	Point	vertex(5, 5);
	Point	outside(2, 6);

    std::cout << "Inside: " << (bsp(a, b, c, inside) ? "True" : "False") << std::endl;
    std::cout << "Edge: " << (bsp(a, b, c, edge) ? "True" : "False") << std::endl;
    std::cout << "Vertex: " << (bsp(a, b, c, vertex) ? "True" : "False") << std::endl;
    std::cout << "Outside: " << (bsp(a, b, c, outside) ? "True" : "False") << std::endl;

	return 0;
}
