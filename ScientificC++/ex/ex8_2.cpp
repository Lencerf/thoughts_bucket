//This exercise is problematic!
#include <iostream>
#include <cassert>

template <class T>
T MyAbs(T x) {
	return (x > 0)?x:-x;
}

int main(int argc, char const *argv[]) {
	std::cout << MyAbs<int>(-1) << "\t" << MyAbs<double>(-1.1) << std::endl;
	return 0;
}