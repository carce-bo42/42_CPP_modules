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

}

#endif
