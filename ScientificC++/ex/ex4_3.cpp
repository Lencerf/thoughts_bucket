#include <iostream>
#include <cmath>

int main(int argc, char const *argv[]) {
	double dot_p = 0;
	for (int j = 0; j < 100000; j++) {
		double* v1 = new double[3];
		double* v2 = new double[3];
		for (int i = 0; i < 3; i++) {
			v1[i] = exp(i);
			v2[i] = pow(i,2);
		}
		dot_p = 0;
		for (int i = 0; i < 3; i++) {
			dot_p += v1[i] * v2[i];
		}
		delete[] v1;
		delete[] v2;
	}
	std::cout << dot_p << std::endl;
	return 0;
}