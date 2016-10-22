#include <iostream>

void print_matrix (int size, double** matrix) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			std::cout << matrix[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}

void minor(int size, double** matrix, int x, int y, double** result) {
	for (int i = 0, i2 = 0; i < size; i++) {
		if (i != x) {
			for (int j = 0, j2 = 0; j < size; j++) {
				if(j != y) {
					result[i2][j2] = matrix[i][j];
					j2++;
				}
			}
			i2++;
		}
	}
}

double det(int size, double** matrix) {
	if (size == 2) {
		return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
	} else {
		double det_result = 0;
		for (int i = 0; i < size; i++) {
			double** minor_m = new double*[size - 1];
			for (int j = 0; j < size - 1; j++) {
				minor_m[j] = new double[size - 1];
			}
			minor(size, matrix, 0, i, minor_m);
			if (i%2 == 0) {
				det_result += matrix[0][i] * det(size - 1, minor_m);
			} else {
				det_result -= matrix[0][i] * det(size - 1, minor_m);
			}
			for (int j = 0; j < size - 1; j++) {
				delete[] minor_m[j];
			}
			delete[] minor_m;
		}
		return det_result;
	}
}

int main(int argc, char const *argv[]) {
	int N = 1;
	do {
		std::cout << "input the size of the matrix N > 1: ";
		std::cin >> N;
	} while (N <= 1);

	double** m = new double*[N];
	for (int i = 0; i < N; i++) {
		m[i] = new double[N];
	}
	std::cout << "input the matrix:\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> m[i][j];
		}
	}
	/*
	double** minor_m = new double*[N - 1];
	for (int i = 0; i < N -1; i++) {
		minor_m[i] = new double[N - 1];
	}
	minor(N, m, 2, 2, minor_m);
	for (int i = 0; i < N -1; i++) {
		for (int j = 0; j < N -1; j++) {
			std::cout << minor_m[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	for (int i = 0; i < N - 1; i++) {
		delete[] minor_m[i];
	}
	delete[] minor_m;*/

	printf("The determinent of this matrix is %f.\n", det(N, m));

	for (int i = 0; i < N; i++) {
		delete[] m[i];
	}
	delete[] m;
	return 0;
}