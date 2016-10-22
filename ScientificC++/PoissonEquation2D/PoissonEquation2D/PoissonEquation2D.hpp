//
//  PoissonEquation2D.hpp
//  PoissonEquation2D
//
//  Created by  on 16/1/13.
//  Copyright © 2016年 Lencerf. All rights reserved.
//

#ifndef PoissonEquation2D_hpp
#define PoissonEquation2D_hpp

#include <stdio.h>
#include <string>
#include "Vector.hpp"
#include "Matrix.hpp"
#include "LinearSystem.hpp"
#include "FiniteGrids2D.hpp"

class PoissonEquation2D {
private:
    double (*mp_rhsFunc)(double x, double y);
    double mXMin;
    double mXMax;
    double mYMin;
    double mYMax;
    // 0 stand for Dirichlet Bc, 1 stand for x Neumann Bc, 2 stand for y Neumann Bc
    int mLeftBcType;
    double (*mp_LeftBc)(double y);
    int mRightBcType;
    double (*mp_RightBc)(double y);
    int mTopBcType;
    double (*mp_TopBc)(double x);
    int mBottomBcType;
    double (*mp_BottomBc)(double x);
    
    Matrix* mp_LhsMat = NULL;
    Vector* mp_result = NULL;
    Vector* mp_RhsVec = NULL;
    LinearSystem* mp_LinearSystem = NULL;
    
    FiniteGrids2D* mp_Grids = NULL;


public:
    PoissonEquation2D(double (*p_rhsFunc)(double, double));
    ~PoissonEquation2D();
    
    void SetLeftBc(double xMin, double LeftBcType, double (*p_LeftBc)(double));
    void SetRightBc(double xMax, double RightBcType, double (*p_RightBc)(double));
    void SetTopBc(double yMax, double TopBcType, double (*p_TopBc)(double));
    void SetBottomBc(double yMin, double BottomBcType, double (*p_BottomBc)(double));
    
    void Solve(unsigned int numNodesX, unsigned int numNodesY,
               std::string outputFile);
    
};

#endif /* PoissonEquation2D_hpp */
