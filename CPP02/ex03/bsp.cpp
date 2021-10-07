#include "Point.hpp"

const Fixed	sign(Point const &q, Point const &r1, Point const &r2 ) {

	Fixed qx(q.xGet());
	Fixed qy(q.yGet());
	Fixed r1x(r1.xGet());
	Fixed r1y(r1.yGet());
	Fixed r2x(r2.xGet());
	Fixed r2y(r2.yGet());

	Fixed aux1;
	Fixed aux2;
	Fixed aux3;
	Fixed aux4;

	aux1 = qx - r2x;
	aux2 = r1y - r2y;
	aux3 = r1x - r2x;
	aux4 = qy - r2y;

	/*std::cout << aux1 << std::endl;
	std::cout << aux2 << std::endl;
	std::cout << aux3 << std::endl;
	std::cout << aux4 << std::endl;
	std::cout << qx << std::endl;
	std::cout << qy << std::endl;
	std::cout << r1x << std::endl;
	std::cout << r1y << std::endl;
	std::cout << r2x << std::endl;
	std::cout << r2y << std::endl;*/

	std::cout << aux1 * aux2 - aux3 * aux4 << std::endl;

	return ( aux1 * aux2 - aux3 * aux4 );
}

bool	bsp( Point const &a, Point const &b, Point const &c, Point const &point ) {

	//std::cout << "Inside the function call: " <<  a.xGet() << std::endl;
	Fixed s1 = sign(point, a, b);
	Fixed s2 = sign(point, b, c);
	Fixed s3 = sign(point, c, a);
	Fixed s4 = Fixed();

	if (s1 <=  s4 && s2 <= s4 && s3 <= s4)
		return true ;
	else if (s1 >= s4 && s2 >= s4 && s3 >= s4)
		return true ;
	else
		return false ;
}
