#ifndef WEAPON_HPP
# define WEAPON_HPP
#include <iostream>

class Weapon {

	public:

		std::string&	getType(void) const;
		void			setType(std::string type);

		Weapon(std::string initial_type);
		~Weapon(void);

	private:

		std::string		_type;

};

#endif 
