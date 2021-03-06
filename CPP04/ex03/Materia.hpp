#ifndef MATERIA_HPP
# define MATERIA_HPP

#include "Character.hpp"

class ICharacter;

class AMateria {

	protected:

		std::string	type;

	public:

		AMateria( void );
		AMateria( std::string const &type );
		AMateria( AMateria const &rhs );
		virtual ~AMateria( void );

		AMateria&	operator = ( AMateria const &rhs );

		std::string const&		getType( void ) const;
		virtual AMateria*		clone( void ) const = 0;
		virtual void 			use( ICharacter& target);

};

class Ice : public AMateria {

	public:

		Ice( void );
		Ice( Ice const &rhs );
		~Ice( void );

		Ice&	operator = ( Ice const  &rhs );

		virtual void		use( ICharacter& target );
		AMateria*			clone( void ) const;

};

class Cure : public AMateria {

	public:

		Cure( void );
		Cure( Cure const &rhs );
		~Cure( void );

		Cure&	operator = ( Cure const  &rhs );

		virtual void		use( ICharacter& target );
		AMateria*			clone( void ) const;

};

#endif
