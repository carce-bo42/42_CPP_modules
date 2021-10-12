#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include "Materia.hpp"

class AMateria;

class ICharacter {

	public:

		virtual			~ICharacter() {}
		virtual			std::string const &getName() const = 0;
		virtual void	equip(AMateria* m) = 0;
		virtual void	unequip(int idx) = 0;
		virtual void	use(int idx, ICharacter& target) = 0;

};

class Character : public ICharacter {

	private:

		void				initInventory( void );
		void				deleteInventory( void );
		void				cloneInventory( Character const &other );

		AMateria*			Inventory[4];
		std::string			_name;

	public:

		Character( void );
		Character( std::string const &name );
		Character( Character const &other );
		~Character( void );

		Character& operator = ( Character const &rhs );

		std::string const&	getName( void ) const;
		void				equip( AMateria* MateriaPtr );
		void				unequip( int idx );
		void				use( int idx, ICharacter& target );

};

#endif
