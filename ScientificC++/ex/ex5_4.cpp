#include <iostream>
#include <cmath>

void calcArray(int size, double* array, double& ave, double& sdev) {
	double sum = 0;
	for (int i = 0; i < size; i++) {
		sum += array[i];
	}
	ave = sum / size;
	double temp = 0;
	for (int i = 0; i < size; i++) {
		temp += (array[i] - ave) * (array[i] - ave);
	}
	sdev = sqrt(temp / (size - 1));
}

int main(int argc, char const *argv[]) {
	int N;
	std::cout << "input the size of the array: ";
	std::cin >> N;
	double* array = new double[N];
	std::cout << "input the array:\n";
	for (int i = 0; i < N; i++) {
		std::cin >> array[i];
	}
	double ave, sdev;
	calcArray(N, array, ave, sdev);
	printf("The average is %f and the standard deviation is %f.\n", ave, sdev);
	delete[] array;
	return 0;
}