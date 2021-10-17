#include "span.hpp"
#include <cmath>
#include <iterator>
#include <limits>

Span::Span( unsigned int N ) : _N( N ), _stored( 0 ) {
}

Span::Span( Span const &other ) : _N( other.maxSize() ), _stored( other.currentSize() ) {

	for (unsigned int i=0; i<other.currentSize(); i++) {
		this->_v.push_back( other[i] );
	}
}

Span::~Span( void ) {
}

Span&	Span::operator = ( Span const &other ) {

	if (this != &other ) {

		this->_N = other.maxSize();

		for (unsigned int i=0; i < this->_stored; i++) {
			this->_v.pop_back();
		}

		this->_stored = other.currentSize();

		for (unsigned int i=0; i < this->_stored; i++) {
			this->_v.push_back( other[i] );
		}
	}
	return *this;
}

int&	Span::operator [] (unsigned int i) const {

	if (i >= this->_stored) { throw IndexOutOfBounds(); }
	else { return const_cast<int&>(this->_v[i]); }
}

void	Span::addNumber( int n ) {

	if (this->_stored < this->_N ) {
		this->_v.push_back( n );
		++this->_stored;
	}
	else
		throw StorageOverflow() ;
}

void	Span::addNumberNtimes( int n, unsigned int times ) {

	for (unsigned int i=0; i < times; i++) {
		this->addNumber( n );
	}
}

void	Span::addRange( int start, int end ) {

	if (start == end) {
		this->addNumber( start );
	}
	else if ( start < end ) {
		unsigned int max = static_cast<unsigned int>(end - start); 

		for (unsigned int i=0; i < max; i++) {
			this->addNumber( start++ );
		}
	}
	else {
		unsigned int max = static_cast<unsigned int>(start - end);

		for (unsigned int i=0; i < max; i++) {
			this->addNumber( start-- );
		}
	}
}

unsigned int	Span::maxSize( void ) const {
	return this->_N;
}

unsigned int	Span::currentSize( void ) const {
	return this->_stored;
}

ssize_t	Span::longestSpan( void ) const {

	if (this->_stored <= 1) { throw EmptySpanSearch(); }

	ssize_t	maxSpan = 0;
	for (std::vector<int>::const_iterator it1 = this->_v.begin(); it1 < this->_v.end(); it1++) {

		for (std::vector<int>::const_iterator it2 = it1 + 1; it2 < this->_v.end(); it2++) {

			ssize_t sp = static_cast<ssize_t>(abs(*it2 - *it1));
			if (sp > maxSpan) { maxSpan = sp; }	
		}
	}
	return maxSpan;
}

ssize_t	Span::shortestSpan( void ) const {

	if (this->_stored <= 1) { throw EmptySpanSearch(); }

	ssize_t	minSpan = 0xffffffff;
	for (std::vector<int>::const_iterator it1 = this->_v.begin(); it1 < this->_v.end(); it1++) {

		for (std::vector<int>::const_iterator it2 = it1 + 1; it2 < this->_v.end(); it2++) {

			ssize_t sp = static_cast<ssize_t>(abs(*it2 - *it1));
			if (sp < minSpan) { minSpan = sp; }	
		}
	}
	return minSpan;
}

