#include <iostream>
#include <fstream>
#include "AbstractOdeSolver.hpp"
#include "ForwardEulerSolver.hpp"
#include "RKSolver.hpp"

double testF(double y, double t) {
	return 1 + t;
}

int main(int argc, char const *argv[]) {
	//std::ofstream output("output.txt");
	ForwardEulerSolver testSolver;
	testSolver.setTimeInterval(0, 1);
	testSolver.setSetpSize(200);
	testSolver.setInitialValue(2);
	testSolver.setRightHandSide(&testF);
	testSolver.SolveEquation();

	RKSolver testSolver2;
	testSolver2.setTimeInterval(0, 1);
	testSolver2.setSetpSize(200);
	testSolver2.setInitialValue(2);
	testSolver2.setRightHandSide(&testF);
	testSolver2.SolveEquation();

	return 0;
}