#include "Character.hpp"
#include <stdio.h>

void	Character::initInventory( void ) {

	for (int i=0; i<4; i++) {
		this->Inventory[i] = NULL;
	}
}

void	Character::deleteInventory( void ) {

	for (int i=0; i<4; i++) {
		if (this->Inventory[i] != NULL)
			delete this->Inventory[i];
	}
}

void	Character::cloneInventory( Character const &other ) {

	for (int i=0; i<4; i++) {
		if (other.Inventory[i] != NULL)
			this->Inventory[i] = other.Inventory[i]->clone();
	}
}

Character::Character( void ) : _name( "John Doe" ) {

	this->initInventory();
}

Character::Character( std::string const &name ) : _name( name ) {

	this->initInventory();
}

Character::Character( Character const &other ) : _name( other.getName() ) {

	this->initInventory();
	this->cloneInventory( other );
}

Character::~Character( void ) {

	this->deleteInventory();
}

Character&	Character::operator = ( Character const &rhs ) {

	if ( &rhs != this ) {
		this->_name = rhs.getName();

		this->deleteInventory();
		this->initInventory();
		this->cloneInventory( rhs );
	}
	return *this;
}

std::string const&	Character::getName( void ) const {

	return this->_name ;
}

void	Character::equip( AMateria* MateriaPtr ) {

	if (MateriaPtr != NULL) {
		for (int i=0; i<4; i++) {
			if (this->Inventory[i] == NULL) {
				this->Inventory[i] = MateriaPtr;
				break ;
			}
		}
	}
}

void	Character::unequip( int idx ) {

	if (idx >= 0 && idx < 4) {

		this->Inventory[idx] = NULL;
		for (int i=idx; i<3; i++) {
			this->Inventory[i] = this->Inventory[i + 1];
		}
	}
}

void	Character::use( int idx, ICharacter& target ) {

	if (idx >= 0 && idx < 4) {
		this->Inventory[idx]->use( target );
	}
}
