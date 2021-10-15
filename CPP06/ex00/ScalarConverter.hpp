#include <iostream>
#include <string>

#define SC ScalarConverter

class ScalarConverter {

	private:

		// Rep stands for Representation.

		std::string		LiteralValue;
		int				intRep;
		float			foatRep;
		char			charRep;
		double			doubleRep;

	public:

		SC( std::string s );
		SC( SC const &other );
		~SC( void );

		SC operator = ( SC const &other );

		std::string		getLiteralValue( void );
		int				getIntRep( void );
		float			getfloatRep( void );
		char			getCharRep( void );
		double			getDoubleRep( void );

		void			DoConversions( void );
		void			writeOutput( void );
};

