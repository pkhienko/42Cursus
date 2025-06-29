#include "Fixed.hpp"

int main( void ) {

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << "-------- Subject Test --------" << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << "------------------------------" << std::endl;

	std::cout << "-------- Additional Test --------" << std::endl;
	std::cout << "-> decrease test" << std::endl;
	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;

	std::cout << "\na: " << a.toFloat() << "\nb: " << b.toFloat() << std::endl;

	std::cout << "\n-> find min test" << std::endl;
	std::cout << "min : " << Fixed::min( a, b ) << std::endl;
	
	std::cout << "\n-> compare test" << std::endl;
	bool isEq = a == b;
	bool isNeq = a != b;
	bool isLt = a < b;
	bool isGt = a > b;
	bool isEqLt = a <= b;
	bool isEqGt = a >= b;
	std::cout << "Equal: " << isEq << std::endl;
	std::cout << "Not Equal: "<< isNeq << std::endl;
	std::cout << "Less than: "<< isLt << std::endl;
	std::cout << "Greater than: "<< isGt << std::endl;
	std::cout << "Equal or Less than: "<< isEqLt << std::endl;
	std::cout << "Equal or Greater than: "<< isEqGt << std::endl;

	std::cout << "\n-> compute test" << std::endl;
	a = a + b;
	std::cout << "operator + a: " << a << std::endl;
	a = a - b;
	std::cout << "operator - a: " << a << std::endl;

	std::cout << "\ntry to increase a" << std::endl;
	a = a + b;
	std::cout << "a: " << a << std::endl << std::endl;

	std::cout << "operator - a: " << a << std::endl;
	a = a * b;
	std::cout << "operator * a: " << a << std::endl;
	a = a / b;
	std::cout << "operator / a: " << a << std::endl;
	std::cout << "---------------------------------" << std::endl;
	return (0);
}
