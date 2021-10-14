#include "RobotomyRequestForm.hpp"
#include <stdlib.h>

RQF::RQF( std::string target ) : Form( "Robotomy Request", 72, 45 ), _target( target ) {
}

RQF::RQF( RQF const &other ) : Form( other.getName(), other.getSignGrade(), other.getExecGrade() ),
							   _target( other.getTarget() ){
}

RQF::~RQF( void ) {
}

RQF&	RQF::operator = ( RQF const &other ) {

	this->_target = other.getTarget();
	return *this;
}

std::string	RQF::getTarget( void ) const {

	return this->_target;
}

void	RQF::execute( Bureaucrat const &executor ) const {

	Form::execute( executor );
	std::cout << "* Drilling noises *" << std::endl;

	int	v1 = rand() % 100 + 1; //Outputs random number c [1,100]
	if (v1 > 50)
		std::cout << this->_target << " has been succesfully robotomized!" << std::endl;
	else
		std::cout << "Robotomization of " << this->_target << "has failed!" << std::endl;
}
