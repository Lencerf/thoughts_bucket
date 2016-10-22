#include <iostream>
#include "matrix2.hpp"

int main(int argc, char const *argv[]) {
	matrix2 test;
	std::cout << "test is \n" << test << std::endl;
	matrix2 test2(test);
	std::cout << "test2 is \n" << test2 << std::endl;
	matrix2 test3(1,2,3,4);
	std::cout << "test3 is \n" << test3 << std::endl;
	std::cout << "the determinant of test3 is " << test3.determinant() << std::endl;
	std::cout << "the inverse of test3 is\n" << test3.inverse() << std::endl;
	matrix2 test4 = - test3;
	std::cout << "test4 is \n" << test4 << std::endl;
	matrix2 test5= test4 + test3, test6= test4 - test3;
	std::cout << "test5 is \n" << test5 << "\ntest6 is \n" << test6 << std::endl;
	std::cout << "test6 * 2 is \n" << test6.Multiply(2) << std::endl;
	return 0;

}