#ifndef GRADUATEDEF
#define GRADUATEDEF

#include "student.hpp"

class graduate: student
{
public:
	bool isFullTime;
	double sum() const;
};

#endif
