#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
	std::string given_name;
	std::string family_name;
	std::cout << "Please type your given name:\n";
	std::getline(std::cin, given_name);
	std::cout << "Please type your family name:\n";
	std::getline(std::cin, family_name);
	std:: cout << "So your full name is " << given_name << " " << family_name << ".\n";
	return 0;
}