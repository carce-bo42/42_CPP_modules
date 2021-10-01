#include "contact.hpp"

int main()
{
	contact	lol;

	lol.set_arg(FIRST_NAME, "Christian");
	std::cout << lol.get_arg(FIRST_NAME) << std::endl;
	return 0;
}
