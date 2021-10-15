#include "Data.hpp"

uintptr_t	serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*	deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}

int main() {

	{
	Data*	a = new Data(3);

	std::cout << "Value in Data using starting pointer: " << a->getNbr() << std::endl;

	std::cout << std::endl;

	std::cout << "Pointer to Data before seriaization: " << a <<std::endl;
	uintptr_t	a_uintptr = serialize(a);
	std::cout << "Pointer to Data after serialization: " << a_uintptr << std::endl;
	Data* c = deserialize( a_uintptr );
	std::cout << "Pointer to Data after deserialization " << c << std::endl;

	std::cout << std::endl;

	std::cout << "Value in Data using deserializedseriazed pointer: " << c->getNbr() << std::endl;
	delete c;
	}
	Data*	a = new Data(-123);

	std::cout << "Value in Data using starting pointer: " << a->getNbr() << std::endl;

	std::cout << std::endl;

	std::cout << "Pointer to Data before seriaization: " << a <<std::endl;
	uintptr_t	a_uintptr = serialize(a);
	std::cout << "Pointer to Data after serialization: " << a_uintptr << std::endl;
	Data* c = deserialize( a_uintptr );
	std::cout << "Pointer to Data after deserialization " << c << std::endl;

	std::cout << std::endl;

	std::cout << "Value in Data using deserializedseriazed pointer: " << c->getNbr() << std::endl;
	delete c;
}



