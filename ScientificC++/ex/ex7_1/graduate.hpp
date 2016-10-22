#ifndef GRADUATEDEF
#define GRADUATEDEF

#include <string>
#include "student.hpp"

class graduate: student
{
public:
	bool isFullTime;
	double sum() const;
};

#endif