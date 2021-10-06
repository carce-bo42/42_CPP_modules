#include <iostream>

class Fixed {

	public:

		int		getRawBits( void ) const;
		void	setRawBits( int const waw );

		Fixed( void );
		Fixed( Fixed const & src );

		~Fixed( void );

		Fixed &	operator=( Fixed const & rhs );

	private:

		int					_fpvalue;
		static const int 	_fbits = 8;

};

