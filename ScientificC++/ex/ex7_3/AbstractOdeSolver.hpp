#ifndef ABSTRACTODESOLVERDEF
#define ABSTRACTODESOLVERDEF

#include <fstream>
class AbstractOdeSolver {
protected:
	double stepSize;
	double initialTime;
	double finalTime;
	double initialValue;
	double (*p_RightHandSide)(double y, double t);
public:
	void setSetpSize(int N);
	void setTimeInterval(double t0, double t1);
	void setInitialValue(double y0);
	void setRightHandSide(double (*p_rhs)(double, double));
	double RightHandSide(double y, double t);
	virtual void SolveEquation() = 0;
};

#endif