#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define ADD "ADD"
# define EXIT "EXIT"
# define SEARCH "SEARCH"

# define MAX_CONTACTS 8

#include "contact.hpp"

class phonebook {

	public:

		contact 	book[MAX_CONTACTS];
		void		general_prompt(void);

		phonebook(void);
		~phonebook(void);

	private:

		int			_total_contacts;
		void		_prompt_for_info(void);
		void		_display_table(void);

};






















#endif
