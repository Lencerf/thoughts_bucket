#include <iostream>
#include "matrix2.hpp"

matrix2::matrix2() {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			element[i][j] = 0;
		}
	}
}

matrix2::matrix2(const matrix2& otherMatrix2) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			element[i][j] = otherMatrix2.element[i][j];
		}
	}
}

matrix2::matrix2(double a, double b, double c, double d) {
	element[0][0] = a;
	element[0][1] = b;
	element[1][0] = c;
	element[1][1] = d;
}

double matrix2::determinant() const {
	return element[0][0] * element[1][1] - element[1][0] * element[0][1];
}

matrix2 matrix2::inverse() const {
	double det = this->determinant();
	matrix2 result;
	result.element[0][0] = element[1][1] / det;
	result.element[1][1] = element[0][0] / det;
	result.element[0][1] = - element[0][1] / det;
	result.element[1][0] = - element[1][0] / det;
	return result;
}

matrix2& matrix2::operator= (const matrix2& m2) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			element[i][j] = m2.element[i][j];
		}
	}
	return *this;
}

matrix2 matrix2::operator-() const {
	matrix2 result;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			result.element[i][j] = - element[i][j];
		}
	}
	return result;
}

matrix2 matrix2::operator+(const matrix2& m2) const {
	matrix2 result;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			result.element[i][j] = element[i][j] + m2.element[i][j];
		}
	}
	return result;
}

matrix2 matrix2::operator-(const matrix2& m2) const {
	matrix2 result;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			result.element[i][j] = element[i][j] - m2.element[i][j];
		}
	}
	return result;
}

std::ostream& operator<<(std::ostream& output, const matrix2& m2) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			output << m2.element[i][j] << "\t";
		}
		if (i < 1) {
			output << "\n";
		}
	}
	return output;
}

matrix2 matrix2::Multiply(const double x) const {
	matrix2 result;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			result.element[i][j] = element[i][j] * x;
		}
	}
	return result;
}