#include "ForwardEulerSolver.hpp"
#include <cassert>

void ForwardEulerSolver::SolveEquation() {
	double ti = initialTime;
	double yi = initialValue;
	std::ofstream output("output.txt");
	assert(output.is_open());
	while (ti <= finalTime) {
		output << ti << "\t" << yi << "\n";
		yi += stepSize * RightHandSide(yi, ti);
		ti += stepSize;
	}
	output.close();
}
