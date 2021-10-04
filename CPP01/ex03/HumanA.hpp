#include "Weapon.hpp"

class HumanA {

	public:

		void		attack(void) const;

		void		setName(std::string name);

		std::string	getWeapon(void) const ;
		std::string	getName(void) const;

		HumanA(std::string name, Weapon wname);
		~HumanA(void);

	private:

		std::string	_name;
		Weapon&		_wname;

};
