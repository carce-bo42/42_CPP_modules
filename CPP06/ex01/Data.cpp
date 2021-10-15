#include "Data.hpp"

Data::Data( void ) : nbr(0) {
}

Data::Data( int n ) : nbr(n) {
}

Data::Data( Data const &other ) : nbr( other.getNbr() ) {
}

Data::~Data( void ) {
}

Data&	Data::operator = ( Data const &other ) {
	this->nbr = other.getNbr();
	return *this;
}

int	Data::getNbr( void ) const {
	return this->nbr;
}

void	Data::setNbr( int n) {
	this->nbr = n;
}
