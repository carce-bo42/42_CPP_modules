#include <iostream>
#include <cmath>

class Fixed {

	public:

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		float	toFloat( void ) const ;
		int		toInt( void ) const ;

		static const 	Fixed&	min( const Fixed &x, const Fixed &y );
		static const 	Fixed&	max( const Fixed &x, const Fixed &y );
		static  		Fixed&	min( Fixed &x, Fixed &y );
		static  		Fixed&	max( Fixed &x, Fixed &y );

		Fixed( void );
		Fixed( Fixed const &src );
		Fixed( int const n );
		Fixed( float const n );

		~Fixed( void );

		Fixed&	operator = ( Fixed const &rhs );

		bool	operator > ( Fixed const &rhs ) const;
		bool	operator < ( Fixed const &rhs ) const;
		bool	operator >= ( Fixed const &rhs ) const;
		bool	operator <= ( Fixed const &rhs ) const;
		bool	operator == ( Fixed const &rhs ) const;
		bool	operator != ( Fixed const &rhs ) const;

		Fixed	operator + ( Fixed const &rhs );
		Fixed	operator - ( Fixed const &rhs );
		Fixed	operator * ( Fixed const &rhs );
		Fixed	operator / ( Fixed const &rhs );

		Fixed&	operator ++ ( void ); //prefix increment
		Fixed	operator ++ ( int ); //postfix increment

		Fixed&	operator -- ( void ); //prefix decrement
		Fixed	operator -- ( int ); //postfix decrement

	private:

		int					_fpvalue;
		static const int 	_fbits = 8;

};

const Fixed&	min( Fixed const &x, Fixed const &y );
const Fixed&	max( Fixed const &x, Fixed const &y );
Fixed&			min( Fixed &x, Fixed &y );
Fixed&			max( Fixed &x, Fixed &y );
std::ostream&	operator<<( std::ostream &o, Fixed const &rhs );
