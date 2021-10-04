#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon wname) : _name(name), _type(wname) {	

	return ;

}

HumanA::~HumanA(void) {

	return ;

}

std::string	HumanA::getWeapon(void) const {

	return this->_wname.getType() ;

}

void	HumanA::setName(std::string name) {

	this->_name = name;
	
}

std::string	HumanA::getName(void) const {

	return this->_name;

}

