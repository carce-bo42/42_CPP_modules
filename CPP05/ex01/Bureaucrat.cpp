#include "Bureaucrat.hpp"

void	Bureaucrat::errorCheck( int grade ) {

	if (grade > 150)
		throw Bureaucrat::GradeTooLowException() ;
	else if (grade <= 0)
		throw Bureaucrat::GradeTooHighException() ;
	else
		return ;
}

Bureaucrat::Bureaucrat( std::string const name, int grade ) : _name( name ), _grade( grade ) {

	errorCheck( grade );
}

Bureaucrat::Bureaucrat( Bureaucrat const &other ) : _name( other.getName() ), _grade( other.getGrade() ) {
	//An errorCheck( other.grade ) here would be redundant (A bureaucrat cannot exist
	//if it does not have a valid grade, hence copying one that exists ensures that the
	//grade copied is correct.
}

Bureaucrat::~Bureaucrat( void ) {
}

Bureaucrat&	Bureaucrat::operator = ( Bureaucrat const &other ) {

	this->_grade = other.getGrade();
	return *this;
}

std::string	const	Bureaucrat::getName( void ) const {

	return this->_name;
}

int		Bureaucrat::getGrade( void ) const {	

	return this->_grade;
}

void	Bureaucrat::upGrade( void ) {

	errorCheck( this->_grade - 1 );
	--(this->_grade);
}

void	Bureaucrat::downGrade( void ) {

	errorCheck( this->_grade + 1 );
	++(this->_grade);
}

void	Bureaucrat::signForm( Form &f ) {

	if ( this->getGrade() <= f.getSignGrade() ) {
		f.beSigned( *this );
		std::cout << "* " << *this << " signs " << f << " *" << std::endl;
	}
	else
		std::cout << *this << " cannot sign " << f << " because its grade is inferior than the required one" << std::endl;
}

std::ostream&	operator << ( std::ostream &o, Bureaucrat const &rhs ) {

	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return o;
}
