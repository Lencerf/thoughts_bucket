#include <iostream>
#include <string>

class Book
{
public:
	Book();
	std::string author, title, format;
	void SetYearOfPublication(int year);
	int GetYearOfPublication() const;
private:
	int mYearOfPublication;
};

Book::Book() {
	author = "unspecified";
	title = "unspecified";
	format = "unspecified";
}

void Book::SetYearOfPublication(int year) {
	mYearOfPublication = year;
}

int Book::GetYearOfPublication() const {
	return mYearOfPublication;
}

class Ebook: public Book
{
public:
	Ebook();
	std::string hiddenUrl;
};

Ebook::Ebook() : Book() {
	format = "Electronic";
}

int main(int argc, char const *argv[]) {
	Ebook holiday_reading;
	holiday_reading.title = "The skull beneath the skin";
	//holiday_reading.author = "P D James";
	std::cout << "The author is " << holiday_reading.author << "\n";
	std::cout << "The title is " << holiday_reading.title << "\n";
	std::cout << "The format is " << holiday_reading.format << "\n";

	holiday_reading.SetYearOfPublication(1982);
	std::cout << "Year of publication is " << holiday_reading.GetYearOfPublication() << "\n";

	holiday_reading.hiddenUrl = "website.com";
	std::cout << "The URL is " << holiday_reading.hiddenUrl << "\n";
	return 0;
}