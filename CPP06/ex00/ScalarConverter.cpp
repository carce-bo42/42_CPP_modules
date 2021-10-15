#include "ScalarConverter.hpp"

SC::SC( std::string s ) : LiteralValue( s ),
						  intRep( 0 ),
						  floatRep( 0.0f )
						  charRep( '\0' ),
						  doubleRep( 0.0 ) {
}

SC::SC( SC const &other ) : LiteralValue( other.getLiteralValue() ),
						    intRep( other.getIntRep() ),
							floatRep( other.getFloatRep() ),
							charRep( other.getCharRep() ),
							doubleRep( other.getDoubleRep() ) {
}

SC::~SC( void ) {
}

SC	SC::operator = ( SC const &other ) {

	this->LiteralValue = other.getLiteralValue();
	this->IntRep = other.getIntRep();
	this->floatRep = other.getFloatRep();
	this->charRep = other.getCharRep();
	this->doubleRep = other.getDoubleRep();
}

std::string	SC::getLiteralValue( void ) {
	return this->LiteralValue;
}

int	SC::getIntRep( void ) {
	return this->IntRep;
}

float SC::getFloatRep( void ) {
	return this->floatRep;
}

char SC::getCharRep( void ) {
	return this->CharRep;
}

double	SC::getDoubleRep( void ) {
	return this->DoubleRep;
}



