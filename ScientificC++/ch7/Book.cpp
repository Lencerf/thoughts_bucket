#include <cassert>
#include "Book.hpp"

Book::Book() {
	//author = "unspecified haha";
	title = "unspecified";
	publisher = "unspecified";
	format = "unspecified";
}

Book::Book(const Book& otherBook) {
	author = otherBook.author;
	title = otherBook.title;
	publisher = otherBook.title;
	format = otherBook.format;
	price = otherBook.price;
	mYearOfPublication = otherBook.GetYearOfPublication();
}

Book::Book(std::string bookTitle) {
	title = bookTitle;
}

void Book::SetYearOfPublication(int year) {
	assert ((year > 1440) && (year < 2020));
	mYearOfPublication = year;
}

int Book::GetYearOfPublication() const {
	return mYearOfPublication;
}