#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
#include <iostream>

class Zombie {

	public:

		Zombie(std::string name);
		~Zombie(void);

		void			announce(void) const;

		std::string		get_name(void) const;
		void			set_name(std::string name);

	private:

		std::string _name;

};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif
