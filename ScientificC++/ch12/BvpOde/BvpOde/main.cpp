//
//  main.cpp
//  BvpOde
//
//  Copyright © 2016年 Lencerf. All rights reserved.
//

#include <iostream>
#include "Matrix.hpp"
#include "Vector.hpp"
#include "LinearSystem.hpp"
#include "BvpOde.hpp"
#include "SecondOrderOde.hpp"
#include <cmath>

double test_rhs(double x) {
    return 34 * sin(x);
}

int main(int argc, const char * argv[]) {
    SecondOrderOde TestOde(1, 3, -4, test_rhs, 0, M_PI);
    BoundaryConditions TestBcs;
    TestBcs.SetLhsNeumannBc(-5);
    TestBcs.SetRhsDirichletBc(4);
    int grids;
    std::cin >> grids;
    BvpOde testBvpOde(&TestOde, &TestBcs, grids);
    testBvpOde.SolveOde();
    testBvpOde.WriteSolutionFile("test.txt");
    return 0;
}
