#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {

	public:

		Dog( void );
		Dog( Dog const &other );
		virtual ~Dog( void );

		Dog&	operator = ( Dog const &other );

		std::string		getType( void ) const;

		virtual void 	makeSound( void ) const;

};

class WrongDog : public WrongAnimal {

	public:

		WrongDog( void );
		WrongDog( WrongDog const &other );
		virtual ~WrongDog( void );

		WrongDog&	operator = ( WrongDog const &other );

		std::string		getType( void ) const;

		void 	makeSound( void ) const;

};


#endif
