#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"

class Form;

#define RQF RobotomyRequestForm


class RQF : public Form {

	private:

		std::string _target;

	public:

		RQF( std::string target );
		RQF( RQF const &other );
		~RQF( void );

		RQF& operator = ( RQF const &other );

		std::string		getTarget( void ) const;
		void			execute( Bureaucrat const &executor ) const;
};

#endif
