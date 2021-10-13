#include "Bureaucrat.hpp"

int main() {

	try {

		Bureaucrat a( "Judge", 100);
		//Bureaucrat b( "Councilman", 180); //Grade too low case 
		//Bureaucrat c( "XD", -111); //Grade too high case

		Bureaucrat d( a );
		std::cout << d << std::endl;

		Bureaucrat e( "Senator", 3);

		a = e;
		std::cout << a << std::endl;
		std::cout << e << std::endl;

	}
	catch (Bureaucrat::GradeTooLowException &e ) {

		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e ) {

		std::cout << e.what() << std::endl;
	}
}

