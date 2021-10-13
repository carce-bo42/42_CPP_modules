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

		// Exception when incrementing  grade higher than 1 (maximum rank).
		/*for (int i=0; i<100; i++) {
			std::cout << a << std::endl;
			a.upGrade(); 
		}*/                         

		a = d;
		std::cout << std::endl;

		// Exception when decrementing grade lower than 150 (minimum rank).
		/*for (int i=0; i<200; i++) {
			std::cout << a << std::endl;
			a.downGrade(); 
		}*/

	}
	catch (Bureaucrat::GradeTooLowException &e ) {

		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e ) {

		std::cout << e.what() << std::endl;
	}
}

