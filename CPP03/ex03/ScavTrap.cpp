#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap( "Default ScavTrap" ) {

	this->setHP(100);
	this->setEP(50);
	this->setAD(20);

	std::cout << "ScavTrap " << this->getName() << " default unargumented constructor called" << std::endl ;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap( name ) {

	this->setHP(100);
	this->setEP(50);
	this->setAD(20);

	std::cout << "ScavTrap " << name << " default constructor called" << std::endl ;
}

ScavTrap::ScavTrap( ScavTrap const &other ) : ClapTrap( other.getName() ) {

	this->setHP(other.getHP());
	this->setEP(other.getEP());
	this->setAD(other.getAD());	
	std::cout << "ScavTrap " << other.getName() << " copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap( void ) {

	std::cout << "ScavTrap " << this->getName() << " destructor called" << std::endl;
}

void	ScavTrap::attack( std::string const &target ) {

	std::cout << "ScavTrap " << this->getName() << " has attacked " << target << ", causing " <<  this->getAD() << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate( void ) {

	std::cout << "ScavTrap " << this->getName() << " has entered Gatekeeping mode." << std::endl;
}

ScavTrap&	ScavTrap::operator = ( ScavTrap const &other ) {

	this->_name = other.getName();
	this->_HP = other.getHP();
	this->_EP = other.getEP();
	this->_AD = other.getAD();

	return *this ;
}
