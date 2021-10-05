#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _wname(NULL) {

	return ;

}

HumanB::~HumanB(void) {

	return ;

}

void	HumanB::setWeapon(Weapon& wname) {

	this->_wname = &wname;

}

std::string	HumanB::getWeapon(void) const {

	return this->_wname->getType() ;

}

void	HumanB::setName(std::string name) {

	 this->_name = name;

}

std::string	HumanB::getName(void) const {

	return this->_name;

}

void	HumanB::attack(void) const {

	std::cout << this->getName() << " attacks with his " << this->getWeapon() << std::endl;
	return ;

}
