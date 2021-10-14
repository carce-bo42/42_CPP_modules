#include "Form.hpp"
#include "Bureaucrat.hpp"

void	Form::gradeErrorCheck( int grade ) const {

	if (grade > 150)
		throw Form::GradeTooLowException() ;
	else if (grade <= 0)
		throw Form::GradeTooHighException() ;
	else
		return ;
}

void	Form::signatureErrorCheck( int gradeRequired, int grade ) const { 

	if ( grade > gradeRequired )
		throw Form::GradeTooLowException();
}

Form::Form( std::string name, int signGrade, int execGrade ) : _signed( false ),
															   _name( name ),
															   _signGrade( signGrade ),
															   _execGrade( execGrade ) {
	gradeErrorCheck( signGrade );
	gradeErrorCheck( execGrade );
}

Form::Form( Form const &other ) : _signed( other.getSignState() ),
								  _name( other.getName() ),
								  _signGrade( other.getSignGrade() ),
								  _execGrade( other.getExecGrade() ) {
}

Form::~Form( void ) {
}

Form&	Form::operator = ( Form const &other ) {

	this->_signed = other.getSignState();
	return *this;
}

bool	Form::getSignState( void ) const {
	return this->_signed;
}

std::string const	Form::getName( void ) const {
	return this->_name;
}

int		Form::getSignGrade( void ) const {
	return this->_signGrade;
}

int		Form::getExecGrade( void ) const {
	return this->_execGrade;
}

void	Form::beSigned( Bureaucrat const &b ) {

	if (this->_signed) {
		std::cout << *this << " has already been signed." << std::endl;
		return ;
	}
	signatureErrorCheck( this->getSignGrade(), b.getGrade() ); 
	this->_signed = true ;
}

void	Form::execute( Bureaucrat const &executor ) const {

	if (!this->getSignState())
		throw Form::UnsignedFormException() ;
	if (this->getExecGrade() <= executor.getGrade())
		throw Form::GradeTooLowException() ;
}

std::ostream& operator << ( std::ostream &o, Form const &f ) {

	std::string	state;

	if (f.getSignState())
		state = "signed";
	else
		state = "unsigned";
	// GRS: Grade Required to Sign, GRE: Grade Required to Exec.
	o << "Form( " << f.getName() << ") = " << "{ State: " << state
		<< " , GRS: " << f.getSignGrade() << " , GRE: " << f.getExecGrade() << " }";
	return o;
}
