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
	Span sp = Span( 10000 ); // ten thousand 0's.

	sp.addNumberNtimes( 20, 500 ); // five hundred 20's.
	sp.addRange( -4200, 4200 ); // 8400 + 1 (0) numbers.

	//So far we have 8401 + 500 numbers = 8901.
	// the longest span should be 4200 - (-4200) = 8400.
	// the shortest span, since there are repeated numbers, should be 0.

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	// accessing with [] some position that IS NOT FILLED ( not necessary out of storage bounds) 
	// throws an exception:
	try {sp[9000] = 'a';}
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	// I can change any value I want using[]. Lets, for example, change the entry 8900,
	// (the one corresponding to 4200, and see how the longest span changes:
	
	sp[8900] = 10000; // longest span should now be 10000 - (-4200) = 14200.

	std::cout << sp.longestSpan() << std::endl;

	// Adding >1.099 numbers should overflow the object. 
	
	sp.addNumberNtimes( 1, 1099 ); // All good.

	try { sp.addNumberNtimes( -1, 1 ); } // this should throw a StorageOverflow exception.
	catch (std::exception &e) { std::cout << e.what() << std::endl; }
	}

	Span sp(10);
	Span sp2 = sp;

	sp2.addNumber( 1 );

	//Computing shortest/longest span on either an empty or single number instance will throw
	//an emptySearchException:
	try { sp.longestSpan(); }
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	try { sp2.shortestSpan(); }
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	sp2.addNumber( 2 );
	// To see how shortest span indeed does not compute spans between self entries: 
	std::cout << "shortest span of instance with numbers 1 and 2 is: " << sp2.shortestSpan() << std::endl;

	return 0;
}
