#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {

	public:

		Dog( void );
		Dog( Dog const &other );
		virtual ~Dog( void );

		Dog&	operator = ( Dog const &other );

		std::string		getType( void ) const;

		virtual void 	makeSound( void ) const;

	private:

		Brain*	DogBrain;

};

#endif
