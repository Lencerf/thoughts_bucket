#ifndef FORWARDEULERSOLVER
#define FORWARDEULERSOLVER

#include "AbstractOdeSolver.hpp"

class ForwardEulerSolver: public AbstractOdeSolver {
public:
	void SolveEquation();
};

#endif