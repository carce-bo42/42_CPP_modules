#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialForm.hpp"

class Intern {

	public:

		Intern( void );
		Intern( Intern const &other );
		~Intern( void );

		Intern&	operator = (Intern const &other );

		static Form*					makeSCF( std::string target );
		static Form*					makeRQF( std::string target );
		static Form*					makePF( std::string target );

		static Form*	makeForm( std::string FormType, std::string FormTarget );

		class NoSuchFormException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ( "No such form" );
				}
		};

	private:

		static Form*					(*makers[3])(std::string target);
		static std::string const		FormTypes[3];
};
