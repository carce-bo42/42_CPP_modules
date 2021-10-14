#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialForm.hpp"

Intern::Intern( void ) {
}

Intern::Intern( Intern const &other ) {
	(void) other;
}

Intern::~Intern( void ) {
}

Intern&	Intern::operator = ( Intern const &other ) {
	(void) other;
	return *this;
}

Form*	Intern::makeSCF( std::string target )  {
	return new ShrubberyCreationForm( target ); 
}

Form*	Intern::makeRQF( std::string target )  {
	return new RobotomyRequestForm( target );
}

Form*	Intern::makePF( std::string target )  {
	return new PresidentialForm( target );
}

Form*	Intern::makeForm( std::string FormType, std::string FormTarget )  {

	for (int i=0; i<3; i++) {
		if (!FormType.compare(Intern::FormTypes[i])) {
			return ( (*Intern::makers[i])(FormTarget) );
		}
	}
	std::cout << "Intern: These are the FormTypes I am able to process:" << std::endl;
	for (int i=0; i<3; i++) {
		std::cout << "        - " << Intern::FormTypes[i] << std::endl;
	}
	throw NoSuchFormException() ;
	return NULL;
}

Form*	(*Intern::makers[3])(std::string target) = {&Intern::makeSCF, &Intern::makeRQF, &Intern::makePF};
std::string const	Intern::FormTypes[3] = { "shrubbery creation", "robotomy request", "presidential" };
