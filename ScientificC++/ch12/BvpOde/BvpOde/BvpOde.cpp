//
//  BvpOde.cpp
//  BvpOde
//
//  Created by  on 16/1/6.
//  Copyright © 2016年 Lencerf. All rights reserved.
//

#include "BvpOde.hpp"
#include <fstream>
#include <cassert>

BvpOde::BvpOde(SecondOrderOde* p_Ode, BoundaryConditions* p_Bcs, int numNodes) {
    mNumNodes = numNodes;
    mp_Ode = p_Ode;
    mp_Bcs = p_Bcs;
    mp_Grid = new FiniteDifferenceGrid(numNodes, p_Ode->mXmin, p_Ode->mXmax);
    mp_SolveVec = NULL;
    mp_RhsVec = new Vector(numNodes);
    
    mp_LhsMat = new Matrix(numNodes,numNodes);
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            mp_LhsMat->AtIndex(i, j) = 0;
        }
    }
    
    mp_LinearSystem = NULL;
}

BvpOde::~BvpOde() {
    delete mp_Grid;
    //delete mp_SolveVec;
    delete mp_RhsVec;
    delete mp_LhsMat;
    if (mp_LinearSystem != NULL) {
        delete mp_LinearSystem;
    }
}

void BvpOde::SolveOde() {
    const double PointDistance = mp_Grid->AtIndex(1) - mp_Grid->AtIndex(0);
    //initialize rhsvec
    for (int i = 1; i < mNumNodes - 1; i++) {
        mp_RhsVec->AtIndex(i) = (*(mp_Ode->mp_RhsFunc))(mp_Grid->AtIndex(i));
    }
    mp_RhsVec->AtIndex(0) = mp_Bcs->mLhsBcValue;
    mp_RhsVec->AtIndex(mNumNodes - 1) = mp_Bcs->mRhsBcValue;
    
    // initialize lhsmat
    // the fires row
    if (mp_Bcs->mLhsBcIsDirichlet) {
        mp_LhsMat->AtIndex(0, 0) = 1;
    } else if (mp_Bcs->mLhsBcIsNeumann) {
        mp_LhsMat->AtIndex(0, 0) = - 1 / PointDistance;
        mp_LhsMat->AtIndex(0, 1) = 1 / PointDistance;
    }
    // the last row
    if (mp_Bcs->mRhsBcIsDirichlet) {
        mp_LhsMat->AtIndex(mNumNodes - 1, mNumNodes - 1) = 1;
    } else if (mp_Bcs->mRhsBcIsNeumann) {
        mp_LhsMat->AtIndex(mNumNodes - 1, mNumNodes - 2) = - 1 / PointDistance;
        mp_LhsMat->AtIndex(mNumNodes - 1, mNumNodes - 1) = 1 / PointDistance;
    }
    // approximation coefficients
    for (int i = 1; i < mNumNodes - 1; i++) {
        mp_LhsMat->AtIndex(i, i - 1) = - mp_Ode->mCoeffOfUx / (2 * PointDistance)
        + mp_Ode->mCoeffOfUxx / (PointDistance * PointDistance);
        mp_LhsMat->AtIndex(i, i) = mp_Ode->mCoeffOfU -
        2 * mp_Ode->mCoeffOfUxx / (PointDistance * PointDistance);
        mp_LhsMat->AtIndex(i, i + 1) = mp_Ode->mCoeffOfUx / (2 * PointDistance)
        + mp_Ode->mCoeffOfUxx / (PointDistance * PointDistance);
    }
    
    mp_LinearSystem = new LinearSystem(*mp_LhsMat, *mp_RhsVec);
    //std::cout << *mp_LhsMat;
    mp_LinearSystem->SolveGaussianElimination();
    mp_SolveVec = mp_LinearSystem->getResult();
}

void BvpOde::WriteSolutionFile(std::string filename) {
    std::ofstream write_output(filename);
    assert(write_output.is_open());
    assert(mp_SolveVec != NULL);
    for (int i = 0; i < mNumNodes; i++) {
        write_output << mp_Grid->AtIndex(i) << "\t" << mp_SolveVec->AtIndex(i) << "\n";
    }
    write_output.close();
}