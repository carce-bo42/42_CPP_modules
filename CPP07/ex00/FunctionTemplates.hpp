#ifndef FUNCTIONTEMPLATES_HPP
# define FUNCTIONTEMPLATES_HPP

#include <iostream>
#include <iomanip>

// Swap function. Swaps the values of two arguments.
template < typename T >
void	swap( T &x, T &y ) {

	if (&x != &y ) {
		T aux = x; // If it is stored in a reference, y = aux will seek the value of x which has changed to the value of y thus not swapping correctly for the previous x value.
		x = y;
		y = aux;
	}
}

template < typename T >
T const &min( T const &x, T const &y ) {

	return ( x < y ? x : y );
}

template < typename T >
T const &max( T const &x, T const &y ) {

	return ( x > y ? x : y );
}

#endif
