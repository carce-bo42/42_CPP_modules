#include "mutantstack.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);

	std::cout << "Element at the top (end): " << mstack.top() << std::endl;

	mstack.pop(); // Removes element at the top.

	std::cout << "Size of the stack: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << "Size before iteration: " << mstack.size() << std::endl;

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Iterator for constructed by deep copy stack: " << std::endl;

	std::stack<int> s(mstack);
	// Until here is the intra provided main (a bit formatted so it is clearer).

	MutantStack<int> s1(mstack);

	for (int i = 0; i < 5; i++) { mstack.pop(); }  // Remove all elements from mstack

	MutantStack<int>::const_iterator cit = s1.begin();
	MutantStack<int>::const_iterator cite = s1.end();

	//*cit = 3; Does not work since it is a contant iterator. 
	
	++cit;
	--cit;

	while (cit != cite) 
	{
		std::cout << *cit << std::endl;
		++cit;
	}
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "reverse iteration for deep copied = operator: " << std::endl;

	MutantStack<int>	s2;

	s2 = s1;
	for ( int i = 0; i< 5; i++ ) { s1.pop(); } //remove elements from s1.

	MutantStack<int>::reverse_iterator rit = s2.rbegin();
	MutantStack<int>::reverse_iterator rite = s2.rend();

	++rit;
	--rit;
	while (rit != rite) 
	{
		std::cout << *rit << std::endl;
		++rit;
	}

	return 0;
}
