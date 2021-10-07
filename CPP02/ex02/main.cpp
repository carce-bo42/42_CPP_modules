#include "Fixed.hpp"
int main( void ) {

	// Different constructor calls:
	Fixed a( 1.342f );
	Fixed b( 2.658f );
	Fixed c( 3 );
	Fixed d( c );
	Fixed e;

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "e = " << e << std::endl;

	std::cout << std::endl;
	// Addition / subtraction : 
	
	std::cout << "a + b = " << a << " + " << b << " = " << a + b << std::endl;
	std::cout << "a - b = " << a << " - " << b << " = " << a - b << std::endl;
	std::cout << "a + b - c = " << a << " + " << b << " - " << c << " = " << a + b - c << std::endl;
	std::cout << "a - b + c = " << a << " - " << b << " + " << c << " = " << a - b + c << std::endl;

	std::cout << std::endl;
	// Multiplication / division :
	
	std::cout << "a / b = " << a << " / " << b << " = " << a / b << std::endl;
	std::cout << "a / c = " << a << " / " << c << " = " << a / c << std::endl;
	std::cout << "b / a = " << b << " / " << a << " = " << b / a << std::endl;
	// Division between zero gves floating point exception (uncomment to make it explode): 
	//std::cout << "c / e = " << c << " / " << e << " = " << c / e << std::endl;
	
	std::cout << "a * b = " << a << " * " << b << " = " << a * b << std::endl;
	std::cout << "a * a = " << a << " * " << a << " = " << a * a << std::endl;
	std::cout << "b * b = " << b << " * " << b << " = " << b * b << std::endl;	
	std::cout << std::endl;

	a = Fixed( -1.342f );
	b = Fixed( 2.658f );
	c = Fixed( 3 );
	d = Fixed( c );
	e--;
	
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "e = " << e << std::endl;

	std::cout << std::endl;
	// Addition / subtraction : 
	
	std::cout << "a + b = " << a << " + " << b << " = " << a + b << std::endl;
	std::cout << "a - b = " << a << " - " << b << " = " << a - b << std::endl;
	std::cout << "a + b - c = " << a << " + " << b << " - " << c << " = " << a + b - c << std::endl;
	std::cout << "a - b + c = " << a << " - " << b << " + " << c << " = " << a - b + c << std::endl;

	std::cout << std::endl;
	// Multiplication / division :
	
	std::cout << "a / b = " << a << " / " << b << " = " << a / b << std::endl;
	std::cout << "a / c = " << a << " / " << c << " = " << a / c << std::endl;
	std::cout << "b / a = " << b << " / " << a << " = " << b / a << std::endl;
	// Division between zero gves floating point exception (uncomment to make it explode): 
	//std::cout << "c / e = " << c << " / " << e << " = " << c / e << std::endl;
	
	std::cout << "a * b = " << a << " * " << b << " = " << a * b << std::endl;
	std::cout << "a * a = " << a << " * " << a << " = " << a * a << std::endl;
	std::cout << "b * b = " << b << " * " << b << " = " << b * b << std::endl;
	std::cout << std::endl;

	// Comparison operators / increments::
	a = Fixed( 1.342f );
	b = Fixed( -1.243f  );
	c = Fixed( b );
	d = Fixed( a );
	e = Fixed(  2.1234f );

	if (a > b)
		std::cout << " a > b : " << a << " > " << b << " : True"  << std::endl;
	else
		std::cout << " a > b : " << a << " > " << b << " : False"  << std::endl;
	if (a < b)
		std::cout << " a < b : " << a << " < " << b << " : True"  << std::endl;
	else
		std::cout << " a < b : " << a << " < " << b << " : False"  << std::endl;
	if (a == a)
		std::cout << " a == a : " << a << " == " << a << " : True"  << std::endl;
	else
		std::cout << " a == a : " << a << " == " << a << " : False"  << std::endl;
	if (a == b)
		std::cout << " a == b : " << a << " == " << b << " : True"  << std::endl;
	else
		std::cout << " a == b : " << a << " == " << b << " : False"  << std::endl;
	if (a <= b)
		std::cout << " a <= b : " << a << " <= " << b << " : True"  << std::endl;
	else
		std::cout << " a <= b : " << a << " <= " << b << " : False"  << std::endl;
	if (a >= b)
		std::cout << " a >= b : " << a << " >= " << b << " : True"  << std::endl;
	else
		std::cout << " a >= b : " << a << " >= " << b << " : False"  << std::endl;

	std::cout << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "a++ = " << a++ << std::endl;
	std::cout << "a after increment: " << a << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << "--a = " << --a << std::endl;
	std::cout << "a-- = " << a-- << std::endl;
	std::cout << " a after decrement: " << a << std::endl;

	// min / max functions:
	
	std::cout << "min(a,b) = " << "min(" << a << "," << b << ") = " << min(a,b) << std::endl;
	std::cout << "max(a,b) = " << "max(" << a << "," << b << ") = " << max(a,b) << std::endl;
	std::cout << "Fixed::min(a,b) = " << "Fixed::min(" << a << "," << b << ") = " << Fixed::min(a,b) << std::endl;
	std::cout << "Fixed::max(a,b) = " << "Fixed::max(" << a << "," << b << ") = " << Fixed::max(a,b) << std::endl;

	return 0;

}
