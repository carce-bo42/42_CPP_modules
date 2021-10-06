#include <iostream>
#include <cmath>

class Fixed {

	public:

		int		getRawBits( void ) const;
		void	setRawBits( int const waw );

		float	toFloat( void ) const ;
		int		toInt( void ) const ;

		Fixed( void );
		Fixed( Fixed const & src );
		Fixed( int const n );
		Fixed( float const n );

		~Fixed( void );

		bool	operator=( Fixed const & rhs );
		bool	operator>( Fixed const & rhs );
		bool	operator>( Fixed const & rhs );
		bool	operator>=( Fixed const & rhs );
		bool	operator<=( Fixed const & rhs );
		bool	operator==( Fixed const & rhs );
		bool	operator!=( Fixed const & rhs );

		Fixed	operator+( Fixed const & rhs );
		Fixed	operator-( Fixed const & rhs );
		Fixed	operator*( Fixed const & rhs );
		Fixed	operator/( Fixed const & rhs );

		Fixed & opera


	private:

		int					_fpvalue;
		static const int 	_fbits = 8;

};

std::ostream &	operator<<( std::ostream & o, Fixed const & rhs );
