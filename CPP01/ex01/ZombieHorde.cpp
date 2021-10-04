#include "Zombie.hpp"

Zombie*	ZombieHorde(int N, std::string name) {

	Zombie* Zombie_array = NULL;
	if (N < 0)
		std::cout << "Not a valid number of Zombies in array." << std::endl;
	else {
		Zombie_array = new Zombie[N];
		for (int i = 0; i < N; i++)
			Zombie_array[i].set_name(name);
	}
	return Zombie_array ;
}
