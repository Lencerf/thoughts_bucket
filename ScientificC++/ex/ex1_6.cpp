#include <iostream>

int main(int argc,char* argv[])
{
	int n_cars[5];
	std::cout << "Please inmput the number of cars: ";
	for (int i = 0; i < 5; i++)
	{
		std::cin >> n_cars[i];
	}
	double ave_n = 0;
	for (int i = 0; i < 5; i++)
	{
		ave_n += n_cars[i];
	}
	ave_n /= 5;
	std::cout << "The average number of cars is " << ave_n << ".\n";
	return 0;
}