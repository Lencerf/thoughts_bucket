#include <iostream>

void printInteger (int* p_x) {
	std::cout << *p_x << std::endl;
}

int main(int argc, char const *argv[]) {
	int x = 6;
	printInteger(&x);
	return 0;
}