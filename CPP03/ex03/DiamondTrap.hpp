#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {

	public:

		DiamondTrap( void );
		DiamondTrap( std::string name );
		DiamondTrap( DiamondTrap const &other );
		~DiamondTrap( void );

		void			whoAmI( void );
		void			attack( std::string const &target );

		std::string		getName( void ) const;
		void			setName( std::string const &NewName );
		

		DiamondTrap& operator = ( DiamondTrap const &other );

	private:

		std::string	_name;

};

#endif

