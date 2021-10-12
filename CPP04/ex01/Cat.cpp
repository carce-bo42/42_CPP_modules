#include "Cat.hpp"

///////////////////////////////////// CAT /////////////////////////////////////////////////////

Cat::Cat( void ) : Animal( "Cat" ), CatBrain(new Brain) {

	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat( Cat const &other ) : Animal( other.getType() ),
	   						   CatBrain( new Brain ) {

	for (int i=0; i < 100; i++) {
		CatBrain->setIdea( i, other.CatBrain->getIdea(i) );	
	}
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat( void ) {

	delete this->CatBrain;
	std::cout << "Cat destructor called" << std::endl;
}

std::string		Cat::getType( void ) const {

	return this->_type;
}

void	Cat::makeSound( void ) const {

	std::cout << "Meaw meaw!" << std::endl;
}

Cat&	Cat::operator = ( Cat const &other ) {

	if (&other != this) {
		delete this->CatBrain;

		Brain*	newCatBrain = new Brain;
		for (int i=0; i < 100; i++) {
			newCatBrain->setIdea( i, other.CatBrain->getIdea(i) );
		}
		this->_type = other.getType();
		this->CatBrain = newCatBrain;
	}
	return *this;
}
