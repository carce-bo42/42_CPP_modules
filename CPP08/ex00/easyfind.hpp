#include <iostream>
#include <algorithm>

template < typename T >
typename T::iterator	easyfind( T &IntContainer, int const &toFind ) {

	typename T::iterator it;

	// easyfind will return IntContainer.end() in case it does not find it,
	// else it returns the iterator which found the first occurrency.
	try {
		it = std::find( IntContainer.begin(), IntContainer.end(), toFind );
		return (it);
	}
   	// find throws exception when (cplusplus): if either an element comparison
	// or an operation on an iterator throws.	
	catch (std::exception &e) {
		std::cout << "Find Exception: " << e.what() << std::endl; 
	}
	it = IntContainer.end();
	return (it);
}
