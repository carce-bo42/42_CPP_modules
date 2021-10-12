#include "MateriaSource.hpp"

void	MateriaSource::deleteInventory( void ) {
	for (int i=3; i>0; i--)	{
		if (this->Inventory[i] != NULL)
			delete this->Inventory[i];
	}
}

void	MateriaSource::initInventory( void ) {
	for (int i=0; i<4; i++)	{
		this->Inventory[i] = NULL;
	}
}

void	MateriaSource::cloneInventory( MateriaSource const &other ) {

	for (int i=0; i<4; i++) {
		if (other.Inventory[i] != NULL)
			this->Inventory[i] = other.Inventory[i]->clone();
	}
}


MateriaSource::MateriaSource( void ) {

	this->initInventory();
}

MateriaSource::MateriaSource( MateriaSource const &other ) {

	this->initInventory();
	this->cloneInventory( other );
}

MateriaSource::~MateriaSource( void ) {

	this->deleteInventory();
}

MateriaSource&	MateriaSource::operator = ( MateriaSource const &other ) {

	if ( &other != this ) {
		this->deleteInventory();
		this->initInventory();
		this->cloneInventory( other );
	}
	return *this;
}

void	MateriaSource::learnMateria( AMateria* MateriaPtr ) {

	if (MateriaPtr != NULL) {

		for (int i=0; i<4; i++) {
			if (this->Inventory[i] == MateriaPtr)
				return ;
		}

		int	j=-1;
		for (int i=0; i<4; i++) {
			if (this->Inventory[i] == NULL) {
				j = i;
				this->Inventory[i] = MateriaPtr;	
				break ;
			}
		}

	if (j != -1)
		std::cout << "Succesfully added " << MateriaPtr->getType() << " to the Source Inventory!" << std::endl;
	else
		std::cout << "Source Inventory is full!" << std::endl;
	}
}

AMateria*	MateriaSource::createMateria( std::string const &type ) {

	for (int i=0; i<4; i++) {
		if (this->Inventory[i] != NULL) {
			if (!this->Inventory[i]->getType().compare(type)) {
				AMateria*	out = this->Inventory[i]->clone();
				return out;
			}
		}
	}
	std::cout << "Cannot create materia of unknown type \"" << type << "\"" << std::endl;
	return NULL;
}
