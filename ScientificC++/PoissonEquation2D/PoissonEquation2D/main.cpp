//
//  main.cpp
//  PoissonEquation2D
//
//  Copyright © 2016年 Lencerf. All rights reserved.
//

#include <iostream>
#include <cmath>
#include "PoissonEquation2D.hpp"

double rhsFunc(double x, double y) {
    return - 4 * (1 - x * x - y * y) * std::exp(- x * x - y * y);
}

double leftBc(double y) {
    return std::exp(- y * y);
}

double rightBc(double y) {
    return std::exp(- 1 - y * y);
}

double bottomBc(double x) {
    return std::exp(- x * x);
}

double topBc(double x) {
    return std::exp(- 4 - x * x);
}

int main(int argc, const char * argv[]) {
    PoissonEquation2D testEq(&rhsFunc);
    testEq.SetLeftBc(0, 0, &leftBc);
    testEq.SetRightBc(1, 0, &rightBc);
    testEq.SetTopBc(2, 0, &topBc);
    testEq.SetBottomBc(0, 0, &bottomBc);
    testEq.Solve(5, 5, "a.txt");
    std::cout << "Hello, World!\n";
    return 0;
}
