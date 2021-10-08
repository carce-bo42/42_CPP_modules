#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int main( void ) {

	Point a( -1.0f, 0.0f );
	Point b( 0.0f, 1.0f );
	Point c( 1.0f, 0.0f );

	Point x( 12.0f, -12.0f);

	Point& aREF = a;
	Point& bREF = b;
	Point& cREF = c;
	Point& xREF = x;

	if (bsp(aREF, bREF, cREF, xREF))
		std::cout << "x is inside the triangle defined by (a, b, c)." << std::endl;
	else
		std::cout << "x is not inside the triangle defined by (a, b, c)." << std::endl;

	Point y( 0.5f, 0.1f);
	Point& yREF = y;

	if (bsp(aREF, bREF, cREF, yREF))
		std::cout << "y is inside the triangle defined by (a, b, c)." << std::endl;
	else
		std::cout << "y is not inside the triangle defined by (a, b, c)." << std::endl;

	Point z( 1.0f, -1.0f);
	Point& zREF = z;

	if (bsp(aREF, bREF, cREF, zREF))
		std::cout << "z is inside the triangle defined by (a, b, c)." << std::endl;
	else
		std::cout << "z is not inside the triangle defined by (a, b, c)." << std::endl;
	return 0;

}
