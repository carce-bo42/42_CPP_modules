#include <iostream>
#include <stack>
#include <deque>

// from cppreference: Stack has 2 possible typenames. First, the type of the
// container, then a double ended que (deque) from which it gets its member functions,
// with the exclusion of, among others, iterators. Simply recovereing the functionality of this
// inner deque conntainer can make a stack iterable.
//
// Theres 4 of them: iterator, const_iterator, reverse_iterator, const_reverse_iterator.
// Const means it can iterate but not modify its value.
//
// The underlying container, once again from cpprenference, is called c. Anytime c is 
// used I refer to a method from the underlying deque.  
//
// Since it is still a container, it has to be implemented in a header (cannot be compiled).

template < typename T >
class MutantStack : public std::stack<T> {


	public:

		typedef	typename std::stack<T>::container_type				container_type;

		typedef typename container_type::iterator					iterator;
		typedef typename container_type::const_iterator				const_iterator;
		typedef typename container_type::reverse_iterator			reverse_iterator;
		typedef typename container_type::const_reverse_iterator		const_reverse_iterator;


		MutantStack( void ) {}
		MutantStack( MutantStack const &other ) : std::stack<T>( other ) {} // Call base class copy
		~MutantStack( void ) {}

		MutantStack&	operator = ( MutantStack const &other ) {
			if (this != &other ) {
				this->std::stack<T>::operator=(other); // Call base class equality.
			}
			return *this;
		}

		iterator	begin( void ) {
			return this->c.begin();
		}
		iterator	end( void ) {
			return this->c.end();
		}


		const_iterator	begin( void ) const {
			return this->c.begin();
		}
		const_iterator	end( void ) const {
			return this->c.end();
		}


		reverse_iterator	rbegin( void ) {
			return this->c.rbegin();
		}
		reverse_iterator	rend( void ) {
			return this->c.rend();
		}


		const_reverse_iterator	rbegin( void ) const {
			return this->c.rbegin(); 
		}
		const_reverse_iterator	rend( void ) const {
			return this->c.redn();
		}

};
