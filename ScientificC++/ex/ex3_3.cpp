#include <iostream>
#include <fstream>
#include <cmath>

int main(int argc, char const *argv[]) {
	int N;
	std::cout << "Please input the number of grid points N: ";
	std::cin >> N;
	double h = 1.0 / (double)(N);
	double x[100], y[100];
	x[0] = 0;
	y[0] = 1;
	for (int i = 1; i < 100; i++) {
		x[i] = i * h;
		y[i] = y[i-1] / (h + 1);
	}
	std::ofstream write_result("result.dat");
	for (int i = 0; i < 100; i++) {
		write_result << x[i] << "\t" << y[i] << "\t" << exp(-x[i]) << "\n";
	}
	write_result.close();
	return 0;
}