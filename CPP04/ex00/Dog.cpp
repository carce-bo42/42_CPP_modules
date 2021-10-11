#include "Dog.hpp"

Dog::Dog( void ) : Animal( "Dog" ) {

	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog( Dog const &other ) : Animal( other.getType() ) {

	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog( void ) {
	
	std::cout << "Dog destructor called" << std::endl;
}

std::string		Dog::getType( void ) const {

	return this->_type;
}

void	Dog::makeSound( void ) const {

	std::cout << "Woof Woof!" << std::endl;
}

Dog&	Dog::operator = ( Dog const &other ) {

	this->_type = other.getType();
}
