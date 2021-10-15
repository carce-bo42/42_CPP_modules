#include "ScalarConverter.hpp"

SC::SC( std::string s ) : LiteralValue( s ),
						  intRep( 0 ),
						  floatRep( 0.0f ),
						  charRep( '\0' ),
						  doubleRep( 0.0 ),
						  Flag( 0 ) {
}

SC::SC( SC const &other ) : LiteralValue( other.getLiteralValue() ),
						    intRep( other.getIntRep() ),
							floatRep( other.getFloatRep() ),
							charRep( other.getCharRep() ),
							doubleRep( other.getDoubleRep() ),
							Flag( other.getFlag() ){
}

SC::~SC( void ) {
}

SC&	SC::operator = ( SC const &other ) {

	this->LiteralValue = other.getLiteralValue();
	this->intRep = other.getIntRep();
	this->floatRep = other.getFloatRep();
	this->charRep = other.getCharRep();
	this->doubleRep = other.getDoubleRep();
	this->Flag = other.getFlag();
	return *this;
}

std::string	SC::getLiteralValue( void ) const {
	return this->LiteralValue;
}

int	SC::getIntRep( void ) const {
	return this->intRep;
}

float SC::getFloatRep( void ) const {
	return this->floatRep;
}

char SC::getCharRep( void ) const {
	return this->charRep;
}

double	SC::getDoubleRep( void ) const {
	return this->doubleRep;
}

short int	SC::getFlag( void ) const {
	return this->Flag;
}

void	SC::DetectType( void ) {

	//Char goes first.
	// If it only has one character and it is printable and it is not numeric: 
	if (this->LiteralValue.length() == 1) {
		if (isprint(this->LiteralValue[0]) && !isdigit(this->LiteralValue[0])) {
			this->charRep = static_cast<char>(this->LiteralValue[0]);
			this->Flag += 16; //+= 0001 0000;
			return ;
		}
	}

	//Int goes second.	
	// If it does not contain either a '.' nor a 'f' :
	if (this->LiteralValue.find('.') == std::string::npos && this->LiteralValue.find('f') == std::string::npos) {
		try {
			this->intRep = static_cast<int>(std::stoi(this->LiteralValue));
			this->Flag += 32; // += 0010 0000;
			return ;
		} catch (...) {}
	}
	
	//Float goes third.
	// If it does contain an f and a dot: 
	if (this->LiteralValue.find('.') != std::string::npos && this->LiteralValue.find('f') != std::string::npos) {
		try {
			this->floatRep = static_cast<float>(std::stof(this->LiteralValue));
			this->Flag += 64; // += 0100 0000;
			return ;
		} catch (...) {}
	}

	//Double goes last.
	// It does not need any condition.
	try {
		this->doubleRep = static_cast<double>(std::stod(this->LiteralValue));
		this->Flag += 128; // += 1000 0000;
		return ;
	} catch(...) {
		this->Flag += (1 + 2 + 4 + 8); // += 0000 1111 // sets all representations to impossible.
	}


}

// No flag is set to impossible unless all possible casts have failed. Checking just
// one of these flags is already checking if these case has happened.
void	SC::DoConversions( void ) {

	if ((this->Flag & 0xffff) <= 8)
		return ;

	// If it is a char.
	if ((this->Flag & 16) == 16) {

		try {
			this->intRep = static_cast<int>(this->charRep);
		}catch (...){
			this->Flag += 2;
		}

		try {
			this->floatRep = static_cast<float>(this->charRep);
		}catch (...){
			this->Flag += 4;
		}

		try {
			this->doubleRep = static_cast<double>(this->charRep);
		}catch (...) {
			this->Flag += 8;
		}
	}

	//If it is an int:
	if ((this->Flag & 32) == 32) {

		try {
			this->charRep = static_cast<char>(this->intRep);
		}catch (...){
			this->Flag += 1;
		}

		try {
			this->floatRep = static_cast<float>(this->intRep);
		}catch (...){
			this->Flag += 4;
		}

		try {
			this->doubleRep = static_cast<double>(this->intRep);
		}catch (...) {
			this->Flag += 8;
		}
	}

	//If it is a float:
	if ((this->Flag & 64) == 64) {

		try {
			this->charRep = static_cast<char>(this->floatRep);
		}catch (...){
			this->Flag += 1;
		}

		try {
			this->intRep = static_cast<int>(this->floatRep);
		}catch (...){
			this->Flag += 2;
		}

		try {
			this->doubleRep = static_cast<double>(this->floatRep);
		}catch (...) {
			this->Flag += 8;
		}
	}

	// If it is a double:	
	if ((this->Flag & 128) == 128) {

		try {
			this->charRep = static_cast<char>(this->doubleRep);
		}catch (...){
			this->Flag += 1;
		}

		try {
			this->intRep = static_cast<int>(this->doubleRep);
		}catch (...){
			this->Flag += 2;
		}

		try {
			this->floatRep = static_cast<double>(this->doubleRep);
		}catch (...) {
			this->Flag += 4;
		}
	}
}
	
void	SC::writeOutput( void ) {

	std::cout << "char: ";
	if ((this->Flag & 1) == 1)
		std::cout << "impossible" << std::endl;
	else if (!isprint(this->charRep))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "[" << this->charRep << "]" << std::endl;

	std::cout << "int: ";
	if ((this->Flag & 2) == 2)
		std::cout << "impossible" << std::endl;
	else
		std::cout << this->intRep << std::endl; 

	std::cout << "float: ";
	if ((this->Flag & 4) == 4)
		std::cout << "impossible" << std::endl;
	else if (floor(this->floatRep) == this->floatRep)
		std::cout << this->floatRep << ".0f" << std::endl;
	else
		std::cout << this->floatRep << "f" << std::endl;

	std::cout << "double: ";
	if ((this->Flag & 8) == 8)
		std::cout << "impossible" << std::endl;
	else if ( floor(this->doubleRep) == this->doubleRep )
		std::cout << this->doubleRep << ".0" << std::endl;
	else
		std::cout << this->doubleRep << std::endl;
}

