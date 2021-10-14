#include "PresidentialForm.hpp"

PF::PF( std::string target ) : Form( "Presidential Form", 25, 5 ),
							_target( target ) {
}

PF::PF( PF const &other ) : Form( other.getName(), other.getSignGrade(), other.getExecGrade() ),
							_target( other.getTarget() ) {
}

PF::~PF( void ) {
}

PF&	PF::operator = ( PF const &other ) {

	this->_target = other.getTarget();
	return *this;
}

std::string	PF::getTarget( void ) const {

	return this->_target;
}

void	PF::execute( Bureaucrat const &executor ) const {

	Form::execute( executor );
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
