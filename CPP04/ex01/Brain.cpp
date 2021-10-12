#include "Brain.hpp"

Brain::Brain( void ) {

	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain( Brain const &other ) {

	std::cout << "Brain copy constructor called" << std::endl;
	for (int i=0; i < 100; i++) {
		this->_ideas[i] = other.getIdea( i );
	}
}

Brain&	Brain::operator = ( Brain const &other ) {

	if (&other != this) {
		for (int i=0; i < 100; i++) {
			this->_ideas[i] = other.getIdea( i );
		}
	}
	return *this;
}

Brain::~Brain( void ) {

	std::cout << "Brain destructor called" << std::endl;
}

std::string	Brain::getIdea( int idx ) const {

	if (idx >= 0 && idx < 100 )
		return this->_ideas[idx];
	else {
		std::cout << "Idea out of scope" << std::endl;
		return "";
	}
}

void	Brain::setIdea( int idx, std::string idea ) {

	if (idx >= 0 && idx < 100 )
		this->_ideas[idx] = idea;
	else
		std::cout << "Idea out of scope" << std::endl;
}
