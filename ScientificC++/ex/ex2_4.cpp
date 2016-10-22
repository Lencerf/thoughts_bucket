#include <iostream>

void printVectors(double* vec)
{
	for (int i = 0; i < 3; ++i)
	{
		std::cout << vec[i] << "\t";
	}
	std::cout << "\n";
}

void printMatrix(double* matrix)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << matrix[3*i+j] << "\t";
		}
		std::cout << "\n";
	}
}

int main (int argc, char* argv[])
{
	double u[3] = {1.0, 2.0, 3.0};
	double v[3] = {6.0, 5.0, 4.0};
	double A[3][3] = {{1, 5, 0}, {7, 1, 2}, {0, 0, 1}};
	double B[3][3] = {{-2, 0, 1}, {1, 0, 0}, {4, 1, 0}};
	double w[3];
	for (int i = 0; i < 3; ++i)
	{
		w[i] = u[i] - 3 * v[i];
	}

	double x[3], y[3], z[3], C[3][3], D[3][3];
	for (int i = 0; i < 3; i++)
	{
		x[i] = u[i] - v[i];
	}
	for (int i = 0; i < 3; i++)
	{
		y[i] = 0;
		for (int j = 0; j < 3; j++)
		{
			y[i] += A[i][j] * u[j];
		}
	}
	for (int i = 0; i < 3; i++)
	{
		z[i] = y[i] - v[i];
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			C[i][j] = 4 * A[i][j] - 3 * B[i][j];
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			D[i][j] = 0;
			for (int k = 0; k < 3; k++)
			{
				D[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	printf("u is \n");
	printVectors(&u[0]);
	printf("v is \n");
	printVectors(&v[0]);
	printf("A is \n");
	printMatrix(&A[0][0]);
	printf("B is \n");
	printMatrix(&B[0][0]);
	printf("x is \n");
	printVectors(&x[0]);
	printf("y is \n");
	printVectors(&y[0]);
	printf("z is \n");
	printVectors(&z[0]);
	printf("C is \n");
	printMatrix(&C[0][0]);
	printf("D is \n");
	printMatrix(&D[0][0]);
	return 0;
}