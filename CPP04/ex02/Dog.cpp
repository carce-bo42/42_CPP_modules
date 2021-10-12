#include "Dog.hpp"

////////////////////////////////////////////// DOG /////////////////////////////////////////////

Dog::Dog( void ) : Animal( "Dog" ), DogBrain(new Brain) {

	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog( Dog const &other ) : Animal( other.getType() ), 
							   DogBrain( new Brain ) {

	for (int i=0; i < 100; i++) {
		DogBrain->setIdea( i, other.DogBrain->getIdea(i) );
	}
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog( void ) {
	
	delete this->DogBrain;
	std::cout << "Dog destructor called" << std::endl;
}

std::string		Dog::getType( void ) const {

	return this->_type;
}

void	Dog::makeSound( void ) const {

	std::cout << "Woof Woof!" << std::endl;
}

Dog&	Dog::operator = ( Dog const &other ) {

	if (&other != this) {
		delete this->DogBrain;

		Brain*	newDogBrain = new Brain;
		for (int i=0; i < 100; i++) {
			newDogBrain->setIdea( i, other.DogBrain->getIdea(i) );
		}
		this->_type = other.getType();
		this->DogBrain = newDogBrain;
	}
	return *this;
}
