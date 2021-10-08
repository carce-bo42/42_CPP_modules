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
	return ( (float)this->getRawBits() / (float)(1 << Fixed::_fbits) ) ;

}

int	Fixed::toInt( void ) const {

	return ( this->getRawBits() >> Fixed::_fbits ) ;
	
}


/////////////////////////
// Operator overloads //
////////////////////////

Fixed &		Fixed::operator = ( Fixed const &rhs ) {

	this->_fpvalue = rhs.getRawBits();
	return *this ;

}

bool	Fixed::operator > ( Fixed const	&rhs) const {

	return ( this->getRawBits() > rhs.getRawBits() ) ;

}

bool	Fixed::operator < ( Fixed const	&rhs ) const {

	return ( this->getRawBits() < rhs.getRawBits() ) ;

}

bool	Fixed::operator >= ( Fixed const &rhs ) const {

	return ( this->getRawBits() >= rhs.getRawBits() ) ;

}

bool	Fixed::operator <= ( Fixed const &rhs ) const {

	return ( this->getRawBits() <= rhs.getRawBits() ) ;

}

bool	Fixed::operator == ( Fixed const &rhs ) const {

	return ( this->getRawBits() == rhs.getRawBits() ) ;

}

bool	Fixed::operator != ( Fixed const &rhs ) const {

	return ( this->getRawBits() != rhs.getRawBits() ) ;

}

Fixed	Fixed::operator + ( Fixed const &rhs ) {

	Fixed a;

	a.setRawBits(this->getRawBits() + rhs.getRawBits());
	return ( a ) ;

}

Fixed	Fixed::operator - ( Fixed const &rhs ) {

	Fixed a;

	a.setRawBits(this->getRawBits() - rhs.getRawBits());
	return ( a  ) ;

}

// We lose precision in exchange for range. Multiplication will have
// a max precision of 2^-4 = 0.0625, and the maximum whole part, which
// was initially 2^(31 - 8) -1 = 8 388 607, is now 2^(31 - 8 - 4) -1 = 524 287.

Fixed	Fixed::operator * ( Fixed const &rhs ) {

	Fixed	output;
	int		aux_1;
	int		aux_2;

	aux_1 = this->getRawBits() >> (int)(Fixed::_fbits / 2) ;
	aux_2 = rhs.getRawBits() >> (int)(Fixed::_fbits / 2) ;

	output.setRawBits( aux_1 * aux_2 );

	return ( output ) ;
}

Fixed	Fixed::operator / ( Fixed const &rhs ) {

	int		aux_1;
	int		aux_2;

	aux_1 = this->getRawBits() << (int)(Fixed::_fbits / 2) ;
	aux_2 = rhs.getRawBits() << (int)(Fixed::_fbits / 2) ;

	return ( Fixed((float)aux_1 / (float)aux_2) ) ;

}

// 1 = 00000000 00000000 00000000 00000001, which interpreted
// as fixed point is the least representable positive amount that
// this format can handle.
Fixed&	Fixed::operator ++ ( void ) {

	this->setRawBits( this->getRawBits() + 1 );
	return ( *this ) ;

}

Fixed	Fixed::operator ++ ( int ) {

	Fixed	output = Fixed(*this);
	++(*this);

	return ( output ) ;

}

Fixed&	Fixed::operator -- ( void ) {

	this->setRawBits( this->getRawBits() - 1 );
	return ( *this ) ;

}

Fixed	Fixed::operator -- ( int ) {

	Fixed	output = Fixed(*this);
	--(*this);

	return ( output ) ;

}

//////////////////////
// Class Functions //
/////////////////////	

const Fixed&	Fixed::min( const Fixed &x, const Fixed &y ) {

	if (x < y)
		return x;
	else
		return y;

}

const Fixed&	Fixed::max( const Fixed &x, const Fixed &y ) {

	if (x > y)
		return x;
	else
		return y;

}


Fixed&	Fixed::min( Fixed &x, Fixed &y ) {

	if (x < y)
		return x;
	else
		return y;

}

Fixed&	Fixed::max( Fixed &x, Fixed &y ) {

	if (x > y)
		return x;
	else
		return y;

}

/////////////////////////////////
//Outter function definitions //
////////////////////////////////

const Fixed&	min( Fixed const &x, Fixed const &y ) {

	if (x < y)
		return x;
	else
		return y;

}


const Fixed&	max( Fixed const &x, Fixed const &y ) {

	if (x > y)
		return x;
	else
		return y;

}

Fixed&	min( Fixed &x, Fixed &y ) {

	if (x < y)
		return x;
	else
		return y;

}


Fixed&	max( Fixed &x, Fixed &y ) {

	if (x > y)
		return x;
	else
		return y;

}

///////////////////////////////
// Outter operator overloads//
//////////////////////////////

std::ostream&	operator << ( std::ostream & o, Fixed const &rhs ) {

	o << rhs.toFloat();
	return o;

}


