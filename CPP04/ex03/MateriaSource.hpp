#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "Character.hpp"

class IMateriaSource {

	public:

		virtual	~IMateriaSource() {}

		virtual void		learnMateria(AMateria*) = 0;
		virtual	AMateria*	createMateria(std::string const &type) = 0;

};

class MateriaSource : public IMateriaSource {

	public:

		MateriaSource( void );
		MateriaSource( MateriaSource const &other );
		~MateriaSource( void );

		MateriaSource& operator = ( MateriaSource const &other );

		void			learnMateria( AMateria* MateriaPtr );
		AMateria*		createMateria( std::string const &type );

	private:

		void		initInventory( void );
		void		deleteInventory( void );
		void		cloneInventory( MateriaSource const &other );

		AMateria*	Inventory[4];

};
#endif
