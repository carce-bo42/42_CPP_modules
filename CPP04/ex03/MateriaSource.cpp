#include "MateriaSource.hpp"

void	MateriaSource::deleteInventory( void ) {
	for (int i=0; i<4; i++)	{
		if (this->Inventory[i] != NULL)
			delete this->Inventory[i];
	}
}

void	MateriaSource::initInventory( void ) {
	for (int i=0; i<4; i++)	{
		this->Inventory[i] = NULL;
	}
}

MateriaSource::MateriaSource( void ) {

	this->initInventory();
}

MateriaSource::MateriaSource( MateriaSource const &other ) {

	this->initInventory();

	for (int i=0; i<4; i++) {
		if (other.Inventory[i] != NULL)
			this->Inventory[i] = other.Inventory[i]->clone();
	}
}

MateriaSource::~MateriaSource( void ) {

	this->deleteInventory();
}

MateriaSource&	operator = ( MateriaSource const &other ) {

	this->deleteInventory();
	this->initInventory();

	for (int i=0; i<4; i++) {
		if (other.Inventory[i] != NULL)
			this->Inventory[i] = other.Inventory[i]->clone();
	}
}

void	MateriaSource::learnMateria( AMateria* MateriaPtr ) {

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

AMateria*	MateriaSource::createMateria( std::string const &type ) {

	for (int i=0; i<4; i++) {
		if (this->Inventory[i] != NULL) {
			if (!this->Inventory[i]->getType().compare(type))
				return this->Inventory[i]->clone();
		}
	}
	std::cout << "Cannot create materia of unknown type \"" << type << "\"" << std::endl;
	return NULL;
}
