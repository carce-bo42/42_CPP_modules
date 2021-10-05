#include "Karen.hpp"
#include <vector>
#include <string>

Karen::Karen(void) {

	std::cout << "*Wild Karen appears*" << std::endl;
	std::cout << "Beware suboptimal customer service providers for I have something to say to all of you!" << std::endl;
	return ;

}

Karen::~Karen(void) {

	std::cout << "See you and your manager in hell" << std::endl;
	std::cout << "*Karen suddenly explodes*" << std::endl;
	return ;

}

void	Karen::complain(std::string level) {

	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(Karen::*functions[])(void) = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error};

	for (int i = 0; i < 4; i++) {
		if (levels[i] == level) {
			(this->*functions[i])();
			return ;
		}
	}
	std::cout << "I might leave a considerable tip to you young workers, here, take these $100." << std::endl;
	return ;
}

void	Karen::debug(void) {

	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
	std::cout << "I just love it!" << std::endl;
	return ;

}

void	Karen::info(void) {

	std::cout << "I cannot believe adding extra bacon cost more money." << std::endl;
	std::cout << "You don’t put enough! If you did I would not have to ask for it!" << std::endl;
	return ;

}

void	Karen::warning(void) {

	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming here for years and you just started working here last month." << std::endl;
	return ;

}

void	Karen::error(void) {

	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
	return ;

}
