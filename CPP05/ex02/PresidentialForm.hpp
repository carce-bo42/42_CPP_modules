#ifndef PRESIDENTIALFORM_HPP
# define PRESIDENTIALFORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"

class Form;

#define PF PresidentialForm

class PF : public Form {

	private:

		std::string	_target;

	public:

		PF( std::string target );
		PF( PF const &other );
		~PF( void );

		PF& operator = ( PF const &other );

		std::string		getTarget( void ) const;
		void	execute( Bureaucrat const &executor ) const;
};

#endif
