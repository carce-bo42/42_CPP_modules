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
		if (levels[i] == av[1]) {
			arg_level = i;
	}

	switch (arg_level) {

		case 0 :

			std::cout << "[ DEBUG ]" << std::endl;
			sample_karen.complain("DEBUG");
			std::cout << std::endl;
			arg_level += 1;

		case 1 :

			std::cout << "[ INFO ]" << std::endl;
			sample_karen.complain("INFO");
			std::cout << std::endl;
			arg_level += 1;

		case 2 :

			std::cout << "[ WARNING ]" << std::endl;
			sample_karen.complain("WARNING");
			std::cout << std::endl;
			arg_level += 1;

		case 3 :

			std::cout << "[ ERROR ]" << std::endl;
			sample_karen.complain("ERROR");
			std::cout << std::endl;
			break ;

		default:

			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break ; 
	}
}






	return 0 ;
	
}
