#include <iostream>

class Karen {

	public:

		void	complain(std::string level);

		Karen(void);
		~Karen(void);

	private:

		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

};
