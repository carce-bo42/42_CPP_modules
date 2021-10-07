#include "Fixed.hpp"

///////////////////
// Constructors //
//////////////////

Fixed::Fixed(void) : _fpvalue(0) {
}

Fixed::Fixed(Fixed const & src) {

	*this = src;

}

Fixed::Fixed(float const n ) : _fpvalue(roundf(n * (float)(1 << Fixed::_fbits))) {
}

Fixed::Fixed( int const n) : _fpvalue(n << Fixed::_fbits) {
}


/////////////////
// Destructor //
////////////////

Fixed::~Fixed( void ) {
}


////////////////////
// Get/Set // 
///////////////////

int	Fixed::getRawBits( void ) const {

	return this->_fpvalue;

}

void	Fixed::setRawBits( int const raw ) {

	this->_fpvalue = raw;

}


///////////////////////////
// Conversion functions // 
//////////////////////////

float	Fixed::toFloat( void ) const {

	// This line doesnt work because (1 >> 8) is esentially 0:
	// 0000 0001 >> 8 = 0000 0000 (shifting to the right is problematic).
	//return ((float)this->getRawBits() * (float)(1 >> Fixed::_fbits)) ;
	return ( (float)this->getRawBits() / (float)(1 << Fixed::_bits) ) ;

}

int	Fixed::toInt( void ) const {

	return ( this->getRawBits() >> Fixed::_fbits ) ;
	
}


/////////////////////////
// Operator overloads //
////////////////////////

bool	Fixed::operator > ( Fixed const	&rhs) {

	return ( this->getRawBits() > rhs.getRawBits() ) ;

}

bool	Fixed::operator < ( Fixed const	&rhs ) {

	return ( this->getRawBits() < rhs.getRawBits() ) ;

}

bool	Fixed::operator >= ( Fixed const &rhs ) {

	return ( this->getRawBits() >= rhs.getRawBits() ) ;

}

bool	Fixed::operator <= ( Fixed const &rhs ) {

	return ( this->getRawBits() <= rhs.getRawBits() ) ;

}

bool	Fixed::operator == ( Fixed const &rhs ) {

	return ( this->getRawBits() == rhs.getRawBits() ) ;

}

bool	Fixed::operator != ( Fixed const &rhs ) {

	return ( this->getRawBits() != rhs.getRawBits() ) ;

}

Fixed &		Fixed::operator=( Fixed const &rhs ) {

	this->_fpvalue = rhs.getRawBits();
	return *this ;

}

std::ostream&	operator<<( std::ostream & o, Fixed const &rhs ) {

	o << rhs.toFloat();
	return o;

}


