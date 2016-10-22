#include <iostream>

void intAddOne (int* p_x) {
	(*p_x) ++;
}

int main(int argc, char const *argv[]) {
	int x = 5;
	intAddOne(&x);
	std::cout << x << std::endl;
	return 0;
}