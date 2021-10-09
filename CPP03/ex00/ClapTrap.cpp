#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string name ) : _name(name),
										 _HP(10),
										 _EP(0),
										 _AD(0) {
}

ClapTrap::ClapTrap( ClapTrap const &other ) : _name(other.getName()), 
											  _HP(other.getHP()),
											  _EP(other.getEP()),
											  _AD(other.getAD()) {
}

ClapTrap::~ClapTrap( void ) {
}

void	ClapTrap::attack( std::string const &target ) {

	std::cout << "ClapTrap " << this->getName() << " was attacked " << target << ", causing " << this->getAD() << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage( unsigned int amount ) {

	std::cout << "ClapTrap " << this->getName() << " took " << amount << " damage!" << std::endl;
	if (amount >= this->getHP())
		this->setHP(0);
	else
		this->setHP( this->getHP() - amount );
}

void	ClapTrap::beRepaired( unsigned int amount ) {

	std::cout << "ClapTrap " << this->getName() << " got repaired " << amount << " Hit Points!" << std::endl; 
	this->_HP += amount;
}

std::string	ClapTrap::getName( void ) const {

	return ( this->_name );
}

unsigned int	ClapTrap::getHP( void ) const {

	return ( this->_HP );
}

unsigned int	ClapTrap::getEP( void ) const {

	return ( this->_EP );
}

unsigned int	ClapTrap::getAD( void ) const {

	return ( this->_AD );
}

void	ClapTrap::setName( std::string const &NewName ) {

	this->_name = NewName;
}

void	ClapTrap::setHP( unsigned int HP ) {

	this->_HP = HP;
}

void 	ClapTrap::setEP( unsigned int EP ) {

	this->_EP = EP;
}

void	ClapTrap::setAD( unsigned int AD ) {

	this->_AD = AD;
}

ClapTrap&	ClapTrap::operator = ( ClapTrap const &other ) {

	this->_name = other.getName();
	this->_HP = other.getHP();
	this->_EP = other.getEP();
	this->_AD = other.getAD();

	return *this;
}

