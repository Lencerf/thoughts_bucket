#include "iostream"
#include "Ebook.hpp"

int main(int argc, char const *argv[]) {
	Ebook holiday_reading;
	Ebook book2("2nd");
	printf("The version is %s.\n", book2.version.c_str());
	std::cout << "The title is " << holiday_reading.title << "\n";
	printf("The price is %d\n", holiday_reading.price);
	holiday_reading.title = "The skull beneath the skin";
	//holiday_reading.author = "P D James";
	std::cout << "The author is " << holiday_reading.author << "\n";
	std::cout << "The title is " << holiday_reading.title << "\n";
	std::cout << "The format is " << holiday_reading.format << "\n";

	holiday_reading.SetYearOfPublication(1982);
	std::cout << "Year of publication is " << holiday_reading.GetYearOfPublication() << "\n";

	holiday_reading.hiddenUrl = "changyuan.me";
	std::cout << "The URL is " << holiday_reading.hiddenUrl << "\n";
	return 0;
}