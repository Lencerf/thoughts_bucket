//
//  FiniteDifferenceGrid.cpp
//  BvpOde
//
//  Created by  on 16/1/6.
//  Copyright © 2016年 Lencerf. All rights reserved.
//

#include "FiniteDifferenceGrid.hpp"

FiniteDifferenceGrid::FiniteDifferenceGrid(int numNodes, double xMin, double xMax) {
    double step = (xMax - xMin) / (numNodes - 1);
    for (int i = 0; i < numNodes - 1; i++) {
        mNodes.push_back(xMin + i * step);
    }
    mNodes.push_back(xMax);
}

double FiniteDifferenceGrid::AtIndex(int n) {
    return mNodes[n];
}
