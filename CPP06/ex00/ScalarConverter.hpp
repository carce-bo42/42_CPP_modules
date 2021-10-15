#include <iostream>
#include <cmath>

#define SC ScalarConverter

class ScalarConverter {

	private:

		// Rep stands for Representation.
		
		std::string		LiteralValue;
		int				intRep;
		float			floatRep;
		char			charRep;
		double			doubleRep;

		// the initial 4bits from this value will be
		// respectively set to 1 in case an exception is
		// thrown by any of the data type conversors I use
		// (stoi, stof, stod):
		// Flag & 0000 0000 0000 0001 = char flag;
		// Flag & 0000 0000 0000 0010 = int flag.
		// Flag & 0000 0000 0000 0100 = float flag;
		// Flag & 0000 0000 0000 1000 = double flag;
		// Flag & 0000 0000 0001 0000 = is char flag;
		// Flag & 0000 0000 0010 0000 = is int flag;
		// Flag & 0000 0000 0100 0000 = is float flag;
		// Flag & 0000 0000 1000 0000 = is double flag;
		//

		unsigned short int		Flag;

	public:

		SC( std::string s );
		SC( SC const &other );
		~SC( void );

		SC& operator = ( SC const &other );

		std::string		getLiteralValue( void ) const;
		int				getIntRep( void ) const;
		float			getFloatRep( void ) const;
		char			getCharRep( void ) const;
		double			getDoubleRep( void ) const;

		short int		getFlag( void ) const;

		void			DoConversions( void );
		void			DetectType( void );
		void			writeOutput( void );
};
