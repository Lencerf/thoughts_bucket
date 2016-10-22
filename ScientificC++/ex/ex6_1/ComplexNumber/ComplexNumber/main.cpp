#include <iostream>
#include "ComplexNumber.hpp"

int main(int argc, char const *argv[]) {
	ComplexNumber z(1, -1);
	std::cout << z.GetRealPart() << std::endl;
	std::cout << RealPart(z) << std::endl;

	std::cout << z << std::endl;
	ComplexNumber z2(z);
	std::cout << z2 << std::endl;
	return 0;
}