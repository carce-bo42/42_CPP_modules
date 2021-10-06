#include "Karen.hpp"

int main(int ac, char **av) {

	if (ac != 2) {
		std::cerr << "This program admits one and only one argument" << std::endl;
		return 1 ;
	}

	Karen sample_karen;

	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	arg_level = -1;

	for (int i = 0; i < 4; i++) {
		if (!levels[i].compare(av[1])) {
			arg_level = i;
		}
	}
	int do_default = 1;

	switch (arg_level) {

		case 0 :

			std::cout << "[ DEBUG ]" << std::endl;
			sample_karen.complain("DEBUG");
			std::cout << std::endl;

		case 1 :

			std::cout << "[ INFO ]" << std::endl;
			sample_karen.complain("INFO");
			std::cout << std::endl;

		case 2 :

			std::cout << "[ WARNING ]" << std::endl;
			sample_karen.complain("WARNING");
			std::cout << std::endl;

		case 3 :

			std::cout << "[ ERROR ]" << std::endl;
			sample_karen.complain("ERROR");
			std::cout << std::endl;
			do_default = 0;

		default:

			if (do_default) 
				std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return 0 ;
}
