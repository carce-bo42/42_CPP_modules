#include "FunctionTemplates.hpp"

int main() {

	{
	int	i = 3;
	int	j = 4;

	// INT demonstrartion.
	std::cout << "Min of (" << i << " , " << j << "): " << min<int>(i,j) << std::endl;
	std::cout << "Max of (" << i << " , " << j << "): " << max<int>(i,j) << std::endl;
	std::cout << "Before swapping: " << "i = " << i << " and " << "j = " << j << std::endl;
	swap<int>(i,j);
	std::cout << "After swapping: " << "i = " << i << " and " << "j = " << j << std::endl;

	std::cout << std::endl;
	}
	{
	float	i = 123.51f;
	float	j = 5453.1244f;

	// FLOAT demonstrartion.
	std::cout.precision(4);
	std::cout << std::setiosflags( std::ios::fixed );
	std::cout << "Min of (" << i << " , " << j << "): " << min<float>(i,j) << std::endl;
	std::cout << "Max of (" << i << " , " << j << "): " << max<float>(i,j) << std::endl;
	std::cout << "Before swapping: " << "i = " << i << " and " << "j = " << j << std::endl;
	swap<float>(i,j);
	std::cout << "After swapping: " << "i = " << i << " and " << "j = " << j << std::endl;

	std::cout << std::endl;
	}
	{
	char	i = 'a';
	char	j = 'b';

	// char demonstrartion.
	std::cout << "Min of (" << i << " , " << j << "): " << min<char>(i,j) << std::endl;
	std::cout << "Max of (" << i << " , " << j << "): " << max<char>(i,j) << std::endl;
	std::cout << "Before swapping: " << "i = " << i << " and " << "j = " << j << std::endl;
	swap<char>(i,j);
	std::cout << "After swapping: " << "i = " << i << " and " << "j = " << j << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	}
	// Subject main:
	{
		int a = 2;
		int b = 3;

		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

		std::string c = "chaine1";
		std::string d = "chaine2";

		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	return 0;
}
