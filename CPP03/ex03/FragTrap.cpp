#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap("Default FragTrap") {

	this->setHP(100);
	this->setEP(100);
	this->setAD(30);

	std::cout << "FragTrap " << this->getName() << " default unargumented constructor called" << std::endl;
}

FragTrap::FragTrap( std::string name ) : ClapTrap( name ) {

	this->setHP(100);
	this->setEP(100);
	this->setAD(30);

	std::cout << "FragTrap " << name << " default constructor called" << std::endl;
}

FragTrap::FragTrap( FragTrap const &other ) : ClapTrap( other.getName() ) {

	this->setHP( other.getHP() );
	this->setEP( other.getEP() );
	this->setAD( other.getAD() );

	std::cout << "FragTrap " << other.getName()  << " copy constructor called" << std::endl;
}

FragTrap::~FragTrap( void ) {

	std::cout << "FragTrap " << this->getName() << " destructor called" << std::endl;
}

void	FragTrap::attack( std::string const &target ) {

	std::cout << "FragTrap " << this->getName() << " has attacked " << target << ", causing " << this->getAD() << " points of damage!" << std::endl;
}

void	FragTrap::highFivesGuys( void ) {

	std::cout << "FragTrap " << this->getName() << ": *raises hand in order to high five you*" << std::endl;
}

FragTrap&	FragTrap::operator = ( FragTrap const &other ) {

	this->_name = other.getName();
	this->_HP = other.getHP();
	this->_EP = other.getEP();
	this->_AD = other.getAD();

	return *this ;
}
