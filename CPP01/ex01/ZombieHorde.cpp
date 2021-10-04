#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name) {

	Zombie*	Zombie_array = new Zombie[N];	
	for (int i = 0; i < N; i++)
		Zombie_array[i].set_name(name);
	return Zombie_array ;

}
