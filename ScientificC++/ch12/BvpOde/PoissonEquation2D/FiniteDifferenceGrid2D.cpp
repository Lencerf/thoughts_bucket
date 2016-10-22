//
//  FiniteDifferenceGrid2D.cpp
//  BvpOde
//
//  Created by  on 16/1/12.
//  Copyright © 2016年 Lencerf. All rights reserved.
//

#include "FiniteDifferenceGrid2D.hpp"
#include <cassert>
FiniteDifferenceGrid2D::FiniteDifferenceGrid2D(int numNodesX, int numNodesY,
                                               double xMin, double xMax,
                                               double yMin, double yMax):
mNumNodesX(numNodesX), mNumNodesY(numNodesY) {
    const double stepX = (xMax - xMin) / numNodesX;
    const double stepY = (yMax - yMin) / numNodesY;
    for (int i = 0; i < numNodesX; i++) {
        for (int j = 0; j < numNodesY; j++) {
            mNodes.push_back(Node2D(xMin + i * stepX, xMax + j * stepY));
        }
    }
}
             
Node2D FiniteDifferenceGrid2D::At(int n, int m) {
    assert(n < mNumNodesX && m < mNumNodesY);
    return mNodes[n * mNumNodesY + m];
}