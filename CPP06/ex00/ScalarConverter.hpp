#include <iostream>
#include <string>

#define SC ScalarConverter

class ScalarConverter {

	private:

		// Rep stands for Representation.


		// the initial 4bits from this value will be
		// respectively set to 1 in case an exception is
		// thrown by any of the data type conversors I use
		// (stoi, stof, stod):
		// ImpossibleFlag ^ 0000 0001 = int flag.
		// ImpossibleFlag ^ 0000 0010 = float flag;
		// ImpossibleFlag ^ 0000 0100 = char flag;
		// ImpossibleFlag ^ 0000 1000 = double flag;

		short int		impossibleFlag;

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

		short int		getImpossibleFlag( void );

		void			DoConversions( void );
		void			writeOutput( void );
};

