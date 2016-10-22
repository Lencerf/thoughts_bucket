//
//  FiniteGrids2D.hpp
//  PoissonEquation2D
//
//  Copyright © 2016年 Lencerf. All rights reserved.
//

#ifndef FiniteGrids2D_hpp
#define FiniteGrids2D_hpp

#include <stdio.h>
#include "Nodes2D.hpp"

class FiniteGrids2D {
private:
    unsigned int mNumNodesX;
    unsigned int mNumNodesY;
    Nodes2D** mGrid = NULL;
    
public:
    FiniteGrids2D(unsigned int numNodesX, unsigned int numNodesY);
    ~FiniteGrids2D();
    void PutToArea(double xMin, double xMax, double yMin, double yMax);
    Nodes2D AtIndex(int nX, int nY);
    int getNumNodesX();
    int getNumNodexY();
};

#endif /* FiniteGrids2D_hpp */
