#include "ScalarConverter.hpp"

int main(int argc, char **argv) {

	// Some suggestions:
	//
	// CHAR_BIT    :   8
	// CHAR_MAX    :   127
	// CHAR_MIN    :   -128
	// INT_MAX     :   2147483647
	// INT_MIN     :   -2147483648
	// LONG_MAX    :   9223372036854775807
	// LONG_MIN    :   -9223372036854775808
	// SCHAR_MAX   :   127
	// SCHAR_MIN   :   -128
	// SHRT_MAX    :   32767
	// SHRT_MIN    :   -32768
	// UCHAR_MAX   :   255
	// UINT_MAX    :   4294967295
	// ULONG_MAX   :   18446744073709551615
	// USHRT_MAX   :   65535
	//FLT_MAX     :        3.402823466e+38
	//FLT_MIN     :        1.175494351e-38
	//-FLT_MAX    :       -3.402823466e+38
	//-FLT_MIN    :       -1.175494351e-38
	//DBL_MAX     :       1.79769313486232e+308 //printf rounded values, not reliable (but you can try similar magnitudes.
	//DBL_MIN     :        2.2250738585072e-308 // Same applies.
	//-DBL_MAX     :     -1.79769313486232e+308 //Same applies.
	//
	if (argc != 2)
		std::cerr << "Number of parameters MUST be 1" << std::endl;
	else {
		std::string	arg( argv[1] );
		ScalarConverter A( arg );

		A.DetectType();
		A.DoConversions();
		A.writeOutput();
	}
	return 0;
}
