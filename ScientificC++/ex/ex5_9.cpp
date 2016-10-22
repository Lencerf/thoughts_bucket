#include <iostream>

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

void SolveLinear (int size, double** A, double* u, double* b) {
	const double detA = det(size, A);
	if (detA != 0) {
		std::cout << "OK\n";
	}
	for (int i = 0; i < size; i++) {
		double** matrixi = new double*[size];
		for (int j = 0; j < size; j++) {
			matrixi[j] = new double[size];
		}
		for (int j = 0; j < size; j++) {
			if (j == i) {
				for (int k = 0; k < size; k++) {
					matrixi[k][j] = b[k];
				}
			} else {
				for (int k = 0; k < size; k++) {
					matrixi[k][j] = A[k][j];
				}
			}
		}
		u[i] = det(size, matrixi) / det(size, A);
		for (int j = 0; j < size; j++) {
			delete[] matrixi[j];
		}
		delete[] matrixi;
	}
}

int main(int argc, char const *argv[]) {
	double** A = new double* [3];
	double A2[3][3] = {{1.2, 1.3, 1.4}, {3.2, 4.3, 4.5}, {3.2, 5.6, 7.8}};
	for (int i = 0; i < 3; i++) {
		A[i] = &A2[i][0];
	}
	double u[3];
	double b[3] = {3.2, 4.7, 5.2};
	SolveLinear(3, A, &u[0], &b[0]);
	for (int i = 0; i < 3; i++) {
		std::cout << u[i] << "\t";
	}
	std::cout << std::endl;
	return 0;
}