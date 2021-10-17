#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template < typename T >
class Array {

	public:

		Array( void ) : A( new T[0] ), _size( 0 ) {};

		Array( unsigned int n ) : A( new T[n] ), _size( n ) {};

		Array( Array<T> const &other ) : A( new T[other.size()] ), _size( other.size() ) {

			for (unsigned int i=0; i<other.size(); i++) {
				this->A[i] = other[i];
			}
		}

		~Array( void ) { delete [] this->A; }

		Array<T>& operator = (Array<T> const &other) {

			if (this != &other) {

				delete [] this->A;
				this->A = new T[other.size()];
				this->_size = other.size();

				for (unsigned int i=0; i<other.size(); i++) {
					this->A[i] = other[i];
				}
			}
			return *this;
		}

		T&	operator [] (unsigned int i) const {

			if (i >= this->_size) { throw IndexOutOfBounds(); }
			else { return this->A[i]; }
		}

		unsigned int	size( void ) const { return this->_size; }

		// Index out of bounds exception: 

		class	IndexOutOfBounds : public std::exception {
			public:
				virtual const char* what() const throw() {
					return( "Index out of bounds" );
				}
		};

	private:

		T*				A;
		unsigned int	_size;
};
			
#endif
