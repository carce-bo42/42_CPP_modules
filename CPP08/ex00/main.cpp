#include "easyfind.hpp"
#include <iterator>
#include <vector>
#include <array>

int main() {

	///////////// WITH VECTOR ////////////////////////
	{
	std::vector<int>	v1(100, 0); // 100 entries with value 0.

	for (int i=0; i < 100; i++) {
		v1.push_back( i*i);
	}
	
	std::vector<int>::iterator	it = easyfind( v1, 32 );

	if (it != v1.end() )
		std::cout << "first value is at position " << std::distance(v1.begin(), it);
	else
		std::cout << "value was not found at any position" << std::endl;

	std::cout << std::endl;
	it = easyfind( v1, 81 );

	if (it != v1.end() )
		std::cout << "first value is at position " << std::distance(v1.begin(), it);
	else
		std::cout << "value was not found at any position" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	}
	
	////////////////////// WITH ARRAY /////////////////////////////////
	std::array<int, 8>	a1 = { -1, 0, -1, 0, 0, -1, 2, -1};

	std::array<int, 8>::iterator	it = easyfind( a1, -1 );

	if (it != a1.end() )
		std::cout << "first value is at position " << std::distance(a1.begin(), it);
	else
		std::cout << "value was not found at any position" << std::endl;
	
	std::cout << std::endl;
	it = easyfind( a1, 0 );
	std::cout << std::endl;

	if (it != a1.end() )
		std::cout << "first value is at position " << std::distance(a1.begin(), it);
	else
		std::cout << "value was not found at any position" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	return 0;
}





