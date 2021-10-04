#include <iostream>

int main()
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "Address in memory of str: &str = " << &str << std::endl;
	std::cout << "Adress in memory of stringPTR:  stringPTR = " << stringPTR << std::endl;
	std::cout << "Address in memory of stringREF: &strinREF =  " << &stringREF << std::endl;
	std::cout << std::endl;

	std::cout << "string using pointer: *stringPTR = " << *stringPTR << std::endl;
	std::cout << "string using reference: stringREF = " << stringREF << std::endl;
	std::cout << std::endl;

	return 0;

}
