//
//  FiniteGrids2D.cpp
//  PoissonEquation2D
//
//  Copyright © 2016年 Lencerf. All rights reserved.
//

#include "FiniteGrids2D.hpp"
#include <cassert>

FiniteGrids2D::FiniteGrids2D(unsigned int numNodesX, unsigned int numNodesY) {
    mNumNodesX = numNodesX;
    mNumNodesY = numNodesY;
    mGrid = new Nodes2D*[numNodesX];
    for (int i = 0; i < numNodesX; i++) {
        mGrid[i] = new Nodes2D;
    }
}

FiniteGrids2D::~FiniteGrids2D() {
    for (int i = 0; i < mNumNodesX; i++) {
        delete[] mGrid[i];
    }
    delete[] mGrid;
}

void FiniteGrids2D::PutToArea(double xMin, double xMax, double yMin, double yMax) {
    const double stepX = (xMax - xMin) / mNumNodesX;
    const double stepY = (yMax - yMin) / mNumNodesY;
    for (int i = 0; i < mNumNodesX; i++) {
        for (int j = 0; j < mNumNodesY; j++) {
            mGrid[i][j].x = xMin + i * stepX;
            mGrid[i][j].y = xMax + j * stepY;
        }
    }
}

Nodes2D FiniteGrids2D::AtIndex(int nX, int nY) {
    assert(nX>=0 && nX < mNumNodesX);
    assert(nY>=0 && nY < mNumNodesY);
    return mGrid[nX][nY];
}

int FiniteGrids2D::getNumNodesX() {
    return mNumNodesX;
}

int FiniteGrids2D::getNumNodexY() {
    return mNumNodesY;
}
