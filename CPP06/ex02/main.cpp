#include "Base.hpp"
#include <iostream>
#include <time.h>

Base*	generate( void ) {

	srand(time(NULL)); // initiallize random seed.

	int	val = rand() % 10;
	Base *p;
	
	if (val % 3 == 0) {
		p = new A();
	}
	else if (val % 3 == 1) {
		p = new B();
	}
	else {
		p = new C();
	}
	return p;
}
	   	
void	identify(Base& p) {

	try {
		A&	a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	} catch(...) {}
	try {
		B&	b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	} catch(...){}
	try {
		C&	c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	} catch(...) {}
	std::cout << "What did you just pass me" << std::endl;
}


void	identify(Base* p) {

	A*	a = dynamic_cast<A*>(p);
	if (a) {
		std::cout << "A" << std::endl;
		return ;
	}
	B*	b = dynamic_cast<B*>(p);
	if (b) {
		std::cout << "B" << std::endl;
		return ;
	}
	C*	c = dynamic_cast<C*>(p);
	if (c) {
		std::cout << "C" << std::endl;
		return ;
	}
	std::cout << "What did you just pass me" << std::endl;
}



