#include <cmath>
#include <iostream>

double SolveNewton(double (*pFunc)(double), double (*pFuncPrime)(double), double x) {
	double step;
	do {
		step = (*pFunc)(x)/(*pFuncPrime)(x);
		x -= step;
	} while (fabs(step) > 1.0e-5);
	return x;
}

double sqrt10(double x) {
	return sqrt(x) - 10;
}

double sqrt10Prime(double x) {
	return 1.0/(2.0*sqrt(x));
}

double cube10(double x) {
	return x*x*x - 10;
}

double cube10Prime(double x) {
	return 3*x*x;
}

int main(int argc, char const *argv[]) {
	double (*p_func) (double x);
	double (*p_func2) (double x);
	p_func = cube10;
	p_func2 = &cube10;
	std::cout << cube10(10) << std::endl;
	std::cout << p_func(10) << std::endl;
	std::cout << p_func2(10) << std::endl;
	std::cout << SolveNewton(sqrt10,sqrt10Prime,1.0) << std::endl;
	std::cout << SolveNewton(cube10,cube10Prime,1.0) << std::endl;

	int a[2] = {1,2};
	int *p_x;
	std::cout << a << std::endl;
	std::cout << &a << std::endl;
	std::cout << &a[0] << std::endl;
	std::cout << &a[1] << std::endl;
	p_x = a;
	std::cout << *p_x << std::endl;
	std::cout << p_x << std::endl;
	std::cout << &p_x << std::endl;
	std::cout << &a[0] << std::endl;
	return 0;
}