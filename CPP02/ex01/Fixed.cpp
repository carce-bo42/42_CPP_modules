#include "Fixed.hpp"

Fixed::Fixed(void) : _fpvalue(0) {

	std::cout << "Default constructor called" << std::endl;

}

Fixed::Fixed(Fixed const & src) {

	std::cout << "Copy constructor called" << std::endl;
	*this = src;

}

// 0001 is 2^0 = 1. 0001 << 1 = 0010 which is 2^1.
// It seems natural that 2^_fbits = 1 << _fbits.
Fixed::Fixed(float const n ) : _fpvalue(roundf(n * (float)(1 << Fixed::_fbits))) {

	std::cout << "Float constructor called" << std::endl;

}

Fixed::Fixed( int const n) : _fpvalue(n << Fixed::_fbits) {

	std::cout << "Int constructor called" << std::endl;

}

Fixed::~Fixed( void ) {

	std::cout << "Destructor called" << std::endl;

}

int	Fixed::getRawBits( void ) const {

	//std::cout << "getRawBits member function called" << std::endl;
	return this->_fpvalue;

}

void	Fixed::setRawBits( int const raw ) {

	//std::cout << "setRawBits member function called" << std::endl;
	this->_fpvalue = raw;

}

float	Fixed::toFloat( void ) const {

	return (((float)this->getRawBits()) / ((float)(1 << Fixed::_fbits))) ;

}

int	Fixed::toInt( void ) const {

	return (this->getRawBits() >> Fixed::_fbits) ;
	
}

Fixed &		Fixed::operator=( Fixed const & rhs ) {

	std::cout << "Assignation operator called" << std::endl;
	this->_fpvalue = rhs.getRawBits();
	return *this;

}

std::ostream &	operator<<( std::ostream & o, Fixed const & rhs ) {

	o << rhs.toFloat();
	return o;

}
