//
//  main.cpp
//  NIntegrate
//
//  Copyright © 2016年 Lencerf. All rights reserved.
//

#include <iostream>
#include "NIntegrate1D.hpp"

double fx (double x) {
    return x * x;
}

int main(int argc, const char * argv[]) {
    NIntegrate1D test(&fx, 0, 1);
    std::cout << test.Calculate() << std::endl;
    return 0;
}
