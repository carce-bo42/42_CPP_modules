#include "ScalarConverter.hpp"

SC::SC( std::string s ) : LiteralValue( s ),
						  intRep( 0 ),
						  floatRep( 0.0f )
						  charRep( '\0' ),
						  doubleRep( 0.0 ),
						  impossibleFlag( 0 ) {
}

SC::SC( SC const &other ) : LiteralValue( other.getLiteralValue() ),
						    intRep( other.getIntRep() ),
							floatRep( other.getFloatRep() ),
							charRep( other.getCharRep() ),
							doubleRep( other.getDoubleRep() ),
							impossibleFlag( other.getImpossibleFlag() ){
}

SC::~SC( void ) {
}

SC	SC::operator = ( SC const &other ) {

	this->LiteralValue = other.getLiteralValue();
	this->IntRep = other.getIntRep();
	this->floatRep = other.getFloatRep();
	this->charRep = other.getCharRep();
	this->doubleRep = other.getDoubleRep();
	this->impossibleFlag = other.getImpossibleFlag();
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

void	SC::DoConversions( void ) {

	// Int conversion.
	try {
		this->intRep = std::stoi( s );
	}
	catch (std::invalid_argument &e) {
		ImpossibleFlag += 1; // += 0000 0001
	}
	catch (std::out_of_range &e ) {
		ImpossibleFlag += 1; // += 0000 0001
	}

	// Float conversion.
	try {
		this->floatRep = std::stof( s );
	}	
	catch (std::invaid_argument &e) {
		ImpossibleFlag += 2; // += 0000 0010
	}
	catch (std::out_of_range &e) {
		ImpossibleFlag += 2; // += 0000 0010
	}

	// Char conversion.
	if (ImpossibleFlag ^ 1 == 1 )
		ImpossibleFlag += 4; // += 0000 0100
	else
		this->CharRep = static_cast<char>(this->intRep);

	// Double conversion.
	try {
		this->DoubleRep = std::stod( s );
	}
	catch (std::invalid_argument &e) {
		ImpossibleFlag += 8; //+= 0000 1000
	}
	catch (std::out_of_range &e) {
		ImpossibleFlag += 8; // += 0000 1000
	}
}
	



