#include <iostream>

void test(int* p_x) {
	printf("%d\n", *p_x);
}

int main(int argc, char const *argv[]) {
	int x[3] = {12, 34, 32};
	test(x);

	return 0;
}