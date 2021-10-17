#include <iostream>
#include <vector>

class Span {

	public:

		Span( unsigned int N );
		Span( Span const &other );
		~Span( void );

		Span&	operator = ( Span const &other );
		int&	operator [] ( unsigned int entry ) const;

		void	addNumber( int n );
		void	addNumberNtimes( int n, unsigned int times);
		void	addRange( int start, int end );

		unsigned int	maxSize( void ) const;
		unsigned int	currentSize( void ) const;

		ssize_t		longestSpan( void ) const;
		ssize_t		shortestSpan( void ) const;

		// Index out of bounds exception:
		class	IndexOutOfBounds : public std::exception {
			public:
				virtual const char* what() const throw() {
					return( "Index out of bounds" );
				}
		};

		class	StorageOverflow : public std::exception {
			public:
				virtual const char* what() const throw() {
					return( "Storage of Span overflowed" );
				}
		};

		class	EmptySpanSearch : public std::exception {
			public:
				virtual const char* what() const throw() {
					return( "Cannot compute Span over empty or single value object" );
				}
		};

	private:

		unsigned int		_N;
		std::vector<int>	_v;
		unsigned int		_stored;
};
