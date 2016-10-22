#ifndef RKROLVER
#define RKROLVER

#include "AbstractOdeSolver.hpp"

class RKSolver: public AbstractOdeSolver {
public:
	void SolveEquation();
};

#endif