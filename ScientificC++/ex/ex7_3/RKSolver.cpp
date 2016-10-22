#include "RKSolver.hpp"

#include <cassert>

void RKSolver::SolveEquation() {
	double ti = initialTime;
	double yi = initialValue;
	std::ofstream output("output1.txt");
	assert(output.is_open());
	while (ti <= finalTime) {
		output << ti << "\t" << yi << "\n";
		const double k1 = stepSize * RightHandSide(yi, ti);
		const double k2 = stepSize * RightHandSide(yi + k1 / 2, ti + stepSize / 2);
		const double k3 = stepSize * RightHandSide(yi + k2 / 2, ti + stepSize / 2);
		const double k4 = stepSize * RightHandSide(yi + k3, ti + stepSize);
		yi += (k1 + 2 * (k2 + k3) + k4) / 6;
		ti += stepSize;
	}
	output.close();
}