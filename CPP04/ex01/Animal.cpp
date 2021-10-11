#include "Animal.hpp"

/////////////////////////////////// ANIMAL /////////////////////////////////////////////////

Animal::Animal( void ) : _type( "Animal Vessel" ) {

	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal( std::string name ) : _type( name ) {

	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal( Animal const &other ) {

	this->_type = other.getType();
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal( void ) {

	std::cout << "Animal destructor called" << std::endl;
}

std::string	Animal::getType( void ) const {

	return this->_type;
}

void	Animal::makeSound( void ) const {

	std::cout << "I am not an Animal subtype, I shall not make an animal associated sound" << std::endl;
}

Animal& 	Animal::operator = ( Animal const &other ) {

	this->_type =  other.getType();
	return *this;
}
