#include "Fixed.hpp"

class Point {

	public:

		Point( void );
		Point( Fixed const &x, Fixed const &y );
		Point( Point &p );
		Point( const Point &p );
		Point( float const x, float const y );

		const Fixed&	xGet( void ) const;
		const Fixed&	yGet( void ) const;

		Point&			operator = ( Point &rhs );
		const Point& 	operator = ( const Point &rhs );

	private:

		Fixed const _x;
		Fixed const _y;

};
