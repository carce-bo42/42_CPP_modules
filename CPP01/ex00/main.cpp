#include "Zombie.hpp"

int main() {

	// By normal initialization:

	{
	Zombie z1("Normal Christian");
	}

	//With heap allocation:
	
	{
	Zombie* z1 = new Zombie("Allocated Christian");
	z1->announce();
	delete z1;
	}

	//by calling randomChump:
	
	randomChump("randomChump Christian");
	
	//by calling newZombie (heap allocation):
	
	Zombie* Zombie_ptr;

	Zombie_ptr = newZombie("newZombie Christian");
	delete Zombie_ptr;

	std::cout << "The end" << std::endl;

	return 0;
}
