#include <iostream>

int main(int argc, char const *argv[])
{
	double A[2][2] = {{4, 10}, {1, 1}};
	double det_A = A[0][0]*A[1][1] - A[0][1]*A[1][0];
	
	return 0;
}