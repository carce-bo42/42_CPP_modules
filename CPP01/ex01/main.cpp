#include "Zombie.hpp"

int main()
{
	int N = 100;

	// Creation of Zombie Horde with their default names:
	Zombie* zombie_array = ZombieHorde(N, "Dumb Zombie");

	// Proof that the names have been propperly set: 
	for (int i= 0; i < N; i++) {
		zombie_array[i].announce();
	}

	//Deletion of the zombie array and all its entries:
	delete [] zombie_array;

	return 0;
}
