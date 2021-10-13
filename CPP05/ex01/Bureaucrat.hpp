#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat {

	private:

		void				errorCheck( int grade );

		std::string const	_name;
		int					_grade;

	public:
	
		Bureaucrat( std::string name, int grade );
		Bureaucrat( Bureaucrat const &other );
		~Bureaucrat( void );

		Bureaucrat&	operator = ( Bureaucrat const &other );

		std::string const		getName( void ) const;
		int						getGrade( void ) const;

		void					upGrade( void );
		void					downGrade( void );

		void					signForm( Form &f ); 

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return( "Grade too high" );
				}
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ( "Grade too low" );
				}
		};
};

std::ostream&	operator << ( std::ostream &o, Bureaucrat const &rhs );

#endif 
