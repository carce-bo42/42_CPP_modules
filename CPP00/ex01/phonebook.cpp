#include "phonebook.hpp"
#include <stdlib.h>
#include <stdio.h>

phonebook::phonebook(void) : _total_contacts(0) {

	std::cout << "Welcome to My Awesome Phonebook!\n" << std::endl;
	return  ;

}

phonebook::~phonebook(void) {

	 return ;

}

void	phonebook::general_prompt(void) {
	
	std::string	buff;

	while (42) {
		std::cin >> buff;
		if (!buff.compare(ADD)) {
			this->_prompt_for_info();
			std::cout << "Contact added!" << std::endl << std::endl;
		}
		else if (!buff.compare(SEARCH)) {
			this->_display_table();
		}
		else if (!buff.compare(EXIT)) {
			std::cout << "Program exited" << std::endl << std::endl;
			for (int i = 0; i < MAX_CONTACTS; i++)
				this->book[i].~contact();
			exit(0);
		}
		else
			std::cout << "Valid commands: ADD, SEARCH, EXIT" << std::endl << std::endl;
		buff.clear();
	}
}

void	phonebook::_prompt_for_info(void) {

	std::string buff;
	int			index;

	index = (this->_total_contacts % MAX_CONTACTS);

	std::cout << "First name:" << std::endl;
	std::cin >> buff;
	this->book[index].set_arg(FIRST_NAME, buff);
	buff.clear();

	std::cout << "Last name:" << std::endl;
	std::cin >> buff;
	this->book[index].set_arg(LAST_NAME, buff);
	buff.clear();

	std::cout << "Nickname:" << std::endl;
	std::cin >> buff;
	this->book[index].set_arg(NICKNAME, buff);
	buff.clear();

	std::cout << "Phone Number:" << std::endl;
	std::cin >> buff;
	this->book[index].set_arg(PHONE_NBR, buff);
	buff.clear();

	std::cout << "Darkest Secret:" << std::endl;
	std::cin >> buff;
	this->book[index].set_arg(SECRET, buff);
	buff.clear();

	this->_total_contacts += 1;

}

static void	display_info(std::string str) {

	if (str.length() > 10) {
		for (int i = 0; i < 9; i++) {
			std::cout << str[i];
		}
		std::cout << ".";
	}
	else {
		std::cout << std::setw(10);
		std::cout << str;
		std::cout << std::setw(0);
	}
}

static void	display_header(void) {

	display_info((std::string)("INDEX"));
	std::cout << "|";
	display_info((std::string)("FIRST_NAME"));
	std::cout << "|";
	display_info((std::string)("LAST_NAME"));
	std::cout << "|";
	display_info((std::string)("NICKNAME"));
	std::cout << "|";
	display_info((std::string)("PHONE_NBR"));
	std::cout << std::endl;

}


void	phonebook::_display_table(void) {

	if (this->book[0].get_arg(0).empty()) {
		std::cout << "No contacts to be displayed" << std::endl;
	}
	else {
		display_header();
		for (int i = 0; !this->book[i].get_arg(0).empty(); i++) {
			display_info(std::to_string(i));
			std::cout << "|";
			for (int j = 0; j < 4; j++) {
				display_info(this->book[i].get_arg(j));
				if (j != 3)
					std::cout << "|";
				else
					std::cout << std::endl;
			}
			if (i == MAX_CONTACTS - 1)
				break ;
		}
	}
	std::cout << std::endl;
}
