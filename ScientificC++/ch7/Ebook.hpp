#ifndef EBOOKHEADERDEF
#define EBOOKHEADERDEF 

#include <string>
#include "Book.hpp"

class Ebook: public Book
{
public:
	Ebook();
	Ebook(std::string v);
	std::string hiddenUrl;
	std::string version;
};

#endif