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
    return - 1;
}

int main(int argc, const char * argv[]) {
    /* Code for test Linear system
    Vector rhs(3);
    for (int i = 0; i < 3; i++) {
        rhs[i] = i;
    }
    Matrix coe(3,3);
    coe[0][0] = 1.1; coe[0][1] = 2; coe[0][2] = 3;
    coe[1][0] = 2.3; coe[1][1] = 3.4; coe[1][2] = 4.2;
    coe[2][0] = -1.2; coe[2][1] = -3.2; coe[2][2] = -9;
    std::cout << "The det of coe is" << coe.det() << std::endl;
    std::cout << "coe is \n";
    std::cout << coe;
    LinearSystem test(coe,rhs);
    test.Solve();
    std::cout << "The result is \n";
    for (int i = 0; i < 3; i ++) {
        std::cout << (*(test.getResult()))[i] << "\t";
    }
    std::cout << std::endl;*/
    
    SecondOrderOde TestOde(1, 0, 0, test_rhs, 0, 1);
    BoundaryConditions TestBcs;
    TestBcs.SetLhsDirichletBc(0);
    TestBcs.SetRhsDirichletBc(0);
    int grids;
    std::cout << "Please input the number of grids: " << std::endl;
    std::cin >> grids;
    BvpOde testBvpOde(&TestOde, &TestBcs, grids);
    testBvpOde.SolveOde();
    testBvpOde.WriteSolutionFile("test.txt");
    return 0;
}
