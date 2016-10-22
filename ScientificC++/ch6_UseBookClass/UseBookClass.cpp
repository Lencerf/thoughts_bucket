#include <iostream>
#include "Book.hpp"

int main(int argc, char const *argv[]) {
	Book book1;

	book1.author = "Griffith";
	book1.title = "Electrodynamics";
	book1.publisher = "PS";
	book1.format = "hard";
	book1.SetYearOfPublication(2003);

	printf("%s:%s(%s),%s,%d\n", book1.author.c_str(), book1.title.c_str(), book1.format.c_str(), book1.publisher.c_str(), book1.GetYearOfPublication());

	return 0;
}