#include "Bureaucrat.hpp"

int main() {

	try {

		Bureaucrat a( "Judge", 20);
		Bureaucrat b( "Councilman", 50); 

		Form	c( "Divorce Papers", 60, 20);
		Form	d( "New Law", 25, 2);
		//Form	e( "aa", -1, -1); //Form grade too high exception.
		//Form	e( "aa", 151, 1511); //Form grade too low exception.

		b.signForm( c ); // Should output that c cannot be signed by b.
		a.signForm( c );

		a.signForm( c ); // Outputs that the form has already been signed.

		//d.beSigned( b ); // Form grade too high exception.
		std::cout << "/////////////////////////" << std::endl;

		d.beSigned( a );
		d.beSigned( a );

	}
	catch (Bureaucrat::GradeTooLowException &e ) {

		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e ) {

		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e ) {

		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooHighException &e ) {

		std::cout << e.what() << std::endl;
	}
}

