#include <iostream>
#include <cmath>
#include "ComplexNumber.hpp"

void PrintMatrix (int size, ComplexNumber** m) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			std::cout << m[i][j] << "\t";
		}
		std::cout << "\n";
	}
}

void Normalize (int size, ComplexNumber* v) {
	double squaredNorm = 0;
	for (int i = 0; i < size; i++) {
		squaredNorm += v[i].GetRealPart() * v[i].GetRealPart() 
					+ v[i].GetImaginaryPart() * v[i].GetImaginaryPart();
	}
	const double norm = sqrt(squaredNorm);
	for (int i = 0; i < size; i++) {
		const double x = v[i].GetRealPart() / norm;
		const double y = v[i].GetImaginaryPart() / norm;
		v[i] = ComplexNumber(x, y);
	}
}

void Multiply (int size, ComplexNumber** m1, ComplexNumber** m2, ComplexNumber** result) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			result[i][j] = ComplexNumber(0);
			for (int k = 0; k < size; k++) {
				result[i][j] = result[i][j] + m1[i][k] * m2[k][j];
			}
		}
	}
}

void exp (int size, ComplexNumber** A, ComplexNumber** result) {
	ComplexNumber** An = new ComplexNumber*[size];
	ComplexNumber** An_m_1 = new ComplexNumber*[size];
	for (int i = 0; i < size; i++) {
		An[i] = new ComplexNumber[size];
		An_m_1[i] = new ComplexNumber[size];
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			An_m_1[i][j] = (i==j?ComplexNumber(1):ComplexNumber(0));
			result[i][j] = An_m_1[i][j];
		}
	}
	double denominator = 1;

	for (int i = 1; i < 10; i++) {
		Multiply(size, A, An_m_1, An);
		denominator *= i;

		//std::cout << denominator << std::endl;
		//PrintMatrix(3,An);

		for (int j = 0; j < size; j++) {
			for (int k = 0; k < size; k++) {
				result[j][k] = result[j][k] + An[j][k] / denominator;
				An_m_1[j][k] = An[j][k];
			}
		}
		//printf("An_m_1 is \n");
		//PrintMatrix(3,An_m_1);

	}
	for (int i = 0; i < size; i++) {
		delete[] An[i];
		delete[] An_m_1[i];
	}
	delete[] An;
	delete[] An_m_1;
}

int main(int argc, char const *argv[]) {
	ComplexNumber z(1, -1);
	std::cout << z.GetRealPart() << std::endl;
	std::cout << RealPart(z) << std::endl;

	std::cout << z << std::endl;
	ComplexNumber z2(z);
	std::cout << z2 << std::endl;
	std::cout << z2.CalculateConjugate() << std::endl;
	ComplexNumber z3(3);
	std::cout << z3 << std::endl;
	ComplexNumber z4(3,4);
	z4.SetConjugate();
	std::cout << z4 << std::endl;
	ComplexNumber* test = new ComplexNumber[3];
	test[0] = ComplexNumber(1,1);
	test[1] = ComplexNumber(1,-1);
	test[2] = ComplexNumber(1);
	Normalize(3, test);
	for (int i = 0; i < 3; i++) {
		std::cout << test[i] << "\t";
	}
	delete[] test;
	std::cout << std::endl;
	std::cout << z / 1 << " " << z / ComplexNumber(1, 1) << std::endl;
	std::cout << std::endl;

	ComplexNumber** F = new ComplexNumber*[3];
	ComplexNumber** expF = new ComplexNumber*[3];
	for (int i = 0; i < 3; i++) {
		F[i] = new ComplexNumber[3];
		expF[i] = new ComplexNumber[3];
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			F[i][j] = (i==j?ComplexNumber(1.0/3.0):ComplexNumber(-1.0/6.0));
		}
	}

	//PrintMatrix(3,F);
	exp(3, F, expF);
	PrintMatrix(3,expF);


	for (int i = 0; i < 3; i++) {
		delete[] F[i];
	}
	delete[] F;

	std::cout << ComplexNumber(1,-5).CalculatePower(0) << std::endl;
	return 0;
}