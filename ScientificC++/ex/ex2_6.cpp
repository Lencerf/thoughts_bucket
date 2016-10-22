#include <iostream>
#include <cmath>

double func_f(double x)
{
	return exp(x) + pow(x,3) -5;
}

double func_fp(double x)
{
	return exp(x) + 3 * pow(x,2);
}

int main(int argc, char const *argv[])
{
	/*
	double x[100];
	x[0] = 0;
	for (int i = 1; i < 100; i++)
	{
		x[i] = x[i-1] - func_f(x[i-1]) / func_fp(x[i-1]);
	}
	std::cout << x[99] << "\n";
	std::cout << func_f(x[99]) << "\n";
	*/
	double x_prev = 0;
	double x_next = 0;
	double epsilon = 0.1;
	std::cout << "Please inpu epsilon: ";
	std::cin >> epsilon;
	do {
		x_prev = x_next;
		x_next = x_prev - func_f(x_prev)/func_fp(x_prev);
	} while (fabs(x_next - x_prev) >= epsilon);
	std::cout << x_prev << "\n";
	printf("f(%f) = %f\n",x_next, func_f(x_next));
	return 0;
}