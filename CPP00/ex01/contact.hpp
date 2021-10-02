#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

# define FIRST_NAME 0
# define LAST_NAME 	1
# define NICKNAME 	2
# define PHONE_NBR	3
# define SECRET		4

class contact {

	public:

		void			set_arg(int type, std::string atr);
		std::string		get_arg(int type) const;

		contact(void);
		~contact(void);

	private:

		std::string		_first_name;
		std::string		_last_name;
		std::string		_nickname;
		std::string		_phone_nbr;
		std::string		_secret;

};

#endif
