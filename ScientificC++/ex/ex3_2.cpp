#include <iostream>
#include <fstream>

int main(int argc, char const *argv[] 
{
	std::fstream read_file("Output.dat");
	if (!read_file.is_open()) {
		return 1;
	}
	int number_of_rows = 0;
	while (!read_file.eof()) {
		double d1, d2, d3, d4;
		read_file >> d1 >> d2 >> d3 >> d4;
		if (!read_file.fail()) {
			number_of_rows++;
		}
	}
	printf("Number of rows = %d\n", number_of_rows);
	return 0;
}