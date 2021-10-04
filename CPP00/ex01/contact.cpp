#include "contact.hpp"

contact::contact(void) {

	for (int i = 0; i >= 4; i++)
		contact::set_arg(i, "");
	return ;

}

contact::~contact(void) {

	if (!this->get_arg(FIRST_NAME).empty()) {

		std::cout << this->get_arg(FIRST_NAME)
					<< " " << this->get_arg(LAST_NAME)
					<< "\'s information lost forever" << std::endl;

	}
	return ;

}

void	contact::set_arg(int type, std::string atr) {

	if (type == FIRST_NAME) {
		this->_first_name = atr;
	}
	else if (type == LAST_NAME) {
		this->_last_name = atr;
	}
	else if (type == NICKNAME) {
		this->_nickname = atr;
	}
	else if (type == PHONE_NBR) {
		this->_phone_nbr = atr;
	}
	else if (type == SECRET) {
		this->_secret = atr;
	}
	return ;

}

std::string	contact::get_arg(int type) const {

	if (type == FIRST_NAME) {
		return this->_first_name;
	}
	else if (type == LAST_NAME) {
		return this->_last_name; 
	}
	else if (type == NICKNAME) {
		return this->_nickname;
	}
	else if (type == PHONE_NBR) {
		return this->_phone_nbr; 
	}
	else if (type == SECRET) {
		return this->_secret; 
	}
	return NULL;
	
}
