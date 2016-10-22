#include <iostream>
#include <cmath>

double pNorm(int size, double* vec, int p = 2) {
	double temp = 0;
	for (int i = 0; i < size; i++) {
		temp += pow(fabs(vec[i]), p);
	}
	return pow(temp, 1.0 / (double)(p));
}

int main(int argc, char const *argv[]) {
	int N;
	std::cout << "input the dimension of v:";
	std::cin >> N;
	double* vec = new double[N];
	std::cout << "input the vector: ";
	for (int i = 0; i < N; i++) {
		std::cin >> vec[i];
	}
	int p = 2;
	std::cout << "input p: ";
	std::cin >> p;
	printf("The 2-norm of vec is %f.\n", pNorm(N, vec));
	printf("The %d-norm of vec is %f.\n", p, pNorm(N, vec, p));
	delete[] vec;
	return 0;
}