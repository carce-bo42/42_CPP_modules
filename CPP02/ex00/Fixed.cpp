#include "Fixed.hpp"

Fixed::Fixed(void) : _fpvalue(0) {

	std::cout << "Default constructor called" << std::endl;

}

Fixed::Fixed(Fixed const & src) {

	std::cout << "Copy constructor called" << std::endl;
	*this = src;

}

Fixed::~Fixed(void) {

	std::cout << "Destructor called" << std::endl;

}

int	Fixed::getRawBits(void) const {

	std::cout << "getRawBits member function called" << std::endl;
	return this->_fpvalue;

}

void	Fixed::setRawBits(int const raw) {

	std::cout << "setRawBits member function called" << std::endl;
	this->_fpvalue = raw;

}

Fixed &		Fixed::operator=(Fixed const & rhs) {

	std::cout << "Assignation operator called" << std::endl;
	this->_fpvalue = rhs.getRawBits();
	return *this;

}
