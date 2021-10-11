#include "Animal.hpp"

Animal::Animal( void ) : _animal( "Animal Vessel" ) {

	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal( std::string name ) : _animal( name ) {

	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal( Animal const &other ) {

	this->_type = other.type;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal( void ) {

	std::cout << "Animal destructor called" << std::endl;
}

void	Animal::makeSound( void ) const {

	std::cout << "I am not an Animal subtype, I shall not make an animal associated sound" << std::endl;
}

Animal& 	Animal::operator = ( Animal const &other ) {

	this->_type =  other.type;
	return *this;
}
