#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

// Only to be called if the type/class suppports the << operator.
template < typename T >
void	displayElement( T &element ) {
	std::cout << element << " ";
}

// Only to be called if the type/class supports the += operator.
template < typename T >
void	add1( T &element ) {
	element += 1;
}

//Specialization function when it is a string since the ascci number 1 is not printable
// and I wanted to make clear the function call works for strings.
template <>
void	add1( std::string &element) {
	element += "***";
}

template < typename T >
void	subtract1( T &element ) {
	element -= 1;
}

template < typename T >
void	iter(T *array, size_t len, void (*f)(T &element)) {
	
	if (!array || !len || !f)
		return ;
	for (size_t i=0; i<len; i++) {
		(*f)(array[i]);
	}
}

#endif
