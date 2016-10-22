#include "AbstractOdeSolver.hpp"
#include <iostream>

void AbstractOdeSolver::setSetpSize(int N) {
	stepSize = (finalTime - initialTime) / (double)(N);
	printf("set step size to %f.\n", stepSize);
}

void AbstractOdeSolver::setTimeInterval(double t0, double t1) {
	initialTime = t0;
	finalTime = t1;
}

void AbstractOdeSolver::setInitialValue(double y0) {
	initialValue = y0;
}

void AbstractOdeSolver::setRightHandSide(double (*p_rhs)(double, double)) {
	p_RightHandSide = p_rhs;
}

double AbstractOdeSolver::RightHandSide(double y, double t) {
	return (*p_RightHandSide)(y,t);
}