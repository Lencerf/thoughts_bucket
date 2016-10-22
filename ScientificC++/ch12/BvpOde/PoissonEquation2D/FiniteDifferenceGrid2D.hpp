//
//  FiniteDifferenceGrid2D.hpp
//  BvpOde
//
//  Created by  on 16/1/12.
//  Copyright © 2016年 Lencerf. All rights reserved.
//

#ifndef FiniteDifferenceGrid2D_hpp
#define FiniteDifferenceGrid2D_hpp

#include <stdio.h>
#include <vector>
#include "Node2D.hpp"

class FiniteDifferenceGrid2D {
    
private:
    int mNumNodesX;
    int mNumNodesY;
    std::vector<Node2D> mNodes;
public:
    FiniteDifferenceGrid2D(int numNodesX, int numNodesY, double xMin, double xMax,
                           double yMin, double yMax);
    Node2D At(int n, int m);
};

#endif /* FiniteDifferenceGrid2D_hpp */
