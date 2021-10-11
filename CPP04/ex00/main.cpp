#include "Dog.hpp"
#include "Cat.hpp"
#include <stdlib.h>

int main()
{
	{
		std::cout << "Example:" << std::endl;
		std::cout << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		delete meta;
		delete i;
		delete j;
		//system("leaks Animals_test1");
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Wrong Example:" << std::endl;
	std::cout << std::endl;

	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* j = new WrongDog();
	const WrongAnimal* i = new WrongCat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete i;
	delete j;
	//system("leaks Animals_test1");
	return 0;
}
