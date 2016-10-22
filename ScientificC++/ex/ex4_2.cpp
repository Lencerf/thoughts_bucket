#include <iostream>

int main(int argc, char const *argv[]) {
	int a, b;
	std::cout << "Imput the value of a and b: ";
	std::cin >> a >> b;
	int* p1 = &a;
	int* p2 = &b;
	int* p_temp = new int;
	*p_temp = *p1;
	*p1 = *p2;
	*p2 = *p_temp;
	delete p_temp;
	printf("After swap, a = %d, b = %d.\n", *p1, *p2);
	return 0;
}