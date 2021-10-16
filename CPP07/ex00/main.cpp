#include "FunctionTemplates.hpp"

int main() {

	{
	int	i = 3;
	int	j = 4;

	// INT demonstrartion.
	std::cout << "Min of (" << i << " , " << j << "): " << min<int>(i,j) << std::endl;
	std::cout << "Max of (" << i << " , " << j << "): " << max<int>(i,j) << std::endl;
	std::cout << "i = " << i << " and " << "j = " << j << std::endl;
	swap<int>(i,j);
	std::cout << "After swapping:" << std::endl;
	std::cout << "i = " << i << " and " << "j = " << j << std::endl;

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
	std::cout << "i = " << i << " and " << "j = " << j << std::endl;
	swap<float>(i,j);
	std::cout << "After swapping:" << std::endl;
	std::cout << "i = " << i << " and " << "j = " << j << std::endl;

	std::cout << std::endl;
	}
	char	i = 'a';
	char	j = 'b';

	// char demonstrartion.
	std::cout << "Min of (" << i << " , " << j << "): " << min<char>(i,j) << std::endl;
	std::cout << "Max of (" << i << " , " << j << "): " << max<char>(i,j) << std::endl;
	std::cout << "i = " << i << " and " << "j = " << j << std::endl;
	swap<char>(i,j);
	std::cout << "After swapping:" << std::endl;
	std::cout << "i = " << i << " and " << "j = " << j << std::endl;

	std::cout << std::endl;
	return 0;
}
