#ifndef ANIMAL_HPP
# define ANIMAL_HPP
#include <iostream>

class Animal {

	public:

		Animal( void);
		Animal( std::string name );
		Animal( Animal const &other );
		virtual ~Animal( void );

		virtual void	makeSound( void ) const = 0;
		std::string		getType( void ) const;

		Animal&	operator = ( Animal const &other );

	protected:

		std::string	_type;

};

#endif
