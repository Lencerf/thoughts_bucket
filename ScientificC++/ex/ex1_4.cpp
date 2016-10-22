#include <iostream>
 
int main(int argc, char* arcv[])
{
	double A[2][2] = {{1,3},{3,2}};
	double B[2][2] = {{3,4},{1,2}};
	double C[2][2];
	double D[2][2];

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			C[i][j] = A[i][j] + B[i][j];
		}
	}
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			D[i][j] = 0;
			for (int k = 0; k < 2; ++k)
			{
				D[i][j] += A[i][k] * B[k][j];
			}

		}
	}
	std::cout << "Matrix C is \n";
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			std::cout << C[i][j] << "\t";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
	std::cout << "Matrix D is \n";
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			std::cout << D[i][j] << "\t";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}