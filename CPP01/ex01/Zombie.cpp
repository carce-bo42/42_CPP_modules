#include "Zombie.hpp"

int	Zombie::_getNbZombies(void) {

	return Zombie::_nbZombies ;

}

std::string	Zombie::_create_default_name(void) {

	std::string default_name;

	default_name = "DefaultZombie";
	default_name += std::to_string(Zombie::_getNbZombies()); 
	return default_name ;

}


Zombie::Zombie(std::string name) : _name(name) {

	Zombie::_nbZombies += 1;
	return ;

}

Zombie::Zombie(void) : _name(Zombie::_create_default_name()) {

	Zombie::_nbZombies += 1;
	return ;

}

Zombie::~Zombie(void) {

	std::cout << this->get_name() << " has died." << std::endl;
	Zombie::_nbZombies -= 1;
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

int	Zombie::_nbZombies = 0;
