#include "Karen.hpp"

int main() {

	Karen sample_karen;

	sample_karen.complain("DEBUG");
	sample_karen.complain("INFO");
	sample_karen.complain("DEBUG");
	sample_karen.complain("WARNING");
	sample_karen.complain("ERROR");
	sample_karen.complain("DEBUG");
	sample_karen.complain("ERROR");
	sample_karen.complain("WARNING");
	sample_karen.complain("ERROR");
	sample_karen.complain("ERROR");
	sample_karen.complain("DEBUG");
	sample_karen.complain("WARNING");
	sample_karen.complain("WARNING");
	sample_karen.complain("WARNING");
	sample_karen.complain("WARNING");

	//Error message when karen gets an unvalid level: (it becomes very kind and comprehensive).
	sample_karen.complain("aa");

	return 0 ;
	
}
