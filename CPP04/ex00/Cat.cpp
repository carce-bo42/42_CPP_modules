#include "Cat.hpp"

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

	std::cout << "Woof Woof!" << std::endl;
}

Cat&	Cat::operator = ( Cat const &other ) {

	this->_type = other.getType();
}
