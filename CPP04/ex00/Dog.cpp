#include "Dog.hpp"

////////////////////////////////////////////// DOG /////////////////////////////////////////////

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
	return *this;
}

//////////////////////////////////////// WRONG DOG //////////////////////////////////////////

WrongDog::WrongDog( void ) : WrongAnimal( "WrongDog" ) {

	std::cout << "WrongDog constructor called" << std::endl;
}

WrongDog::WrongDog( WrongDog const &other ) : WrongAnimal( other.getType() ) {

	std::cout << "WrongDog copy constructor called" << std::endl;
}

WrongDog::~WrongDog( void ) {
	
	std::cout << "WrongDog destructor called" << std::endl;
}

std::string		WrongDog::getType( void ) const {

	return this->_type;
}

void	WrongDog::makeSound( void ) const {

	std::cout << "Woof Woof!" << std::endl;
}

WrongDog&	WrongDog::operator = ( WrongDog const &other ) {

	this->_type = other.getType();
	return *this;
}
