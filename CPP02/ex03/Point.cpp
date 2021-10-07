#include "Point.hpp"

///////////////////
// Constructors //
//////////////////

Point::Point( void ) : _x(Fixed()), _y(Fixed()) {
}

Point::Point( Fixed const &x, Fixed const &y ) : _x(x) , _y(y) {
}

Point::Point( float const x, float const y ) : _x(Fixed(x)), _y(Fixed(y)) {
}

Point::Point( Point &p ) {
	*this = p;
}

Point::Point( const Point &p ) {
	*this = p;
}


//////////////
// Get/set //
////////////

const Fixed&	Point::xGet( void ) const {
	return this->_x;
}

const Fixed&	Point::yGet( void ) const {
	return this->_y;
}

//////////////////////////
// Assignment operator //
/////////////////////////

Point&	Point::operator = ( Point &rhs ) {

	return ( rhs );
}
	
const Point&	Point::operator = ( const Point &rhs ) {

	return ( rhs );
}

