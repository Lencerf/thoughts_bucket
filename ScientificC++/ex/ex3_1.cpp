#include <iostream>
#include <fstream>
#include <cassert>
#include <cmath>

int main(int argc, char const *argv[])
{
	double x[4] = {0, 1, 1, 0};
	double y[4] = {0, 0, 1, 1};
	std::ofstream write_output("Output.dat");
	write_output.setf(std::ios::scientific);
	write_output.setf(std::ios::showpos);
	write_output.precision(10);
	assert(write_output.is_open());
	for (int i = 0; i < 4; i++) {
		write_output << x[i] << '\t';
	}
	write_output << '\n';
	write_output.flush();
	for (int i = 0; i < 4; i++) {
		write_output << y[i] << '\t';
	}
	write_output << '\n';
	write_output.flush();
	write_output.close();

	/*
	std::ofstream write_output2("Output2.dat");
	write_output2.setf(std::ios::scientific);
	write_output2.precision(5);
	write_output2 << M_PI;
	write_output2.close();
	*/

	return 0;
}

int search (int fd) {
    
}