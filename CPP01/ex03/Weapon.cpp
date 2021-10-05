#include "Weapon.hpp"

Weapon::Weapon(std::string initial_type) : _type(initial_type) {

	return ;

}

Weapon::~Weapon(void) {

	return ;

}

std::string&	Weapon::getType(void) {

	return this->_type;

}

void	Weapon::setType(std::string type) {

	this->_type = type;
	return ;

}

