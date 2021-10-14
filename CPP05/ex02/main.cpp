#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialForm.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialForm.hpp"

int main() {

	try {
		Bureaucrat a( "Me", 3 );
		Bureaucrat b( "Jesus", 50);
		Bureaucrat c( "Other", 146);

		//Form lol( "XD", 10, 10); //Form is now an abstract class thus uninstantiable.

		PresidentialForm pf( "Paco Sanz" );

		//pf.execute( b ); // Cannot execute unsigned form exception.

		a.signForm( pf ); 

		//pf.execute( b ); // Grade too low (to execute) exception.
		a.executeForm( pf );

		std::cout << std::endl;
		///////////////////////////////////////////////////////////////////
		std::cout << std::endl;

		RobotomyRequestForm rqf( "The White House" );

		b.signForm( rqf ); // Can be signed by b (grade 50).
		//rqf.execute( b ); // But executing it throws grade too low (to execute) exception.

		a.signForm( rqf ); 
		for (int i=0; i<20; i++) {
			a.executeForm( rqf );
		}

		std::cout << std::endl;
		///////////////////////////////////////////////////////////////////
		std::cout << std::endl;

		ShrubberyCreationForm scf( "Home" ); 
		ShrubberyCreationForm scf2( "../../../../../../../../../../../hey*$%&..:.;.,;" );

		//scf.beSigned( c ); // Grade too low (to sign) exception.

		b.signForm( scf );

		scf.beSigned( b );

		b.executeForm( scf );
		b.executeForm( scf );
		b.executeForm( scf );

		a.executeForm( scf );

		a.signForm( scf2 );
		//a.executeForm( scf2 ); //Error opening output file exception.

	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}

