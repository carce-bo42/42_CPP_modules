#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {

	public:

		FragTrap( void );
		FragTrap( std::string name );
		FragTrap( FragTrap const &other );
		~FragTrap( void );

		void			attack( std::string const &target );
		void			highFivesGuys( void );

		FragTrap& operator = ( FragTrap const &other );

};

#endif
