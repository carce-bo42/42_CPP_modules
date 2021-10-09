#include "DiamondTrap.hpp"
#include <string>

std::string		DiamondTrap::getName( void ) const {

	return this->_name;
}

void		DiamondTrap::setName( std::string const &NewName ) {

	this->_name = NewName;
}

DiamondTrap::DiamondTrap( void ) : ScavTrap(),
								   FragTrap() {

	this->setName( "Default DiamondTrap" );
	this->ClapTrap::setName( this->_name.append( "_clap_name" ) );
	this->_HP = this->FragTrap::getHP();
	this->_EP = this->ScavTrap::getEP();
	this->_AD = this->FragTrap::getAD();

	std::cout << "DiamondTrap " << this->_name << " default unargumented constructor called." << std::endl;
}
	

DiamondTrap::DiamondTrap( std::string name ) : ScavTrap( name ),
											   FragTrap( name ) {
	this->DiamondTrap::setName( name );
	this->ClapTrap::setName( name.append( "_clap_name" ) );
	this->_HP = this->FragTrap::getHP();
	this->_EP = this->ScavTrap::getEP();
	this->_AD = this->FragTrap::getAD();

	std::cout << "DiamondTrap " << this->_name << " default constructor called." << std::endl;
}

DiamondTrap::DiamondTrap( DiamondTrap const &other ) : ScavTrap( other.getName() ),
													   FragTrap( other.getName() ) {
	this->setName( other.getName() );
	ClapTrap::_name = name.append( "_clap_name" );
	this->setHP( other.FragTrap::getHP() );
	this->setEP( other.ScavTrap::getEP() );
	this->setAD( other.FragTrap::getAD() );
	std::cout << "DiamondTrap " << other.getName() << " copy constructor called." << std::endl;				
}

DiamondTrap::~DiamondTrap( void ) {

	std::cout << "DiamondTrap " << this->getName() << " destructor called." << std::endl;
}

void	DiamondTrap::attack( std::string const &target ) {

	this->ScavTrap::attack( target );
}

void	DiamondTrap::whoAmI( void ) {

	std::cout << "DiamondTrap: " << std::endl;
	std::cout << "- My name is " << this->getName() << std::endl;
	std::cout << "- My ClapTrap name is " << this->ClapTrap::getName() << std::endl;
}

DiamondTrap&	DiamondTrap::operator = ( DiamondTrap const &other ) {

	this->_name = other.getName();
	this->_HP = other.getHP();
	this->_EP = other.getEP();
	this->_AD = other.getAD();

	return *this ;
}



