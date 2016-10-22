#include <iostream>

int main(int argc, char const *argv[]) {
	int* p = new int;
	*p = 1;
	std::cout << *p << std::endl;
	delete p;
	int* p2 = new int;
	*p2 = 2;
	std::cout << *p << std::endl;
	std::cout << p << "\t" << p2 << std::endl;
	return 0;
}