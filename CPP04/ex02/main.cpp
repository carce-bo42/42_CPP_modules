#include "Dog.hpp"
#include "Cat.hpp"
#include <stdlib.h>

void	leaks_check( void ) {

	system("leaks Animals_test3");
}

int main()
{
	atexit(leaks_check);
	//const Animal k; Uninstantiable since it is abstract.
	const Animal* i = new Cat();
	const Animal* j = new Dog();

	Dog k;
	Dog l( k );
	Cat m;
	Cat n( m );

	m = n;
	l = k;

	delete j;//should not create a leak
	system("leaks Animals_test3");
	delete i;
	system("leaks Animals_test3");
	return 0;
}
