#include "student.hpp"

student::student(): name("unknown") {;}

student::student(std::string n): name(n) {;}

double student::sum() const {
	return fine + fee;
}

double student::getFine() const {
	return fine;
}

void student::setFine(double x) {
	fine = x;

}