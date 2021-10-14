#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

	private:

		void				gradeErrorCheck( int grade ) const;
		void				signatureErrorCheck( int gradeRequired, int grade ) const;

		bool				_signed;
		std::string const	_name;
		int const			_signGrade;
		int const			_execGrade;

	public:

		Form( std::string name, int signGrade, int execGrade );
		Form( Form const &other );
		virtual ~Form( void );

		Form&	operator = ( Form const &other );

		bool				getSignState( void ) const;
		std::string const	getName( void ) const;
		int					getSignGrade( void ) const;
		int					getExecGrade( void ) const;

		void				beSigned( Bureaucrat const &b );
		virtual void		execute( Bureaucrat const &executor ) const = 0;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ( "Grade too high" );
				}
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ( "Grade too low" );
				}
		};

		class UnsignedFormException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ( "Cannot execute unsigned Form" );
				}
		};

};

std::ostream&	operator << ( std::ostream &o, Form const &f );

#endif
