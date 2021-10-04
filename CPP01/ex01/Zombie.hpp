#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
#include <iostream>

class Zombie {

	public:

		void				announce(void) const;

		std::string			get_name(void) const;
		void				set_name(std::string name);

		Zombie(std::string name);
		Zombie(void);
		~Zombie(void);

	private:

		static int			_nbZombies;

		static int			_getNbZombies(void);
		static std::string	_create_default_name(void);	

		std::string 		_name;

};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

Zombie*	ZombieHorde(int N, std::string name);

#endif
