#include <iostream>

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

		std::string const&	_name;

	public:

		Character( void );
		Character( std:::string const &name );
		Character( Character const &rhs );
		~Character( void );

		Character operator = ( Characer const &rhs );

		std::string const&	getName( void ) const;
		void				equip( AMateria* m );
		void				unequip( int idx );
		void				use( int idx, ICharacter& target );

};
