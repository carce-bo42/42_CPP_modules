#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat {

	public:

		class GradeTooHighException : public std::exception {

			public:

				virtual const char* what() const throw() {

					return( "Grade Too High" );
				}
		};

		class GradeTooLowException : public std::exception {

			public:

				virtual const char* what() const throw() {

					return ( "Grade Too Low" );
				}
		};
		
		Bureaucrat( std::string name, int grade );
		Bureaucrat( Bureaucrat const &other );
		~Bureaucrat( void );

		Bureaucrat&	operator = ( Bureaucrat const &other );

		std::string const		getName( void ) const;
		int						getGrade( void ) const;

		void					upGrade( void );
		void					downGrade( void );

	private:

		void				ErrorThrower( int grade );

		std::string const	_name;
		int					_grade;
};

std::ostream&	operator << ( std::ostream &o, Bureaucrat const &rhs );

#endif 
