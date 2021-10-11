#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {

	public:

		Cat( void );
		Cat( Cat const &other );
		~Cat( void );

		Cat&	operator = ( Cat const &other );

		std::string		getType( void ) const;

		virtual void 	makeSound( void ) const;

};

class WrongCat : public WrongAnimal {

	public:

		WrongCat( void );
		WrongCat( WrongCat const &other );
		~WrongCat( void );

		WrongCat&	operator = ( WrongCat const &other );

		std::string		getType( void ) const;

		void 	makeSound( void ) const;

};

#endif
