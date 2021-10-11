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

//////////////////////////////// WRONG ANIMAL //////////////////////////////////////////////


WrongAnimal::WrongAnimal( void ) : _type( "WrongAnimal Vessel" ) {

	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( std::string name ) : _type( name ) {

	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal const &other ) {

	this->_type = other.getType();
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal( void ) {

	std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string	WrongAnimal::getType( void ) const {

	return this->_type;
}

void	WrongAnimal::makeSound( void ) const {

	std::cout << "I am not an WrongAnimal subtype, I shall not make an animal associated sound" << std::endl;
}

WrongAnimal& 	WrongAnimal::operator = ( WrongAnimal const &other ) {

	this->_type =  other.getType();
	return *this;
}
