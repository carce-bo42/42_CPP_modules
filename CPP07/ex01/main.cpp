#include "iter.hpp"

int main() {

	{
		//With ints:
		int	Array[5] = { 1, 2, 3, 4, 5 };

		iter( Array, 5, displayElement<int>);
		std::cout << std::endl;
		iter( Array, 5, add1<int>);
		std::cout << std::endl;
		iter( Array, 5, displayElement<int>);
		std::cout << std::endl;
		iter( Array, 5, subtract1<int>);
		std::cout << std::endl;
		iter( Array, 5, displayElement<int>);
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
	}
	{
		//With chars:
		char	Array[5] = { 'a', 'b', 'c', 'd', 'e'};

		iter( Array, 5, displayElement<char>);
		std::cout << std::endl;
		iter( Array, 5, add1<char>);
		std::cout << std::endl;
		iter( Array, 5, displayElement<char>);
		std::cout << std::endl;
		iter( Array, 5, subtract1<char>);
		std::cout << std::endl;
		iter( Array, 5, displayElement<char>);
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
	}
	{
		//With strings:
		std::string	Array[5] = { "first", "second", "third", "fourth", "fifth"};

		iter( Array, 5, displayElement<std::string>);
		std::cout << std::endl;
		iter( Array, 5, add1<std::string>);
		std::cout << std::endl;
		iter( Array, 5, displayElement<std::string>);
		std::cout << std::endl;
		//std::string has no viable overloaded -= operator, thus the line subtracting had to be omitted.
	}
	return 0;
}
