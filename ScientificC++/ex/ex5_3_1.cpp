#include <iostream>

void swap (double* p_x1, double* p_x2) {
	double temp = *p_x1;
	*p_x1 = *p_x2;
	*p_x2 = temp;
}

int main(int argc, char const *argv[]) {
	double x1, x2;
	std::cout << "imput two numbers: ";
	std::cin >> x1 >> x2;
	printf("x1=%f, x2=%f.\n", x1, x2);
	swap(&x1, &x2);
	printf("After swap, x1=%f, x2=%f.\n", x1, x2);
	return 0;
}