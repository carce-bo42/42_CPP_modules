#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &wname) : _name(name), _wname(wname) {	

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

void	HumanA::attack(void) const {

	std::cout << this->getName() << " attacks with his " << this->getWeapon() << std::endl;
	return ;

}


