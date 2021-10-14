#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"

class Form;

#define SCF ShrubberyCreationForm 

class SCF : public Form {

	private:

		std::string _target;

	public:

		SCF( std::string target );
		SCF( SCF const &other );
		~SCF( void );

		SCF& operator = ( SCF const &other );
		
		std::string		getTarget( void ) const;
		void			execute( Bureaucrat const &executor ) const;

		class OutputFileFailException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ( "Error opening output file" );
				}
		};
};

#endif
