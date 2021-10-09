#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {

	public:

		ClapTrap( std::string name );
		ClapTrap( ClapTrap const &other );
		~ClapTrap( void );

		virtual void		attack( std::string const &target );
		void				takeDamage( unsigned int amount );
		void				beRepaired( unsigned int amount );

		std::string 		getName( void ) const;
		unsigned int		getHP( void ) const;
		unsigned int		getEP( void ) const;
		unsigned int		getAD( void ) const;

		void 				setName( std::string const &NewName );
		void				setHP( unsigned int HP);
		void				setEP( unsigned int EP );
		void				setAD( unsigned int AD );

		ClapTrap&	operator = ( ClapTrap const &other );

	protected:

		std::string		_name;
		unsigned int	_HP;
		unsigned int	_EP;
		unsigned int	_AD;

};

#endif 
