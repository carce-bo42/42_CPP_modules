#include "Cat.hpp"

///////////////////////////////////// CAT /////////////////////////////////////////////////////

Cat::Cat( void ) : Animal( "Cat" ) {

	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat( Cat const &other ) : Animal( other.getType() ) {

	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat( void ) {

	std::cout << "Cat destructor called" << std::endl;
}

std::string		Cat::getType( void ) const {

	return this->_type;
}

void	Cat::makeSound( void ) const {

	std::cout << "Meaw meaw!" << std::endl;
}

Cat&	Cat::operator = ( Cat const &other ) {

	this->_type = other.getType();
	return *this;
}

//////////////////////////////// WRONG CAT /////////////////////////////////////////////////////


WrongCat::WrongCat( void ) : WrongAnimal( "WrongCat" ) {

	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat( WrongCat const &other ) : WrongAnimal( other.getType() ) {

	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat( void ) {

	std::cout << "WrongCat destructor called" << std::endl;
}

std::string		WrongCat::getType( void ) const {

	return this->_type;
}

void	WrongCat::makeSound( void ) const {

	std::cout << "Meaw meaw!" << std::endl;
}

WrongCat&	WrongCat::operator = ( WrongCat const &other ) {

	this->_type = other.getType();
	return *this;
}
