#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {

	return ;

}

Zombie::~Zombie(void) {

	std::cout << this->get_name() << " has died." << std::endl;
	return ;

}

void	Zombie::announce(void) const {

	std::cout << this->get_name() << " BraiiiiiiinnnzzzZ..." << std::endl;
	return ;

}

std::string	Zombie::get_name(void) const {

	return this->_name ;
	
}

void	Zombie::set_name(std::string name) {

	this->_name = name;
	return ;

}	
