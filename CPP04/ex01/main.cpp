#include "Dog.hpp"
#include "Cat.hpp"
#include <stdlib.h>

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	system("leaks Animals_test2");
	delete i;
	system("leaks Animals_test2");
	return 0;
}
