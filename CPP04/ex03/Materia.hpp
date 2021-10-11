#include <iostream>
#include "ICharacter.hpp"

class AMateria;

class IMateriaSource {

	public:

		virtual	IMateriaSource( void );
		virtual	~IMateriaSource() {}

		virtual void		learnMateria(AMateria*) = 0;
		virtual	AMateria*	createMateria(std::string const &type) = 0;

};

class MateriaSource : public IMateriaSource {

	public:

		MateriaSource( void );
		MateriaSource( MateriaSource const &other );
		~MateriaSource( void );

		MateriaSource operator = ( MateriaSource const &other );

		void			learnMateria( AMateria* MateriaPtr );
		AMateria*		createMateria( std::string const &type );

	private:

		AMateria*	SourceInventory[4];

};

class AMateria {

	protected:

		std::string	type;

	public:

		AMateria( void );
		AMateria( std::string const &type );
		AMateria( AMateria const &rhs );
		~AMateria( void );

		AMateria	operator = ( AMateria const &rhs );

		std::string const&		getType( void ) const;
		virtual AMateria*		clone( void ) const = 0;
		virtual void 			use( ICharacter& target);

};

class Ice : public AMateria {

	public:

		Ice( void );
		Ice( Ice const &rhs );
		~Ice( void );

		Ice	operator = ( Ice const  &rhs );

		virtual void		use( ICharacter& target );
		AMateria*			clone( void ) const;

};

class Cure : public AMateria {

	public:

		Cure( void );
		Cure( Cure const &rhs );
		~Cure( void );

		Cure	operator = ( Cure const  &rhs );

		virtual void		use( ICharacter& target );
		AMateria*			clone( void ) const;

};
