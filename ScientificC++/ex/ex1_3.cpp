#include <iostream>
#include <cmath>

int main(int argc, char* argv[])
{
	double v1[3] = {0.2, 0.3, 0.4};
	double v2[3] = {1.2, 1.5, 1.4};
	double sp = 0;
	double ns_v1 = 0;
	double ns_v2 = 0;

	for (int i = 0; i < 3; ++i)
	{
		sp += v1[i] * v2[i];
	}
	std::cout << sp << "\n";
	for (int i = 0; i < 3; ++i)
	{
		ns_v1 += v1[i] * v1[i];
	}
	for (int i = 0; i < 3; ++i)
	{
		ns_v2 += v2[i] * v2[i];
	}

	std::cout << "Norm of v1 is " << sqrt(ns_v1) << "\n";
	std::cout << "Norm of v2 is " << sqrt(ns_v2) << "\n";



	return 0;
}