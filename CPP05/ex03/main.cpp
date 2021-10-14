#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialForm.hpp"
#include "Intern.hpp"

int main() {

	try {
		Bureaucrat a( "Me", 3 );
		Bureaucrat b( "Jesus", 50);
		Bureaucrat c( "Other", 146);

		//Form lol( "XD", 10, 10); //Form is now an abstract class thus uninstantiable.

		Intern	intern;

		Form*	pf = intern.makeForm( "presidential", "Paco Sanz" );
		//PresidentialForm pf( "Paco Sanz" );

		//pf.execute( b ); // Cannot execute unsigned form exception.

		a.signForm( *pf ); 

		//pf.execute( b ); // Grade too low (to execute) exception.
		a.executeForm( *pf );

		std::cout << std::endl;
		///////////////////////////////////////////////////////////////////
		std::cout << std::endl;

		Form*	rqf = intern.makeForm( "robotomy request", "The White House" );
		//RobotomyRequestForm rqf( "The White House" );

		b.signForm( *rqf ); // Can be signed by b (grade 50).
		//rqf.execute( b ); // But executing it throws grade too low (to execute) exception.

		a.signForm( *rqf ); 
		for (int i=0; i<20; i++) {
			a.executeForm( *rqf );
		}

		std::cout << std::endl;
		///////////////////////////////////////////////////////////////////
		std::cout << std::endl;

		Form*	scf = intern.makeForm( "shrubbery creation", "Home" );
		//ShrubberyCreationForm scf( "Home" ); 

		//scf.beSigned( c ); // Grade too low (to sign) exception.

		b.signForm( *scf );

		scf->beSigned( b );

		b.executeForm( *scf );
		b.executeForm( *scf );
		b.executeForm( *scf );

		a.executeForm( *scf );

		//Form* errorform = intern.makeForm( "lol", "whatever" ); (void)errorform; //No such form error.

		//a.executeForm( scf2 ); //Error opening output file exception.

		delete pf;
		delete rqf;
		delete scf;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}

