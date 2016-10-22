//
//  PoissonEquation2D.cpp
//  PoissonEquation2D
//
//  Created by  on 16/1/13.
//  Copyright © 2016年 Lencerf. All rights reserved.
//

#include "PoissonEquation2D.hpp"
#include <fstream>
#include <cassert>
PoissonEquation2D::PoissonEquation2D(double (*p_rhsFunc)(double, double)):
mp_rhsFunc(p_rhsFunc) {}

PoissonEquation2D::~PoissonEquation2D() {
    if (mp_result != NULL) {
        delete mp_result;
    }
    if (mp_LhsMat != NULL) {
        delete mp_LhsMat;
    }
    if (mp_RhsVec != NULL) {
        delete mp_RhsVec;
    }
    if (mp_Grids != NULL) {
        delete mp_Grids;
    }
    if (mp_LinearSystem != NULL) {
        delete mp_LinearSystem;
    }
    
}

void PoissonEquation2D::SetLeftBc(double xMin, double LeftBcType, double (*p_LeftBc)(double)) {
    mXMin = xMin;
    mLeftBcType = LeftBcType;
    mp_LeftBc = p_LeftBc;
}

void PoissonEquation2D::SetRightBc(double xMax, double RightBcType, double (*p_RightBc)(double)) {
    mXMax = xMax;
    mRightBcType = RightBcType;
    mp_RightBc = p_RightBc;
}

void PoissonEquation2D::SetTopBc(double yMax, double TopBcType, double (*p_TopBc)(double)) {
    mYMax = yMax;
    mTopBcType = TopBcType;
    mp_TopBc = p_TopBc;
}

void PoissonEquation2D::SetBottomBc(double yMin, double BottomBcType, double (*p_BottomBc)(double)) {
    mYMin = yMin;
    mBottomBcType = BottomBcType;
    mp_BottomBc = p_BottomBc;
}

void PoissonEquation2D::Solve(unsigned int numNodesX, unsigned int numNodesY, std::string outputFile) {
    //mp_result = new Vector(numNodesX * numNodesY);
    mp_RhsVec = new Vector(numNodesX * numNodesY);
    mp_LhsMat = new Matrix(numNodesX * numNodesY, numNodesX * numNodesY);
    const double stepX = (mXMax - mXMin) / (numNodesX - 1);
    const double stepY = (mYMax - mYMin) / (numNodesY - 1);
    // generate grids
    //mp_Grids = new FiniteGrids2D(numNodesX, numNodesY);
    //mp_Grids->PutToArea(mXMin, mXMax, mYMin, mYMax);
    
    // assign values to rhs vector
    // interior nodes
    for (int i = 1; i < numNodesX - 1; i++) {
        for (int j = 1; j < numNodesY - 1; j++) {
            mp_RhsVec->AtIndex(i * numNodesY + j) = (*mp_rhsFunc)(mXMin + i * stepX, mYMin + j * stepY);
        }
    }
    // nodes on the left and right boundary
    for (int j = 0; j < numNodesY; j++) {
        mp_RhsVec->AtIndex(j) = (*mp_LeftBc)(mYMin + j * stepY); // i = 0
        mp_RhsVec->AtIndex((numNodesX - 1) * numNodesY + j) = (*mp_RightBc)(mYMin + j * stepY); // i = numNodesX - 1
    }
    // nodes on the top and bottom boundary
    for (int i = 1; i < numNodesX - 1; i++) {
        mp_RhsVec->AtIndex(i * numNodesY) = (*mp_BottomBc)(mXMin + i * stepX); // j = 0
        mp_RhsVec->AtIndex(i * numNodesY + numNodesY - 1) = (*mp_TopBc)(mXMin + i * stepX); // j = munNodesY - 1
    }
    
    // assign values to rhs matrix
    for (int i = 1; i < numNodesX - 1; i++) {
        for (int j = 1; j < numNodesY - 1 ; j++) {
            mp_LhsMat->AtIndex(i * numNodesY + j, i * numNodesY + j) = - 2 / (stepX * stepX) - 2 / (stepY * stepY);
            mp_LhsMat->AtIndex(i * numNodesY + j, (i + 1) * numNodesY + j) = mp_LhsMat->AtIndex(i * numNodesY + j, (i - 1) * numNodesY + j) = 1 / (stepX * stepX);
            mp_LhsMat->AtIndex(i * numNodesY + j, i * numNodesY + j + 1) = mp_LhsMat->AtIndex(i * numNodesY + j, i * numNodesY + j - 1) = 1 / (stepY * stepY);
        }
    }
    // apply bc to rhs matrix
    // left bc i = 0, right bc i = numNodesX - 1
    for (int i = 0; i < numNodesX; i += (numNodesX - 1)) {
        for (int j = 0; j < numNodesY; j++) {
            int BcType = (i == 0 ? mLeftBcType:mRightBcType);
            switch (BcType) {
                case 0:
                    mp_LhsMat->AtIndex(i * numNodesY + j, i * numNodesY + j) = 1;
                    break;
                case 1: // partial x
                    if (i == 0) { // left
                        mp_LhsMat->AtIndex(j, j) = - 1 / stepX;
                        mp_LhsMat->AtIndex(j, numNodesY + j) = 1 / stepX;
                    } else { // right
                        mp_LhsMat->AtIndex(i * numNodesY + j, i * numNodesY + j) = 1 / stepX;
                        mp_LhsMat->AtIndex(i * numNodesY + j, (i - 1) * numNodesY + j) = - 1 / stepX;
                    }
                    break;
                case 2: // partial y
                    if (j == 0) {
                        mp_LhsMat->AtIndex(i * numNodesY + j, i * numNodesY + j) = - 1 / stepY;
                        mp_LhsMat->AtIndex(i * numNodesY + j, i * numNodesY + j + 1) = 1 / stepY;
                    } else if (j == numNodesY - 1) {
                        mp_LhsMat->AtIndex(i * numNodesY + j, i * numNodesY + j - 1) = - 1 / stepY;
                        mp_LhsMat->AtIndex(i * numNodesY + j, i * numNodesY + j) = 1 / stepY;
                    } else {
                        mp_LhsMat->AtIndex(i * numNodesY + j, i * numNodesY + j - 1) = - 0.5 / stepY;
                        mp_LhsMat->AtIndex(i * numNodesY + j, i * numNodesY + j + 1) = 0.5 / stepY;
                    }
                    break;
                default:
                    break;
            }
        }
    }
    // bottom bc j = 0, top bc j = numNodesY - 1
    for (int j = 0; j < numNodesY; j += (numNodesY - 1)) {
        for (int i = 1; i < numNodesX - 1; i++) {
            int BcType = (j == 0 ? mBottomBcType:mTopBcType);
            switch (BcType) {
                case 0:
                    mp_LhsMat->AtIndex(i * numNodesY + j, i * numNodesY + j) = 1;
                    break;
                case 1: // partial x,
                    mp_LhsMat->AtIndex(i * numNodesY + j, (i - 1) * numNodesY + j) = - 0.5 / stepX;
                    mp_LhsMat->AtIndex(i * numNodesY + j, (i + 1) * numNodesY + j) = 0.5 / stepX;
                    break;
                case 2: // partial y
                    if (j == 0) { // bottom
                        mp_LhsMat->AtIndex(i * numNodesY + j, i * numNodesY + j) = - 1 / stepY;
                        mp_LhsMat->AtIndex(i * numNodesY + j, i * numNodesY + j + 1) = 1 / stepY;
                    } else { // top
                        mp_LhsMat->AtIndex(i * numNodesY + j, i * numNodesY + j) = 1 / stepY;
                        mp_LhsMat->AtIndex(i * numNodesY + j, i * numNodesY + j - 1) = - 1 / stepY;
                    }
                    break;
                default:
                    break;
            }
        }
    }
    //std::cout << *mp_LhsMat;
    //std::cout << mp_LhsMat->AtIndex(3, 3) << "\t" << mp_LhsMat->AtIndex(2, 2) << std::endl;
    mp_LinearSystem = new LinearSystem(*mp_LhsMat, *mp_RhsVec);
    mp_LinearSystem->SolveGaussianElimination();
    std::ofstream output(outputFile);
    assert(output.is_open());
    for (int i = 0; i < numNodesX; i++) {
        for (int j = 0; j < numNodesY; j++) {
            output << mXMin + i * stepX << "\t" << mYMin + j * stepY << "\t" << mp_LinearSystem->getResult()->AtIndex(i * numNodesY + j) << "\n";
        }
    }
    output.close();
    // right bc i = numNodesX - 1
}
