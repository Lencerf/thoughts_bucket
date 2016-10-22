#include <iostream>
#include "phd.hpp"
#include "student.hpp"
#include "graduate.hpp"

int main(int argc, char const *argv[]) {
	student a;
	student b("lcy");
	student* p_phd = new phd;
	std::cout << b.name << std::endl;
	std::cout << p_phd->sum() << std::endl;
	return 0;
}