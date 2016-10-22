#include <iostream>

int main(int argc, char const *argv[]) {
	int i = 5;
	int* p_j = &i;
	*p_j *= 5;
	int* p_k = new int;
	*p_k = i;
	printf("i=%d, *p_k=%d\n", i, *p_k);
	return 0;
}