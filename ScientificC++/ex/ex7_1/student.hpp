#ifndef STUDENTDEF
#define STUDENTDEF

#include <string>

class student
{
private:
	double fine;
public:
	student();
	student(std::string n);
	std::string name;
	double fee;
	virtual double sum() const;
	double getFine() const;
	void setFine(double x);
};

#endif
