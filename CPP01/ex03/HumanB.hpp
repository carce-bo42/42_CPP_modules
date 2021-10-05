#include "Weapon.hpp"

class HumanB {

	public:

		void		attack(void) const;

		void		setWeapon(Weapon& wname);
		void		setName(std::string name);

		std::string	getWeapon(void) const;
		std::string	getName(void) const;

		HumanB(std::string name);
		~HumanB(void);

	private:

		std::string	_name;
		Weapon*		_wname;

};	
