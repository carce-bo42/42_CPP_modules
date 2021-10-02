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

	while (42) {
		std::cin >> buff;
		if (!buff.compare(ADD)) {
			for (int i = 0; i < 5; i++) {
				this->_prompt_for_info(i);
			}
		}
		else if (!buff.compare(SEARCH)) {
			this->_display_table();
		}
		else if (!buff.compare(EXIT)) {
			std::cout << "Program exited" << std::endl;
			for (int i = 0; i < MAX_CONTACTS; i++)
				this->book[i].~contact();
			exit(0);
		}
		else
			std::cout << "Valid commands: ADD, SEARCH, EXIT" << std::endl;
		buff.clear();
	}
}

void	contact::_prompt_for_info(int type)

	std::string buff;
	int			index;

	index = this->_total_contacts % MAX_CONTACTS;

	std::cout << "First name:" << std::endl;
	std::cin >> buff;
	this->book[index].set_arg(FIRST_NAME, buff);

	std::cout << "Last name:" << std::endl;
	std::cin >> buff;
	this->book[index].set_arg(FIRST_NAME, buff);

	std::cout << "Nickname:" << std::endl;
	std::cin >> buff;
	this->book[index].set_arg(FIRST_NAME, buff);

	std::cout << "Phone Number:" << std::endl;
	std::cin >> buff;
	this->book[index].set_arg(FIRST_NAME, buff);

	std::cout << "Darkest Secret:" << std::endl;
	std::cin >> buff;
	this->book[index].set_arg(FIRST_NAME, buff);

	this->_total_contacts += 1;

}


