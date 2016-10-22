#include <iostream>
#include "DoubleVector.h"

int main(int argc, char const *argv[]) {
	DoubleVector<5> v;
	v[0] = 1.0;
	std::cout << v[0] << std::endl;
	v[7] = 5.0;
	return 0;
}