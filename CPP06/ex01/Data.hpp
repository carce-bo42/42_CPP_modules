#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>

class Data {

	public:

		Data( void );
		Data( int n );
		Data( Data const &other );
		~Data( void );

		Data&	operator = ( Data const &other );

		int		getNbr( void ) const ;
		void	setNbr( int n );

	private:

		int		nbr;
};

#endif
