#include <iostream>

int main(int argc, char const *argv[]) {
	for (int k = 0; k < 100; k++) {
		double** A = new double*[2];
		double** B = new double*[2];
		double** C = new double*[2];
		for (int i = 0; i < 2; i++) {
			A[i] = new double[2];
			B[i] = new double[2];
			C[i] = new double[2];
		}
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				A[i][j] = i + j;
				B[i][j] = i - j;
			}
		}
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				C[i][j] = A[i][j] + B[i][j];
			}
		}
		std::cout << "Matrix C is:\n";
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				std::cout << C[i][j] << "\t";
			}
			std::cout << "\n";
		}
		for (int i = 0; i < 2; i++) {
			delete[] A[i];
			delete[] B[i];
			delete[] C[i];
		}
		delete[] A;
		delete[] B;
		delete[] C;
	}
	return 0;
}