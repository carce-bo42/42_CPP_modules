#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap :  public ClapTrap {

	public:

		ScavTrap( void );
		ScavTrap( std::string name );
		ScavTrap( ScavTrap const &other );
		~ScavTrap( void );

		void			attack( std::string const &target );
		void					guardGate( void );

		ScavTrap&	operator = ( ScavTrap const &other );

};


#endif
