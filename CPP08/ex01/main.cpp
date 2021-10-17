#include "span.hpp"

int main()
{
	{ ///////// Intra test //////////
	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	}

	{
	Span sp = Span( 10000 );

	sp.addNumberNtimes( 20, 500 );
	sp.addRange( -4200, 4200 );

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	try { sp.addNumberNtimes( 1, 1000 ); }
	catch (std::exception &e) { std::cout << e.what() << std::endl; }
	}
	return 0;
}
