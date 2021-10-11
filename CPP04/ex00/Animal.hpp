#ifndef ANIMAL_HPP
# define ANIMAL_HPP
#include <iostream>

class Animal {

	public:

		Animal( void);
		Animal( std::string name );
		Animal( Animal const &other );
		~Animal( void );

		virtual void	makeSound( void ) const;
		std::string		getType( void ) const;

		Animal&	operator = ( Animal const &other );

	protected:

		std::string	_type;

};

class WrongAnimal {

	public:

		WrongAnimal( void);
		WrongAnimal( std::string name );
		WrongAnimal( WrongAnimal const &other );
		~WrongAnimal( void );

		void	makeSound( void ) const;
		std::string		getType( void ) const;

		WrongAnimal&	operator = ( WrongAnimal const &other );

	protected:

		std::string	_type;

};


#endif
