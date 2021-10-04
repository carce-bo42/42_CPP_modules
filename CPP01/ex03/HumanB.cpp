#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _wname(NULL) {

	return ;

}

HumanB::~HumanB(void) {

	return ;

}

void	HumanB::setWeapon(std::string wtype) {

	this->w_name->setType(wtype);

}

std::string	HumanB::getWeapon(void) const {

	return this->_wname.getType() ;

}

void	HumanB::setName(std::string name) {

	 this->_name = name;

}

std::string	HumanB::getName(void) const {

	return this->_name;

}
