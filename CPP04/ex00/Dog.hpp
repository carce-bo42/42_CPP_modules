#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {

	public:

		Dog( void );
		Dog( Dog const &other );
		~Dog( void );

		Dog&	operator = ( Dog const &other );

		std::string		getType( void ) const;

		virtual void 	makeSound( void ) const;

}

#endif
