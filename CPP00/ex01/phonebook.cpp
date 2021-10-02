#include "phonebook.hpp"
#include <stdlib.h>

phonebook::phonebook(void) : _total_contacts(0) {

	std::cout << "Welcome to My Awesome Phonebook!\n" << std::endl;
	return  ;

}

contact::~contact(void) {

	 return ;

}

void	contact::general_prompt(void) {
	
	std::string	buff;

	std::cin >> buff;
	if (!buff.compare(ADD)) {
		this->total_contacts += 1;
		for (int i = 0; i < 5; i++) {
			this->_prompt_for_info(i);
		}
	}
	else if (!buff.compare(SEARCH)) {
		this->_display_table();
	}
	else if (!buff.compare(EXIT)) {
		std::cout << "Program exited\n";
		for (int i = 0; i < MAX_CONTACTS; i++)
			this->(~book[i]);
		exit(0);
	}
}

void	contact::_prompt_for_info(int type)

