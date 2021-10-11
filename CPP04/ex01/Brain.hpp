#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain {

	public:

		Brain( void );
		Brain( Brain const &other );
		~Brain( void );

		std::string	getIdea( int idx ) const;
		void		setIdea( int idx, std::string idea );

		Brain&	operator = (Brain const &other );

	protected:

		std::string	_ideas[100];

};

#endif
