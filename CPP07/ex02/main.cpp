#include "Array.hpp"
#include "stdlib.h"
#define MAX_VAL 750

void	CheckLeaks( void ) {

	system( "leaks Templates3" );
}

int main() {

	atexit( CheckLeaks );
	// MY MAIN (ONLY FOR INT BUT I THINK IT WAS NEVER THE POINT).
	{
	Array<int>	a( 3 );

	a[0] = 1;
	a[1] = 2;
	a[2] = 3;

	std::cout << "size of a is: " << a.size() << std::endl;
	std::cout << "a: ";
	for (int i=0; i<3; i++) {
		std::cout << "a[" << i << "] = " << a[i] << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Assigning a to a new empty array:" << std::endl;
	std::cout << std::endl;

	Array<int> b; // No parameters.

	std::cout << "size of b (b = a) is: " << a.size() << std::endl;
	std::cout << "b: ";

	b = a;
	for (int i=0; i<3; i++) {
		std::cout << "b[" << i << "] = " << b[i] << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Contrucion by copy: " << std::endl;
	std::cout << std::endl;

	Array<int>	c( b );

	std::cout << "size of c( a ) is: " << a.size() << std::endl;
	std::cout << "c: ";

	for (int i=0; i<3; i++) {
		std::cout << "c[" << i << "] = " << c[i] << " ";
	}
	
	std::cout << std::endl;
	std::cout << std::endl;

	try {
		std::cout << "Trying to access an index out of bounds: " << std::endl;
		std::cout << std::endl;

		std::cout << a[3] << std::endl;
	} catch (Array<int>::IndexOutOfBounds &e ) {
		std::cout << e.what() << std::endl;
	}
	}
	/////////////////////////////////////////777777777777777777777777777/////
	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
	// THE INTRA MAIN:
	Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];

    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
	std::cout << std::endl;
	std::cout << std::endl;
	return 0;
}
