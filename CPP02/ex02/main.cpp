#include "Fixed.hpp"
int main( void ) {

	// Addition subtraction:
	
	Fixed a( 1.342f );
	Fixed b( 2.658f );
	Fixed c( 3 );
	Fixed d( c );
	Fixed e;
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;

}
