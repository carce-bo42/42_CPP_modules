#include "Materia.hpp"

////////////////////////// AMateria //////////////////////////////////

AMateria::AMateria( void ) : type( "typeless" ) {
}

AMateria::AMateria( std::string const &type ) : type( type ) {
}

AMateria::AMateria( AMateria const &rhs ) : type( rhs.type ) {
}

AMateria::~AMateria( void ) {
}

AMateria&	AMateria::operator = (AMateria const &rhs ) {
	this->type = rhs.getType() ;
	return *this;
}

std::string const&	AMateria::getType( void ) const {
	return this->type;
}

void	AMateria::use( ICharacter& target ) {
	std::cout << "Uses " << this->type << " on " << target.getName() << std::endl;
}

////////////////////////// Ice //////////////////////////////////

Ice::Ice( void ) : AMateria( "ice" ) {
}

Ice::Ice( Ice const &rhs ) : AMateria( rhs.getType() ) {
}

Ice::~Ice( void ) {
}

Ice&	Ice::operator = (  Ice const &rhs ) {
	this->type = rhs.getType();
	return *this;
}

void	Ice::use( ICharacter& target ) {
	std::cout << "*shoots an ice bolt at " << target.getName() << "*" << std::endl;
}

AMateria*	Ice::clone( void ) const {
	return new Ice ;
}

//////////////////////////// Cure ///////////////////////////////////


Cure::Cure( void ) : AMateria( "cure" ) {
}

Cure::Cure( Cure const &rhs ) : AMateria( rhs.getType() ) {
}

Cure::~Cure( void ) {
}

Cure&	Cure::operator = (  Cure const &rhs ) {
	this->type = rhs.getType();
	return *this;
}

void	Cure::use( ICharacter& target ) {
	std::cout << "*heals " << target.getName() << "'s wounds*" << std::endl;
}

AMateria*	Cure::clone( void ) const {
	return new Cure ;
}
