#include <iostream>

void Multiply (int size, double** m1, double** m2, double** result) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			result[i][j] = 0;
			for (int k = 0; k < size; k++) {
				result[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}
}
void Multiply (int size, double* v, double** m, double* v_rusult) {
	for (int i = 0; i < size; i++) {
		v_rusult[i] = 0;
		for (int j = 0; j < size; j++) {
			v_rusult[i] += v[j] * m[j][i];
		}
	}
}
void Multiply (int size, double** m, double* v, double* v_result) {
	for (int i = 0; i < size; i++) {
		v_result[i] = 0;
		for (int j = 0; j < size; j++) {
			v_result[i] += m[i][j] * v[j];
		}
	}
}
void Multiply (int size, double s, double** m, double** m_result) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			m_result[i][j] = s * m[i][j];
		}
	}
}
void Multiply (int size, double** m, double s, double** m_result) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			m_result[i][j] = m[i][j] * s;
		}
	}
}
int main(int argc, char const *argv[]) {
	int N;
	std::cout << "input the size of the matrix: ";
	std::cin >> N;

	double scalar;
	std::cout << "input a scalar: ";
	std::cin >> scalar;

	double* vec = new double[N];
	std::cout << "input a vector: ";
	for (int i = 0; i < N; i++) {
		std::cin >> vec[i];
	}
	double* v_result = new double[N];

	double** matrix1 = new double*[N];
	double** matrix2 = new double*[N];
	double** result = new double*[N];
	for (int i = 0; i < N; i++) {
		matrix1[i] = new double[N];
		matrix2[i] = new double[N];
		result[i] = new double[N];
	}
	std::cout << "input matrix1:\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> matrix1[i][j];
		}
	}
	std::cout << "input matrix2:\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> matrix2[i][j];
		}
	}

	Multiply(N, matrix1, matrix2, result);
	std::cout << "matrix1 * matrix2 is\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cout << result[i][j] << "\t";
		}
		std::cout << "\n";
	}

	Multiply(N, vec, matrix1, v_result);
	std::cout << "vec * matrix1 is\n";
	for (int i = 0; i < N; i++) {
		std::cout << v_result[i] << "\t";
	}
	std::cout << std::endl;

	Multiply(N, matrix1, vec, v_result);
	std::cout << "matrix1 * vec is\n";
	for (int i = 0; i < N; i++) {
		std::cout << v_result[i] << "\t";
	}
	std::cout << std::endl;

	Multiply(N, scalar, matrix1, result);
	std::cout << "scalar * matrix1 is\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cout << result[i][j] << "\t";
		}
		std::cout << std::endl;
	}

	Multiply(N, matrix1, scalar, result);
	std::cout << "matrix1 * scalar is\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cout << result[i][j] << "\t";
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < N; i++) {
		delete[] matrix1[i];
		delete[] matrix2[i];
		delete[] result[i];
	}
	delete[] matrix1;
	delete[] matrix2;
	delete[] result;
	delete[] vec;
	delete[] v_result;
	return 0;
}